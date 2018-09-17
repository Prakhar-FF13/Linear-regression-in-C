// Merge Sort Helper.
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
// Sorts the array (Mergse Sort)
void sort(double *arr, int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		sort(arr, low, mid);
		sort(arr, mid+1, high);
		sort_merge(arr, low, mid, high);
	}
}
//prints percentage of points greater than percentile value ...
void percentileValue(double *arr, double percentile, int len){
	int i, index;
	double x;
	double *tarr = malloc(len * sizeof(double));
	for(i = 0 ; i <  len ; i++)
		tarr[i] = arr[i];
	sort(tarr, 0, len-1);
	x = percentile/100 * (len-1);
	index = x;
	printf("%.1lf%% of values are greater than : %.1lf\n", 100 - percentile, tarr[index]);
	free(tarr);
}
// Returns the target variabe as an array..
double* returnTarget(double **mat, int colnum, int rows){
	int i;
	double *y = malloc(rows * sizeof(double));
	for(i = 0 ; i < rows ; i++)
		y[i] = mat[i][colnum];
		
	return y;
}
// Returns the feature matrix ecluding target variable (it assumes last column is target variable )..
double** returnFeatures(double **mat, int rows){
	int i, j;
	double **newmat = malloc(rows * sizeof(double *));
	for(i = 0 ; i < rows ; i++){
		newmat[i] = malloc(6 * sizeof(double));
		for(j = 0 ; j < 6 ; j++)
			newmat[i][j] = mat[i][j];
		free(mat[i]);
	}
	free(mat);
	return newmat;
} 
// Returns minimum value in a column..
double minValue(double **arr, int colnum){
	double mine = 1e7;
	int i;
	for(i =  0 ; i < 19806 ; i++)
		if(arr[i][colnum] < mine)
			mine = arr[i][colnum];
			
	return mine;
}
//Returns maximum value in a column..
double maxValue(double **arr, int colnum){
	double maxe = -1;
	int i;
	for(i =  0 ; i < 19806 ; i++)
		if(arr[i][colnum] > maxe)
			maxe = arr[i][colnum];
			
	return maxe;
}
