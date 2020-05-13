//
//  employee.c
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#include <string.h>
#include "employee.h"

Person* new_Employee(const char* pFName, const char* pLName, const char* pDepartment, const char* pCompany, int salary)
{
    Employee* pEmpObj;
    Person* pObj;
    pObj = new_Person(pFName, pLName);
    pEmpObj = malloc(sizeof(Employee));
    if (pEmpObj == NULL)
    {
        pObj->Delete(pObj);
        return NULL;
    }
    pObj->pDerivedObj = pEmpObj;
    
    pEmpObj->pDepartment = malloc(sizeof(char)*(strlen(pDepartment)+1));
    strcpy(pEmpObj->pDepartment, pDepartment);
    pEmpObj->pCompany = malloc(sizeof(char)*(strlen(pCompany)+1));
    strcpy(pEmpObj->pCompany, pCompany);
    pEmpObj->salary = salary;
    
    
    pObj->Delete = delete_Employee;
    pObj->Display = Employee_DisplayInfo;

    return pObj;
}



void delete_Employee(Person* const pPersonObj)
{
    Employee* pEmpobj;
    pEmpobj = pPersonObj->pDerivedObj;
    
    free(pEmpobj->pCompany);
    free(pEmpobj->pDepartment);
    free(pEmpobj);
    
    delete_Person(pPersonObj);
}



void Employee_DisplayInfo(Person* const pPersonObj)
{
    Employee* pEmpObj;
   
    Person_DisplayInfo(pPersonObj);
    pEmpObj = pPersonObj->pDerivedObj;
   
    printf("Department: %s\n", pEmpObj->pDepartment);
    printf("Company: %s\n", pEmpObj->pCompany);
    printf("salary: %d\n", pEmpObj->salary);
}
