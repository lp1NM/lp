#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int choice;
    do {
        cout << "\nSelect a CPU Scheduling Algorithm:" << endl;
        cout << "1. FCFS" << endl;
        cout << "2. SJF" << endl;
        cout << "3. Round Robin" << endl;
        cout << "4. Priority" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int bt[20], wt[20], tat[20], i, n;
                float wtavg, tatavg;

                cout << "\nEnter the number of processes -- ";
                cin >> n;

                for (i = 0; i < n; i++) {
                    cout << "Enter Burst Time for Process " << i << " -- ";
                    cin >> bt[i];
                }

                wt[0] = wtavg = 0;
                tat[0] = tatavg = bt[0];

                for (i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tat[i] = tat[i - 1] + bt[i];
                    wtavg += wt[i];
                    tatavg += tat[i];
                }

                cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << endl;
                for (i = 0; i < n; i++) {
                    cout << "\t P" << i << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
                }

                cout << "Average Waiting Time -- " << wtavg / n << endl;
                cout << "Average Turnaround Time -- " << tatavg / n << endl;
                break;
            }
            case 2: {
                int n;
                cout << "\nEnter the number of processes -- ";
                cin >> n;

                vector<int> p(n), bt(n), wt(n), tat(n);
                float wtavg = 0, tatavg = 0;

                for (int i = 0; i < n; i++) {
                    p[i] = i;
                    cout << "Enter Burst Time for Process " << i << " -- ";
                    cin >> bt[i];
                }

                for (int i = 0; i < n; i++) {
                    for (int k = i + 1; k < n; k++) {
                        if (bt[i] > bt[k]) {
                            swap(bt[i], bt[k]);
                            swap(p[i], p[k]);
                        }
                    }
                }

                wt[0] = 0;
                tat[0] = bt[0];

                for (int i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tat[i] = tat[i - 1] + bt[i];
                    wtavg += wt[i];
                    tatavg += tat[i];
                }

                cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "\n\t P" << p[i] << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i];
                }

                cout << "\nAverage Waiting Time -- " << wtavg / n << endl;
                cout << "Average Turnaround Time -- " << tatavg / n << endl;
                break;
            }
            case 3: {
                int i, j, n, t, max;
                float awt = 0, att = 0, temp = 0;
                cout << "\nEnter the no of processes -- ";
                cin >> n;
                int bu[n], wa[n], tat[n], ct[n];
                for (i = 0; i < n; i++) {
                    cout << "Enter Burst Time for process " << i + 1 << " -- ";
                    cin >> bu[i];
                    ct[i] = bu[i];
                }
                cout << "Enter the size of time slice -- ";
                cin >> t;
                max = bu[0];
                for (i = 1; i < n; i++) {
                    if (max < bu[i])
                        max = bu[i];
                }
                for (j = 0; j < (max / t) + 1; j++) {
                    for (i = 0; i < n; i++) {
                        if (bu[i] != 0) {
                            if (bu[i] <= t) {
                                tat[i] = temp + bu[i];
                                temp = temp + bu[i];
                                bu[i] = 0;
                            } else {
                                bu[i] = bu[i] - t;
                                temp = temp + t;
                            }
                        }
                    }
                }
                for (i = 0; i < n; i++) {
                    wa[i] = tat[i] - ct[i];
                    att += tat[i];
                    awt += wa[i];
                }
                cout << "The Average Turnaround time is -- " << att / n << endl;
                cout << "The Average Waiting time is -- " << awt / n << endl;
                cout << "\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME" << endl;
                for (i = 0; i < n; i++) {
                    cout << "\t" << i + 1 << "\t " << ct[i] << "\t\t " << wa[i] << "\t\t " << tat[i] << endl;
                }
                break;
            }
            case 4: {
                int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
                float wtavg, tatavg;

                cout << "\nEnter the number of processes --- ";
                cin >> n;

                for (i = 0; i < n; i++) {
                    p[i] = i;
                    cout << "Enter the Burst Time & Priority of Process " << i << " --- ";
                    cin >> bt[i] >> pri[i];
                }

                for (i = 0; i < n; i++)
                    for (k = i + 1; k < n; k++)
                        if (pri[i] > pri[k]) {
                            temp = p[i];
                            p[i] = p[k];
                            p[k] = temp;
                            temp = bt[i];
                            bt[i] = bt[k];
                            bt[k] = temp;
                            temp = pri[i];
                            pri[i] = pri[k];
                            pri[k] = temp;
                        }

                wtavg = wt[0] = 0;
                tatavg = tat[0] = bt[0];

                for (i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tat[i] = tat[i - 1] + bt[i];
                    wtavg += wt[i];
                    tatavg += tat[i];
                }

                cout << "\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME" << endl;

                for (i = 0; i < n; i++)
                    cout << p[i] << "\t\t" << pri[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;

                cout << "Average Waiting Time is --- " << wtavg / n << endl;
                cout << "Average Turnaround Time is --- " << tatavg / n << endl;
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}
