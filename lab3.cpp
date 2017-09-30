// Lab3.cpp
// James Mock 
// COSC 2030
// 2017-09-30
// Numeric Errors

#include <iomanip>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

double factorial(int x) // factorial computation
{
	double fact = 1;
	if (!(x == 0))
	{
		for (int i = 2; i <= x; i++)
		{
			fact *= i;
		}
	}
	return fact;
}
double f(int x) 
{
	double ratio = 1 / static_cast<double>(x);
	double fSum = 0;
	for (int i = 0; i < x; i++)
	{
		fSum += ratio;
	}
	return fSum;
}

int main()
{
	const int SENTINEL = -9999;
	long sum;
	long n;
	bool done = false;

	

	while (!done)
	{
		cout << "Please enter a non-negative interger or " << SENTINEL << " to end:" << endl;
		cin >> n;
		if (n == SENTINEL) //Check for end
		{
			done = true;
		}
		else if (n == 0)
		{
			n = 1;
		}
		else if (n < 0) //fix negative numbers
		{
			n = n*(-1);
		}

		if (!done)
		{
			sum = 0;
			for (int i=1; i <= n; i++)
			{
				sum += i;
			}
			
			cout << "The sum of consecutive integers from 0 to " << n << " is " << sum << endl;
			cout << "The product of " << n << "! is " << factorial(n) << endl;
			cout << "Result of f(n) function: " << std::setprecision(20) << f(n) << endl << endl;

			for (double i = 3.4; i < 4.4; i += 0.2)
			{
				cout << "i = " << i << endl;
			}

		}
		
	}

	return 0;
}


//Part 1a: The largest short is 32767. Anything that sums to over 32767 (n>255) will cause an overflow. An overflow can be detected by the sum suddenly becomes negative.  
//Part 1b: The largest long is 2,147,483,647. n > 7787761 will cause an overflow.

//Part 2a: An overflow is dected when the output of the factorial function is inf. n > 34 will cause an overflow.
//Part 2b: n > 170 will cause an overflow when the factorial function uses doubles instead of floats.

//Part 3a: The function should always output 1 if the computations are exact, but floats are stupid and inaccurate so it doesn't.
//Part 3b: Because double computations are far more accurate than float computations the function now outputs correctly. If you use the setpercision function you would see it is still not 1.

//Part 4a: The code should not print 4.4 since the loop condition is i < 4.4. This occurs because the program is truncating a double (4.4 and .2) to compare it to a float.
//Part 4b: When i's data type is a double the program no longer truncates 4.4 or .2 and the loop works as advertised.

