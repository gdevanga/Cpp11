// Cpp11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class PersonC
{
	int m_nAge{ 0 };
	bool m_bGender{ false };

public:
	PersonC(int age, bool gender) : m_nAge(age), m_bGender(gender)
	{
	}

	// Default constructor is deleted.
	PersonC() = delete;

	// Copy constructor is deleted
	PersonC(const PersonC & o) = delete;

	// No Type conversion allowed!
	PersonC(double, bool) = delete;

	// No heap too
	void* operator new (size_t) = delete;
};


int main()
{
	// error C2280: 'PersonC::PersonC(void)': attempting to reference a deleted function
	// PersonC p;

	PersonC ram(9, true);

	// error C2280: 'PersonC::PersonC(const PersonC &)': attempting to reference a deleted function
	// PersonC sita(ram);

	// error C2280: 'PersonC::PersonC(double,bool)': attempting to reference a deleted function
	// PersonC hanuman(6.7, true);

	// error C2280: 'void *PersonC::operator new(std::size_t)': attempting to reference a deleted function
	// PersonC* lakshan = new PersonC(8, true);

	getchar();


    return 0;
}

