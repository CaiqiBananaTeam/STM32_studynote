
#include "keyboard.h"
#include "gpio.h"
#include "oled.h"
void  KEY_Scan()
{
    HAL_GPIO_WritePin(GPIOA,C1_Pin,RESET);    
    if(HAL_GPIO_ReadPin(GPIOA,R1_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(1,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R1_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,1)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
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
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,2)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
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
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
       
        // HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,3)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        
         //HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
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
    }
    if(HAL_GPIO_ReadPin(GPIOA,R2_Pin)==0)
    {
        OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(2,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
         
        while(HAL_GPIO_ReadPin(GPIOA, R2_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R3_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(3,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
         
        while(HAL_GPIO_ReadPin(GPIOA, R3_Pin) == 0);
    }
    if(HAL_GPIO_ReadPin(GPIOA,R4_Pin)==0)
    {
         OLED_Clear();
        HAL_Delay(20);
        OLED_ShowString(39,4,"(4,4)",16);
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
         
        while(HAL_GPIO_ReadPin(GPIOA, R4_Pin) == 0);
    }
   

    HAL_GPIO_WritePin(GPIOA,C4_Pin,SET);



}



