#include<iostream>
using namespace std;
#define int long long
int solve(int n)
{
    int op1 = n;
    int op2 = (13*n)/12;
    return max(op1,op2);
}
int32_t main()
{
    int n;
    cin>>n;
    cout<<solve(n);
}
