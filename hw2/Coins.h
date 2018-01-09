#include<iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10,
CENTS_PER_NICKEL = 5;

class Coins
{
public:
    Coins(int q, int d, int n, int p)
    {
	quarters = q;
	dimes    = d;
	nickels  = n;
	pennies  = p;
    }

    void deposit_coins(Coins &c)
    //remove the coins from c and put them into this Coins object
    {
	quarters += c.quarters;
	dimes += c.dimes;
	nickels += c.nickels;
	pennies += c.pennies;

	c.clear();
    }

    bool has_exact_change_for_coins(Coins c)
    {
    	if(quarters >= c.quarters &&
		   dimes >= c.dimes &&
		   nickels >= c.nickels &&
		   pennies >= c.pennies)
		   return true;
		else return false;
    }

    Coins extract_exact_change(Coins c)
    {
		quarters -= c.quarters;
		dimes -= c.dimes;
		nickels -= c.nickels;
		pennies -= c.pennies;
		
		return c;
    }

    int total_value_in_cents()
    {
	return quarters*CENTS_PER_QUARTER +
	       dimes   *CENTS_PER_DIME +
	       nickels *CENTS_PER_NICKEL +
	       pennies *1;
    }

    void print(ostream &out) //"6 quarters, 2 dimes, ..."
    {
		out << quarters << " quarters, "
		    << dimes << " dimes, "
		    << nickels << " nickels, "
		    << pennies << " pennies.";
    }

    int get_q()
    {
	return quarters;
    }

    int get_d()
    {
	return dimes;
    }

    int get_n()
    {
	return nickels;
    }

    int get_p()
    {
	return pennies;
    }


private:
    int quarters, dimes, nickels, pennies;

    void clear()
    {
	quarters = 0;
	dimes = 0;
	nickels = 0;
	pennies = 0;
    }
};
ostream & operator << (ostream & out, Coins c)
{
	out << c.get_q() << " quarters, "
	    << c.get_d() << " dimes, "
    	    << c.get_n() << " nickels, "
	    << c.get_p() << " pennies";
	return out;
}

Coins coins_required_for_cents(int amount_in_cents)
{
	int q = amount_in_cents / CENTS_PER_QUARTER;
	amount_in_cents -= q*CENTS_PER_QUARTER;
	int d = amount_in_cents / CENTS_PER_DIME;
	amount_in_cents -= d*CENTS_PER_DIME;
	int n = amount_in_cents / CENTS_PER_NICKEL;
	int p = amount_in_cents -= n*CENTS_PER_NICKEL;
	
	return Coins(q, d, n, p);
}
