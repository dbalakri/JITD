#include "itoa.h"
#include <string.h>

char* itoa(int n){
	char* digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	char* numstring = new char[0];
	int m = 0;
	while(n>0){
	    int d = n%10;
	    m = (m*10)+d;
	    n = n/10;
	}
	while(m>0){
	    int d = m%10;
	    strcat(numstring, digits[d]);
	    m = m/10;
	}
	return numstring;
}