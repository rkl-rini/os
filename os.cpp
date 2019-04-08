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
// creating the function to find if the system is in safe state  
bool Safe(int processes[], int avail[], int max[][R], 
			int allot[][R]) 
{ 
	int need[P][R]; 
    	// creating the need matrix
	Need(need, max, allot); 
	bool finish[P] = {0}; 

	// To store the safe sequence of the requests 
	int safeSeq[P]; 

	// Duplicate and make a copy of available resources 
	int work[R]; 
	for (int i = 0; i < R ; i++) 
		work[i] = avail[i]; 
