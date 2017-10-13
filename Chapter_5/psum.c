#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float a[100000000];
float p[100000000];
float a1[100000000];
float p1[100000000];
void psum1(float a[],float p[],long n){
    clock_t start,end;
    start=clock();
    long i;
    p[0]=a[0];
    for(int i=0;i<n;i++){
        p[i]=p[i-1]+a[i];
    }
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printf("psum1 is %lf\n",duration);
}
void psum2(float a[],float p[],long n){
    clock_t start,end;
    start=clock();
    long i;
    p[0]=a[0];
    for(int i=1;i<n-1;i+=2){
        float mid_val=p[i-1]+a[i];
        p[i]=mid_val;
        p[i+1]=a[i+1]+mid_val;
    }
    if(i<n){
        p[i]=p[i-1]+a[i];
    }
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printf("psum2 is %lf\n", duration);
}
int main(void){
    psum1(a1,p1,100000000);
    psum2(a,p,100000000);
}