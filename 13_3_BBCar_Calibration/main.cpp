#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);


BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table0[] = {-7.736, -7.576, -8.134, -7.736, -6.061, 0.000, 6.061, 7.736, 8.134, 7.576, 7.736};

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table1[] = {-9.331, -8.932, -9.251, -8.772, -5.503, 0.000, 5.503, 8.772, 9.251, 8.932, 9.331};


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(-5);

        wait(5);

        car.stop();

        wait(5);

    }

}