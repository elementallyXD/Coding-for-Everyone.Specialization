/*
Open and read a file of integers into an array that is created with the first integer telling you how many to read.
So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].
Then compute their average as a double and their max  as an int.  Print all this out neatly to the screen and to an output file named answer-hw3.
*/

#include "Header.h"

static int size = 0;

int main(void) {
	int* data = readData();
	double sum = 0.0;

	for (int i = 0; i < size; i++)
	{
		printf(" %i ", data[i]);
		sum += data[i];
	}
	
	printf("\nAverage = %lf", sum/size);
	printf("\nMax = %i", data[FindMax(data)]);

	WriteData(sum, &data[FindMax(data)]);

	return 0;
}

//reading data from file
int* readData() {
	char ch, temp[4] = { '\0' };
	int i = 0, j = 0, first = 0;
	static int data[] = { 0 };
	
	FILE* fp = NULL;

	if (fopen_s(&fp, "Array.txt", "r") != NULL) {
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
				if (first == 0) {
					size = atoi(temp);
					
					first = 1;
					
					j = 0;
					for (int i = 0; i < 4; i++)
						temp[i] = '\0';			//clear the buffer
				}
				else {
					data[i++] = atoi(temp);	//converting chars array and adding number to int array

					j = 0;
					for (int i = 0; i < 4; i++)
						temp[i] = '\0';			//clear the buffer
				}
			}
		}

		if (temp[0] != '\0') {
			data[size - 1] = atoi(temp); //adding to int array last number
		}

		fclose(fp);
	}

	return data;
}

//write data to the file
void WriteData(double sum, int* value) {
	FILE* fp = NULL;

	if (fopen_s(&fp, "answer-hw3.txt", "w") != NULL) {
		perror("Error while opening the file.\n");
		return EXIT_FAILURE;
	}
	else if(fp){
		fprintf(fp, "Average = %lf", sum / size);
		fprintf(fp, "\nMax = %i", *value);
		fclose(fp);
	}
}

int FindMax(int* array) {
	int * max = array;
	int location = 0;
	
	for (int i = 1; i < size; i++)
	{
		if (array[i] > *max)
		{
			*max = array[i];
			location = i;
		}
	}

	return location;
}