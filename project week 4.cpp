#include <iostream>
#include <string>
using namespace std;

struct AuctionItem 
{
    int itemNumber;
    string description;
    double reservePrice;
    double highestBid;
    int numBids;
};
void auctionSetup(AuctionItem items[], int size);
void placeBid(AuctionItem items[], int size, int buyerNumber);
void endAuction(AuctionItem items[], int size);

int main()
{
    const int SIZE = 10;
    AuctionItem items[SIZE];
    auctionSetup(items, SIZE);
    for (int i = 1; i <= 3; ++i)
    {
        placeBid(items, SIZE, i);
    }
    endAuction(items, SIZE);
    return 0;
}
void auctionSetup(AuctionItem items[], int size)
{
    cout << "Auction Setup\n";
    cout << "Enter details for at least 10 items:\n";
    for (int i = 0; i < size; ++i) 
    {
        cout <<"Item"<<i+1 <<":\n";
        cout << "Item Number:";
        cin >> items[i].itemNumber;
        cin.ignore();
        cout << "Description:";
        getline(cin, items[i].description);
        cout << "Reserve Price: ";
        cin >> items[i].reservePrice;
        items[i].numBids = 0;
        items[i].highestBid = 0.0;
    }
}
void placeBid(AuctionItem items[], int size, int buyerNumber)
{
    cout << "\nBuyer " << buyerNumber << " Bidding:\n";
    cout << "Enter item number you want to bid for: ";
    int itemNumber;
    cin >> itemNumber;
    // Find the item
    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (items[i].itemNumber == itemNumber)
        {
            found = true;
            cout << "Item:"<<items[i].description<<",Current Highest Bid:"<<items[i].highestBid<<endl;
            double newBid;
            cout << "Enter your bid: ";
            cin >> newBid;
            if (newBid>items[i].highestBid&&newBid>items[i].reservePrice)
            {
                items[i].highestBid = newBid;
                items[i].numBids++;
                cout << "Bid accepted!\n";
            } 
            else
            {
                cout<<"Your bid must be higher than the current highest bid and reserve price.\n";
            }
            break;
        }
    }
    if (!found) 
    {
        cout << "Item not found.\n";
    }
}
void endAuction(AuctionItem items[], int size) 
{
    cout << "\nEnd of Auction\n";
    double totalFee = 0.0;
    int itemsSold = 0;
    int itemsNotMetReserve = 0;
    int itemsWithNoBids = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (items[i].highestBid >= items[i].reservePrice) 
        {
            totalFee +=0.1*items[i].highestBid; 
            itemsSold++;
            cout<<"Item"<<items[i].itemNumber<<"sold for $"<<items[i].highestBid<<endl;
        } 
        else if (items[i].numBids==0) 
        {
            itemsWithNoBids++;
            cout<<"Item"<<items[i].itemNumber<<"received no bids.\n";
        } 
        else
        {
            itemsNotMetReserve++;
            cout<<"Item"<<items[i].itemNumber<<"did not meet the reserve price.\n";
        }
    }
    cout<<"Total fee for sold items: $"<<totalFee<<endl;
    cout<<"Number of items sold:"<<itemsSold<<endl;
    cout<<"Number of items that did not meet reserve price:"<<itemsNotMetReserve<<endl;
    cout<<"Number of items with no bids:"<<itemsWithNoBids<<endl;
}


