#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"
#include "base.h"

int cInt(double num){//func for good print nums
	if(num - (double)((int)num) == 0){
		return 1;
	}
	return 0;
}

void pDbl(double num){//func for good print nums
	int count = 0;
	double num1 = num - (double)((int)num);
	num1 *= 1000000;
	for(int i = 0;i < 5;i++){
		if((int)round(num1) % 10 == 0){
			count++;num1 /= 10;
			continue;
		}else break;
	}
	switch(count){
		case 1:
			printf("%.5f\n",num);
			break;
		case 2:
			printf("%.4f\n",num);
			break;
		case 3:
			printf("%.3f\n",num);
			break;
		case 4:
			printf("%.2f\n",num);
			break;
		case 5:
			printf("%.1f\n",num);
			break;
		default:
			printf("%f\n",num);
	}
}

int strcomp(char *str1,char *str2,int size){//func for args check in UI
	for(int i = 0;i<size;i++,str1++,str2++){
		if(*str1 != *str2){
			return 0;
		}
	}
	return 1;
}

int compDbl(void *x,void *y){
	if(*(double *)x == *(double *)y){
		return 0;
	}
	if(*(double *)x > *(double *)y){
		return 1;
	}
	return -1;
}
int compInt(void *x,void *y){
	if(*(int *)x == *(int *)y){
		return 0;
	}
	if(*(int *)x > *(int *)y){
		return 1;
	}
	return -1;
}

void swap(void *x, void *y, int elsize){
	void *tmp = malloc(elsize);
	memcpy(tmp,x,elsize);
	memcpy(x,y,elsize);
	memcpy(y,tmp,elsize);
	free(tmp);
}

int cSorted(void *mass,int size, int(comp)(void * , void * ), int elsize){
	for(int i = 1;i < size;i++){
		if(comp(&(mass[i * elsize]),&(mass[(i-1)*elsize])) == LESS){
			return 0;
		}
	}
	return 1;
}

void reverse(void *mass, int size, int elsize){//reverses mass
	int i = 0;size--;
	
	while(i < size){
		swap(&(mass[i * elsize]),&(mass[size * elsize]),elsize);i++;size--;
	}
}

int sort(void *mass,int size,int sortChoice,int creverse,int elemsize,int(comp)(void * , void * )){
	if(size <= 0){
		return 0;
	}else if(elemsize <= 0){
		return 0;
	}else if(mass == NULL){
		return 0;
	}else if(comp == NULL){
		return 0;
	}
	switch(sortChoice){
		case QUICK:
			Qsort(mass,size,2,comp,elemsize);
			break;
		case HEAP:
			heapSortR(mass,size,comp,elemsize);
			break;
		case INSERTION:
			insertSort(mass,size,comp,elemsize);
			break;
		case MERGE:
			mergeSort(mass,0,size-1,comp,elemsize);
			break;
		case BUBBLE:
			bubbleSort(mass,size,comp,elemsize);
			break;
		case SELECT:
			selectSort(mass,size,comp,elemsize);
			break;
		case COMB:
			combSort(mass,size,comp,elemsize);
			break;
		case SHELL:
			shellSort(mass,size,comp,elemsize);
			break;
		default:
			return 0;
	}
	
	if(!cSorted(mass,size,comp,elemsize)){
		return 0;
	}
	if(creverse){
		reverse(mass,size,elemsize);
	}
	return 1;
}