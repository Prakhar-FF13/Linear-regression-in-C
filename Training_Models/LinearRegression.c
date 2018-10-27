// Initialize Random weight by random values...
void initializeWeights(double *w){
	int i;
	for(i = 0 ; i < 7 ; i++)
		w[i] = (double)rand()/(double)RAND_MAX;
}

// Caculates y_predicted as -> X * transpose(w);
double* predict(double **X, double *w){
	double *predicted = malloc(10000 * sizeof(double));
	int i,j;
	for(i = 0 ; i < 10000 ; i++){
		predicted[i] = w[0];
		for(j = 0 ; j < 6 ; j++)
			predicted[i] += (X[i][j] * w[j+1]);
	}
	return predicted;
}
//Calculating errors ....
double* errors(double *y_true, double* y_pred){
	int i;
	double *err = malloc(10000 * sizeof(double));
	for(i = 0 ; i < 10000; i++)
		err[i] = (y_true[i] - y_pred[i]);
	return err;
}

// Calculates Xtranspose * errors....
double* gradient(double **X, double *y){
	double *new_w_fix = malloc(7 * sizeof(double));
	int i,j;
	for(j = 0 ; j < 7 ; j++){
		new_w_fix[j] = 0;
		for(i = 0 ; i  < 10000 ; i++)
			if(j != 0)
				new_w_fix[j] += (y[i] * X[i][j-1]);
			else
				new_w_fix[j] += (y[i]);
		
		new_w_fix[j] = (-2*1.0/10000) * (new_w_fix[j]);
	}
	return new_w_fix;
}
// Train the model ...
double* LinearRegression(double** X_train, double* y_train, double alpha){	
	double *w = malloc(7 * sizeof(double));
	initializeWeights(w);
	int i,j;
	for(i = 0 ; i < 5000 ; i++){
		double *y_pred = predict(X_train, w);
		double *err = errors(y_train, y_pred);
		double *grad = gradient(X_train, err);
		for(j = 0 ; j  < 7 ; j++){
			grad[j] *= alpha; 
			w[j] -= grad[j];
		}
		free(y_pred);
		free(err);
		free(grad);
	}
	return w;
}
