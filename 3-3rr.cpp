// ROUND ROBIN CPU SCHEDULING ALGORITHM
#include<iostream>
using namespace std;

int main()
{
    int i, j, n, t, max;
    float awt = 0, att = 0, temp = 0;
    cout << "Enter the no of processes -- ";
    cin >> n;
    int bu[n], wa[n], tat[n], ct[n];
    for(i = 0; i < n; i++)
    {
        cout << "Enter Burst Time for process " << i+1 << " -- ";
        cin >> bu[i];
        ct[i] = bu[i];
    }
    cout << "Enter the size of time slice -- ";
    cin >> t;
    max = bu[0];
    for(i = 1; i < n; i++)
    {
        if(max < bu[i])
            max = bu[i];
    }
    for(j = 0; j < (max/t) + 1; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(bu[i] != 0)
            {
                if(bu[i] <= t)
                {
                    tat[i] = temp + bu[i];
                    temp = temp + bu[i];
                    bu[i] = 0;
                }
                else
                {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }
    cout << "The Average Turnaround time is -- " << att/n << endl;
    cout << "The Average Waiting time is -- " << awt/n << endl;
    cout << "\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME" << endl;
    for(i = 0; i < n; i++)
    {
        cout << "\t" << i+1 << "\t " << ct[i] << "\t\t " << wa[i] << "\t\t " << tat[i] << endl;
    }
    return 0;
}
