#pragma once
#include "tool.h"

double interp(double y[2], double x[2], double x_i);
int interp_fit(Data *input, Data *output, double interval);