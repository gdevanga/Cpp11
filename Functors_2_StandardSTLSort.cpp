#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	int id;
	int age;
	Student(int id, int age) : id(id), age(age) {}
	// other data;

	
};

bool compById(const Student& s1, const Student& s2)
{
	return s1.id < s2.id;
};

bool compByAge(const Student& s1, const Student& s2)
{
	return s1.age < s2.age;
};

class functorComparison
{
	bool byAge{ false };
	bool byId{ false };

public:
	functorComparison(bool age, bool id) : byAge(age), byId(id) {}

	bool operator()(const Student& s1, const Student& s2)
	{
		if (byAge)
		{
			return s1.age < s2.age;
		}
		else if (byId)
		{
			return s1.id < s2.id;
		}
	}
};

int main()
{
	vector<Student> vStudents;
	vStudents.emplace_back(8, 10);
	vStudents.emplace_back(4, 7);
	vStudents.emplace_back(90, 9);

	cout << " \n print student records in sorted order of their ID ";
	sort(vStudents.begin(), vStudents.end(), compById);
	for (auto a : vStudents)
		cout << a.id << " ";

	cout << " \n print student records in sorted order of their Age ";
	sort(vStudents.begin(), vStudents.end(), compByAge);
	for (auto a : vStudents)
		cout << a.age << " ";

	functorComparison fcObjByAge(true, false);
	functorComparison fcObjById(false, true);

	cout << " \n print student records in sorted order of their Id ";
	sort(vStudents.begin(), vStudents.end(), fcObjById);
	for (auto a : vStudents)
		cout << a.id << " ";

	cout << " \n print student records in sorted order of their Age ";
	sort(vStudents.begin(), vStudents.end(), fcObjByAge);
	for (auto a : vStudents)
		cout << a.age << " ";

	return 0;
}