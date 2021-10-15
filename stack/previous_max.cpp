#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;
void Previous_max(int a[],int n)
{
    stack <int> s;              // stack s
    for(int i=0;i<n;i++)        // for loop for trversing the array
    {
        while(!s.empty() && s.top()<=a[i])  //if the stack is not empty and top is <a[i] then pop the top element 
            s.pop();
        int prev=s.empty()?-1:s.top();     // if the stack is empty then put prev = -1 if not empty then put prev = top element
        cout<<prev<<" ";        // printing the previous max element
        s.push(a[i]);           // then pushing the a[i] element to s
    } 
}
int main()
{
    int a[10]={82,4,6,3,2,34};
    int n=6;
    Previous_max(a,n);
    return 0;
}