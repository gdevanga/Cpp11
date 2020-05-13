//
//  person.c
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "person.h"




Person* new_Person(const char* pFName, const char* pLName)
{
    Person* pObj = NULL;
   
    pObj = (Person*)malloc(sizeof(Person));
    if (pObj == NULL)
    {
        return NULL;
    }
    pObj->pDerivedObj = pObj; //pointing to itself
    pObj->pFirstName = malloc(sizeof(char)*(strlen(pFName)+1));
    strcpy(pObj->pFirstName, pFName);
    pObj->pLastName = malloc(sizeof(char)*(strlen(pLName)+1));
    strcpy(pObj->pLastName, pLName);

    pObj->Delete = delete_Person;
    pObj->Display = &Person_DisplayInfo;

    return pObj;
}




void delete_Person(Person* const pPersonObj)
{
    if(pPersonObj!= NULL)
    {
        free(pPersonObj->pFirstName);
        free(pPersonObj->pLastName);
        free(pPersonObj);
    }
}




int Person_DisplayInfo(Person* const pPersonObj)
{
    printf("FirstName: %s\n", pPersonObj->pFirstName);
    printf("LastName: %s\n", pPersonObj->pLastName);
    return 1;
}
