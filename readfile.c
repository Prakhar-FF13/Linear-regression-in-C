#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structure.c"
/*typedef struct Row{
	int id; // The Number of datapoint.
	double crim; // Per Capita Crime Rate by town.
	double zn;  // proportion of residential land zoned for lots over 25,000 sq.ft.
	double indus; // proportion of non-retail business acres per town.
	double chas; // Charles River dummy variable (= 1 if tract bounds river; 0 otherwise).
	double nox; // nitrogen oxides concentration (parts per 10 million).
	double rm; // average number of rooms per dwelling.
	double age; // proportion of owner-occupied units built prior to 1940.
	double dis; // weighted mean of distances to five Boston employment centres.
	int rad; // index of accessibility to radial highways.
	int tax; // full-value property-tax rate per $10,000.
	double ptratio; // pupil-teacher ratio by town.
	double black; // 1000(Bk - 0.63)^2 where Bk is the proportion of blacks by town.
	double lstat; // lower status of the population (percent).
	double medv; // median value of owner-occupied homes in $1000s.
}row;*/ 

char** read_csv(char *str){
	// Open the file on disk.
	FILE *fp;
	fp = fopen(str, "r");
	if(fp == NULL){
		printf("Could not open file\n");
		return;
	}
	
	printf("Loading the Dataset");
	double timespent = 0.0;
	clock_t start = clock();
	char **data = malloc(21615 * sizeof(char *));
	int j;
	for(j = 0 ; j < 21615 ; j++)
		data[j] = malloc(1000 * sizeof(char));
	j = 0;
	do{
		fscanf(fp, "%s", data[j]);
		j++;
	}while(!feof(fp));
	
	clock_t end = clock();
	
	timespent = (end-start)/(CLOCKS_PER_SEC/1000);
	printf("\nLoading - Done\nTime Taken to load the dataset : %fms\n", timespent);
	printf("_________________________________________________________\n");
	return data;
}

int main(){
	char **data = read_csv("kc_house_data.csv");
	int i;
	for(i =0  ; i < 10 ; i++)
		printf("%s\n", data[i]);
	return 0;
}
