/*
 * File:   main.c
 * Author: Chris Hajduk
 *
 * Created on March 4, 2013, 10:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p33fxxxx.h>
#include "OutputCompare.h"
#include "InputCapture.h"
#include "OutputCompare.c"
#include "InputCapture.c"
//#include "UART.c"



_FOSCSEL(FNOSC_PRIPLL);
_FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF);

/*
 *
 */
int main(int argc, char** argv) {

    initIC();
    initOC();

    while(1)
    {
        short ic;
        for (ic = 1; ic <= 8; ic++)
        {
            if (checkic[ic] == 1)
            {
              if(t2[ic] > t1[ic])
              {
                 icTimeDiff[ic] = (t2[ic] - t1[ic]);
                 checkic[ic] = 0;
              }
              else
              {
                 icTimeDiff[ic] = ((PR2 - t1[ic]) + t2[ic]);
                 checkic[ic] = 0;
              }
            }
        }

        //Quadcopter input mixing
        //Output to: OCXRS = .... (X is output channel)

        //int motor1, motor2, motor3, motor4; //Front Right, Back Left, Front Left, Back Right

        //Throttle
        motor1 = thro;
        motor2 = thro;
        motor3 = thro;
        motor4 = thro;

        //Roll - left roll (counter clockwise) is negative, right roll (clockwise) is positive
        motor2 += (roll - MIDDLE_PWM)/2;
        motor3 += (roll - MIDDLE_PWM)/2;
        motor1 += (MIDDLE_PWM - roll)/2;
        motor4 += (MIDDLE_PWM - roll)/2;

        //Pitch - Forward rotation is positive, backwards rotation is negative
        motor1 += (MIDDLE_PWM - pitch)/2;
        motor3 += (MIDDLE_PWM - pitch)/2;
        motor2 += (pitch - MIDDLE_PWM)/2;
        motor4 += (pitch - MIDDLE_PWM)/2;


        //Yaw - left (counter clockwise) is negative, right (clockwise) is positive
        motor1 += (pitch - MIDDLE_PWM)/2;
        motor2 += (pitch - MIDDLE_PWM)/2;
        motor3 += (MIDDLE_PWM - pitch)/2;
        motor4 += (MIDDLE_PWM - pitch)/2;


        init_EasyVarNames();
        //setPWM(1,icTimeDiff[1]);
    }

    return (EXIT_SUCCESS);
}

