#include <stdio.h>
long scale(long x,long y,long z){
	long t=x+4*y+12*z;
	return t;
}
int main(void){
	printf("%ld",scale(2,3,4));
}