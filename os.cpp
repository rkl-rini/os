// C++ program to illustrate Banker's Algorithm 
#include<iostream> 
using namespace std; 

// Number of processes 
const int P = 3; 

// Number of resources 
const int R = 3; 

// Function to find the need of each process 
void calculateNeed(int need[P][R], int maxm[P][R], 
				int allot[P][R]) 
{ 
	// Calculating Need of each P 
	for (int i = 0 ; i < P ; i++) 
		for (int j = 0 ; j < R ; j++) 

			// Need of instance = maxm instance - 
			//				 allocated instance 
			need[i][j] = maxm[i][j] - allot[i][j]; 
} 