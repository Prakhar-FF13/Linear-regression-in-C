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
row fillValues(char **token){
	row r;
	return r;
}


row parseString(char *str){
	char **token = split(str, ',');
	int i = 0;
	/*for(i =0  ;i  < 21 ; i++)
		printf("%s\n", token[i]);*/
	return (fillValues(token));
}

