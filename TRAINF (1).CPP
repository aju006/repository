#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<dos.h>
#include<ctype.h>
//int x;
class train
 {
   int trainno;
   char from[25];
   char to[25];
   char date[10];
   char tarrivalH[5];
   char tarrivalD[5];
   int tcharge;
   int seats;
  public:
   char *trainhome()
    {
     return from;
    }
   char *traindes()
    {
     return to;
    }
   int trainprice()
    {
     return tcharge;
    }
   int gettrain()
    {
     return trainno;
    }
   int getseats()
    {
     return seats;
    }
   void enter()
    {
     cout<<"\n\n\t\tEnter new train number\n\t\t";
     cin>>trainno;
     cout<<"\n\n\t\tEnter new train arrival station\n\t\t";
     gets(from);
     cout<<"\n\n\t\tEnter ne train destination station\n\t\t";
     gets(to);
     cout<<"\n\n\t\tEnter new train running date\n\t\t";
     gets(date);
     cout<<"\n\n\t\tEnter new train arrival time\n\t\t";
     gets(tarrivalH);
     cout<<"\n\n\t\tEnter new train destination time\n\t\t";
     gets(tarrivalD);
     cout<<"\n\n\t\tEnter new train charge:\n\t\t";
     cin>>tcharge;
     cout<<"\n\n\t\tEnter number of seats";
     cin>>seats;
    }
   int modifyseat(int t)
    {
     if(seats>=t)
       {
	seats-=t;
	return 1;
       }
     else
       {
	return 0;
       }
    }
   void admin()
    {
     train s;
     s.enter();
     ofstream fout("train0.dat",ios::app|ios::binary);
     fout.write((char*)&s,sizeof(train));
     getch();
    }
   void display()
    {
     cout<<endl;

     cout<<"*************************************************"
	 <<"*****************************************";
     cout<<"\n\tTrain no              :"<<trainno;
     cout<<"\n\tFrom                  :";puts(from);
     cout<<"\tDestination           :";puts(to);
     cout<<"\tDate                  :";puts(date);
     cout<<"\tReach destination at  :";puts(tarrivalH);
     cout<<"\tReach destination on  :";puts(tarrivalD);
     cout<<"\tTicket charge         :"<<tcharge;
     cout<<"\n\tTotal seats available  :"<<seats<<endl;
     cout<<"**************************************************"
	 <<"******************************************\n\n\n\n";
    }
   void timedis()
    {
     cout<<endl;

     cout<<"*************************************************"
	 <<"*****************************************";
     cout<<"\n\tTrain no              :"<<trainno;
     cout<<"\n\tFrom                  :";puts(from);
     cout<<"\tDestination           :";puts(to);
     cout<<"\tDate                  :";puts(date);
     cout<<"\tReach destination at  :";puts(tarrivalH);
     cout<<"\tReach destination on  :";puts(tarrivalD);
     cout<<"\tTicket charge         :"<<tcharge;
     cout<<"\n\tTotal seats available  :"<<seats<<endl;
     cout<<"**************************************************"
	 <<"******************************************\n\n\n\n";


    }
 };

