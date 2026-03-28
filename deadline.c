#include <stdio.h>


#define ROWS 4
#define LEN 100


void print_arr(char arr[][LEN]);
void fio(char name);
int read_rows(char arr[][LEN], int rows);
int read_lines(char *s, int size);


int main() {
	
	char fiog[ROWS][LEN];

	if(!read_rows(fiog,ROWS)) { 
		return 0;
	}

	printf("\n");

	print_arr(fiog);

	return 0;
}


int read_line(char *s, int size) {
	int ok = 1;
	int i =0;
	int c;
	while(ok&&(c=getchar())!=EOF && c != '\n') {
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



int read_rows(char arr[][LEN], int rows) {
	int ok =1;
	for(int i = 0; i<rows && ok; i++) {
		ok = read_line(arr[i], LEN);
	}
	return ok;
}

void print_arr(char arr[][LEN]) {
	for(int i=0; i<ROWS; i++) {
		printf("%s\n", arr[i]);
	}	

}