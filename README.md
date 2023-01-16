# 点灯

需要注意的是:

+ 每一个项目似乎都需要设置一下json文件
+ 设置io口，很麻烦，时钟设置如果不是资源紧张，一般不需要特殊设置。  
倒没什么特别需要注意的，666；
需要的函数：

``` C
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);//将PA1置高电平

HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);//将PA1置低电平

HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_1);//取反PA1电平

HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1);//读取PA1电平状态

HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);//初始化引脚
**需要注意的是，这些init函数，使用cubemx就能帮我们自动初始化引脚，但是对于其他外设，可能需要其他的寄存器命令，这些大概率是需要从别人的库或者手册里找到的。**


```

# 键盘

+ 熟练掌握GPIO的input和output的设置，键盘检测。
+ 能用到的，在这里write和read，重点是对行列的扫描监测，引脚的input模式主要用来检测，也就是说用来作为输入信息来判断的，output就是通过一些信息做出的决定。





# OLED显示屏

从这里我们就需要知道STM32开发的基本流程了，一般的，mx配置生成，需要注意的就两个，一个是在makefile里面加上新添加文件.c文件，还有在.h文件中声明。
OLED的使用比较复杂：

+ 因为最基础的函数需要写入寄存器，寄存地地址等值需要库函数，**我们需要网络找到它的现有库。**
+ 同时**我们需要知道，需要显示的字符，要通过软件提前生成（包括大小）**

``` C
HAL_I2C_Mem_Write(&hi2c1 ,0x78,0x00,I2C_MEMADD_SIZE_8BIT,&cmd,1,0x100);
//这是本节最重要的函数，用于向寄存器写入命令，库文件本身几乎所有，都建立在这个函数上
```

我们在本次实验中选用的I2C通信，I2C通信：

+ SCL（serial clock）:时钟线，传输CLK信号，一般是I2C主设备向从设备提供时钟的通道。
+ SDA（serial data）：数据线，通信数据都通过SDA线传输
  记住以上两点就可以了。

# UART通信

### 这里需要注意使用的函数

``` C
HAL_UART_Transmit(&huart1, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
这就是本节stm32部分的主体函数，第一个参数就是&huart1，一般是mx帮你设置好的句柄，**第二个参数就是要发送的，char型的数据，第三个是char数组的长度，最后一个，是时间，什么时间，如果超时，就不发送，一般就选择HAL_MAX_DELAY.**


### 多参数函数补充
```C
/串口1发送数据函数
#include <stdarg.h>
#include <stdio.h>
void my_sum(int count, ...);

int main(int argc, char* argv[])
{
    int count = 5;
    printf("compute sum of %d numbers.\n", count);
    my_sum(count, "the sum of numbers is:", 1, 2, 3, 4, 5);//可变参数的函数
    return 0;
}

void my_sum(int count, ...)//需要使用前面提到的stdarg库
{
    //将要用来存放需要的某个可变参数的指针的信息
    va_list ap;//ap理解为指针，指向所有参数的指针
    char* prompt;
    int sum = 0;

    //开始的初始化，其中ap含有指向可变参数的指针的信息，count是当前函数中最后一个非可变的参数(这样才能定位).
    va_start(ap, count);//start是什么意思，就是通过count，把ap指向count的下一个参数

    //获取并返回下一个可变参数的值，第一个参数是ap不用说了，第二个参数是要获取的参数的类型。
    //根据文档，如果类型指定错误了，或者没有下一个可变参数了，那么返回的结果是随机的。
    prompt = va_arg(ap, char*);//这里char，是因为主函数里加了一句字符串
    printf("%s\n", prompt);

    int i;
    for (i = 0; i < count; ++i)
    {
        sum += va_arg(ap, int);//这里直接读取，ap就自动到下一个位置了
    }

    //使用完可变参数之后要用这个来释放资源
    va_end(ap);
    printf("%d\n", sum);
}
```

### 于是，在这基础上，就有我们的函数：

```C
void u1_printf(char* fmt, ...) {
  uint16_t len;
  va_list ap;
  va_start(ap, fmt);//虽然用了这种模式，但是对后面的参数并没有什么实际的处理
  uint8_t buf[200];
  vsprintf((char*)buf, fmt, ap);
  va_end(ap);
  len = strlen((char*)buf);
  HAL_UART_Transmit(&huart1, buf, len, HAL_MAX_DELAY);//这里的UART——transmit就类似于arduino中的printf
}
```

### 需要补充一点冠以vsprintf的东西：

```C
u1_printf("(%c ,%c)\n",a[0],a[1]);//他就类似于arduino中的printf
//这里就是很重要的，这中多参数的填充，在上一段代码中，相当于，用fmt的格式，将ap里面的东西填到buf中，a[0],a[1]都会放到ap里面，所以，这种输出是可以的。一般来说，就算输入的参数有数字什么的，对应为int，他也会放在一个char的buf中，也就是自己内部转换了。
```
### 蓝牙
无需多言，就是最简单的uart通信，需要注意的是蓝牙AT指令设置，role和cmode很重要，而且，波特率需要与板子的设置为相同。
主体函数还是：
```C
HAL_UART_Transmit(&huart1,buf,len,HAL_MAX_DELAY)
```
稍后再来看其他的transmit函数，有不同的功效。适用于不同的情况。