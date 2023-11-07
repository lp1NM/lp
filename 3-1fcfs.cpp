// FCFS CPU SCHEDULING ALGORITHM
#include <iostream>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    
    cout << "Enter the number of processes -- ";
    cin >> n;
    
    for(i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i << " -- ";
        cin >> bt[i];
    }
    
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    
    cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << endl;
    for(i = 0; i < n; i++) {
        cout << "\t P" << i << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    
    cout << "Average Waiting Time -- " << wtavg/n << endl;
    cout << "Average Turnaround Time -- " << tatavg/n << endl;
    
    return 0;
}
