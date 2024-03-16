#include <iostream>
#include <string>
using namespace std;
class Ticket
{
    protected:
    string type;
    float oneDayPrice;
    float twoDaysPrice;
    public:
    Ticket(string t,float oneDay,float twoDays):type(t),oneDayPrice(oneDay),twoDaysPrice(twoDays) 
    {
    }
    virtual void displayOptions() 
    {
        cout<<type<<":\n";
        cout<<"One day: $"<<oneDayPrice<<endl;
        cout<<"Two days: $"<<twoDaysPrice<<endl;
    }
    float getOneDayPrice() 
    const 
    {
        return oneDayPrice;
    }
    float getTwoDaysPrice()
    const
    {
        return twoDaysPrice;
    }
};
class GroupTicket:public Ticket
{
    public:
    GroupTicket():Ticket("Group (6+ people)", 15.00, 22.50)
    {
    }
};
class FamilyTicket:public Ticket 
{
    public:
    FamilyTicket():Ticket("Family(up to 2 adult& 3 children)",60.00, 90.00) 
    {
    }
};
class IndividualTicket:public Ticket 
{
    public:
    IndividualTicket(string t,float oneDay,float twoDays):Ticket(t,oneDay,twoDays)
    {
    }
};
class Attraction
{
    protected:
    string name;
    float price;
    public:
    Attraction(string n,float p):name(n),price(p) 
    {
    }
    void display() 
    {
        cout<<name<<": $"<<price<<endl;
    }
    float getPrice() 
    const 
    {
        return price;
    }
};
class Booking 
{
    private:
    Ticket* tickets[10];
    Attraction* attractions[10];
    int ticketCount;
    int attractionCount;
    float totalCost;
    public:
    Booking():ticketCount(0),attractionCount(0),totalCost(0) 
    {
    }
    void addTicket(Ticket* ticket) 
    {
        if(ticketCount<10) 
        {
            tickets[ticketCount++]=ticket;
        }
    }
    void addAttraction(Attraction* attraction) 
    {
        if(attractionCount<10) 
        {
            attractions[attractionCount++]=attraction;
        }
    }
    float calculateTotalCost() 
    {
        totalCost=0;
        for(int i=0;i<ticketCount;i++) 
        {
            totalCost+=tickets[i]->getOneDayPrice();
        }
        for(int i=0; i<attractionCount; i++) 
        {
            totalCost+=attractions[i]->getPrice();
        }
        return totalCost;
    }
    void displayBookingDetails() 
    {
        cout<<"Booking details:\n";
        for(int i=0;i<ticketCount;i++) 
        {
            tickets[i]->displayOptions();
        }
        for (int i=0;i<attractionCount;i++) 
        {
            attractions[i]->display();
        }
        cout<<"Total Cost: $"<<totalCost<<endl;
    }
};

int main() 
{
    cout<<"One-day ticket options:\n";
    IndividualTicket adult("Adult", 20.00, 30.00);
    IndividualTicket child("Child", 12.00, 18.00);
    IndividualTicket senior("Senior", 16.00, 24.00);
    adult.displayOptions();
    child.displayOptions();
    senior.displayOptions();
    GroupTicket group;
    group.displayOptions();
    FamilyTicket family;
    family.displayOptions();
    
    cout << "\nAvailable attractions:\n";
    Attraction lionFeeding("Lion Feeding", 2.50);
    Attraction penguinFeeding("Penguin Feeding", 2.00);
    Attraction eveningBarbecue("Evening Barbecue (Two-day tickets only)", 5.00);
    lionFeeding.display();
    penguinFeeding.display();
    eveningBarbecue.display();
    
    Booking booking;
    booking.addTicket(&adult);
    booking.addTicket(&child);
    booking.addAttraction(&lionFeeding);
    booking.addAttraction(&eveningBarbecue);
    float totalCost = booking.calculateTotalCost();
    cout<<"\nTotal cost of the booking: $"<<totalCost<<endl;

    booking.displayBookingDetails();
    return 0;
}
output:
One-day ticket options:
Adult:
One day: $20
Two days: $30
Child:
One day: $12
Two days: $18
Senior:
One day: $16
Two days: $24
Group (6+ people):
One day: $15
Two days: $22.5
Family(up to 2 adult& 3 children):
One day: $60
Two days: $90

Available attractions:
Lion Feeding: $2.5
Penguin Feeding: $2
Evening Barbecue (Two-day tickets only): $5

Total cost of the booking: $39.5
Booking details:
Adult:
One day: $20
Two days: $30
Child:
One day: $12
Two days: $18
Lion Feeding: $2.5
Evening Barbecue (Two-day tickets only): $5
Total Cost: $39.5

--------------------------------
