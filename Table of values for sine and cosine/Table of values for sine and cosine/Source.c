/*
Write a C program that has a function that prints a table of values for sine and cosine between (0, 1). 
You will upload your program as a text file.
*/

#include <stdio.h>
#include <math.h>

int main(void) {

	double x, step = 0.1;

	printf("Input step (defult is 0.1):");
	scanf_s("%lf", &step);
	
	if (step >= 0 && step < 1) {
		for (double x = 0; x <= 1; x += step) {
			printf("sin(%lf)=%lf\n", x, sin(x));
		}

		printf("\n");
		x = 0;
		while (x <= 1)
		{
			printf("cos(%lf)=%lf\n", x, cos(x));
			x += step;
		}
	}

	return 0;
}