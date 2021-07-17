#include<iostream>
using namespace std;
int main()
{
    int n,m,i,p;
    cin>>n>>m;
    int a[m+n];
    int b[m];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int k=m+n-1;
    int j=n-1;
    int l=m-1;
    while(l>=0 && j>=0)
    {
        if(a[j]<b[l])
        {
            a[k]=b[l];
            k--;
            l--;
        }
        else
        {
            a[k] = a[j];
            k--;
            j--;
        }

    }
    while(l>=0)
        {
            a[k] = b[l];
            k--;
            l--;
        }

    for(i=0;i<m+n;i++)
    {
        cout<<a[i];
    }




}

