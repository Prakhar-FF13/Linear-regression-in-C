#include "readfile.c"
#include "vect_operations.c"
#include "vector.c"
#include "Data_Analysis_Helper.c"
#include "DataAnalysis.c"
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

int main(){
	double **X_train = malloc(10000 * sizeof(double *));
	double **X_test = malloc(5000 * sizeof(double *));
	double *y_train = malloc(10000 * sizeof(double));
	double *y_test = malloc(5000 * sizeof(double));
	performOperations(X_train, y_train, X_test, y_test, 10000, 5000);
	int i,j;
	printf("\nThe size of Train Set : (%d, %d)\n", 10000, 6);
	printf("\nThe size of Test Set : (%d, %d)\n", 5000, 6);
	double alpha[11] = {0.5, 0.4, 0.3, 0.2, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001};
	printf("\n\n ---------------- Training Regression Models ---------------------- \n\n");
	printf("------------- Linear Regression-------------\n");
	double *w_best;
	double maxerr = 1e7;
	for(i = 0 ; i < 11 ; i++){
		double *w = LinearRegression(X_train, y_train, alpha[i]);
		double *y_pred = predict(X_train, w);
		double *err = errors(y_train, y_pred);
		double sum = 0;
		for(j = 0 ; j < 10000 ; j++)
			sum += err[j] * err[j];
		printf("Error for alpha %.7lf is : %.6lf\n", alpha[i], sum);	
		if(sum <= maxerr){
			maxerr = sum;
			w_best = w;
		}
	}
	printf("\nBest Model has an error of -> %lf\n", maxerr);
	printf("Feature Coefficient of Best Model :\n");
	for(i = 1 ; i < 7 ; i++)
		printf("Feature %d has coefficient :  %.6lf\n", i, w_best[i]);
	return 0;
}
