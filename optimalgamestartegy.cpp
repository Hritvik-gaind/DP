#include<iostream>
using namespace std;
int a[1000005];
int optimalstrategy(int i,int j)
{
	if(i>j)
	{
		return 0;
	}
	//case 1
	int firstpick = a[i]+min(optimalstrategy(i+2,j),optimalstrategy(i+1,j-1));

	//case2
	int lastpick = a[j]+min(optimalstrategy(i,j-2),optimalstrategy(i+1,j-1));
	return max(firstpick,lastpick);


}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<optimalstrategy(0,n-1);
	return 0;
}
