#include "mbed.h" 
#include "Motor.h" 
#include "C12832A1Z.h" 
 
C12832A1Z lcd(p5, p7, p6, p8, p11); // LCD display 
AnalogIn potentiometer(p19); 
Motor m(p25, p27, p28);  
 
int main() { 
    while(1) { 
    float poten= potentiometer.read();  
    m.speed(poten);  
        int speed_value = (int)(poten * 100); 
        lcd.locate(0, 3); 
        lcd.printf("Speed : %d%%", speed_value); 
        ThisThread::sleep_for(100ms);  
    } 
} 