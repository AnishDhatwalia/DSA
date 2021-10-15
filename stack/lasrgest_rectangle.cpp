#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stack>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector<int> previous_min(int a[], int n)
{
    stack<int> s; // stack s
    s.push(a[0]);
    vector<int> v;
    v.push_back(-1);
    for (int i = 1; i < n; i++) // for loop for trversing the array
    {
        while (!s.empty() && s.top() >= a[i]) //if the stack is not empty and top is <a[i] then pop the top element
            s.pop();
        int prev = s.empty() ? -1 : s.top(); // if the stack is empty then put prev = -1 if not empty then put prev = top element
        v.push_back(prev);                   // printing the previous max element
        s.push(i);                           // then pushing the i element to s
    }
    return v;
}
vector<int> next_min(int a[], int n)
{
    stack<int> s; // stack s
    s.push(a[0]);
    vector<int> A; // A is the vector for storing the index
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() > a[i])
            s.pop();
        int next = s.empty() == 0 ? s.top() : n;
        A.push_back(next);
        s.push(i);
    }
    reverse(A.begin(), A.end());
    A.push_back(n);
    for (auto t : A)
        cout << t << " ";
    return A;
}
void largest_rectangle(int a[], int n)
{
    vector<int> prev;
    vector<int> next;
    int res = 0;
    prev = previous_min(a, n);
    next = next_min(a, n);
    for (int i = 0; i < n; i++)
    {
        int ctr = a[i];
        ctr += (i - prev[i] - 1) * a[i];
        ctr += (next[i] - i - 1) * a[i];
        res = max(res, ctr);
    }
    cout << res << endl;
}
void Largest_rectangle(vector<int> a)
{
    int i, j, count, min;
    long int Area, Max = 0;
    vector <int> h = a;
    int n = h.size();
    h[n] = 0; //to avoid crash while executing h[n]
    for (i = 0; i < n; i++)
    {
        count = 1;
        min = h[i];
        j = i - 1;
        while (j >= 0)
        { //Loop to check for greater no.s in reverse dir.
            if (h[j] > min)
            {
                count++;
                j--;
            }
            else
                break;
        }
        while (h[i + 1] == min && i + 1 < n)
        {
            i++; //Loop to check for similar no.s (forward)
            count++;
        }
        j = i + 1;
        while (h[j] >= min && j < n)
        {
            j++; //Loop to check for greater no.s (forward)
            count++;
        }
        Area = min * count;
        if (Area > Max)
            Max = Area;
    }
    cout << Max << " ";
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    //largest_rectangle(a, n);
    vector <int> A;
    for(auto i:a)
    {
        A.push_back(a[i]);
    }
    Largest_rectangle(A);
    return 0;
}