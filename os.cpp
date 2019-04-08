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
    // If the processes are not yet finished or system is not in safe state. 
	int count = 0; 
	while (count < P) 
	{ 
		// to find the process that is not yet finished and to allocate 
		//resources to the processes whose needs can be 
		//satisfied using current resources 
		bool found = false; 
		for (int p = 0; p < P; p++) 
		{ 
			// First check if a process is finished, 
			// if no move onto the next condition 
			if (finish[p] == 0) 
			{ 
				// Check if for all resources of 
				// current Process, need is less than work 
				int j; 
				for (j = 0; j < R; j++) 
					if (need[p][j] > work[j]) 
						break; 

				// If all needs of p were satisfied. 
				if (j == R) 
				{ 
					// Add the allocated resources of 
					// current P to the available/work 
					// resources that is the free the resources 
					for (int k = 0 ; k < R ; k++) 
						work[k] += allot[p][k]; 

					// Add this process to safe sequence. 
					safeSeq[count++] = p; 

					// Mark this process as finished 
					finish[p] = 1; 

					found = true; 
				} 
			} 
		} 

