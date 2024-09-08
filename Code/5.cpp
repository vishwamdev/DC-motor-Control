#include "mbed.h" 
#include "Motor.h" 
#include "C12832A1Z.h" 
 
Motor m(p25, p27, p28); // pwm, fwd, rev 
Motor n(p22, p14, p17); // pwm, fwd, rev 
DigitalIn j_up(p15);  
DigitalIn j_down(p12);  
DigitalIn j_left(p13); 
DigitalIn j_right(p16);  
AnalogIn potentiometer(p20); //poten pin 
C12832A1Z lcd(p5, p7, p6, p8, p11); 
 
 
int main() { 
     
    while(1) { 
        if (j_up == 1) {
             float p = potentiometer.read(); 
            m.speed(p); 
            n.speed(p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Forward,         Speed : %d%%", 
speed_vlv); 
 
        } 
        else if (j_down == 1) { 
            float p = potentiometer.read(); 
            m.speed(-p); 
            n.speed(-p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: Backward,      Speed : %d%%", 
speed_vlv); 
        }  
        else if (j_right == 1) { 
            float p = potentiometer.read(); 
            m.speed(p); 
            n.speed(p/2); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: right,         Speed : %d%%", 
speed_vlv); 
        } 
        else if (j_left == 1) { 
            float p = potentiometer.read(); 
            m.speed(p/2); 
            n.speed(p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: left,           Speed : %d%%", 
speed_vlv); 
        }       
        else { 
            m.speed(0.0); // Stop the motor if no button is pressed 
            n.speed(0.0); 
            lcd.cls(); 
lcd.locate(0, 0); 
            lcd.printf("Direction: Stop"); 
        } 
        ThisThread::sleep_for(100ms); 
    }