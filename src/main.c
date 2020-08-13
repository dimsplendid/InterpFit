/**
 * main.c
 * 
 * copyright (c) 2018
 *  Wei-Hsiang Tseng
 *  all right reserved
 * 
 */
#include "Interp.h"
#include "tool.h"
#include <string.h>

int main(int argc, char const *argv[]) {
    // check command input
    if (argc != 7) {
        printf("We need csv raw data and edge distance.\n");
        printf("./Interp [file_name] [interval (default=0.1)]\n");
        exit(EXIT_FAILURE);
    }
    double interval = 0.1;
    if(argc == 3) {
        interval = strtod(argv[2], NULL);
    }

    // read file
    // printf("reading csv...\n");

    const char* file_name = strdup(argv[1]);
    Data *inp, *out;
    Data_init(&inp, file_name);
    Data_calloc(&out);

    // Calc Interpolation Fitting curve within range r ang given interval
    // printf("cal Black U...\n");
    
    interp_fit(inp, out, interval);

    Data_print(out);

    #ifdef WINDOWS
    snprintf((char*)output_name, 80, "output\\%s_BlockAvg.csv",CCD->name);
    #endif
    #ifdef LINUX
    snprintf((char*)output_name, 80, "output/%s_BlockAvg.csv",CCD->name);
    #endif
    
    // release memory
    Data_free(inp);
    Data_free(out);
    return 0;
}
