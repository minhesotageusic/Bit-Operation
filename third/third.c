/*
 * third.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Minhesota Geusic
 */
#include <stdio.h>
#include <stdlib.h>
unsigned short set (int number, int nthBit, int value){
	int complementVal = 1 << nthBit;
	value = value << nthBit;
	return (number & ~complementVal) | (value & complementVal);
}
int get (int number, int nthBit){
	int complementVal = 1 << nthBit;
	if(number & complementVal) return 1;
	else return 0;
}

int addOne(int number){
	int count = 1;
	while (number & count){
		number = number ^ count;
		count = count << 1;
	}
	return number ^ count;
}
//doesnt work for negative or zero only for positive
int subtractOne(int number){
	int count = 1;
	int c = 0;
	while(get (number ^ count, c) & 1){
		number = number ^ count;
		count = count << 1;
		c = addOne(c);
	}
	return number ^ count;
}
int main(int argc, char ** argv){
	if(argc == 1) return 0;
	unsigned short num = (unsigned short) atoi(argv[1]);
	unsigned short firstHalf = 0;
	unsigned short secondHalf = 0;
	int count = 1;
	int c = 0;
	while(count ^ 256){		//first half
		if(num & count)
			firstHalf = set(firstHalf, c, 1);
		else
			firstHalf = set(firstHalf, c, 0);
		count = count << 1;
		c = addOne(c);
	}
	c = 0;
	while(count ^ 65536){	//second half
		if (num & count)
			secondHalf = set(secondHalf, c, 1);
		else
			secondHalf = set(secondHalf, c, 0);
		count = count << 1;
		c = addOne(c);
	}
	count = 7;
	int count2 = 0;
	int tempC = count;
	while(tempC ^ 0){
		if(get (firstHalf, count) ^ get(secondHalf, count2)){
			printf("Not-Palindrome");
			return 0;
		}
		tempC = count;
		if(count ^ 0) count--;
		count2 = addOne(count2);
	}
	printf("Is-Palindrome");
	return 0;
}

