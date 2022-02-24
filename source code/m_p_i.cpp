// m_p_i.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <mpi.h>
#include <stdio.h>
#include <math.h>

// iterative factorial
unsigned long factorial(unsigned long n)
{
	unsigned long res = 1, i;
	for (i = 2; i <= n; i++)
		res *= i;
	return res;
}

int main(int argc, char **argv)
{
	int i, upper, num_processes;
	float x = 0;
	double time1, time2, duration, global;
    double local_sum = 0;

	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);

	// Get the rank of the process
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	// root process acquire upper limit to i
	if (world_rank == 0)
	{
		printf(" Enter the value for x : ");
		scanf_s("%f", &x);

		printf(" Enter the value for upper : ");
		scanf_s("%d", &upper);

		x = x * 3.14159 / 180;

	}

	// Broadcast the upper limit to the rest of processes
	MPI_Bcast(&upper, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&x, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	// Synchronize processes (No process go beyond this line until all of then reaches it)
	MPI_Barrier(MPI_COMM_WORLD);

	time1 = MPI_Wtime();
	for (int i = world_rank; i < upper; i += num_processes)
	{
		local_sum += (powl(-1, i)*powl(x, 2 * i)) / factorial(2 * i);
	}
	// Reduce operation to sum all local PIs into one variable in the root process (p0)
	 double global_sum;
	MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	// if root process => print the final value of pi
	if (world_rank == 0)
	{
		printf(" The value of Cos(%f) is : %.4f \n", x,global_sum);
	}
	time2 = MPI_Wtime();
	duration = time2 - time1;

	// Get the max time value from all processes to print
	MPI_Reduce(&duration, &global, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
	if (world_rank == 0)
	{
		printf("Global runtime is %f\n", global);
	}
	// Finalize the MPI environment.
	MPI_Finalize();
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
