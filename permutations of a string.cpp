#include<iostream>
#include<cstring>
using namespace std;

// int factorial(int x)
// {
// 	//base
// 	if(x==0)
// 	{
// 		return 1;
// 	}
// 	//recursive
// 	return x*factorial(x-1);
// }
void computepermutations(char *a,int i)
{

	//base case
	if(a[i]=='\0')
	{

		cout<<a<<" ";
		return;
	}


	//recursive case
	 for(int j=i;a[j]!='\0';j++)
	 {
		 swap(a[i],a[j]);
		 computepermutations(a,i+1);
		 swap(a[i],a[j]); //nullify
	 }



}
int main() {
	char a[100];
	cin>>a;
	int x = strlen(a);
	cout<<factorial(x)<<endl;
	computepermutations(a,0);

	return 0;
}
