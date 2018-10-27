// Here we will select the important Features and remove features like Date, Id etc. which are not important for our study.

/*
Important Features which we will keep ->
1. Price.
2. Number of Bedrooms.
3. Bathrooms.
4. Sqft_living.
5. Floors.
6. Grade.
7. Condition.
*/

// This function creates a double array out of a structure variable.
void FillMatrix(double *mati, row r){
	mati[0] = (double)r.sqft_living; mati[1] = (double)r.bedrooms; mati[2] = (double)r.bathrooms; mati[3] = (double)r.floors;
	mati[4] = (double)r.grade; mati[5] = (double)r.condition; mati[6] = (double)r.price;
}

// Prints a single row of double matrix
void printMatrixRow(double *mati){
	int i;
	for(i = 0 ; i < 7 ; i++)
		printf("%15lf | ", mati[i]);
	printf("\n");
}

// Prints the whole Matrix.
void printMatrix(double **mat, int n){
	char *cols[7] = {"sqft_living", "Bedrooms", "Bathrooms", "Floors", "Grade", "Condition", "Price"};
	int j;
	for(j = 0 ; j <= 6 ; j++)
		printf("%15s | ", cols[j]);
	printf("\n");
	for(j = 0 ; j  < 14 ; j++)
		printf("---------");
	printf("\n");
	for(j = 0 ; j < n ; j++)
		printMatrixRow(mat[j]);
}

// Uses read_csv function and converts the read csv file to double array for vector operations.
double **init(){
	row *r = read_csv("kc_house_data.csv");
	printDataset(r, 10);
	printf("\n\n\nNow we will Convert the dataset to array for manipulation.\nWe will also remove unnecessary features\n\n");
	double timespent = 0.0;
	clock_t start = clock();
	double **mat = malloc(21610 * sizeof(double*));
	int i;
	for(i = 0 ;  i < 21610 ; i++){
		mat[i] = malloc(7 * sizeof(double));
		FillMatrix(mat[i], r[i]);
	}
	free(r);
	timespent = (clock() - start)/(CLOCKS_PER_SEC/1000);
	printf("Time taken to remove features and convert the Dataset : %lf ms\n\n", timespent);
	return mat;
}

