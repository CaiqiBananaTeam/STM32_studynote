
#include "keyboard.h"
//#include "gpio.h"
#include "oled.h"
extern  char ret[3]={0,0,0};
void  KEY_Scan(char *ret)
{
    //char ret[ 2]={0,0};
    HAL_GPIO_WritePin(GPIOA,C1_Pin,RESET);    
    if(HAL_GPIO_ReadPin(GPIOA,R1_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(1,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R1_Pin) == 0);
        ret[0]='1';
        ret[1]='1' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
         ret[0]='2';
        ret[1]='1' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
         ret[0]='3';
        ret[1]='1' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
         ret[0]='4';
        ret[1]='1' ;
    }

    HAL_GPIO_WritePin(GPIOA,C1_Pin,SET);
    HAL_GPIO_WritePin(GPIOA,C2_Pin,RESET);
    if(HAL_GPIO_ReadPin(GPIOA,R1_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(1,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R1_Pin) == 0);
         ret[0]='1';
        ret[1]='2' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
         ret[0]='2';
        ret[1]='2' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
         ret[0]='3';
        ret[1]='2' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
         ret[0]='4';
        ret[1]='2' ;
    }
    HAL_GPIO_WritePin(GPIOA,C2_Pin,SET);
    HAL_GPIO_WritePin(GPIOA,C3_Pin,RESET);

    /*
    
    
    */
     if(HAL_GPIO_ReadPin(GPIOA,R1_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(1,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R1_Pin) == 0);
         ret[0]='1';
        ret[1]='3' ;

    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
         ret[0]='2';
        ret[1]='3' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
         ret[0]='3';
        ret[1]='3' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
         ret[0]='4';
        ret[1]='3' ;
    }




    HAL_GPIO_WritePin(GPIOA,C3_Pin,SET);
    HAL_GPIO_WritePin(GPIOA,C4_Pin,RESET);

    /*
    
    
    */
     if(HAL_GPIO_ReadPin(GPIOA,R1_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(1,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
         
        while(HAL_GPIO_ReadPin(GPIOA, R1_Pin) == 0);
         ret[0]='1';
        ret[1]='4' ;
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
         
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
         ret[0]='2';
        ret[1]='4' ;
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         ret[0]='3';
        ret[1]='4' ;
         
         
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
        ret[0]='4';
        ret[1]='4' ;
    }

    HAL_GPIO_WritePin(GPIOA,C4_Pin,SET);


}


}
