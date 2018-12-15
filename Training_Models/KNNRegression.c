int best_k, best_error = 100000;
typedef struct distance{
	double distance;
	int index;
}distance;

distance dist[10000][10000];
void merge(struct distance arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    struct distance L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) { 
        if (L[i].distance <= R[j].distance) { 
            arr[k] = L[i]; 
            i++; 
        } else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(struct distance arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

double getDistance(double *x1, double *x2, int n){
	int i;
	double ans = 0;
	for(i = 0 ; i < n ; i++){
		ans += ((x1[i] * x2[i]) * (x1[i] * x2[i]));
	}
	return sqrt(ans);
}

double KNNRegression(double **X_train, double *y_train, int train_size){
	int i,j,l,m,n,k;
	double error[train_size];
	int k_arr[] = {3, 4, 5, 6, 7, 15, 20, 50, 100};
	
	//Calculating distances;
	for(i = 0 ; i < train_size ; i++){
		for(j = i+1 ;  j < train_size ; j++){
			dist[i][j].distance = getDistance(X_train[i], X_train[j], 7);
			dist[i][j].index = j;
			dist[j][i].distance = dist[i][j].distance;
			dist[j][i].index = i;
			dist[j][j].distance = 100000;
			dist[j][j].index = j;
			dist[i][i].distance = 100000;
			dist[i][i].index = i;
		}
	}
	printf("Distance Calculation done.\n");
	
	printf("Sorting Distances\n");
	for(i = 0;  i < train_size ;i++){
		mergeSort(dist[i], 0, train_size - 1);
		if((i+1) % 1000 == 0){
			printf("Sorting %% Complete : %d %%\n", (i+1)/100);
		}
	}
	
	// Finding the best K.
	printf("Finding Best K\n");
	for(k = 0 ; k < 9 ; k++){
		double error = 0;
		for(i = 0 ; i < train_size ; i++){
			double prediction = 0.0;
			for(j = 0 ; j < k_arr[k] ; j++)
				prediction += y_train[dist[i][j].index]; 
			prediction = prediction/k_arr[k];
			error += ((y_train[i] - prediction) * (y_train[i] - prediction));
		}
		
		printf("\nFor k : %d, error : %lf",k_arr[k], error);
		
		if(error < best_error){
			best_k = k_arr[k];
			best_error = error;
		}
	}
	
}
