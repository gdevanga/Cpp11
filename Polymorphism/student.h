//
//  student.h
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include "person.h"


typedef struct _Student Student;

typedef struct _Student
{
    Person* pBaseObj;
    char* pBranch;
    char* pCollege;
    int marks;
}Student;

Person* new_Student(const char* pFName, const char* pLName, const char* pBranch, const char* pCollege, int marks);    //constructor
void delete_Student(Person* const pPersonObj);    //destructor

void Student_DisplayInfo(Person* const pPersonObj);


#endif /* student_h */
