#include<iostream>
using namespace std;
int length(char *a)
{
    int i=0,co=0;
    while(a[i]!='\0')
    {
        i++;
        co++;
    }
    return co;

}
bool ispalindrome(char *a)
{
    int i=0;
    int j=length(a)-1;
    while(i<j)
    {
        if(a[i]!=a[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    char a[100];
    cin>>a;
    cout<<boolalpha<<ispalindrome(a);
}

