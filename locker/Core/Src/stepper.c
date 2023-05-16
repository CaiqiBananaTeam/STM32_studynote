#include "stepper.h"
#include "main.h"
#include "delay.h"
const int steps_per_cycle=200;

void loop(int a,int angle)
{
    
    if(a==0)
       HAL_GPIO_WritePin(dir_GPIO_Port,dir_Pin,GPIO_PIN_RESET);//设置逆时针
    else
        HAL_GPIO_WritePin(dir_GPIO_Port,dir_Pin,GPIO_PIN_SET);//设置为顺时针

    for (int i = 0;i<angle;i++)
    {
        HAL_GPIO_WritePin(step_GPIO_Port,step_Pin,GPIO_PIN_SET);
        HAL_Delay(2);
        HAL_GPIO_WritePin(step_GPIO_Port,step_Pin,GPIO_PIN_RESET);
        HAL_Delay(2);
    }
    HAL_Delay(100);
}