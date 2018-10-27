#include "conversion.c"
// This function splits the string at every delimiter and returns the parts of string in an array of strings.
char** split(char *str, char delimiter){
	char **parts = malloc(30 * sizeof(char *));
	char temp[30][30];
	char s[25];
	int i = 0, k = 0, j = 0;
	for(i = 0 ; i < strlen(str) + 1 ; i++)
		if(str[i] == ',' || str[i] == '\0'){
			s[j++] = '\0';
			strcpy(temp[k], s);
			k = k + 1;
			s[0] = '\0';
			j = 0;
		}else{
			s[j++] = str[i];
		}
		
	for(i = 0 ; i < 25 ; i++){
		parts[i] = malloc(30 * sizeof(char));
		strcpy(parts[i], temp[i]);
	}
	return parts;
}

// this function generates structure variable from the tokens in string.
row fillValues(char **token){
	row r;
	int i;
	r.id = token[0]; 						r.date = token[1]; 							r.price = getLong(token[2]);
	r.bedrooms = getInt(token[3]);			r.bathrooms = getInt(token[4]);				r.sqft_living = getInt(token[5]);
	r.sqft_lot = getInt(token[6]);			r.floors = getDouble(token[7]);				r.waterfront = getInt(token[8]);
	r.view = getInt(token[9]);				r.condition = getInt(token[10]);			r.grade = getInt(token[11]);
	r.sqft_above = getInt(token[12]);		r.sqft_basement = getInt(token[13]);		r.year_built = getInt(token[14]);
	r.year_renovated = getInt(token[15]);	r.zipcode = getInt(token[16]);				r.latitude = getDouble(token[17]);
	r.longtitude = getDouble(token[18]);	r.sqft_living15 = getInt(token[19]);		r.sqft_lot15 = getInt(token[20]);
	return r;
}

// Converts the input string into structure variable defined in structure.c
row parseString(char *str){
	// Generates tokens.
	char **token = split(str, ',');
	int i = 0;
	row r = fillValues(token);
	return (r);
}

//Prints a row of the dataset..
void printRow(row r){
	printf("%15s | %15s | %15ld | %15ld | %15ld | %15ld |% 15ld | %15f | %15ld | %15ld | %15ld | %15ld | %15ld | %15ld | %15ld | %15ld | %15ld | %15lf | %15lf | %15ld | %15ld\n",
	r.id, r.date, r.price, r.bedrooms, r.bathrooms, r.sqft_living, r.sqft_lot, r.floors, r.waterfront,
	r.view, r.condition, r.grade, r.sqft_above, r.sqft_basement, r.year_built, r.year_renovated, r.zipcode,
	r.latitude, r.longtitude, r.sqft_living15, r.sqft_lot15);
}

// Prints some rows of the dataset.
void printDataset(row *r, int num_of_points){
	char *cols[21] = {"id", "date", "price", "bedrooms", "bathrooms", "sqft_living", "sqft_lot", "floors", "waterfront",
				 "view", "condition", "grade", "sqft_above", "sqft_basement", "year_built", "year_renovated",
				 "zipcode", "latitude", "longitude", "sqft_living15", "sqft_lot15"};
	int i = 0;
	for(i = 0  ; i < 21 ; i++)
		printf("%15s | ", cols[i]);
	printf("\n");
	for(i = 0 ; i < 21 ; i++)
		printf("------------------");
	printf("\n");
	for(i = 0 ; i < num_of_points ; i++)
		printRow(r[i]);
}

