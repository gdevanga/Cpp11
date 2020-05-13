//
//  main.c
//  Polymorphism
//
//  Created by Girish Devanga on 12/05/20.
//  Copyright © 2020 Girish Devanga. All rights reserved.
//

#include <stdio.h>
#include "person.h"
#include "employee.h"
#include "student.h"

int main(int argc, const char * argv[]) {
    
    Person* PersonObj = new_Person("PersonFirstName", "PersonLastName");
    Person* EmployeeObj = new_Employee("EMployeeFirstName", "EMployeeLastName","Dept", "COmpany", 50000);
    Person* StudentObj = new_Student("StudentFirstName", "STudentLastName","CSE", "CVR", 90);
    
    
    PersonObj->Display(PersonObj);
    PersonObj->Delete(PersonObj);
    
    printf("\n\n");
    
    EmployeeObj->Display(EmployeeObj);
    EmployeeObj->Delete(EmployeeObj);
    
    printf("\n\n");
       
    StudentObj->Display(StudentObj);
    StudentObj->Delete(StudentObj);
      
    
    return 0;
}
