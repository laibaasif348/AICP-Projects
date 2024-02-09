#include <iostream>
#include <string>
using namespace std;

const int MinPeople = 10;
const int MaxPeople = 36;

struct OutingCost
{
    int hireOfCoach;
    double costOfMeal;
    double costOfThtrTicket;
};

OutingCost calculateCost(int numPeople)
{
    if (numPeople >= 12 && numPeople <= 16) 
    {
        return {150, 14.00, 21.00};
    } 
    else if (numPeople >= 17 && numPeople <= 26) 
    {
        return {190, 13.50, 20.00};
    } 
    else if (numPeople >= 27 && numPeople <= 39) 
    {
        return {225, 13.00, 19.00};
    }
    return {0, 0.0, 0.0};
}

void task1() 
{
    int numPeople;
    cout << "Enter the number of senior citizens interested in the outing: ";
    cin >> numPeople;

    OutingCost cost = calculateCost(numPeople);
    int totalCost = cost.hireOfCoach + numPeople * (cost.costOfMeal + cost.costOfThtrTicket);

    cout << "Total cost of the outing: " << totalCost << endl;
    cout << "Cost per person: " << static_cast<double>(totalCost) / numPeople << endl;
}

void task2()
{
    string name;
    double amountPaid;
    int numPeople;
    cout << "Enter the number of senior citizens on the outing: ";
    cin >> numPeople;
    if (numPeople < MinPeople || numPeople > MaxPeople) 
    {
        cerr << "Invalid. Number of people must be between " << MinPeople << " and " << MaxPeople << endl;
        return;
    }
    double totalCollected = 0;
    cout << "Enter the names and amounts paid by the participants:" << endl;
    for (int i = 0; i < numPeople; i++) 
    {
        cout << "Name of participant " << i + 1 << ": ";
        cin >> name;
        cout << "Amount paid by " << name << ": ";
        cin >> amountPaid;
        totalCollected += amountPaid;
    }
    cout << "Total money collected: " << totalCollected << endl;
}

void task3()
{
    int numPeople;
    cout << "Enter the number of senior citizens on the outing: ";
    cin >> numPeople;
    if (numPeople<MinPeople || numPeople>MaxPeople)
    {
        cerr << "Invalid. Number of people must be between"<<MinPeople<<"and"<<MaxPeople<<endl;
        return;
    }
    OutingCost cost = calculateCost(numPeople);
    int totalCost = cost.hireOfCoach + numPeople * (cost.costOfMeal + cost.costOfThtrTicket);
    double totalCollected;
    cout << "Enter the total amount collected from the outing:";
    cin >> totalCollected;
    double profit = totalCollected - totalCost;
    if (profit > 0)
    {
        cout << "The outing made a profit of " << profit << endl;
    } 
    else if (profit == 0)
    {
        cout << "The outing broke even." << endl;
    } 
    else 
    {
        cout << "The outing incurred a loss of"<< -profit << endl;
    }
}

int main()
{
    int choice;
    do 
    {
        cout << "Select a task to perform (1-3),or enter 0 to quit: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cerr<<"Invalid choice."<<endl;
                break;
        }
    }
    while (choice != 0);
    return 0;
}
output:
Select a task to perform (1-3),or enter 0 to quit: 1
Enter the number of senior citizens interested in the outing: 13
Total cost of the outing: 605
Cost per person: 46.5385
Select a task to perform (1-3),or enter 0 to quit: 2
Enter the number of senior citizens on the outing: 13
Enter the names and amounts paid by the participants:
Name of participant 1: aqsa
Amount paid by aqsa: 300
Name of participant 2: ali
Amount paid by ali: 200
Name of participant 3: laiba
Amount paid by laiba: 400
Name of participant 4: mlaika
Amount paid by mlaika: 350
Name of participant 5: dua
Amount paid by dua: 240
Name of participant 6: tahir
Amount paid by tahir: 120
Name of participant 7: yoha
Amount paid by yoha: 267
Name of participant 8: raha
Amount paid by raha: 500
Name of participant 9: waleed
Amount paid by waleed: 340
Name of participant 10: qamar
Amount paid by qamar: 290
Name of participant 11: asma
Amount paid by asma: 570
Name of participant 12: sana
Amount paid by sana: 321
Name of participant 13: isra
Amount paid by isra: 543
Total money collected: 4441
Select a task to perform (1-3),or enter 0 to quit: 3
Enter the number of senior citizens on the outing: 30
Enter the total amount collected from the outing:5000
The outing made a profit of 3815
Select a task to perform (1-3),or enter 0 to quit: 0
Exiting program.

