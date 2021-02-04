/*
In this peer reviewed assignment, you will use an array to calculate an average from raw data —
specifically the average weight of the northern elephant seal (Mirounga angustirostris).
*/

#include <stdio.h>
#include <stdlib.h>

#define size 1000

int* readData();

int main(void) {

	int* weights = readData();
	double sum = 0, average = 0.0;
	
	for (int i = 0; i < size; i++)
	{
		printf(" %i ", weights[i]);
		sum += weights[i];
	}
	
	printf("\nAverage weights are: %lf", average = sum/size);

	return 0;
}

//reading data from file
int* readData() {
	char ch, temp[4] = { '\0' };
	int i = 0, j = 0; 
	static int weight[size] = { 0 };
	FILE* fp = NULL;

	if (fopen_s(&fp, "weights.txt", "r") != NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	else if (fp != NULL)
	{
		while ((ch = fgetc(fp)) != EOF) {
			if (ch >= 48 && ch <= 57) {
				temp[j++] = (char)ch;		//adding chars to chars array for future converting
			}
			else if (ch < 48 && temp[0] != '\0') {
				weight[i++] = atoi(temp);  //converting chars array and adding number to int array

				j = 0;
				for (int i = 0; i < 4; i++)
					temp[i] = '\0';			//clear the buffer
			}
		}

		if (temp[0] != '\0') {
			weight[size-1] = atoi(temp); //adding to int array last number
		}

		fclose(fp);
	}

	return weight;
}