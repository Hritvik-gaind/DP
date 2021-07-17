#include<iostream>
#include<climits>
using namespace std;
#define int long long int
int price[1005];
int weight[1005];
int n,capacity;
int knapsack(int n,int capacity)
{
	//base case
	if(n==0||capacity==0)
	{
		return 0;
	}
	//recursive case
	//exclude
	int op1,op2;
	op1=op2=INT_MIN;
	op1 = 0 + knapsack(n-1,capacity);
	//include
	if(capacity>=weight[n-1])
	{
		op2 = price[n-1] + knapsack(n-1,capacity-weight[n-1]);
	}
	return max(op1,op2);

}
int knapsacktopdown(int n,int capacity,int dp[][1005])
{
	//base case
	if(n==0||capacity==0)
	{
		return dp[n][capacity] = 0;
	}
	if(dp[n][capacity]!=-1)
	{
		return dp[n][capacity];
	}
	int op1=INT_MIN,op2=INT_MIN;
	if(capacity>=weight[n-1])
	{
		op1 = price[n-1] + knapsacktopdown(n-1,capacity - weight[n-1],dp);
	}
	op2 = 0 + knapsacktopdown(n-1,capacity,dp);
	return dp[n][capacity]= max(op1,op2);

}
int32_t main() {
	cin>>n>>capacity;
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	int dp[1005][1005];
	memset(dp,-1,sizeof(dp));
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 	{
	// 		dp[i][j] = -1;
	// 	}
	// }
	// cout<<knapsack(n,capacity);
	cout<<knapsacktopdown(n,capacity,dp);

	return 0;
}
