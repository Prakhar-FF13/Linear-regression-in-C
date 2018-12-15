#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct data{
	double w[7];
	double fimin[7];
	double fimax[7];
	int size;
};

double getPrediction(double point[], double weights[], double fimin[], double fimax[], int cols){
	int i;
	for(i = 0 ; i < 6 ; i++)
		point[i] = (point[i] - fimin[i])*1.0/(fimax[i] - fimin[i]);
	double ans = weights[0];
	for(i = 1 ; i < cols ; i++){
		ans += (point[i-1] * weights[i]);
	}
	return ((ans * (fimax[6] - fimin[6])) + fimin[6]);
}

int main(){
	FILE *fp;
	fp = fopen("model_details.bin", "rb");
	struct data x;
	if(fp == NULL){
		printf("\nCould not open file\n");
		return;
	}else{
		fread(&x, sizeof(struct data), 1, fp);
		int i;
	}
	fclose(fp);
	
	double arr[6];
	printf("\nNOTE : \n");
	printf("1 : Negative expected price of a house tells that the the house configuration is not valid..\n");
	printf("2 : Not entering values according to the range gives result which should not be trusted..\n");
	
	printf("Enter Details of the house - \n");
		
	printf("1. SquareFeet Area of Expected House              								: ");
	scanf("%lf", &arr[0]);
		
	printf("2. Enter number of bedrooms needed in the House   								: ");
	scanf("%lf", &arr[1]);
		
	printf("3. Enter number of bathrooms needed in the House                                : ");
	scanf("%lf", &arr[2]);
		
	printf("4. Enter number of floors needed in the house                                   : ");
	scanf("%lf", &arr[3]);
		
	printf("5. Enter Locality Score (5 to 15) 15 being high benefit locality, 5 for any locality        : ");
	scanf("%lf", &arr[4]);
		
	printf("6. Enter House Condition expected (2 to 5) 1 being OK with old house 5 for only new houses  : ");
	scanf("%lf", &arr[5]);
		
		
	double prediction = getPrediction(arr, x.w, x.fimin, x.fimax, 7);
		
	printf("\nExpected Price of the house : %lf", prediction);
	return 0;
}
