// C++ implementation of First - Fit algorithm 
#include<iostream>
using namespace std; 

void firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n]; 
	for (int i = 0; i < n; i++) 
		allocation[i] = -1;
		
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				allocation[i] = j; 
				blockSize[j] -= processSize[i]; 
				break; 
			} 
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t"
			<< processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

int main() 
{ 
    int m,n;
    cout<<"Enter no of block: ";
	cin >> m;
	cout<<"Enter no of processes: ";
	cin >> n;
	int blockSize[m] ;
	int processSize[n] ;
	for (int i =0;i<m;i++)
	{
	    cout<<"Enter block "<<i+1<<" size: ";
	    cin>>blockSize[i];
	}
	for (int i =0;i<n;i++)
	{
	    cout<<"Enter process "<<i+1<<" size: ";
	    cin>>processSize[i];
	}
	firstFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
