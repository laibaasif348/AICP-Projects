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
output:
Task 1: Enter names and weights on the first day
Enter name for pupil 1:sana
Enter weight for pupil 1 on the first day:50
Enter name for pupil 2:sara
Enter weight for pupil 2 on the first day:35
Enter name for pupil 3:ali
Enter weight for pupil 3 on the first day:40
Enter name for pupil 4:saba
Enter weight for pupil 4 on the first day:60
Enter name for pupil 5:asma
Enter weight for pupil 5 on the first day:35
Task 2: Enter weight of last day and calculate differences
Enter weight for pupil 1 on the last day:50
Enter weight for pupil 2 on the last day:30
Enter weight for pupil 3 on the last day:40
Enter weight for pupil 4 on the last day:65
Enter weight for pupil 5 on the last day:35
Task 3: Pupils with weight differences more than 2.5 kilograms
Pupil sara has a weight difference of 5 kgs(fall)
Pupil saba has a weight difference of 5 kgs(rise)



