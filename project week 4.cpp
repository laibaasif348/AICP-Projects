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
output:
Auction Setup
Enter details for at least 10 items:
Item 1:
Item Number: 101
Description: Antique Table
Reserve Price: 500
Item 2:
Item Number: 102
Description: Vintage Chair
Reserve Price: 300
Item 3:
Item Number: 103
Description: Oil Painting
Reserve Price: 800
Item 4:
Item Number: 104
Description: Collectible Vase
Reserve Price: 200
Item 5:
Item Number: 105
Description: Rare Book
Reserve Price: 600
Item 6:
Item Number: 106
Description: Silver Jewelry
Reserve Price: 400
Item 7:
Item Number: 107
Description: Designer Handbag
Reserve Price: 700
Item 8:
Item Number: 108
Description: Sculpture
Reserve Price: 350
Item 9:
Item Number: 109
Description: Antique Clock
Reserve Price: 450
Item 10:
Item Number: 110
Description: Persian Rug
Reserve Price: 900

Buyer 1 Bidding:
Enter item number you want to bid for: 103
Item: Oil Painting, Current Highest Bid: 0
Enter your bid: 850
Bid accepted!

Buyer 2 Bidding:
Enter item number you want to bid for: 106
Item: Silver Jewelry, Current Highest Bid: 0
Enter your bid: 420
Bid accepted!

Buyer 3 Bidding:
Enter item number you want to bid for: 110
Item: Persian Rug, Current Highest Bid: 0
Enter your bid: 950
Bid accepted!

End of Auction
Item 101 sold for $500
Item 102 did not meet the reserve price.
Item 103 sold for $850
Item 104 did not meet the reserve price.
Item 105 did not meet the reserve price.
Item 106 sold for $420
Item 107 did not meet the reserve price.
Item 108 did not meet the reserve price.
Item 109 did not meet the reserve price.
Item 110 sold for $950
Total fee for sold items: $247.5
Number of items sold: 4
Number of items that did not meet reserve price: 6
Number of items with no bids: 0


