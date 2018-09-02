double **Multiply(double **mat1, double **mat2, int n1, int m1, int n2, int m2){
	if(m1 != n2){
		printf("Matrices given cannot be multiplied");
		return NULL;
	}
	else{
		int i,j,k;
		double **result = malloc(n1 * sizeof(double *));
		for(i = 0 ;i  < n1 ; i++)
			result[i] = malloc(m2 * sizeof(double));
		for(i = 0 ; i < n1; i++){
			for(j = 0; j < m2 ; j++){
				result[i][j] = 0;
				for(k = 0 ; k < m1 ;k++)
					result[i][j] += mat1[i][k] * mat2[k][j]; 
			}
		}
		return result;
	}
}

double **Transpose(double **mat, int n, int m){
	int i,j;
	double **result = malloc(m * sizeof(double *));
	for(i = 0 ; i < m ; i++)
		result[i] = malloc(n * sizeof(double));
		
	for(i = 0 ; i  < n ; i++)
		for(j = 0 ; j < m ; j++)
			result[j][i] = mat[i][j];
			
	return result;
}

double **Add(double **mat1, double **mat2, int n1, int m1, int n2, int m2){
	if(n1 != n2 || m1 != m2)
		return NULL;
	
	int i,j;
	for(i = 0 ; i < n1 ; i++)
		for(j = 0 ; j < m1 ; j++)
			mat1[i][j] = mat1[i][j] + mat2[i][j];
			
	return mat1;	
}

double **Subtract(double **mat1, double **mat2, int n1, int m1, int n2, int m2){
	if(n1 != n2 || m1 != m2)
		return NULL;
	
	int i,j;
	for(i = 0 ; i < n1 ; i++)
		for(j = 0 ; j < m1 ; j++)
			mat1[i][j] = mat1[i][j] - mat2[i][j];
			
	return mat1;	
}
