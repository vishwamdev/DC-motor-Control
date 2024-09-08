#include "mbed.h" 
#include "Motor.h"

Motor m(p25, p27, p28); 

int main() { 
    m.speed(0.5);
}

