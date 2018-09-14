#include "readfile.c"
#include "vect_operations.c"
#include "vector.c"
#include "Data_Analysis_Helper.c"


int main(){
	double **mat = init();
	printMatrix(mat, 10);
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
			
		printf("\n-----------\n");
	}
	
		
	return 0;
}
