// Maclurin(Cosine).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
unsigned long factorial(unsigned long n)
{
	unsigned long res = 1, i;
	for (i = 2; i <= n; i++)
		res *= i;
	return res;
}
void main()
{
	int i, n;
	float x, t = 1;
	double sum = 0;

	printf(" Enter the value for x : ");
	scanf_s("%f", &x);

	printf(" Enter the value for n : ");
	scanf_s("%d", &n);

	x = x * 3.14159 / 180;
	long t1 = clock();
	/* Loop to calculate the value of Cosine */
	for (i = 0; i <= n; i++)
	{
		sum += (powl(-1, i)*powl(x, 2*i)) / factorial(2 * i);
	}

	printf(" The value of Cos(%f) is : %.4f \n", x, sum);
	long t2 = clock();
	double time_taken = ((double)t2-t1) / CLOCKS_PER_SEC; // in seconds

	printf("fun() took %f seconds to execute \n", time_taken);
	_getch();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
