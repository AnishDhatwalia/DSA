#include <bits/stdc++.h>
using namespace std;
void next_max(int a[],int n)
{
    stack <int> s;
    vector <int> A;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<a[i])
            s.pop();
        int next = s.empty()==0?s.top():-1;
        A.push_back(next);
        s.push(a[i]);
    }
    reverse(A.begin(),A.end());
    for(auto j: A)
        cout<<j<<" ";
}
int main()
{
    int a[10]={12,4,24,6,323};
    int n=5;
    next_max(a,n);
    return 0;
}