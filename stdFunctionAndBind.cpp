// stdFunctionAndBind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <functional>

using namespace std;


double multiply(double x, double y)
{
	double result = x*y;
	cout << result << endl;
	return result;
}

int main()
{
	using namespace std::placeholders;

	std::function<double(double, double)> mul_fn = std::bind(&multiply, _1, _2);
	mul_fn(5, 8);

	auto mul_by_5_fn = std::bind(&multiply, 5, _1);
	mul_by_5_fn(7);

	auto mul_by_10_fn = std::bind(&multiply, _1, 10);
	mul_by_10_fn(7);

	getchar();

    return 0;
}

