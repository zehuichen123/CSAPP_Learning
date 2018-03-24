#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
unsigned int snooze(unsigned int secs){
	int sleep_dur=sleep(secs);
	printf("slept for %d of %d secs\n",secs-sleep_dur,secs);
}
int main(void){
	snooze(4);
}
