#ifndef THERMISTOR_H
#define THEMISTOR_H

#ifndef Arduino_h
#include <Arduino.h>
#endif


class Thermistor {
public:
    enum e_calcType {STEINHART};     // enum created since the code can be upgraded with other calc methods
    enum e_tempScale {CELSIUS,KELVIN,FAHRENHEIT};
    float resistence();  //get thermistor resistence
    Thermistor(int analogPin, int ref=5000, int r0=10000, e_tempScale tempScale=CELSIUS, int repeat=10, float a=1.009249522e-03, float b=2.378405444e-04, float c=2.019202697e-07, e_calcType calcType=STEINHART); //constructor and the default values
    float getTemperature();  //get temperature with +/- 0.1 accuracy (
    long getVolt();  //convert digital level (0-1023) to voltage level and return it
private:
    int analogPin;
    int ref;  //arduino voltage. equivalent to max digital level (1023)
    int r0;   //resistence at 25 Celsius
    int repeat; //number of repetitions in rms
    float a,b,c; //steinhart coeficients
//    float t0;    //temperature to convert kelvin to celsius. For Kelvin measure t0=0
    e_tempScale tempScale; //thermistor's temperature scale
    float steinhart(); //steinhart equation
    int rms();    //rms voltage get. return digital level (0-1023)
    e_calcType calcType;

};

#endif
