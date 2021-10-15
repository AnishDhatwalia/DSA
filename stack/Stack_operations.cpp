#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
class stack
{
    int size;
    int top;
    int *st;

public:
    void initialise(int s) // for initialising the value's to the stack
    {
        size = s;
        top = -1;
        st = new int(size);
    }
    void push(int x) // push function for pushing in the top
    {
        if (top == size - 1) // checking whether the stack is full or not
        {
            cout << "Stack overflow\n";
            return;
        }
        else
        {
            top++;       // increasing the top to new
            st[top] = x; // putting the value of x to the top of the stack
        }
    }
    void pop() // popping function
    {
        if (top == -1) // checking whether the stack is empty or not
        {
            cout << "The stack is empty\n";
            return;
        }
        else
        {
            top--; // decreasing the value of top
        }
    }
    void display() // displaying function
    {
        for (int i = 0; i <= top; i++) // for loop for traversing the stack until top is present
        {
            cout << st[top - i] << endl; // displaying the top element of the stack first and followed
        }
    }
};
int main()
{
    stack st;
    st.initialise(5);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(7);
    st.push(8);
    st.push(8);
    st.push(6);
    st.pop();
    st.display();
    return 0;
}