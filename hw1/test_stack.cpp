#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
    string str;
    Stack stk;
    while(getline(cin, str))
    {
	for(int i=0; i<str.size(); i++)
	    stk.push(str[i]);

	for(int j=0; j<str.size(); j++)
	    cout << stk.pop();
	cout << endl;
    }
    return 0;
}
