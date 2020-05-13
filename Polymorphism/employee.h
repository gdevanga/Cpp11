//
//  employee.h
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#ifndef employee_h
#define employee_h

#include "person.h"

typedef struct _Employee Employee;

typedef struct _Employee
{
    Person* pBaseObj;
    char* pDepartment;
    char* pCompany;
    int salary;
}Employee;

Person* new_Employee(const char* pFName, const char* pLName, const char* pDepartment, const char* pCompany, int salary);    //constructor
void delete_Employee(Person* const pPersonObj);    //destructor

void Employee_DisplayInfo(Person* const pPersonObj);
void Employee_WriteToFile(Person* const pPersonObj, const char* pFileName);


#endif /* employee_h */
