#include<iostream>
using namespace std;
char keys[10][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void smartkeypad(char *input,int i,char *out,int j)
{
	//base case
	if(input[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}


	//recursice case
	int digit = input[i]-'0';
	for(int k=0;keys[digit][k]!='\0';k++)
	{
		out[i] = keys[digit][k];
		smartkeypad(input,i+1,out,j+1);
	}


}

int main() {
	char input[100];
	cin>>input;
	char out[100];
	smartkeypad(input,0,out,0);
	return 0;
}
