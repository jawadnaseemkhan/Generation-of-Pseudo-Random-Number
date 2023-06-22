#include <stdio.h>
#include <omp.h>
#include <time.h>

//Declaration  of the variables to be used in the LCG formulas
int seed = 1;
int multiplier = 16807;
int increment = 0;
int module = 2147483647;
int randomNumber;
int hundredNumber;
int i;


int firstTask()
{
	seed = ((seed * multiplier) % module);
		return seed; 

	printf("\n Task 1 Function to generate a random number = %d\n", seed);
}

int secondTask()
{
#pragma omp parallel for

	//hundredNumber = firstTask(randomNumber);
	for(i = 0 ; i < 100; i++)
	{		
		randomNumber = firstTask(seed);
		printf("\nTask 2 Function to generate 100 Random Number sequentially = %d\n", randomNumber);//firstTask(randomNumber));
		//return firstTask(randomNumber);
		
	}
}


int thirdTask()
{
	omp_set_num_threads(4);


#pragma omp parallel 
#pragma omp for
	//hundredNumber = firstTask(randomNumber);
	for (i = 0; i < 100; i++)
	{
		randomNumber = firstTask(seed);
		printf("\nTask 3 Function to generate 100 Random Number parallely = %d and the thread number = %f\n", randomNumber,	omp_get_thread_num());//firstTask(randomNumber));
		//return firstTask(randomNumber);

	}
}
void main() 
{

	double startTime = omp_get_wtime();
	//printf("\n Task 1 Function to generate a random number = %d\n", firstTask(seed));

	firstTask();
	secondTask();
#pragma omp parallel for
	thirdTask();
	//printf("\nTask 1 Function to generate a Random Number = %d\n", firstTask());

	float endTime = omp_get_wtime();
	float totalTime = (endTime - startTime) * 1000;
	printf("Task 4 Measure the performance of the program: %f ms\n\n", totalTime);

	return 0;


}

