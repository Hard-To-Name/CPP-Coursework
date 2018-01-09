#include<iostream>
using namespace std;
#include "Coins.h"
const int CENTS_FOR_CHIPS = 68;

int main()
{
	Coins pocket(5, 3, 6, 8), piggyBank(50, 50, 50, 50);
	if (pocket.has_exact_change_for_coins(coins_required_for_cents(CENTS_FOR_CHIPS)))
    {
	Coins payForChips = pocket.extract_exact_change(coins_required_for_cents(CENTS_FOR_CHIPS));
	cout << "I have " << pocket << " left in my pocket" << endl;
	Coins coins_transfer = piggyBank.extract_exact_change(coins_required_for_cents(205));
	pocket.deposit_coins(coins_transfer);
	cout << "After I transfer $2.05 from my piggyBank to pocket: " << endl;
	cout << "I have " << pocket << " left in my pocket" << endl;
	cout << "I have " << piggyBank << " left in my piggyBank" << endl;
	Coins c(10, 10, 10, 10);
	piggyBank.deposit_coins(c);
	cout << "What a surprise! I got money while vacuuming!!!" << endl;
	cout << "Now I have $" << piggyBank.total_value_in_cents()/100.0 << " in my piggyBank." << endl;
    }
    return 0;
}
