#include<iostream>
using namespace std;
int main()
{ int n,i,j,k,max_sum=INT_MIN,sum=0;
  cin>>n;
  int ar[100];
  for(i=0;i<n;i++)
  {
      cin>>ar[i];
  }
  for(i=0;i<=n-1;i++)
  {
      for(j=i;j<=n-1;j++)
      { sum = 0;
          for(k=i;k<=j;k++)
          {
              sum+=ar[k];
          }
          if(sum>max_sum)
          {
              max_sum = sum;
          }


      }

  }
  cout<<max_sum;









 return 0;
 }

