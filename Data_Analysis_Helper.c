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
