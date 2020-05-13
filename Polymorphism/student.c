//
//  student.c
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#include <string.h>
#include "student.h"

Person* new_Student(const char* pFName, const char* pLName, const char* pBranch, const char* pCollege, int salary)
{
    Student* pStuObj;
    Person* pObj;
    pObj = new_Person(pFName, pLName);
    
    pStuObj = malloc(sizeof(Student));
    if (pStuObj == NULL)
    {
        pObj->Delete(pObj);
        return NULL;
    }
    pObj->pDerivedObj = pStuObj;
    
    pStuObj->pBranch = malloc(sizeof(char)*(strlen(pBranch)+1));
    strcpy(pStuObj->pBranch, pBranch);
    pStuObj->pCollege = malloc(sizeof(char)*(strlen(pCollege)+1));
    strcpy(pStuObj->pCollege, pCollege);
    pStuObj->marks = salary;
    
    
    pObj->Delete = delete_Student;
    pObj->Display = Student_DisplayInfo;
    return pObj;
}



void delete_Student(Person* const pPersonObj)
{
    Student* pStuObj;
    pStuObj = pPersonObj->pDerivedObj;
    
    free(pStuObj->pBranch);
    free(pStuObj->pCollege);
    free(pStuObj);
    
    delete_Person(pPersonObj);
}



void Student_DisplayInfo(Person* const pPersonObj)
{
    Student* pStuObj;
    
    Person_DisplayInfo(pPersonObj);
    pStuObj = pPersonObj->pDerivedObj;
    
    printf("Branch: %s\n", pStuObj->pBranch);
    printf("College: %s\n", pStuObj->pCollege);
    printf("Marks: %d\n", pStuObj->marks);
}

