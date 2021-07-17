#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;

int binarysearch(ll n,ll k)
{
	ll x=0;
	ll mid;
	ll s=1;
	ll e= n;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(pow(mid,k)<=n)
		{
			x=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}

	}
	return x;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<binarysearch(n,k)<<endl;

	}
	return 0;
}
