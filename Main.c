#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Read_File/structure.c"
#include "Read_File/helper.c"
#include "Read_File/readfile.c"
#include "Data_Analysis/vect_operations.c"
#include "Data_Analysis/vector.c"
#include "Data_Analysis/Data_Analysis_Helper.c"
#include "Data_Analysis/DataAnalysis.c"
#include "Training_Models/RandomModel.c"
#include "Training_Models/LinearRegression.c"
#include "Training_Models/KNNRegression.c"
#include "Test_Models_and_Write_to_File/test_model.c"

int main(){
	// Read Data (readfile.c).
	row *r = read_csv("kc_house_data.csv");
	printDataset(r, 10);
	

	// Structure to Matrix Conversion (vector.c).
	double **mat = init(r);
	printMatrix(mat, 10);
	

	// Find and remove outliers (dataanalysis.c).
	mat = findAndRemoveOutliers(mat);
	int newlen = 19806;
	

	//MinMax Scaling.. (dataanalysis.c)
	MinMaxScaling(mat, newlen);
	printMatrix(mat, 10);


	// Train Test Split (dataanalysis.c)
	double **X_train = malloc(10000 * sizeof(double *));
	double **X_test = malloc(5000 * sizeof(double *));
	double *y_train = malloc(10000 * sizeof(double));
	double *y_test = malloc(5000 * sizeof(double));
	train_test_split(X_train, y_train, X_test, y_test, 10000, 5000, mat, newlen);
	printf("\nThe size of Train Set : (%d, %d)\n", 10000, 6);
	printf("\nThe size of Test Set : (%d, %d)\n", 5000, 6);
	
	
	// Training a Random Model For reference .. (Random Model.c File in Training Models
	printf("\n\n ---------------- Training Random Model ---------------------- \n\n");
	randomModel(y_train, 10000);
	
	// Linear Regression - Training Linear Regression model using Hyperparameter Tuning
	double alpha[11] = {0.5, 0.4, 0.3, 0.2, 0.1, 0.01, 0.001, 0.0001, 0.00001};
	printf("\n\n ---------------- Training Regression Models ---------------------- \n\n");
	printf("------------- Multiple Regression-------------\n");
	double *w_best;
	double maxerr = 1e7;
	int i,j;
	for(i = 0 ; i < 9 ; i++){
		// Below functions are defined in Linear Regression.c file and trains the model, predicts values and calculates error
		double *w = LinearRegression(X_train, y_train, alpha[i]);
		double *y_pred = predict(X_train, w);
		double *err = errors(y_train, y_pred);
		double sum = 0;
		for(j = 0 ; j < 10000 ; j++)
			sum += (err[j] * err[j]);
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
		
	
	
	// Hyperparameter tuning for KNNRegression..
	printf("\n\n------------- KNN Regression--------------\n");
	KNNRegression(X_train, y_train, 10000);
	
	
	printf("\n\n------------- Conclusion of Model Training ------------------\n\n");
	printf("The Linear egression Model Performs the Best out of the ones tested, hence we will this one only..");
	
	
	printf("\n\n------------- Testing the Model on Test Dataset -------------------- \n\n");
	displayTestResults(X_test, y_test, w_best, 5000);
	printf("\n\n------------- Writing the model to file --------------------- \n\n");
	writeToFile(w_best, fimin, fimax, 6);
	
	return 0;
}