void loading()
{
 clrscr();
 gotoxy(28,13);
 cputs("********************");
 gotoxy(28,15);
 cputs(" <<..LOADING..>> ");
 gotoxy(28,17);
 cputs("********************");
 gotoxy(28,20);
 cputs("PLEASE WAIT......");
 delay(500);
 gotoxy(28,35);
 cputs("10% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("20% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("30% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("40% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("50% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("60% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("70% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("80% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("90% completed..");
 delay(500);
 gotoxy(28,35);
 cputs("100% completed......");
 //x=0;
 delay(500);
 clrscr();
}
void reservation()
{
  cout<<endl<<endl<<endl<<endl;
  cout<<"\n\n\n\t\t Enter home station";
  char home[25];
  train s;
  gets(home);
  ifstream fin("train0.dat",ios::binary);
  while(fin.read((char*)&s,sizeof(s)));
  {
   if(strcmpi(s.trainhome(),home)==0)
    {
      if(fin.eof())
       {
      // break;
       }
       else
       s.display();
      // break;
    }
  }
  fin.close();
  cout<<"\n\n\n\t\t Enter the required train number:";
  int n;
  cin>>n;
  int price;
  cout<<"\n\n\n\t\t Enter the no of tickets required:";
  int t;
  cin>>t;
  int q;
  fin.open("train().dat",ios::binary);
  while(fin.read((char*)&s,sizeof(s)))
  {
    if(s.gettrain()==n)
    {
      price=s.trainprice();
      q=s.modifyseat(t);
      }
    }
    fin.close();
    if(q==1)
    {
    int cost;
    cost=t*price;
    cout<<"\n\n\n\t\tCost;Rs."<<cost;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout<<"%                  \n";
    cout<<"%                  \n";
    cout<<"%   No of tickets::";
    cout<<price<<endl;
    cout<<"%                  \n";
    cout<<"%                  \n";
    cout<<"%  TOTAL COST::";
    cout<<cost;
    cout<<"%                  \n";
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    fstream f("train0.dat",ios::binary);
    getch();
    int p;
    while(f.read((char*)&s,sizeof(train)))
    { if(s.gettrain()==n)
    {
	s.modifyseat(t);
      p=f.tellp();
      f.seekp(p);
      f.write((char*)&s,sizeof(train));
      break;
    }
    else
    {
    clrscr();
    cout<<endl<<endl<<"\t\t<<RESERVATION NOT POSSIBLE!!>>"<<endl;
    }
    }
  }
  }
    void seat()
    {
     char home[25];
     train s;
     cout<<"\n\n\n\t\t Enter home station:";
     gets(home);
     ifstream fin("train0.dat",ios::binary);
     while(fin.read((char*)&s,sizeof(train)))
     { if (strcmpi(s.trainhome(),home)==0)
       { if(fin.eof())
	 break;
	 s.display();
       }
     }
     fin.close();
    }
    void time()
    {
    char home[25];
    train s;
    cout<<"\n\n\n\t\t Enter home station:";
    gets(home);
    ifstream fin("train0.dat",ios::binary);
    while(fin.read((char*)&s,sizeof(train)))
    {
      if(strcmpi(s.trainhome(),home)==0)
       { if(fin.eof())
	  break;
	  s.timedis();
       }
    }
    fin.close();
    }

    void search()
    {
       char des[25];
	train s;
	cout<<"\n\n\n\n\t\tENTER DESTINATION:";
	 gets(des);
	 ifstream fin("train0.dat",ios::binary);
	  while(fin.read((char*)&s,sizeof(s)))
	   {
	       if(strcmp(s.traindes(),des)==0)
		 {
		     s.display();
		  }
	     }
	      fin.close();
       }
int passcheck()
{
char k[15],ch;
 for(int i=0;i<15;i++)
 { ch=getch();cout<<"*";
  k[i]=ch;
  if((int)ch==13)
  { k[i]='\0';break;}
 }

 if((strcmp(k,"1234")==0))
 {
  return 1;
 }
 else
 return 0;
}
void main()
{
 train s;
  start:
       //	textbackground(0);
	//textcolour(2);
  clrscr();
  cout<<"\n";
  cout<<"\n\t\t\tII  II    I  IIIII  II  IIII  II    I ";
  cout<<"\n\t\t\tII  I I   I  I   I  II  I  I  I I   I ";
  cout<<"\n\t\t\tII  I  I  I  I   I  II  IIII  I  I  I ";
  cout<<"\n\t\t\tII  I   I I  I   I  II  I  I  I   I I ";
  cout<<"\n\t\t\tII  I    II  IIIII  II  I  I  I    II ";
  cout<<"\n";

cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

cout<<"\n\t\tIIII   IIII  II IIII  II    II    II IIII  I    I ";
cout<<"\n\t\tI   I  I  I  II I  I  II    II    II I  I   I  I  ";
cout<<"\n\t\tIIII   IIII  II IIII  II    II    II IIII    II   ";
cout<<"\n\t\tI   I  I  I  II I  I  II    II II II I  I    II   ";
cout<<"\n\t\tI    I I  I  II I  I  IIIII III  III I  I    II   ";
cout<<"\n";
cout<<"\n\n\n\n";
cout<<"                (+++++++++++)\n";
cout<<"		  (++++)\n";
cout<<"	       (+++)\n";
cout<<"	     (+++)\n";
cout<<"	    (++)\n";
cout<<"	    [~]\n";
cout<<"	    | | (~)  (~)  (~)    /~~~~~~~~~~~~\n";
cout<<"	 /~~~~~~~~~~~~~~~~~~~~~~~  [~_~_] |    * * * /~~~~~~~~~~~| \n";
cout<<"       [|  %___________________           | |~~~~~~~~     |\n";
cout<<"	 /[___] ___   ___   ___/  o.    | |   ..  ..      |\n";
cout<<"      /// [___+/-+-\-/-+-\-/-+ \\_________|=|______________________ |\n";
cout<<"    //// @-=-@ \___/ \___/ \___/  @-==-@      @-==-@      @-==-@ ";
cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

cout<<"\n\t\t\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\n\n\n\n PLEASE ENTER THE PASSWORD:";

  if(passcheck()==1)
 {
  do{
    //while(x==1)
     menu:
     loading();
     clrscr();
     cout<<"\n";
     cout<<"\n\t\tII II I III II IIII II I";
     cout<<"\n\t\tII I I I II I I II I";
     cout<<"\n\t\tII I I I I I II IIII I I";
     cout<<"\n\t\tII I II I I II I I I II";
     cout<<"\n\t\tI I I I II IIII II II I I II IIII";
     cout<<"\n";
     cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
     cout<<endl<<endl<<endl<<endl;
     int choice;
     cout<<"\t\t1.Reservation:";cout<<endl<<endl<<endl;
     cout<<"\t\t2.Seat availability:";cout<<endl<<endl<<endl;
     cout<<"\t\t3.Train timing:";cout<<endl<<endl<<endl;
     cout<<"\t\t4.Admin files:";cout<<endl<<endl<<endl;
     cout<<"\t\t5.About:";cout<<endl<<endl<<endl;
     cout<<"\t\t6.Exit program:";cout<<endl<<endl<<endl;
     cout<<endl<<"\t\tChoose the required option:";
     cin>>choice;
     switch(choice)
     {
      case 1:
	    clrscr();
	    cout<<endl<<endl<<endl;
	    cout<<"\n\n\n\t\tWELCOME TO THE TRAIN RESERVATION FORUM:"<<endl;
	    reservation();
	    break;
      case 2:
	    clrscr();
	    cout<<endl<<endl<<endl;
	    cout<<"\n\n\n\t\tSEAT AVILABILITY"<<endl<<endl;
	    seat();
	    getch();
	    break;
      case 3:

	    clrscr();
	    cout<<endl<<endl<<endl;
	    cout<<"\n\n\n\t\tWELCOME TO QUERY FORUM"<<endl<<endl;
	    time();
	    getch();
	    break;
      case 4:
	   char y;
	   do
	   {
	    clrscr();
	    cout<<"\n\n\n\t\tADMIN FILES";
	    cout<<"\n\n\n\t\tPLEASE ENTER THE PASSCODE:";
	    if(passcheck()==1)
	    cout<<"working";
	    //nandu working

	    else
	      {
	       cout<<"\n\n\n\t\t  !!!ACCESS DENIED!!!\n";
	       delay(1000);
	       clrscr();
	       cout<<"\n\n\n\n\n\n\n\n\t\t\tDO YOU WANT TO CONTINUE ?<y/n>";
	       cin>>y;
	       if(toupper(y)!=0)
	       goto menu;
	      }
	    }while(toupper(y)=='Y');
	     break;

      case 5:
	     clrscr();
	     cout<<"\n\n\n\n\t\t@@THANK YOU@@";
	     delay(1000);
	     cout<<endl<<"\n\n\n\t\tBE A PART OF DIGITAL INDIA!";
	     delay(1500);
	     break;
      case 6:
	     exit(0);
      default:
	     {
	       clrscr();
	       cout<<"\n\n\n\n\n\n\n\n\t\tINCORRECT OPTION!!\n\n\n\n\t\t<TERMINATING PROGRAMME>";
	       delay(1500);
	       exit(0);
	      }
	     }
	     cout<<endl<<endl<<endl;
	   }while(1);
    }	  //getch();
  else
  {
   cout<<"\n\n\t\t!!!!ACCESS DENIED!!!!\a";
   delay(1000);
   clrscr();
   cout<<"DO YOU WANT TO CONTINUE?(Y/N)";
   char f;
   cin>>f;
   if(toupper(f)=='Y')
   goto start;
   else
   {
    clrscr();
    cout<<"\n\n\n\t\t THANK YOU FOR USING>>>>HAVE A NICE DAY!!";
    delay(1000);
    exit(0);
   }

  }
}
