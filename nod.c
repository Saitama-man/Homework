#include <stdio.h>

int nod(int a, int b) {
	int ostatok;
	if(a>b) {
		ostatok = a % b;
		if(ostatok !=0) return nod(ostatok, b);
		return b;
	}
	else {
		ostatok = b % a;
		if(ostatok !=0) return nod(ostatok, a);
		return a;
	}
	
}	


int main() {
	int a, b; 
	if(scanf("%d %d", &a, &b) !=2){
		printf("n/a");
		return 0;
	}
	if(a == b){
		printf("Нод равен %d \n", a);
		return 0;
	}
	printf("Нод равен %d \n", nod(a,b));
	return 0;

}

