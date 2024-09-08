#include "mbed.h" 
#include "Motor.h" 
#include "C12832A1Z.h" 
 
DigitalIn joy_up(p15);  
DigitalIn joy_down(p12);  
C12832A1Z lcd(p5, p7, p6, p8, p11); 
Motor m(p25, p27, p28); // pwm, fwd, rev 
AnalogIn potentiometer(p19); 
PwmOut speed(p25); 
 
int main() { 
    speed.period(0.01);  
    speed = 0.0; // Initialize motor speed to 0 
     
    while(1) { 
        if (joy_up == 1) { 
             
            float poten= potentiometer.read();  
            m.speed(poten);  
         
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Forward"); 
  int speed_value = (int)(poten * 100); 
            lcd.locate(0, 12); 
            lcd.printf("Speed : %d%%", speed_value); 
 
        } 
        else if (joy_down == 1) { 
            float poten= potentiometer.read();  
            m.speed(-poten);  
     
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Backward"); 
 
            int speed_value = (int)(poten * 100); 
            lcd.locate(0, 12); 
            lcd.printf("Speed : %d%%", speed_value); 
 
        }  
        else { 
            m.speed(0.0); // Stop the motor if no button is pressed 
        } 
        ThisThread::sleep_for(100ms); 
    } 
} 