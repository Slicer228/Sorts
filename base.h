#ifndef BASE_H
#define BASE_H

#define MORE 1
#define LESS -1
#define EQUAL 0

int compDbl(void *x,void *y);
int compInt(void *x,void *y);
void swap(void *x, void *y, int elsize);
int strcomp(char *str1,char *str2,int size);
int cSorted(void *mass,int size, int(comp)(void * , void * ), int elsize);
void reverse(void *mass, int size, int elsize);
int cInt(double num);
void pDbl(double num);
int sort(void *mass,int size,int sortChoice,int creverse,int elemsize,int(comp)(void * , void * ));

#endif