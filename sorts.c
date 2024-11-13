#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "sorts.h"
#include "base.h"

//-----
int getStartIndex(int start,int end,int choice){
	switch(choice){
		case 1:
			return start;
		case 2:
			return start + (end - start)/2;
		case 3:
			return end;
		default:
			return start;
	}
}
void Qsort0(void *mass,int start,int end, int sChoice, int(comp)(void * , void * ), int elsize){
	if(start >= end){
		return;
	}

	
	int s = getStartIndex(start,end,sChoice);
	swap(&(mass[s*elsize]),&(mass[end*elsize]),elsize);

	int iL = start - 1;
	
	for(int i = start;i < end;i++){

		if(comp(&(mass[i*elsize]),&(mass[end*elsize])) == LESS){
			iL++;
			swap(&(mass[i*elsize]),&(mass[iL*elsize]),elsize);
		}
	}
	
	swap(&(mass[(iL+1)*elsize]),&(mass[end*elsize]),elsize);

	
	Qsort0(mass,start,iL,sChoice,comp,elsize);
	Qsort0(mass,iL + 2,end,sChoice,comp,elsize);
}
void Qsort(void *mass,int size,int sChoice, int(comp)(void * , void * ), int elsize){
	Qsort0(mass,0,size-1,sChoice,comp,elsize);
}
//-----
void heapDownR(void *mass,int size,int k, int(comp)(void * , void * ), int elsize){//рекурсия
	int nMax = k, l = 2*k+1,r = 2*k + 2;
	if(l < size && comp(&(mass[l*elsize]),&(mass[nMax*elsize])) == MORE){
		nMax = l;
	}
	if(r < size && comp(&(mass[r*elsize]),&(mass[nMax*elsize])) == MORE){
		nMax = r;
	}

	if(nMax != k){
		swap(&(mass[nMax*elsize]),&(mass[k*elsize]),elsize);
		
		heapDownR(mass,size,nMax,comp,elsize);
	}
}
void heapSortR(void *mass,int size, int(comp)(void * , void * ), int elsize){//реккурсия
	for(int i = size/2 - 1;i >= 0;i--){
		heapDownR(mass,size,i,comp,elsize);
	}
	
	for(int i = size-1;i >= 0;i--){
		swap(&(mass[0]),&(mass[i*elsize]),elsize);
		heapDownR(mass,i,0,comp,elsize);
	}
}
//-----
void shellSort(void *mass,int size, int(comp)(void * , void * ), int elsize){
	for (int s = size / 1.247; s > 0; s /= 1.247) {
        for (int i = s; i < size; i++) {
            for (int j = i - s; j >= 0 && comp(&(mass[j*elsize]),&(mass[(j + s)*elsize])) == MORE; j -= s){
				swap(&(mass[j*elsize]),&(mass[(j+s)*elsize]),elsize);
			}
        }
    }
}
//-----
void insertSort(void *mass,int size, int(comp)(void * , void * ), int elsize){/* O(N^2) */
	for(int i = 1;i < size;i++){
		for(int j = i;j > 0 && comp(&(mass[j*elsize]),&(mass[(j - 1)*elsize])) == LESS;j--){
			swap(&(mass[j*elsize]),&(mass[(j-1)*elsize]),elsize);
		}
	}
}
//-----
void combSort(void *mass,int size, int(comp)(void * , void * ), int elsize){
	int gap = size;
	
	while(gap > 1){
		gap = gap / 1.247;
		
		if(gap < 1){
			gap = 1;
		}

		for(int i = 0;i + gap < size;i++){
			if(comp(&(mass[i*elsize]),&(mass[(i + gap)*elsize])) == MORE){
				swap(&(mass[i*elsize]),&(mass[(i+gap)*elsize]),elsize);
			}
		}
	}
	insertSort(mass,size,comp,elsize);
}
//-----
void selectSort(void *mass,int size, int(comp)(void * , void * ), int elsize){/* O(N^2) в лучшем - O(N^2)*/
	int min;
	
	for(int i = 0;i < size-1; i++){
		min = i;
		for(int j = i+1;j < size;j++){
			if(comp(&(mass[j*elsize]),&(mass[min*elsize])) == LESS){
				min = j;
			}
		}
		if(min != i){
			swap(&(mass[min*elsize]),&(mass[i*elsize]),elsize);
		}
	}
}
//-----
void bubbleSort(void *mass,int size, int(comp)(void * , void * ), int elsize){/* O(N^2) в лучшем - O(N)*/
	int sorted = 0;
	
	for(int i = 0;i<size-1;i++){
		for(int j = 0;j<size-i-1;j++){
			if(comp(&(mass[j*elsize]),&(mass[(j+1)*elsize])) == MORE){
				swap(&(mass[j*elsize]),&(mass[(j+1)*elsize]),elsize);
				sorted = 1;
			}
		}
		if(!sorted){
			break;
		}else{
			sorted = 0;
		}
	}
}
//-----
void merge(void *mass, int l, int m, int r, int(comp)(void * , void * ), int elsize) {
    int n1 = m - l + 1;
    int n2 = r - m;
    void *L = malloc(n1*elsize);
	void *R = malloc(n2*elsize);
    for (int i = 0; i < n1; i++) {
		memcpy(&(L[i*elsize]),&(mass[(l + i)*elsize]),elsize);
    }
    for (int j = 0; j < n2; j++) {
		memcpy(&(R[j*elsize]),&(mass[(m + 1 + j)*elsize]),elsize);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (comp(&(L[i*elsize]),&(R[j*elsize])) < MORE) {
			memcpy(&(mass[k*elsize]),&(L[i*elsize]),elsize);
            i++;
        } else {
			memcpy(&(mass[k*elsize]),&(R[j*elsize]),elsize);
            j++;
        }
        k++;
    }
    while (i < n1) {
		memcpy(&(mass[k*elsize]),&(L[i*elsize]),elsize);
        i++;
        k++;
    }
    while (j < n2) {
		memcpy(&(mass[k*elsize]),&(R[j*elsize]),elsize);
        j++;
        k++;
    }
	free(L);free(R);
}
void mergeSort(void *mass, int l, int r, int(comp)(void * , void * ), int elsize) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(mass,l,m,comp,elsize);
        mergeSort(mass,m + 1,r,comp,elsize);
        merge(mass,l,m,r,comp,elsize);
    }
}