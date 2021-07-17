#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};
void addfromend(node *&head, node *&tail,int data)
{
	node *m = new node(data);
	if(head==NULL)
	{
		head=m;
		tail=m;
		return;
	}
	tail->next = m;
	tail= m;
}
node *head2=NULL;
node *tail2=NULL;
void addallodd(node *head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		if(temp->data%2!=0)
		{
			addfromend(head2,tail2,temp->data);
		}
		temp=temp->next;
	}
}
void addalleven(node *head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		if (temp->data%2==0)
		{
			addfromend(head2,tail2,temp->data);
		}
		temp=temp->next;
	}
}
void printll(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main() {
	int n;
	cin>>n;
	node *head =NULL;
	node *tail = NULL;
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		addfromend(head,tail,data);
	}
	addallodd(head);
	addalleven(head);
	printll(head2);
	return 0;

}
