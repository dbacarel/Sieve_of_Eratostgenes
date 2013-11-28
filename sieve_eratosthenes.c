/*

Daniele Bacarella 5 Feb 2013

The algorithm used to generate all prime numbers up to a given number
is: Sieve of Eratosthenes https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes


Complexity O(nloglogn)



*/

#include <stdio.h>


int isBitSet (unsigned char val, int offset) {
    static unsigned char mask[] = {1, 2, 4, 8, 16, 32, 64, 128};
    return ((val & mask[offset]) != 0);
}

unsigned char resetBit(unsigned char x, int offset){
return x & ~(1 << offset ) ;
}

void print_prime(unsigned char * array,unsigned int min,unsigned int max){
	int x=min;
	for(;x<max+1;x++)
		if(isBitSet(array[x/8],x%8)){
		printf("%d ", x);
		fflush(stdout);
	}
	printf("\n");

}






int main(int argc, char** argv){


unsigned long int min=2;
unsigned long int max=1000000000;

unsigned char *values = (unsigned char*)calloc(sizeof(unsigned char)*(max/8+1),1);
memset(values,255,sizeof(unsigned char)*(max/8+1));
unsigned long int current=min;
unsigned long int max_sqrt=sqrt(max);



	for(;current<=max_sqrt;current++){
		int slot = current/8;
		int offset = current%8;

		if(isBitSet(values[slot],offset)){
			
			unsigned long int current_square=current*current;
			unsigned long int i = 0;
			unsigned long int j = current_square+(0*current);

			for(;j<=max;j+=current)
				values[j/8]=resetBit(values[j/8],j%8);

		}
	}

	print_prime(values,min,max);

}
