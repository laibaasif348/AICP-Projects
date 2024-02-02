#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int Size =5;

int main() 
{
    string names[Size];
    double weight1stDay[Size];
    double weightLastDay[Size];
    double weightDiff[Size];

    // Task 1: 
    cout << "Task 1: Enter names and weights on the first day"<<endl;
    for (int i = 0; i <Size; i++) 
    {
        cout << "Enter name for pupil "<<i + 1<<":";
        cin >> names[i];

        do
        {
            cout << "Enter weight for pupil "<<i + 1<< " on the first day:";
            cin >> weight1stDay[i];

            if (weight1stDay[i] <= 0) 
            {
                cout << "Invalid weight"<<endl;
            }
        }
        while (weight1stDay[i]<=0);
    }
    // Task 2:
    cout << "\nTask 2: Enter weight of last day and calculate differences\n";
    for (int i = 0; i<Size;i++)
    {
        do 
        {
            cout << "Enter weight for pupil "<<i + 1<<" on the last day:";
            cin >> weightLastDay[i];

            if (weightLastDay[i] <= 0)
            {
                cout << "Invalid weight"<<endl;
            }
        }
        while (weightLastDay[i] <= 0);

        weightDiff[i] = abs(weightLastDay[i] - weight1stDay[i]);
    }
    // Task 3:
    cout << "\nTask 3: Pupils with weight differences more than 2.5 kilograms\n";
    for (int i = 0; i<Size; i++) 
    {
        if (weightDiff[i]>2.5)
        {
            cout << "Pupil " << names[i] << " has a weight difference of " << weightDiff[i]
                      << " kgs("<<(weightLastDay[i] > weight1stDay[i] ? "rise" : "fall")<<")\n";
        }
    }
    return 0;
}



