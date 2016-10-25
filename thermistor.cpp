#include "thermistor.h"


Thermistor::Thermistor(int analogPin, int ref, int r0, e_tempScale tempScale, int repeat, float a, float b, float c, e_calcType calcType){

    this->analogPin = analogPin;
    this->ref = ref;
    this->r0 = r0;
    this->tempScale = tempScale;
    this->repeat = repeat;
    this->a = a;
    this->b = b;
    this->c = c;
    this->calcType = calcType;
}

int Thermistor::rms(){

    long accumulated = 0, digital_value = 0, average = 0;
    for(int i=0 ;i < this->repeat; i++){
        digital_value = analogRead(this->analogPin);   //convert the analog-value (voltage) to digital one (0-1023)
        accumulated += digital_value*digital_value;      //accumulate all the digital-values “repeat” times
    }
    average = accumulated / this->repeat;
    return (int)(sqrt(average));

}

long Thermistor::getVolt(){
	return (this->ref*this->rms())/1023;
}

float Thermistor::resistence(){
    return this->r0 * (this->ref / (float)this->getVolt()) - this->r0;
}

float Thermistor::steinhart(){

    float lnR = log(this->resistence());


    //switching between temperature scales
    switch(this->tempScale){
    case KELVIN:
        return (1.0/ (this->a + this->b * lnR + this->c * lnR * lnR * lnR));
        break;

    case FAHRENHEIT:
        return ((1.0/ (this->a + this->b * lnR + this->c * lnR * lnR * lnR))*(9/5))-459.67;
        break; 

    default: //CELSIUS is the default scale in case of wrong scale input!
        return (1.0/ (this->a + this->b * lnR + this->c * lnR * lnR * lnR)) - 273.15;   
        break;
    }
}

float Thermistor::getTemperature(){

    switch(this->calcType){   //in case of implementation of other temperature equations.
    default:
        return this->steinhart();
        break;
    }
}
