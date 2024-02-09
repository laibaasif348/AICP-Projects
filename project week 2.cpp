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

