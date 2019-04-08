// Question number 20 of the assignment showing the use of banker's algorithm
#include<iostream> 
using namespace std; 

// to store the number of processes 
const int P = 3; 

// to store the number of resources 
const int R = 3; 

// Creating a function to calculate the need of every process
void Need(int need[P][R], int max[P][R], 
				int allot[P][R]) 
{ 
	// Loop to calculate the Need of each Process 
	for (int i = 0 ; i < P ; i++) 
		for (int j = 0 ; j < R ; j++) 

			// Need = max value of instance - allocated value of instance 
			need[i][j] = max[i][j] - allot[i][j]; 
} 
