/*
 * Interpolation Curve Fitting
 * Author: Andrew Tseng
 * Date: 2020/08/13
 */

#include "Interp.h"

double interp(double y[2], double x[2], double x_i) {
    return y[0] + (y[1]-y[0]) / (x[1] - x[0]) * (x_i - x[0]);
}

int interp_fit(Data *input, Data *output, double interval){
    output->range = (int)((input->data[input->range-1].x - input->data[0].x) / interval)+1;
    uint32_t input_i = 0;
    double x[2], y[2];
    x[0] = input->data[0].x;
    x[1] = input->data[1].x;
    y[0] = input->data[0].y;
    y[1] = input->data[1].y;

    for(uint32_t i = 0; i < output->range; i++){
        output->data[i].x = input->data[0].x+ ((double)i) * interval;
        if(output->data[i].x > input->data[input_i+1].x) {
            input_i++;
            x[0] = x[1];
            x[1] = input->data[input_i+1].x;
            y[0] = y[1];
            y[1] = input->data[input_i+1].y;
        }
        output->data[i].y = interp(y, x, output->data[i].x);
    }
    return 0;
}