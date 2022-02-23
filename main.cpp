#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

#define max_limit 50 //max limit for beds in hospital.
using namespace std;

class bed //node will represent as one bed in hospital.
{
  public:
  int pat_id;
  string name;
  bed *next;//pointer to next bed;
};

void traverse(bed *ptr){
  int i=0;
  while (ptr!=NULL)
  {
    cout<<"Bed no:"<<i<<endl;
   cout<<"Patient id:"<<ptr->pat_id<<endl;
   cout<<"Patient name:"<<ptr->name<<endl;
   cout<<"\n";
    i ++;
    ptr=ptr->next;
  }
  
}
int size(bed *head) //return the current no of nodes/size.
{
  bed *ptr=new bed();
  ptr=head->next;
 int i=0;
  while (ptr !=NULL)
  {

   i++;
    ptr=ptr->next;

  }
  return (i+1);
 
}
bed *add_patient(bed *head) //will take data from user and add the patient;
{
  if (size(head) >=max_limit)
  {
    cout<<"!Bed limits are full in our hospital sorry we can't add patient!\n";
  }
  else 
  {
    bed *ptr=new bed();
    ptr=head->next;
    bed *newnode=new bed();//new bed for patient

    cout<<"Enter the Name of patient:\n";
    cin>>newnode->name;
    cout<<"Enter the Patient id\n";
    cin>>newnode->pat_id;

    while (ptr->next !=NULL)
    {
      ptr=ptr->next;
    }
    
    ptr->next=newnode;
    newnode->next=NULL;
  
    
    return head;
  }
  
}
bed *remove_patient(bed *head){
int b_no;
//creating pointer which will point to head
bed *ptr=new bed();
bed *qtr=new bed();
ptr=head; 

cout<<"Enter the bed number of patient you want to remove\n";
cin>>b_no;

if (b_no==0) //first delete
{
 ptr=ptr->next;
 delete head;
 return ptr;
 
}
else if (b_no==size(head)-1) //last delete
{
   
   while (ptr->next->next !=NULL)
   {
     ptr=ptr->next;
   }
   ptr->next=qtr;

   ptr->next=NULL;
   delete qtr;
   return head;

}
else if(b_no>size(head)-1) //error the bed no doesnt exist
{
 cout<<"Error given bed no. not exist in our Hospital\n";
}
else  //insert at given index
{
 int j=0;
 while (j !=b_no-1)
 {
   j++;
   ptr=ptr->next;
 }
 ptr->next=qtr;
 ptr->next=qtr->next;
 delete qtr;
 return head;
 

}
  
  
}
int bill(int min=1000, int max=10000) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
void start() //Start of a program
{
cout<<"-----------------------------------------\n";
cout<<"----------------CITY HOSPITAL------------\n";
cout<<"-----------------------------------------\n";
cout<<"----------------------------By sujal-----\n\n";
cout<<"1.Add Patient\n";
cout<<"2.Remove patient\n";
cout<<"3.Check list of patient\n";
cout<<"4.Exit\n";

}
int main()
{
  bed *head=NULL;
  bed *second=NULL;
  bed *tail=NULL ;
 
   head= new bed();
   second= new bed();
   tail= new bed();

  head->pat_id=8779;
  head->name="Raj";
  head->next=second;

  second->pat_id=9123;
  second->name="Marnus";
  second->next=tail;

  tail->pat_id=9922;
  tail->name="Mark";
  tail->next=NULL;
int in;
char pass;
 while (pass !='n')
 {
  start();
  cout<<"Enter your choice\n";
  cin>>in;
  if (in==1)
  {
    cout<<"::Adding patient::\n";
    bed *k=add_patient(head);
    if (k==head)
    { 
      cout<<"Patient is added successfully...\n";
    }
    
  }
  else if (in==2)
  {
    cout<<"::Removing patient::\n";
    bed *w=remove_patient(head);
    if (w==head)
    {
      cout<<"Patient is removed successfully...\n";
    }
    else if(w !=head){
      cout<<"Patient is removed successfully...\n";
     
    }

    
  }
  else if (in==3)
  {
    cout<<"::List of patients in hospital::\n";
    traverse(head);
  }
  else if (in==4)
  {
    exit(0);
  }
  else
  {
   cout<<"*Invalid input*\n";
  }
  
 }
    return 0;
}
