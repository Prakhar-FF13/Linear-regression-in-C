typedef struct Row{
	char *id; // The Number of datapoint.
	char *date; // Date the house was sold.
	long long price; // Price of the house.
	int bedrooms; // Number of bedrooms.
	int bathrooms; // Number of bathrooms.
	int sqft_living; // Square footage of the home. (Area of house).
	int sqft_lot; // Square footage of the lot.
	double floors; // Number of floors.
	int waterfront; // House has a waterfront or not.
	int view; // Number of times the house has been viewed.
	int condition; // On a scale of 5.
	int grade; // Overall grade given by king county housing unit.
	int sqft_above; // Square footage of the house above the basement.
	int sqft_basement; // Sqaure footage of the basement.
	int year_built; // Year in which the house was built.
	int year_renovated; 
	int zipcode; // Zipcode of the area where the house is located.
	double latitude; // Latitude coordinates.
	double longtitude; // Longitude coordinates.
	int sqft_living15; // Sqft after renovation.
	int sqft_lot15; // Sqft of lot after renovation.
}row; 
