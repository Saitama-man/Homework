#include <stdio.h>
#include "utils.h"

int read_line(char *s, int size) {
	int ok = 1;
	int i =0;
	int c;
	while(ok&&(c=getchar())!=EOF && c != '\n' ) {
		if(i<size-1){
			s[i++] = (char)c; 
			 
		} 
		else {
			ok=0;
			printf("Превышен лимит строк");
		}
	}
	s[i] = '\0';
	return ok;
}