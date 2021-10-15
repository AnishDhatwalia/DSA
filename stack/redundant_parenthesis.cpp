#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<stack>
using namespace std;
bool redundant_parenthesis(string input)
{
    stack<char> s;              // stl of stack
    for(auto i : input)         //taking each charachter of input
    {                           
        switch (i)              //switch case for each charachter
        {
            case '-':
            case '*':
            case '/':
            case '+':
            case '(':s.push(i);         // input of all the operators
                    break;
            case ')':
                    if(!s.empty() && s.top()=='(')  // if find any closing bracket then if top is ( then that means no operator in between so hence bracket is not usefull
                    {
                        return false;   // then return false
                    }  
                    else                // else pop until open bracket
                    {
                        for(;s.top()!='(';)
                        {
                            s.pop();        // pop until top is not equal to open bracket
                        }
                        s.pop();            // pop the (
                    }
                    break;
        }
    }
    return true;
}
int main()
{
    string input="((b+c)+(c))";
    if(redundant_parenthesis(input)) // if true the print yes
        cout<<"Yes";
    else                             // else print no.
        cout<<"No";
    return 0;
}