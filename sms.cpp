#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
int g=0;
class student
{
char Sname[25];
int Srno;
char SFname[25];
char Sdob[25];
char Semail[25];
char Snumber[15]; //giving error with any integer or float datatype
char Saddress[30];
public: void inputdata();
	void adddata(int &n);
	void deletedata(int a,int &b);
	void modifydata(int e);
	void searchdata(int &x,int y);
	void sortdata(int t,int ch=0);
	void displaysorteddata();
	void displaydata(int f)
	{
	 cout<<"\nThe details of student "<<f<<" :";
	 cout<<"\nName: "<<Sname<<"\nFather's name: "<<SFname;
	 cout<<"\nRoll Number: "<<Srno<<"\nDate of Birth: "<<Sdob;
	 cout<<"\nEmail Address: "<<Semail<<"\nMobile Number: "<<Snumber;
	 cout<<"\nAddress: "<<Saddress;
	 cout<<endl;
	}

	student()
	{
	strcpy(Sname," ");
	strcpy(SFname," ");
	Srno=0;
	strcpy(Sdob,"00 00 0000");
	strcpy(Semail,"xyz@abc.com");
	strcpy(Snumber,"8888888888");
	strcpy(Saddress," ");
	}
}stud[100],temp;



void student::inputdata()
{      	cout<<"\nPlease fill the following details ";
	cout<<"for registration of student "<<(::g+1)<<" :";
	cout<<endl;
	cout<<"Enter name: ";
	gets(Sname);
	cout<<"\nEnter Father's name: ";
	gets(SFname);
	cout<<"\nEnter Roll number: ";
	cin>>Srno;
	cout<<"\nEnter Date of Birth(DD_MM_YYYY): ";
	gets(Sdob);
	cout<<"\nEnter Email-Address: ";
	gets(Semail);
	cout<<"\nEnter Mobile number: ";
	cin>>Snumber;
	cout<<"\nEnter address: ";
	gets(Saddress);clrscr();
	cout<<"\nThank you.You have been registered in our database.\n";
	++::g;
}



void student::adddata(int &n)
{
int n1;
char choi;
enter:cout<<"\nEnter the number of students to be added?\n";
cin>>n1;
if(n+n1>100)
{cout<<"\nThe total students in your group cannot be more than 100. Enter again.\n";
goto enter;}
int j=::g+n1;
for(int i=::g;i<j;i++)
stud[i].inputdata();
cout<<"\nExtra students added";
if(n1>0)
{
n+=n1;
main4:cout<<"\nDo you want your data to be sorted(Roll No. wise)? Enter Y for YES and N for NO.";
cin>>choi;
if(choi=='Y'||choi=='y')
{
cout<<"\nAye Aye! Your data is sorted. As quick as it can get!\n";
stud[0].sortdata(n);
}
else if(choi=='N'||choi=='n')
cout<<"\nNo problem. Ahead you go.\n";
else if(choi!='y'||choi!='Y'||choi!='N'||choi!='n')
{cout<<"\nInvalid choice.";
goto main4;
}
}
}



void student::modifydata(int e)
{       cout<<"\nEnter the details of student with Roll number "<<e<<" to be updated:";
	cout<<"\nEnter name: ";
	gets(Sname);
	cout<<"\nEnter Father's name: ";
	gets(SFname);
	cout<<"\nEnter Roll number: ";
	cin>>Srno;
	cout<<"\nEnter Date of Birth(DD MM YYYY): ";
	gets(Sdob);
	cout<<"\nEnter Email-Address: ";
	gets(Semail);
	cout<<"\nEnter Mobile number: ";
	cin>>Snumber;
	cout<<"\nEnter address: ";
	gets(Saddress);clrscr();
	cout<<"\nThank you. The detils of Roll number "<<e<<" have been updated.\n ";
}



void student::deletedata(int a,int &b)
{
int p;
for(p=a;p<b;p++)
{stud[p]=stud[p+1];}
cout<<"\nThe desired record has been deleted.";
b--;
}




