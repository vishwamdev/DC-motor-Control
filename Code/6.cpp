#include "mbed.h" 
#include "Motor.h" 
#include "C12832A1Z.h" 
#include "ACS712.h" 
 
Motor m(p25, p27, p28); // pwm, fwd, rev 
Motor n(p22, p14, p17); // pwm, fwd, rev 
DigitalIn j_up(p15);  
DigitalIn j_down(p12);  
DigitalIn j_left(p13); 
DigitalIn j_right(p16);  
AnalogIn potentiometer(p20); //poten pin 
C12832A1Z lcd(p5, p7, p6, p8, p11); 
ACS712 currentsensor(p19); 
 
int main() { 
     
    while(1) { 
        if (j_up == 1) { 
            float p = potentiometer.read(); 
            m.speed(p); 
            n.speed(p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
        lcd.printf("Direction: Foward"); 
            lcd.locate(0,8); 
          float current = currentsensor.read_current_sensor(); 
        lcd.printf("Current in amps %f",current); 
} 
 
         
        else if (j_down == 1) { 
            float p = potentiometer.read(); 
            m.speed(-p); 
            n.speed(-p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0);
            lcd.printf("Direction: Backward");    
            lcd.locate(0,8); 
            float current_mA = currentsensor.read_current_sensor(); // 
Read current in milliamps 
            lcd.printf("Current in amps %f",current_mA); 
            
         
        }  
        else if (j_right == 1) { 
            float p = potentiometer.read(); 
            m.speed(p); 
            n.speed(p/2); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: right"); 
            lcd.locate(0,8); 
   float current_mA = currentsensor.read_current_sensor(); // Read 
current in milliamps 
            lcd.printf("Current in amps %f",current_mA); 
        } 
        else if (j_left == 1) { 
            float p = potentiometer.read(); 
            m.speed(p/2); 
            n.speed(p); 
            int speed_vlv = (int)(p*100); 
 
            lcd.cls(); 
            lcd.locate(0, 0); 
            lcd.printf("Direction: left"); 
                      lcd.locate(0,8); 
 float current_mA = currentsensor.read_current_sensor(); // Read 
current in milliamps 
            lcd.printf("Current in amps %f",current_mA); 
        }       
        else { 
            m.speed(0.0); // Stop the motor if no button is pressed 
            n.speed(0.0); 
            lcd.cls(); 
            lcd.locate(0, 0); 
    float current_mA = currentsensor.read_current_sensor(); // Read 
current in milliamps 
            lcd.printf("Current in amps %f",current_mA); 
  
        } 
        ThisThread::sleep_for(100ms); 
    } 
