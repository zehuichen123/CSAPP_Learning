#include <iostream>
using namespace std;
typedef struct p1{
	char* a;
	short b;
	double c;
	char d;
	float e;
	char f;
	long g;
	int h;
}p1;
typedef struct p2{
	char d;
	char f;
	short b;
	int h;
	long g;
	double c;
	char* a;
	float e;
}p2;
int main(void){
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(p2)<<endl;
}