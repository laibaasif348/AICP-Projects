#include <iostream>
#include <cmath>
using namespace std;

const int DaysInWeek = 7;
const double MinYield = 12.0;
const int MinDays = 4;

struct MilkRecord
{
    double TotalYield = 0.0;
    int NumMilking = 0;
};

void recordYield(MilkRecord records[], int cowId) 
{
    double yield;
    cout << "Enter yield for each milking: ";
    cin >> yield;
    records[cowId].TotalYield += yield;
    records[cowId].NumMilking++;
}

void calculateStatistics(const MilkRecord records[])
{
    double TotalVolume = 0.0;
    int TotalMilking = 0;
    for (int i = 0; i < 1000; i++)
    {
        TotalVolume += records[i].TotalYield;
        TotalMilking += records[i].NumMilking;
    }
    double averageYield = TotalVolume / TotalMilking;
    int roundTotalVolume = round(TotalVolume);
    int roundAverageYield = round(averageYield);
    cout << "Total weekly volume of milk: " << roundTotalVolume << endl;
    cout << "Average yield per cow in a week: " << roundAverageYield << endl;
}

void identifyCows(const MilkRecord records[])
{
    double MaxYield = 0.0;
    int ProductiveCow = -1;
    int lowYieldCows[1000] = {0}; 
    for (int i = 0; i < 1000; i++)
    {
        if (records[i].TotalYield > MaxYield) 
        {
            MaxYield = records[i].TotalYield;
            ProductiveCow = i;
        }
        int lowYieldDays = 0;
        if (records[i].TotalYield / records[i].NumMilking < MinYield) 
        {
            lowYieldDays = records[i].NumMilking;
        }
        if (lowYieldDays >= MinDays) 
        {
            lowYieldCows[i] = lowYieldDays;
        }
    }

    cout << "Most productive cow (ID): " << ProductiveCow << " with weekly yield: " << round(MaxYield) << endl;
    cout << "Cows with low volume of milk for four or more days:" << endl;
    for (int i = 0; i < 1000; i++)
    {
        if (lowYieldCows[i] > 0)
        {
            cout << "Cow ID: " << i << ", Low yield days: " << lowYieldCows[i] << endl;
        }
    }
}

int main() {
    MilkRecord records[1000] = {0}; 

    for (int day = 1; day <= DaysInWeek; ++day) 
    {
        cout << "Day " << day << ":" << endl;
        int NumMilking;
        cout << "Enter the number of times milked today: ";
        cin >> NumMilking;
        for (int i = 0; i < NumMilking; i++)
        {
            int cowId;
            cout << "Enter cow's ID (3-digit number): ";
            cin >> cowId;

            if (cowId < 100 || cowId > 999)
            {
                cout << "Invalid cow ID" << endl;
                continue;
            }
            recordYield(records, cowId);
        }
    }

    cout << "\n--- Statistics ---" << endl;
    calculateStatistics(records);

    cout << "\n--- Cow Identification ---" << endl;
    identifyCows(records);

    return 0;
}
output:
Day 1:
Enter the number of times milked today: 2
Enter cow's ID (3-digit number): 123
Enter yield for each milking: 20
Enter cow's ID (3-digit number): 456
Enter yield for each milking: 15
Day 2:
Enter the number of times milked today: 1
Enter cow's ID (3-digit number): 789
Enter yield for each milking: 10
Day 3:
Enter the number of times milked today: 2
Enter cow's ID (3-digit number): 123
Enter yield for each milking: 18
Enter cow's ID (3-digit number): 456
Enter yield for each milking: 14
Day 4:
Enter the number of times milked today: 1
Enter cow's ID (3-digit number): 789
Enter yield for each milking: 11
Day 5:
Enter the number of times milked today: 2
Enter cow's ID (3-digit number): 123
Enter yield for each milking: 17
Enter cow's ID (3-digit number): 456
Enter yield for each milking: 13
Day 6:
Enter the number of times milked today: 1
Enter cow's ID (3-digit number): 789
Enter yield for each milking: 12
Day 7:
Enter the number of times milked today: 2
Enter cow's ID (3-digit number): 123
Enter yield for each milking: 16
Enter cow's ID (3-digit number): 456
Enter yield for each milking: 12

--- Statistics ---
Total weekly volume of milk: 148
Average yield per cow in a week: 14

--- Cow Identification ---
Most productive cow (ID): 123 with weekly yield: 71
Cows with low volume of milk for four or more days:
Cow ID: 456, Low yield days: 4


