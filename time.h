// yeah idk what this is for either

#include <iostream>
#include <math.h>
#include <sys/time.h>

using namespace std;
int main(){
	struct timespec ts_start;
	struct timespec ts_end;
	clock_gettime(CLOCK_MONOTONIC, &ts_start);
	for ( int i = 0 ; i< 560;i++){ //code_to_time();
	double x = sin(i);
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	long elapsed = (ts_end.tv_sec-ts_start.tv_sec)*1000000000 +
	ts_end.tv_nsec-ts_start.tv_nsec;
	cout<<"elapsed[ns]="<<elapsed<<endl;
}
