#pragma once
#include <stdio.h>
#include <Stdlib.h>
#include "tool.h"

double interp(int y[2], int x[2], x_i);
double interp_fit(Data *input, Data *output, double interval);