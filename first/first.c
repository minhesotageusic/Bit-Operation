/*
 * first.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Minhesota Geusic
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int addOne(int number){
	int count = 1;
	while (number & count){
		number = number ^ count;
		count = count << 1;
	}
	return number ^ count;
}
int set (int number, int nthBit, int value){
	int complementVal = 1 << nthBit;
	value = value << nthBit;
	return (number & ~complementVal) | (value & complementVal);
}
int comp(int number, int nthBit){
	int complementVal = 1 << nthBit;
	int valueOnNthBit = number & complementVal;
	if(valueOnNthBit & (1 << nthBit)){	//nthbit value is 1
		return number & ~(valueOnNthBit);
	}else{								//nthbit value is 0
		return number | (1 << nthBit);
	}
}
int get (int number, int nthBit){
	int complementVal = 1 << nthBit;
	if(number & complementVal) return 1;
	else return 0;
}
int main(int argc, char ** argv){
	if(argc & 1) return 0;
	FILE * fp;
	fp = fopen(argv[1], "r");
	if( fp == NULL) return 0;

	char c [5] = " ";
	unsigned short x = 0;
	int xt = 0;
	int xt2 = 0;
	char * getC = "get";
	char * compC = "comp";
	char * setC = "set";

	fscanf(fp, "%d", &xt);
	x = (unsigned short) xt;
	xt = 0;
	int print = 0;
	while(fscanf(fp, "%s", c) != EOF){
		if(print ^ 0) printf("\n");
		if(strcmp(c, getC) == 0){
			fscanf(fp, "%d", &xt);
			fscanf(fp, "%d", &xt2);
			printf("%d", get(x, xt));
		}
		else if(strcmp(c, compC) == 0){
			fscanf(fp, "%d", &xt);
			fscanf(fp, "%d", &xt2);
			x = comp(x, xt);
			printf("%d", x);
		}
		else if(strcmp(c, setC) == 0){
			fscanf(fp, "%d", &xt);
			fscanf(fp, "%d", &xt2);
			x = set(x, xt, xt2);
			printf("%d",x);
		}
		print = addOne(print);
	}
	fclose(fp);
	return 0;
}

