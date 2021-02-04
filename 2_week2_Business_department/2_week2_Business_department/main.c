/*
Write a struct that has a member that is the name of a business department: HR, Sales, Research, Software, and Executive (use enums for the 4 departments). 
A second member that is an annual salary as an int. 
A third member that is a social security number(unsigned).  

Generate 10 employees with different social security numbers. 
Invent a salary generator for each department (use some base salary for the department and add in a randomly generated offset). 
Print out the 10 employees and their values to the screen-one line at a time.
*/

#include "main.h"

int main(void) {
    srand(time(0));     // Use current time as seed for random generator 
    business employees[size] = {0};
    
    for (int i = 0; i < size; i++)
    {
        employees[i].dep = Random(0,4);
        employees[i].salary = salary(employees[i].dep) + Random(200, 400);
        employees[i].security = i;

        printf("Emloyees Numb:%d \t Departament: %s \t Salary: %d$\n", employees[i].security, getDepartment(employees[i].dep), employees[i].salary);
    }
	return 0;
}

//salary generator for each department
int salary(department dep){
    switch (dep)
    {
        case 0:
                return 400;
                break;
        case 1: 
                return 600;
                break;
        case 2: 
                return 1000;
                break;
        case 3: 
                return 1300;
                break;
        case 4: 
                return 2000;
                break;
        default:
                return 100;
                break;
    }
}

//Print each department
const char* getDepartment(enum department dp)
{
    switch (dp)
    {
        case 0:
            return "HR";
            break;
        case 1:
            return "Sales";
            break;
        case 2:
            return "Research";
            break;
        case 3:
            return "Software";
            break;
        case 4:
            return "Executive";
            break;
    }
}