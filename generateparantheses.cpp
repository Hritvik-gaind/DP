#include<iostream>
using namespace std;
void generateparentheses(int open,int closed,int n,int i,char* output)
{
	//base case
	if(i==2*n)
	{
		output[i]='\0';
		cout<<output<<endl;
		return;

	}

	//recursive case
	if(closed<open)
	{
		output[i]=')';
		generateparentheses(open,closed+1,n,i+1,output);
	}
	if(open<n)
	{
		output[i] = '(';
		generateparentheses(open+1,closed,n,i+1,output);
	}



}
int main() {
	int n;
	cin>>n;
	char output[100];
	generateparentheses(0,0,n,0,output);
	return 0;
}
