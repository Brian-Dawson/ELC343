/*
Joshua Annandsingh and Brian Dawson
Microcomputer Systems Final Project
Rock Paper Scissors Game
*/
#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
RULES FOR THE GAME
SELECT LEFT BUTTON FOR 1 PLAYER AND RIGHT BUTTON FOR 2 PLAYER
P1 USES LEFT BUTTON AND P2 USES RIGHT BUTTON
0=SCISSORS
1=ROCK
2=PAPER
NUMBER OF PUSHES MOD 3 IS SELECTION NUMBER
*/
int main(void)
{
    LED_Driver_1_Start(); //Starts the Seven Segment Display
    LCD_Start(); //Starts the Character LCD
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   
    char output[256];
    
    
    
    for(;;)
    {   
        int AIgame = 0; //Used to determine if single or two player
        CyDelay(100);
        LCD_ClearDisplay(); //Clears LCD
        /*
        This section displays the text for the selection of single or two player
        */
        LCD_PrintString("L:1 Player");
        LCD_Position(1,0);
        LCD_PrintString("R:2 Player");
        //While loops to determine if a button has been pressed
        while(SW_1_Read()==1 && SW_2_Read()==1){
        }
        if(SW_1_Read() == 0){                                       //Single player
        AIgame=1;
        int count1 = 0,count2 = 0;  
        LED_Driver_1_ClearDisplayAll(); //Clears Seven Segment  
        LCD_ClearDisplay(); //Clears LCD
        for(int i =9;i>=0;i--){                                     //Countdown until game starts
        LED_Driver_1_Write7SegDigitDec(i, 0); //Draws the current number to the seven segment
        CyDelay(1000); //Waits one second
        LED_Driver_1_ClearDisplayAll(); //Clears for next number
        }
        LCD_PrintString("P1 GO!"); //Tells Player 1 to go
        for(int i =0; i< 30; i++){                                  //Time for P1 input
        if(SW_1_Read()==0) 
        {
            count1 = count1 + 1; 
              
            while(SW_1_Read()==0)
            {
            }
        
        }
        CyDelay(100); //Delay for debouncing
        }
        LCD_ClearDisplay(); //
        count2 = rand();                                            //AI Selection
        
        if(count1%3 == 0 && count2%3 ==0){
            //Scissors v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors"); //Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Scissors"); //Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500); //1.5 Second Delay
            LCD_ClearDisplay();
            LCD_PrintString("TIE"); //Display who won
        }
        else if(count1%3 == 0 && count2%3 ==1){
            //Scissors v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("AI Wins");//Display who won
        }
        else if(count1%3 == 0 && count2%3 ==2){
            //Scissors v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==0){
            //Rock v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Scissors");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==1){
            //Rock v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("TIE");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==2){
            //Rock v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("AI Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 ==0){
            //Paper v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Scissors");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("AI Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 ==1){
            //Paper v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 == 2){
            //Paper v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"AI: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("TIE");//Display who won
        }
        CyDelay(1500);
        LCD_ClearDisplay();
        LCD_PrintString("Press Any Button");                        //Restart Section
        LCD_Position(1,0);
        LCD_PrintString("to restart");
        //This waits for someone to hit one of the buttons
        while(SW_1_Read()==1 && SW_2_Read()==1){
        }
        CyDelay(100);
        }
        
        
        
        if(SW_2_Read() == 0 && AIgame==0){                          //2 Player
        LCD_ClearDisplay();    //Clears the LCD
        int count1 = 0,count2 = 0;
        for(int i =9;i>=0;i--){                                     //Countdown
        LED_Driver_1_Write7SegDigitDec(i, 0); //Draws the current number to the seven segment
        CyDelay(1000); //1 Second Delay
        LED_Driver_1_ClearDisplayAll();//Clears for next number
        }
        LCD_ClearDisplay();
        LCD_PrintString("P1 GO!"); //Tells player 1 to go
        for(int i =0; i< 30; i++) //Waits for 3 seconds
        { 
        if(SW_1_Read()==0)
        {
              count1 = count1 + 1;
              
            while(SW_1_Read()==0)
            {
            }
        
        }
        CyDelay(100); //Delay for debouncing
        }                             
        LCD_ClearDisplay();
        LCD_PrintString("P2 GO!"); //Tells player 2 to go
        for(int i =0; i< 30; i++) //Waits for 3 seconds
        {
        if(SW_2_Read()==0)
        {
              count2 = count2 + 1;
              
            while(SW_2_Read()==0)
            {
            }
        
        }
        CyDelay(100); //Delay for debouncing
        }                             
        
        if(count1%3 == 0 && count2%3 ==0){
            //Scissors v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Scissors");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("TIE");//Display who won
        }
         else if(count1%3 == 0 && count2%3 ==1){
            //Scissors v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P2 Wins");//Display who won
        }
         else if(count1%3 == 0 && count2%3 ==2){
            //Scissors v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Scissors");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==0){
            //Rock v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Scissors");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==1){
            //Rock v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("TIE");//Display who won
        }
        else if(count1%3 == 1 && count2%3 ==2){
            //Rock v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Rock");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P2 Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 ==0){
            //Paper v Scissors
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Scissors");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P2 Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 ==1){
            //Paper v Rock
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Rock");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("P1 Wins");//Display who won
        }
        else if(count1%3 == 2 && count2%3 == 2){
            //Paper v Paper
            LCD_ClearDisplay();
            sprintf(output,"Player 1: %s","Paper");//Output for 1st player selection
            LCD_PrintString(output);
            LCD_Position(1,0);
            sprintf(output,"Player 2: %s","Paper");//Output for 2nd player selection
            LCD_PrintString(output);
            CyDelay(1500);
            LCD_ClearDisplay();
            LCD_PrintString("TIE");//Display who won
        }
        CyDelay(1500); //1.5 second delau
        LCD_ClearDisplay();
        LCD_PrintString("Press Any Button");                        //Restart Section
        LCD_Position(1,0);
        LCD_PrintString("to restart");
        //Wait for button press
        while(SW_1_Read()==1 && SW_2_Read()==1){
        }
        CyDelay(100);
        }
    }
    }



/* [] END OF FILE */
