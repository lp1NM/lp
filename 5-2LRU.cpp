#include <iostream>
using namespace std;

int main() {
    int i, j, n, ref_str[50], frame[10], no, avail, fcount = 0;
    int counter[10] = {0};

    cout << "ENTER THE NUMBER OF PAGES: ";
    cin >> n;

    cout << "ENTER THE PAGE NUMBER: ";
    for (i = 1; i <= n; i++) {
        cin >> ref_str[i];
    }

    cout << "ENTER THE NUMBER OF FRAMES: ";
    cin >> no;

    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }

    cout << "ref string\t page frames\t Hit/Fault" << endl;
    for (i = 1; i <= n; i++) {
        cout << ref_str[i] << "\t\t\t";
        avail = 0;
        for (j = 0; j < no; j++) {
            if (frame[j] == ref_str[i]) {
                avail = 1;
                counter[j] = i;
                for (j = 0; j < no; j++) {
                    cout << frame[j] << "\t\t";
                }
                cout << "H";  // Page Hit
            }
        }

        if (avail == 0) {
            int min = 0;
            for (j = 1; j < no; j++) {
                if (counter[j] < counter[min]) {
                    min = j;
                }
            }
            frame[min] = ref_str[i];
            counter[min] = i;
            fcount++;
            for (j = 0; j < no; j++) {
                cout << frame[j] << "\t\t";
            }
            cout << "F"; 
        }
        cout << endl;
    }

    cout << "Page Fault Is " << fcount << endl;

    return 0;
}