void student::sortdata(int t,int ch)
{
int v=t;
int j=1;
int w,a,u,s,y;
char choi,choic,choice;

if(ch==5)
{choic='Y';
goto main9;}
for(u=0;u<t;u++)
{
   for(s=j;s<t;s++)
   {
      if(stud[s].Srno<stud[u].Srno)
      {
	temp=stud[s];
	stud[s]=stud[u];
	stud[u]=temp;
       }
   }
     j++;
}
cout<<"\nDo you wish to see the sorted data?\n";
main3:cout<<"Enter Y for YES and N for NO.\n";
cin>>choic;
main9:if(choic=='Y'||choic=='y')
{ clrscr();
  for(w=0;w<v;w++)
  {
    stud[w].displaysorteddata();
    if(w%21==0&&w!=0)
    {
     int x=(w+1);
     if((v-w)>21)
     y=20+x;
     else if((v-w)<21)
     y=v;
     main10:cout<<"\nLoad more? Enter Y for yes and No for no.\n";
     char choice;
     cin>>choice;
	 if(choice=='Y'||choice=='y')
	 {
	 clrscr();
	 for(int u=x;u<y;u++)
	 {stud[u].displaysorteddata();
	 w++;}
	 }
	 else if(choice=='N'||choice=='n')
	 {cout<<"\nThank you for being satisfied by our work.";
	 break;}
	 else
	 {cout<<"\nInvalid choice";
	 goto main10;}
    }
}

}
else if(choic=='n'||choic=='N');
else if(choic!='Y'||choic!='y'||choic!='N'||choic!='n')
{cout<<"\nInvalid choice\n";
goto main3;}
else;
getch();
clrscr();
}




void student::displaysorteddata()
{
cout<<"\nROLL NUMBER:  "<<Srno<<"    NAME: "<<Sname;
}




void student::searchdata(int &x,int y) //using & because calling delete func
{                                 //which will decrease length of object array
long rno;
int m=x;
int flag=0;
int q;
main2:cout<<"\nEnter the Roll Number to be searched for:\n";
cin>>rno;
switch(y)
{
case 1:
for(q=0;q<m;q++)
{
if(stud[q].Srno==rno)
{
stud[q].displaydata(stud[q].Srno);
flag=1;
break;
}
}
if(flag==0)
{
cout<<endl<<"Invalid Roll number.";
goto main2;
}
break;
case 2:
for(q=0;q<m;q++)
{
if(stud[q].Srno==rno)
{
stud[q].modifydata(stud[q].Srno);
flag=1;
break;
}
}
if(flag==0)
{
cout<<endl<<"Invalid Roll number.";
goto main2;
}
break;
case 3:
for(q=0;q<m;q++)
{
if(stud[q].Srno==rno)
{
stud[q].deletedata(q,x);
flag=1;
break;
}
}
if(flag==0)
{
cout<<endl<<"Invalid Roll number.";
goto main2;
}
break;
}
}



void main()
{
clrscr();
int n;
cout<<"GREETINGS! WELCOME TO PURJAYSIN *SCHOOL MANAGEMENT* DATABASE.\n";
main5:cout<<"\nEnter the number of students to be registered.\n";
cin>>n;
if(n>100)
{
cout<<"\nInvalid number. Enter a valid number(less than 100)";
goto main5;
}
cout<<"\nA unique feature of our software is that we can also sort your data for you.";
cout<<"\nYou may enter the data in any order and trust our software to sort it for you.\n";
for(int i=0;i<n;i++)
{
stud[i].inputdata();
}
clrscr();
int ch;
char cho,choi;
cout<<"\nThank you for registering.The registration process is over.\n";
main6:cout<<"\nDo you want your data to be sorted(Roll No. wise)? Enter Y for YES and N for NO.";
cin>>choi;
if(choi=='Y'||choi=='y')
{
cout<<"\nAye Aye! Your data is sorted. As quick as it can get!\n";
stud[0].sortdata(n);
}
else if(choi=='N'||choi=='n')
cout<<"\nNo problem. Ahead you go.\n";
else
{
cout<<"\nInvalid choice";
goto main6;
}
do
{
clrscr();
cout<<endl<<"\nThe database is complete,so";
main1:cout<<"\n1.Do you wish to look at any existing record?";
cout<<"\n2.Do you wish to modify any existing record?";
cout<<"\n3.Do you wish to delete any existing record?";
cout<<"\n4.Do you wish to add new record(s)?";
cout<<"\n5.Do you wish to see the sorted list?";
cout<<"\n6.Do you wish to take no further action?";
cout<<"\nEnter 1, 2, 3, 4, 5 or 6 to make a choice.\n";
cin>>ch;
clrscr();

if(ch==1||ch==2||ch==3)
stud[0].searchdata(n,ch);
else if(ch==4)
stud[0].adddata(n);
else if(ch==5)
stud[0].sortdata(n,ch);
else if(ch==6)
{cout<<"\nThank you for registering your group. Have a magnificent day ahead.";
break;}
else
{cout<<"\nInvalid choice";
goto main1;}
cout<<"\n\nDo you wish to perform any of the actions of the MAIN MENU again?";
cout<<"\nEnter Y for YES and N for NO.\n";
cin>>cho;
clrscr();
}while(cho=='Y'||cho=='y');
if(cho=='N'||cho=='n')
cout<<"\nThank you for registering your group. Have a magnificent day ahead.";
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nIt is illegal to reproduce this software without the developer's permission.";
cout<<"\nCopyright@PURJAYSIN Ltd.";

getch();
}
