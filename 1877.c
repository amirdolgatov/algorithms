#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
	

	char str1[SIZE];
	char str2[SIZE];

	const char *yes = "yes";
	const char *no = "no";

	int passw = 0;
	int passw1 = 0;
	int passw2 = 0;
	int attempt = 0;

	fgets(str1, SIZE, stdin);
	fgets(str2, SIZE, stdin);

	passw1 = atoi(str1);
	passw2 = atoi(str2);


	while(attempt < 10000){
		
		if(attempt % 2 == 0)
			passw = passw1;
		else
			passw = passw2;


		if (passw == attempt)
		{
			printf("%s\n", yes);
			return 0;
		}

		++attempt;
	}

	printf("%s\n", no);

	return 0;
}