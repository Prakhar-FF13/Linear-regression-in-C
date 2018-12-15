// Predicts the price of a single data  point.
double getPrediction(double *point, double *weights, int cols){
	int i;
	double ans = weights[0];
	for(i = 1 ; i < cols ; i++){
		ans += (point[i-1] * weights[i]);
	}
	return ans;
}

// Calculate the predictions of all points then calculates the error.
void displayTestResults(double **X_test, double *y_test, double *w, int test_size){
	int i;
	double *predictions = malloc(test_size * sizeof(double));
	for(i = 0 ; i < test_size ; i++){
		predictions[i] = getPrediction(X_test[i], w, 7);
	}
	double err = 0;
	for(i = 0 ; i < test_size ; i++){
		err += (y_test[i] - predictions[i]) * (y_test[i] - predictions[i]);
	}
	
	printf("\n Best Test Results are : %.6lf", err);
}

struct data{
	double w[7];
	double fimin[7];
	double fimax[7];
	int size;
};

// Write the model to File.
void writeToFile(double *w_best, double *fimin, double *fimax, int size){
	FILE *fp;
	fp = fopen("model_details.bin", "wb");
	if(fp == NULL){
		printf("\nCould not write to file..\n");
		return;
	}else{
		struct data d;
		d.size = size;
		int i;
		for(i = 0 ; i < size ; i++){
			d.w[i] = w_best[i];
			d.fimin[i] = fimin[i];
			d.fimax[i] = fimax[i];
		}
		fwrite(&d, sizeof(struct data), 1, fp);
	}
	fclose(fp);
}
