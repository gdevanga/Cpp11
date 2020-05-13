//
//  person.h
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#ifndef person_h
#define person_h

#include <stdlib.h>

typedef struct _Person Person;


typedef int    (*fptrDisplayInfo)(Person*);
typedef void    (*fptrDelete)(Person*) ;

typedef struct _Person
{
    void* pDerivedObj;
    
    char* pFirstName;
    char* pLastName;
    //interface to access member functions
    fptrDisplayInfo Display;
    fptrDelete        Delete;
}Person;

Person* new_Person(const char* pFName, const char* pLName);    //constructor
void delete_Person(Person* const pPersonObj);    //destructor

int Person_DisplayInfo(Person* const pPersonObj);


#endif /* person_h */
