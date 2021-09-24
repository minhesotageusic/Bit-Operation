/*
 * second.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Minhesota Geusic
 */
#include <stdio.h>
#include <stdlib.h>
int addOne(int number){
	int count = 1;
	while (number & count){
		number = number ^ count;
		count = count << 1;
	}
	return number ^ count;
}
int main(int argc, char ** argv){
	if(argc == 1) return 0;
	unsigned short num = (unsigned short)atoi(argv[1]);
	int num1Count = 0;
	int numPair = 0;
	int num1perpair = 0;
	int count = 1;
	while(count ^ 65536){
		if(num & count)	{//there is a 1 at the given count bit
			num1Count = addOne(num1Count);
			num1perpair = addOne(num1perpair);
			if(num1perpair & 2) {
				numPair = addOne(numPair);
				num1perpair = 0;
			}
		}
		else{			 //there is a 0 at the given count bit
			num1perpair = 0;
		}
		count = count << 1;
	}
	if(num1Count & 1) printf("Odd-Parity	");
	else printf("Even-Parity	");
	printf("%d", numPair);
	return 0;
}
