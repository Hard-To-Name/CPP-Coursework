#include "Coins.h"

using namespace std;

int main()
{
	cout << "Options:\n"
		 << "1: deposit change\n"
		 << "2: extract change\n"
		 << "3: print balance\n"
		 << "0: quit" << endl;
	Coins myCoins(0, 0, 0, 0);
	int order;
	while(cout<<"\nPlease enter an order (1, 2, 3, 0): " && cin>>order)
	{
		switch(order)
		{
			case 1:
			{
				double dollar;
				cout << "Please input the amount of money you want to deposit (in dollar): ";
				cin >> dollar;
				Coins a = coins_required_for_cents((int)(dollar*100));
				myCoins.deposit_coins(a);
				cout << "Successfully Deposited." << endl;
				break;
			}
			
			case 2:
			{
				double dollar;
				cout << "Please input the amount of money you want to extract (in dollar): ";
				while(true)
				{
					cin >> dollar;
					Coins a = coins_required_for_cents((int)dollar*100);
					if(myCoins.has_exact_change_for_coins(a))
						break;
					cout << "Insufficient coins. Please enter a smaller amount: ";
				}
				myCoins.extract_exact_change(coins_required_for_cents((int)(dollar*100)));
				cout << "Successfully Extracted." << endl;
				break;
			}
			
			case 3:
			{
				myCoins.print(cout);
				cout << endl;
				break;
			}
				
			
			case 0:
				return 0;
		}
	}
}
