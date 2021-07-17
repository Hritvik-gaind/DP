#include<iostream>
using namespace std;
#define ll long long int
ll n,m,x,y;

bool kyasabkoscholarshipdesakte(ll mid)
{
	if(mid*x<=m+(n-mid)*y)
	{
		return true;
	}
	return false;


}
int main() {

	cin>>n>>m>>x>>y;
	int s=0;
	int e = n;
	int ans=0;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(kyasabkoscholarshipdesakte(mid)==true)
		{
			ans=mid;
			s=mid+1;

		}
		else
		{
			e=mid-1;
		}

	}
	cout<<ans;
	return 0;
}
