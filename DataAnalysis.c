#include "readfile.c"
#include "vect_operations.c"
#include "vector.c"

void sort_merge(double *arr, int low, int mid, int high){
	int l = mid - low + 1;
	int r = high - mid;
	int *left = malloc(l * sizeof(double));
	int *right = malloc(r *  sizeof(double));
	int i, j, k = low;
	for(i = low ; i <= mid ; i++)
		left[i-low] = arr[i];
	for(i = mid + 1 ; i <= high ; i++)
		right[i-mid-1] = arr[i];
	i = 0, j = 0, k = low;	
	while(i < l && j < r){
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i < l)
		arr[k++] = left[i++];
	while(j < r)
		arr[k++] = right[j++];
			
	free(left);
	free(right);
}

void sort(double *arr, int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		sort(arr, low, mid);
		sort(arr, mid+1, high);
		sort_merge(arr, low, mid, high);
	}
}

double percentileValue(double *arr, int percentile){
	sort(arr, 0, 21610);
}

int main(){
	/*double **mat = init();
	printMatrix(mat, 10);*/
	double *arr = malloc(9 * sizeof(double));
	int i;
	for(i = 0 ; i < 9 ; i++)
		arr[i] = (10 - i);
		
	for(i = 0 ; i < 9 ; i++)
		printf("%lf ", arr[i]);
	printf("\n");	
	sort(arr, 0, 8);
	for(i = 0 ; i < 9 ; i++)
		printf("%lf ", arr[i]);
	return 0;
}
