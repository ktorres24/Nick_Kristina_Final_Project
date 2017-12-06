## Names 
Kristina Torres and Nicholas Hunt   
   
## Design Overview
This is a small four wheel car that send signals to 4 seperate motors at different speeds to make it steer. The direction of the car is determined by which of the 4 buttons the user presses (forward,backward,left right). 
    
## Hardware List
TM4C123 LaunchPad      
4 Pin Momentary Switch  
4 DC Mini Electric Motors     
2 Dual TB6612FNG Breakout   
2 AA Battery (4-Pack)  
2 Battery Holders

## Hardware Description
Inputs:  Buttons used to control the direction of the car.
PF4 (Left)
PF0 (Right) 
PD6 (Forward) 
PD7 (Backwards)

Outputs: Used to send PWM to motors and high/low reading to driver inputs for rotation direction.
PD0 (Front right motor)
PD1 (Back right motor)
PA6 (Front left motor) 
PA7 (Back left motor)
PE1 (AIN1)
PE2 (AIN2)
PE3 (STBY Driver #1)
PC5 (BIN1)
PC6 (BIN2)
PC7 (STBY Driver #2)

## Software Description
Most important parts of our software/code were setting the duty cycle for different speeds and setting certain pins high or low for CW and CCW rotation. These functions are summarized below.

GPIOPinWrite high or low to the motor driver input based on this table:

![high low](https://user-images.githubusercontent.com/31192254/33670571-6cf914b2-da73-11e7-8700-9a7141503169.PNG)

PWMPulseWidthSet a value of 500 or 900 to change the speed of the motor based on direction shown on this table:

![duty cycle](https://user-images.githubusercontent.com/31192254/33670794-e425df98-da73-11e7-9f67-95e0b8104327.PNG)


## Summary and Conclusions
Overall this project provided us with a good opportunity to figure out a lot of the problems we could run into with our senior project. Additionally, we learned more about PWM/setting clocks properly and that we should comment as we code :)
