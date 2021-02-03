//WRITE A PROGRAM THAT CAN GIVE THE SINE OF A VALUE BETWEEN 0 AND 1 (NON INCLUSIVE).
//YOU WILL BE GRADED BASED ON WHETHER THE PROGRAM CAN OUTPUT A VALUE IN THE CORRECT RANGE AND WHETHER YOUR CODE IS WELL - FORMATTED AND LOGICALLY CORRECT.

#include <stdio.h>
#include <math.h>

int main(void) {
	
	double x, res = 0;

	printf("X = ");
	scanf_s("%lf", &x);
	if (x >= 0 && x < 1) res = sin(x);

	printf("\nSIN(%lf) = %lf", x, res);
	
	return 0;
}