#include <iostream>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n], j = 0, t = m - 1;
	for (int i = 0; i < n; i++) 
        allocation[i] = -1;

	for(int i = 0; i < n; i++)
	{
		while (j < m){
			if(blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				t = (j - 1) % m;
				break;
			}
			if (t == j)
			{
				t = (j - 1) % m;
				break;
			}
			j = (j + 1) % m;
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << " " << i + 1 << "\t\t\t\t" << processSize[i]
			<< "\t\t\t\t";
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
	int blockSize[m];
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

	NextFit(blockSize, m, processSize, n);

	return 0;
}
