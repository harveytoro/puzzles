#include <stdio.h>

int main() {
	
	int denaryN;
	scanf("%d",&denaryN);
		
	int inputN = denaryN; 
	int base = 2; 
	int binaryN[30] = {}; 
	int count = 0;


	int convertsystem = 1;	//has values 1 2 4 8 16...
	int reverse = 0; 
	int temp; 

	do {
	// this loop converts denary to binary
 	binaryN[count] = inputN % base;
	inputN = inputN / base;
	count++;

	} while (inputN != 0);


	for (int i = (count -1); i >= 0; i--) {
	// this loop converts the reverse binary back to denary
		temp = binaryN[i] * convertsystem;
		reverse += (binaryN[i] * convertsystem);
		convertsystem += convertsystem;
										
	}
				
	printf("%d",reverse);

}