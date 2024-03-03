#include <iostream>
#include <iomanip>
using namespace std;

double calculateParkingPrice(char day, int arrivalHour, int parkingHours, bool hasFrequentParking)
 {
    double pricePerHour;
    double discount;
    double totalPrice;

    if (day == 'S' || day == 's') 
	{
        pricePerHour = 2.0;
    }
	else 
	{
        pricePerHour = (arrivalHour >= 8 && arrivalHour < 16) ? 3.0 : 4.0;
    }

    discount = (hasFrequentParking && arrivalHour >= 16) ? 0.5 : 0.1;
    totalPrice = pricePerHour * parkingHours * (1 - discount);

    return totalPrice;
}

int main()
 {
    char day;
    int arrivalHour;
    int parkingHours;
    bool hasFrequentParking;
    double totalPrice;
    double dailyTotal = 0.0;

    cout << "Enter the day (S for Saturday, U for Sunday, or any other letter for weekdays): ";
    cin >> day;
    cout << "Enter the hour of arrival (in 24-hour format): ";
    cin >> arrivalHour;
    cout << "Enter the number of hours to park: ";
    cin >> parkingHours;
    cout << "Do you have a frequent parking number? (1 for Yes, 0 for No): ";
    cin >> hasFrequentParking;

    totalPrice = calculateParkingPrice(day, arrivalHour, parkingHours, hasFrequentParking);
    cout << fixed << setprecision(2);
    cout << "Total price to park: $" << totalPrice << endl;

    double paymentAmount;
    cout << "Enter payment amount: $";
    cin >> paymentAmount;

    if (paymentAmount >= totalPrice)
	 {
        dailyTotal += paymentAmount;
        cout << "Payment accepted. Thank you!\n";
    } 
	else
	 {
        cout << "Insufficient payment. Please pay the required amount.\n";
    }

    cout << "Daily total: $" << dailyTotal << endl;

    return 0;
}
Output:
Enter the day (S for Saturday, U for Sunday, or any other letter for weekdays): M
Enter the hour of arrival (in 24-hour format): 14
Enter the number of hours to park: 3
Do you have a frequent parking number? (1 for Yes, 0 for No): 0
Total price to park: $9.00
Enter payment amount: $10
Payment accepted. Thank you!
Daily total: $10.00

