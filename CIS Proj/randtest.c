#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    
		int dieVal= (rand() %6)+1;
		int otherDieVal= (rand() %6)+1;
        printf("%d %d \n", dieVal,otherDieVal );
	
    printf("\n");
}