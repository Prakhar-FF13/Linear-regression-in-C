// Returns an integer 
int getInt(char *s){
	return atoi(s);
}

long long getLong(char *s){
	char *si;
	return strtol(s, &si, 10);
}

// Returns a double value
double getDouble(char *s){
	return atof(s);
}
