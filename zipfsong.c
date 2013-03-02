#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double order(double qi[], int n);
int main() {

	int first_line_n;
	char first_line_m[30];

	scanf ("%d%[^\n]%*c",&first_line_n, first_line_m);
			
	
	int n = first_line_n;
	int m = atoi(first_line_m);
		
	//input validation
	if(n < 1 || n > 5000)
		return 0;
	if(m < 1 || m > n)
		return 0;
		
	char songsn[n][100];
			
	long fi[n];
	double zi[n];
	double qi[n];
			
	double calculate_zi;
	int div = 2;
		
	for (int i = 0; i < n; i++) {
		//this loop takes the song plays and names assigns them to arrays and the calculates qi
		scanf("%ld%*c%[^\n]%*c",&fi[i],songsn[i]);
			
		if (fi[i] < 1 || fi[i] > 1000000000000)
			return 0;
		if((strlen(songsn[i])) > 30 ||(strlen(songsn[i]))<1)
			return 0;
					
		if (i == 0) {
			calculate_zi = fi[0];
		}
		else {
			calculate_zi = fi[0] / div;
			div++;
		}
		zi[i] = calculate_zi;
				
		qi[i] = fi[i] / zi[i];
			
	}
		
	double ret[n];
	for (int i=0; i<n;i++) {
		//make a copy of qi array before it gets ordered
		ret[i] = qi[i];
	}
			
	double anws;
	for (int i = 0; i < m;i++) {
		// print out anwser in correct order comparing anws to the copy of qi to get correct order
		anws = order(qi,n);
		for (int j = 0;j < n; j++) {
			if(anws == ret[j]){
				printf("%s\n",songsn[j]);
				ret[j] = 0;
			}
		}
	}
		
}

double order(double qi[], int n){
	//Function to get largest qi value at qi[0] then return that value to be compared
	double temp;
	int i;
			
	for (i = 0; i < n; i++) {
 	   if (qi[i] > qi[0]) {
			temp = qi[0];
	        qi[0] = qi[i];
	        qi[i] = temp;
	   }
	}
	
	double returnvalue = qi[0];
	qi[0] = 0;
	return returnvalue;
	
}