#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structure.c"
 
// id,date,price,bedrooms,bathrooms,sqft_living,sqft_lot,floors,waterfront,view,condition,grade,sqft_above,sqft_basement,yr_built,yr_renovated,zipcode,lat,long,sqft_living15,sqft_lot15
// 7129300520,20141013T000000,221900,3,1,1180,5650,1,0,0,3,7,1180,0,1955,0,98178,47.5112,-122.257,1340,5650

char** split(char *str, char delimiter){
	char **parts = malloc(30 * sizeof(char *));
	char temp[30][30];
	char s[25];
	int i = 0, k = 0, j = 0;
	for(i = 0 ; i < strlen(str) + 1 ; i++)
		if(str[i] == ',' || str[i] == '\0'){
			s[j++] = '\0';
			strcpy(temp[k], s);
			k = k + 1;
			s[0] = '\0';
			j = 0;
		}else{
			s[j++] = str[i];
		}
		
	for(i = 0 ; i < 25 ; i++){
		parts[i] = malloc(30 * sizeof(char));
		strcpy(parts[i], temp[i]);
	}
	return parts;
}

row parseString(char *str){
	char **token = split(str, ',');
	int i = 0;
	for(i =0  ;i  < 21 ; i++)
		printf("%s\n", token[i]);
}

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
		data[j] = malloc(500 * sizeof(char));
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
		
	row r = parseString("7129300520,20141013T000000,221900,3,1,1180,5650,1,0,0,3,7,1180,0,1955,0,98178,47.5112,-122.257,1340,5650");
	return 0;
}
