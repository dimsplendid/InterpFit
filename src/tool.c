/**
 * tool.h
 * 
 * copyright (c) 2018
 *  Wei-Hsiang Tseng
 *  all right reserved
 * 
 */

#include "tool.h"
void rmFileAtrr (char file_name[80]) {
    char *pch = NULL;
    if(NULL != (pch = strrchr(file_name,'.'))) {
        *pch = '\0';
    }
}

int Data_init(Data **self, const char *file_name) {
    if(((*self) = malloc(sizeof(Data))) == NULL) {
        exit(EXIT_FAILURE);
    }
    Datus *data = NULL;
    if((data=(Datus *)calloc(sizeof(Datus), MAXDATASIZE)) == NULL) {
        exit(EXIT_FAILURE);
    }
    printf("reading %s...\n", file_name);
    FILE *f = fopen(file_name, "r");
    if(!f){
        printf("Open File Fail...");
        exit(EXIT_FAILURE);
    }

    uint32_t counter = 0;
    while(fscanf(f, "%lf %lf", \
           &data[counter].x, &data[counter].y) != EOF) {
        counter++;
    }
    fclose(f);
    (*self)->data = data;
    strcpy((*self)->name, file_name);
    (*self)->range = counter;
    return 0;
}

int Data_calloc(Data **self) {
    if(((*self) = malloc(sizeof(Data))) == NULL) {
        exit(EXIT_FAILURE);
    }
    Datus *data = NULL;
    if((data=(Datus *)calloc(sizeof(Datus), MAXDATASIZE)) == NULL) {
        exit(EXIT_FAILURE);
    }
    (*self)->data = data;
    return 0;
}

int Data_free(Data *self) {
    if (self->data != NULL){
        free(self->data);
    }
    free(self);
    return 0;
}

void Data_print(Data *self) {
    FILE *f = fopen("output.txt", "w");
    for(uint32_t i = 0; i < self->range; i++) {
        fprintf(f, "%lf\t%lf\n", self->data[i].x, self->data[i].y);
    }
    fclose(f);
    /*
    for(uint32_t i = 0; i < self->range; i++) {
        printf("%lf\t%lf\n", self->data[i].x, self->data[i].y);
    }
    */
}