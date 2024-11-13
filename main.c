#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "sorts.h"
#include "base.h"

int main(int argc,char *argv[])
{
	/*
	argv[1] - название сортировки
	argv[2] - размер массива
	argv[3,4] - необязательный аргумент,
	--norand - выключает рандомную генерацию массива;
	--reverse - сортирует в обратном направлении
	*/
	
	srand(time(NULL));
	
	clock_t start_time, end_time;
	int intMass = 1;
	int creverse = 0;
	double delemVal;
	int ielemVal;
	int valOfSorts = 8;
	int norand = 0;
	int choice = 0;
	char *reverseS = "--reverse";
	char *norandS = "--norand";
	char *qsortS = "qsort";
	char *heapsortS = "heapsort";
	char *insertsortS = "insertsort";
	char *mergeS = "mergesort";
	char *bubbleS = "bubblesort";
	char *selectS = "selectsort";
	char *combS = "combsort";
	char *shellS = "shellsort";
	char *sorts[] = {qsortS,heapsortS,insertsortS,mergeS,bubbleS,selectS,combS,shellS};
	
	/*if(argc < 3 || argc > 5){//работы программы для тестового UI
		puts("Incorrect quantity of args!");
		return 1;
	}else if(atoi(argv[2]) <= 0){
		puts("Incorrect value of mass size!");
		return 1;
	}else if(argc == 5){
		if(!strcomp(argv[3],reverseS,strlen(argv[3])) && !strcomp(argv[3],norandS,strlen(argv[3]))){
			puts("Unexpected arg 3!");
			return 1;
		}else{
			if(strcomp(argv[3],reverseS,9)) creverse = 1;
			if(strcomp(argv[3],norandS,8)) norand = 1;
		}
		if(!strcomp(argv[4],reverseS,strlen(argv[4])) && !strcomp(argv[4],norandS,strlen(argv[4]))){
			puts("Unexpected arg 4!");
			return 1;
		}else{
			if(strcomp(argv[4],reverseS,9)) creverse = 1;
			if(strcomp(argv[4],norandS,8)) norand = 1;
		}
		if(strcomp(argv[3],argv[4],strlen(argv[3]))){
			puts("Equal args!");
			return 1;
		}else if(strcomp(argv[3],argv[4],strlen(argv[3]))){
			puts("Equal args!");
			return 1;
		}
	}else if(argc == 4){
		if(!strcomp(argv[3],reverseS,strlen(argv[3])) && !strcomp(argv[3],norandS,strlen(argv[3]))){
			puts("Unexpected arg 3!");
			return 1;
		}else{
			if(strcomp(argv[3],reverseS,9)) creverse = 1;
			if(strcomp(argv[3],norandS,8)) norand = 1;
		}
	}

	for(int i = 0;i < valOfSorts;i++){
		if(strcomp(argv[1],sorts[i],strlen(sorts[i]))){
			choice = i+1;
			break;
		}
	}
	
	if(!choice){
		puts("Unexpected arg 1!");
		return 1;
	}

	puts("Put 0 if you want to make double mass: ");
	while(1){
		if(scanf("%d",&ielemVal) == 0){
			puts("Invalid input! Please enter a correct number!");
			fflush(stdin);
		}else{
			intMass = ielemVal;
			break;
		}
	}

	int size = atoi(argv[2]);
	double mass[size];
	int mass1[size];

	if(norand){
		puts("Start writing mass elements:\n");
		for(int i = 0;i < size;i++){
			if(intMass){
				if(scanf("%d",&ielemVal) == 0){
					puts("Invalid input! Please enter a correct number!");
					fflush(stdin);
					i--;
				}else{
					mass1[i] = ielemVal;
				}
			}else{
				if(scanf("%lf",&delemVal) == 0){
					puts("Invalid input! Please enter a correct number!");
					fflush(stdin);
					i--;
				}else{
					mass[i] = delemVal;
				}
			}
		}
	}else{
		puts("Source mass:\n");
		if(intMass){
			for(int i = 0;i < size;i++){
				mass1[i] = rand();
				printf("%d\n",mass1[i]);
			}
		}else{
			for(int i = 0;i < size;i++){
				mass[i] = (rand()/(double)RAND_MAX) * 3000000;
				pDbl(mass[i]);
			}
		}
	}
	
	puts("----------------------------------------");
	
	start_time = clock();
	if(sort(intMass ? mass1 : mass,size,choice,creverse,intMass ? 4 : 8,intMass ? compInt : compDbl)){
		end_time = clock();
		printf("\nThe result of %s with size = %d:\n\n",sorts[choice-1],size);
		for(int i = 0;i < size;i++){
			intMass ? printf("%d\n",mass1[i]) : pDbl(mass[i]);
		}
		printf("\nTime spent(in secs): ");pDbl(((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	}else printf("\nMass with size = %d wasn't sorted by %s...",size,sorts[choice-1]);
	*/
	
	
	puts("TESTS");//АВТОМАТИЗИРОВАННЫЙ ТЕСТ ДЛЯ ПРОГОНА СРАЗУ ВСЕХ МЕТОДОВ
	int sizze;
	puts("Enter size of test int mass: ");
	scanf("%d",&sizze);
	puts("\nSource mass: ");
	int mass[sizze],k[sizze];
	for(int i = 0; i < sizze; i++) {mass[i] = rand();printf("%d\n",mass[i]);}
	for(int i = 0; i < 8;i++){
		puts("\n----------------------\n");
		memcpy(k,mass,sizeof(mass));
		printf("Sorted by %s: \n",sorts[i]);
		start_time = clock();
		sort(k,sizze,i+1,0,sizeof(int),compInt);
		end_time = clock();
		for(int j = 0;j < sizze; j++) printf("%d\n",k[j]);
		printf("\nTime spent(in secs): ");pDbl(((double)(end_time - start_time)) / CLOCKS_PER_SEC);
		puts("\n");
		memcpy(k,mass,sizeof(mass));
		printf("Reverse sortes by %s: \n",sorts[i]);
		start_time = clock();
		sort(k,sizze,i+1,1,sizeof(int),compInt);
		end_time = clock();
		for(int j = 0;j < sizze; j++) printf("%d\n",k[j]);
		printf("\nTime spent(in secs): ");pDbl(((double)(end_time - start_time)) / CLOCKS_PER_SEC);
		puts("\n----------------------\n");
	}
	
	return 0;
}