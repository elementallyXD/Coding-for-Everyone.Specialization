#pragma once
#include <stdio.h>

#define size 10

typedef enum department {
	HR, Sales, Research, Software, Executive
} department;

typedef struct business {
	department dep;
	int salary;
	unsigned short security;
} business;

inline int Random(int lower, int upper) { return (rand() % (upper - lower + 1)) + lower; }
int salary(department dep);
const char* getDepartment(enum department dp);