#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
class stack
{
    int size;                   //size of stack
    int top;                    // top of the stack
    char *st;                   // Dynamic Array 

public:
    void initialise(int n)      // Initialising the values to stack
    {
        size = n;               
        st = new char(size);    // Dynamically allocating memory to the array 
        top = -1;               
    }
    char pop()                  // Pop function of the top element 
    {   
        char x = '0';           
        if (top == -1)          // if the stack is empty 
        {
            cout << "Underflow";
            return x;           // returning x
        }
        x = st[top];            // putting the value to x of the popping element 
        top--;                  // decreasing the size
        return x;
    }
    int parethesis(string s)        // parethesis function to check whether the brackets are balanced or not 
    {
        int n = s.size();
        for (int i = 0; i < n; i++)     // for traversing the string 
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')  // pushing the brackets to the stack 
            {
                top++;
                st[top] = s[i];
            }
            else if (s[i] == '}' || s[i] == ')' || s[i] == ']') // popping the bracket when closing bracket is there 
            {
                char x = pop();
                if (x != '(' && s[i] == ')' || x != '[' && s[i] == ']' || x != '{' && s[i] == '}') // checking whether the closing bracket is same as that of the top element of the stack or not 
                    return false; 
            }
        }
        return true;
    }
};
int main()
{
    stack s;
    s.initialise(5);
    string st = "{(a+b)-(b-a)}";
    int x = s.parethesis(st);
    cout << x;
    return 0;
}