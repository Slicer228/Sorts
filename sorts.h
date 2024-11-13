#ifndef SORTS_H
#define SORTS_H

#define BUBBLE 5
#define COMB 7
#define SHELL 8
#define QUICK 1
#define MERGE 4
#define HEAP 2
#define SELECT 6
#define INSERTION 3

int getStartIndex(int start,int end,int choice);
void Qsort0(void *mass,int start,int end, int sChoice, int(comp)(void * , void * ), int elsize);
void Qsort(void *mass,int size,int sChoice, int(comp)(void * , void * ), int elsize);
void heapDownR(void *mass,int size,int k, int(comp)(void * , void * ), int elsize);
void heapSortR(void *mass,int size, int(comp)(void * , void * ), int elsize);
void shellSort(void *mass,int size, int(comp)(void * , void * ), int elsize);
void insertSort(void *mass,int size, int(comp)(void * , void * ), int elsize);
void combSort(void *mass,int size, int(comp)(void * , void * ), int elsize);
void selectSort(void *mass,int size, int(comp)(void * , void * ), int elsize);
void bubbleSort(void *mass,int size, int(comp)(void * , void * ), int elsize);
void merge(void *mass, int l, int m, int r, int(comp)(void * , void * ), int elsize);
void mergeSort(void *mass, int l, int r, int(comp)(void * , void * ), int elsize);

#endif