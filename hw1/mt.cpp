#include "stack.h"
int main()
{
	int c = 0;
	Stack stk;
	while(true)
	{
		cout<<"1:pop/2:top/3:push/9:pushAll: ";
		cin>>c;
		switch (c)
		{
			case 1:
				{
					cout<<stk.pop();
					break;
				}
			case 2:
				{
					cout<<stk.top();
					break;
				}
			case 3:
				{
					char a;
					cin>>a;
					stk.push(a);
					break;
				}
			case 9:
				{
					for (int i = 0;i<1000;i++)
					{
						stk.push('v');
					}
					break;
				}
			default:break;
		}
	cout<<endl;
	}
}
