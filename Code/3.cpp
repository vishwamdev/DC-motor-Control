#include "mbed.h" 
#include "Motor.h" 
#include "C12832A1Z.h" 
 
DigitalIn joy_up(p15);  
DigitalIn joy_down(p12);  
C12832A1Z lcd(p5, p7, p6, p8, p11); 
Motor m(p25, p27, p28); // pwm, fwd, rev 
PwmOut speed(p25); 
 
int main() {
     speed.period(0.01);  
    speed = 0.0; // Initialize motor speed to 0 
     
    while(1) { 
        if (joy_up == 1) { 
            m.speed(0.2); // Set motor speed to 20% (forward) 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Forward"); 
        } 
        else if (joy_down == 1) { 
            m.speed(-0.2); // Set motor speed to -20% (backward) 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Backward"); 
        }  
        else { 
            m.speed(0.0); // Stop the motor if no button is pressed 
        } 
        ThisThread::sleep_for(100ms); 
    } 