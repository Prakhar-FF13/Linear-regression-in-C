#include "readfile.c"
#include "vect_operations.c"
#include "vector.c"
#include "Data_Analysis_Helper.c"

// Finds Outlier using Percentile values...
void findOutliers(double **mat){
	int i, j, k, len = 21610;
	double *arr = malloc(len * sizeof(double));
	printf("\n\n ----- Identiying outliers ----- \n\n");
	
	for(i = 0 ; i < 7 ; i++){
		printf("For feature number %d\n", i+1);
		for(j = 0 ; j < len ; j++)
			arr[j] = mat[j][i];
		printf("Printing Percentiles : \n\n");
		for(k = 0 ; k <= 99 ; k+=10)
			percentileValue(arr, k, len);
			
		for(k = 1; k <= 10; k++)
			percentileValue(arr, 99 + (k*1.0/10), len);
		if(i != 6)	
		printf("\n-----------\n");
	}
	
	printf("\n --------------- Possible Outliers -------------------- \n");
	printf("1. From sqft_living         feature - House with 290 sqft area and 13540 sqft area\n");
	printf("2. From Number of bedrooms  feature - House with 0 bedrooms and 33 bedrooms\n");
	printf("3. From Number of bathrooms feature - House with 0 bathrooms and 8 bathrooms\n");
	printf("4. From Price Feature       feature - House with Price 1 and houses with prices above 960000\n");
	printf("\n");
}

// Finds and returns the indexes of outliers points...
int *indexOutliers(double **mat){
	printf("\n--------------- A Closer look at above houses ------------------- \n\n");	
	int i,j,k,len = 21610, count = 0;
	int *arr = malloc((len+5) * sizeof(int));
	for(i = 0 ; i < len ; i++)
		arr[i] = 0;

	for(i = 0 ; i < len ; i++)
		if(mat[i][0] >= 6500)
			count++, arr[i] = 1;
	printf("\n Number of house with sqft_area near to max value : %d", count);
	count = 0;
	
	for(i = 0 ; i < len ; i++)
		if(mat[i][1] == 0 || mat[i][1] >= 8)
			count++, arr[i] = 1;
	printf("\n Number of houses with large number of bedrooms : %d", count);
	count = 0;
		
	for(i = 0 ; i < len ; i++)
		if(mat[i][2] == 0 || mat[i][2] >= 8)
			count++, arr[i] = 1;
	printf("\n Number of houses with large number of bathrooms : %d", count);
	count = 0;
	
	
	for(i = 0 ; i < len ; i++)
		if(mat[i][6] <= 10 || mat[i][6] >= 960000)
			count++, arr[i] = 1;
	printf("\n Number of houses with large number of bedrooms : %d", count);
	return arr;
}

// Uses the indexes of outliers points to remove them...
double **findAndRemoveOutliers(double **mat){
	findOutliers(mat);
	int *arr = indexOutliers(mat);
	int i,j,k,len = 21610, count = 0;
	for(i = 0 ; i < 21610 ; i++)
		if(arr[i] == 1)
			count++;
	printf("\nTotal Number of Outliers found %d \n", count);
	double **newmat = malloc((len - count) * sizeof(double));
	k = 0;
	for(i = 0 ; i < len ; i++){
		if(arr[i] == 1){
			free(mat[i]);
			continue;	
		} 
		newmat[k] = malloc(7 * sizeof(double));
		for(j = 0 ; j < 7 ; j++)
			newmat[k][j] = mat[i][j];
		k++;
		free(mat[i]);
	}
	free(mat);
	free(arr);
	printf("\nNew matrix size after feature removal (%d,%d)\n\n", (len - count), 7);
	return newmat;
}

int main(){
	double **mat = init();
	printMatrix(mat, 10);
	mat = findAndRemoveOutliers(mat);
	printMatrix(mat, 10);
	return 0;
}
