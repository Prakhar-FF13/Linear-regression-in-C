char *cols[15] = {"id", "crim", "zn", "indus", "chas", "nox", "rm", "age", "dis",
				 "rad", "tax", "ptratio", "black", "lstat", "medv"};


typedef struct Row{
	int id; // The Number of datapoint.
	double crim; // Per Capita Crime Rate by town.
	double zn;  // proportion of residential land zoned for lots over 25,000 sq.ft.
	double indus; // proportion of non-retail business acres per town.
	double chas; // Charles River dummy variable (= 1 if tract bounds river; 0 otherwise).
	double nox; // nitrogen oxides concentration (parts per 10 million).
	double rm; // average number of rooms per dwelling.
	double age; // proportion of owner-occupied units built prior to 1940.
	double dis; // weighted mean of distances to five Boston employment centres.
	int rad; // index of accessibility to radial highways.
	int tax; // full-value property-tax rate per $10,000.
	double ptratio; // pupil-teacher ratio by town.
	double black; // 1000(Bk - 0.63)^2 where Bk is the proportion of blacks by town.
	double lstat; // lower status of the population (percent).
	double medv; // median value of owner-occupied homes in $1000s.
}row; 
