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
// Performs outlier removal and train-test split ...
double fimin[6], fimax[6];

// Scaling the cdataset first..
void MinMaxScaling(double **mat, int newlen){
	int i,j;
	printf("\n-------------------------------\nMin-Max Scaling\n\n");
	for(j = 0 ; j <= 6 ; j++){
		double x = minValue(mat, j);
		double y = maxValue(mat, j);
		fimin[j] = x; fimax[j] = y;
		for(i = 0 ;  i < newlen ; i++)
			mat[i][j] = (mat[i][j] - x)*1.0/(y-x);
	}
}

void train_test_split(double **X_train, double *y_train, double **X_test, double *y_test, int trainpts, int testpts, double **mat, int newlen){
	int i,j;
	printf("\n--------------------------------------------------\nTrain Test Splitting \n");
	double *y = returnTarget(mat, 6, newlen);
	mat = returnFeatures(mat, newlen);
	for(i = 0 ; i < trainpts ; i++){
		X_train[i] = malloc(6 * sizeof(double));
		for(j = 0 ; j < 6 ; j++)
			X_train[i][j] = mat[i][j];
	}
	for(i = trainpts ; i < trainpts+testpts ; i++){
		X_test[i-trainpts] = malloc(6 * sizeof(double));
		for(j = 0 ; j < 6 ; j++)
			X_test[i-trainpts][j] = mat[i][j];
	}
	
	for(i = 0 ; i < trainpts ; i++)
		y_train[i] = y[i];
		
	for(i = trainpts ; i < trainpts+testpts ; i++)
		y_test[i-trainpts] = y[i];
		
	free(mat);
	free(y);
	
}
