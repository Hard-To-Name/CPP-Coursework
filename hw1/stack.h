#define STACK_CAPACITY 1000
#include<iostream>

class Stack
{
private:
    int count;
    char stk[STACK_CAPACITY];
    void error(const char *msg)
    {
	std::cerr << "ERROR:" << msg << std::endl;
    }

public:
    Stack() //constructor for a stack
    {
	count = 0;
    }

    void push(char c) //adds c to the top of the stack
    {
	if(isFull())
	{
	    error("The stack is already full. :D");
	    return;
	}
	stk[count] = c;
	count++;
    }

    char pop() //removes top element, returns it
    {
	if(isEmpty())
	{
	    error("The stack is already empty. :D");
	    return '\0';
	}
	count--;
	char temp = stk[count];
	stk[count] = '\0';
	return temp;
    }

    char top() //returns top element, returns it
    {
	if(isEmpty())
	{
	    error("The stack is already empty. :D");
	    return '\0';
	}
	return stk[count-1];
    }

    bool isEmpty() //returns true iff the stack is empty
    {
	return count == 0;
    }

    bool isFull() //returns true iff the stack is full
    {
	return count == STACK_CAPACITY;
    }
    ~Stack(){} //destructor for a stack
};
