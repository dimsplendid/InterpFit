/**
 * tool.h
 * 
 * copyright (c) 2018
 *  Wei-Hsiang Tseng
 *  all right reserved
 * 
 */
#pragma once
#include <string.h>
#include <inttypes.h>
#define MAXDATASIZE 1000000

void rmFileAtrr (char file_name[80]);


// Data Structure
typedef struct _Datus {
    double x;
    double y;
} Datus;

typedef struct _Data {
    char name[20];
    uint32_t range;
    Datus *data;
} Data;

// Data constructor
int Data_init(Data **self, const char *file_name);
int Data_calloc(Data **self);
// Data destructor
int Data_free(Data *self);

// Data Methods
void Data_print(Data *self);