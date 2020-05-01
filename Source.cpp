#include<iostream>
#include<conio.h>
 using namespace std;

 struct node
 {
	 int info;
	 node* next;
	 node* prev;
 };
 node *emplist(node* head,int data);
 node *beg(node* head,int data);
 node *end(node* head,int data);
 node *nposition(node* head,int data,int position);
void disp(node* head);
 int main()
 {
	 cout<<"\n\t Date: 7 May,2018 \t\t\t\t Name: Furqan Ali \t\t\t\t Reg: 170401027 \n";
 node *head=NULL;
 int data,position,ch;
while(1)
{
 cout<<"\n 1.To Insert In An empty List \n 2.To Insert At The Begning of The List \n 3.To Insert At The End of The List \n 4.To Insert At nth Position of The List \n 5.To Display List \n 6.To End The Program ";
 cout<<"\n\n\t Enter Choice: ";
	 cin>>ch;
	 switch(ch)
	 {
	 
	 case 1:
		 if(head!=NULL){
			 cout<<"\n List Is Not Empty ";break;}
		 else{ 
			 cout<<"\n Enter Element: ";cin>>data;
		 head=emplist(head,data);
		 break;}	 
	 
	 case 2:
		 cout<<"\n Enter Element: ";
		 cin>>data;
		 head=beg(head,data);
		 break;
	 
	 case 3:
		 cout<<"\n Enter Element: ";
		 cin>>data;
		 head=end(head,data);
		 break;
	 
	 case 4:
		 cout<<"\n Enter Element: ";
		 cin>>data;
		 cout<<"\n Enter Position: ";
		 cin>>position;
		head=nposition(head,data,position);
		break;
	 
	 case 5:
		 disp(head);
		 break;
	 
	 case 6:
		 exit(0);
	 default:
		 cout<<"\n Wrong Choice!!! ";
	 }
}

 getch();
 }

 node *emplist(node* head,int data)
 {
 node *tmp;
 tmp=new node;
 tmp->info=data;
 tmp->next=NULL;
 tmp->prev=NULL;
head=tmp;
return head;
 }

 node *beg(node* head,int data)
 {
 node *tmp;
 tmp=new node;
 tmp->info=data;
 tmp->prev=NULL;
 tmp->next=head;			//Problem
 head->prev=tmp;
 head=tmp;
 return head;
 }

 node *end(node* head,int data)
 {
 node *p,*tmp;
 tmp=new node;
 tmp->info=data;
 p=head;					//Problem
 while(p->next!=NULL)
 {
 p=p->next;
 } 
 p->next=tmp;
 tmp->next=NULL;
 tmp->prev=p;
 return head;
 }

 node *nposition(node* head,int data,int position)
 {
 node *tmp,*p;
 tmp=new node;
 tmp->info=data;
 if(position==1)
 //1st Bracket
 {
 tmp->prev=NULL;
 tmp->next=head;
 head->prev=tmp;
 head=tmp;
 return head;
 }
 p=head;
 for(int i=1;i<position && p!=NULL; i++)
 //2nd Bracket
 {
p=p->next;
 }
 if(p==NULL)
 //3rd Bracket
 {
 cout<<"\n There Are Less Than "<<position<<" Elements ";
 }
 else
 //4th Bracket
 {
 tmp->prev=p;
 tmp->next=p->next;
 if(p->next!=NULL)
	 {p->next->prev=tmp;
 p->next=tmp;
 }
 return head;
 }
 }
 
 void disp(node* head)
 {
 node *p;
 if(head==NULL){
	 cout<<"\n Empty List";
 }
 else
 {
 p=head;
 cout<<"\n List::\n "<<endl;
 }
 while(p!=NULL)
 {
 cout<<p->info<<"\t";
 p=p->next;
 }
 cout<<endl;
 }
