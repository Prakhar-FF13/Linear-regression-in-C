void randomModel(double *y_train, int size){
	int train_size = size, i;
	double *errors = malloc(train_size * (sizeof(double)));
	double *predictions = malloc(train_size * (sizeof(double)));
	int iterations = 1;
	double average_error = 0, current_error;
	int k = 0;
	while(iterations < 10000){
		current_error = 0;
		for(i =0 ; i < 10000; i++)
			predictions[i] = (double)rand()/(double)RAND_MAX;

		for(i = 0 ; i < 10000 ; i++)
			errors[i] = (y_train[i] - predictions[i]) * (y_train[i] - predictions[i]);
			
		for(i = 0 ; i < 10000 ; i++)
			current_error += errors[i];
			
		average_error += current_error;
		
		if(((k+1) % 100) == 0){
			printf(".");
		}
		
		iterations++;
		k++;
	}
	printf("\nDone\n");
	free(predictions);
	free(errors);
	printf("\nAverage Error of the Random Model was found to be : %lf\n", average_error);
}
