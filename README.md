# Thermistor
Simple Arduino Thermistor class for analog NTC thermistors.
The program reads the selected analog pin and converts the data into a scale temperature. So, a simple electronic circuit should be made.
For more instructions, see this: http://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_Analog_Temperature_Sensor_2_(NTC_-_Negative_Temperature_Coeficient)

The value selection for parameters a, b and c to the Steinhart equation are sensor dependent and can be evaluated with a 3-equation system. For simplicity, you can use this online calculator: https://sanjit.wtf/Calibrator/webCalibrator.html

With that, you need to search in your NTC datasheet 3 pairs of resistance-temperature. Choose values within the range you will work for more precise results.
