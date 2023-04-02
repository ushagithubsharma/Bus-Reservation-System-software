#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
class bus
{
	private:
		string b_no,b_name,d_name;
		int b_seats;
	public:
		void menu();
		void new_bus();
		void view_bus();
		void single_view_bus();
		void all_view_bus();
		void update_bus();
		void del_bus();
		void route_bus();
		void detail_bus();
		void booking();
		void renew_bus();
		void search_booking();
		void update_booking();
		void delete_booking();
		void show_booking();
};
void bus::menu()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	cout<<"\n\n ***MAIN MENU***";
	cout<<"\n\n 1. ADD BUS RECORD";
	cout<<"\n 2. VIEW BUSES DETAIL";
	cout<<"\n 3. UPDATE BUS DETAIL";
	cout<<"\n 4. DELETE BUS DETAIL";
	cout<<"\n 5. ROUTS OF BUSES";
	cout<<"\n 6. BUS SEAT DEATIL";
	cout<<"\n 7. BOOKING RECORD";
	cout<<"\n 8. SEATS RENEW";
	cout<<"\n 9. SEARCH BOOKING RECORD";
	cout<<"\n 10. UPDATE BOOKING RECORD";
	cout<<"\n 11. DELETE BOOKING RECORD";
	cout<<"\n 12. SHOW ALL BOOKING RECORD";
	cout<<"\n 13. EXIT";
	cout<<"\n\n ENTER YOUR CHOICE : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			new_bus();
			break;
		case 2:
			view_bus();
			break;
		case 3:
			update_bus();
			break;
		case 4:
			del_bus();
			break;
		case 5:
			route_bus();
			break;
		case 6:
			detail_bus();
			break;
		case 7:
			booking();
			break;
		case 8:
			renew_bus();
			break;
		case 9:
			search_booking();
			break;
		case 10:
			update_booking();
			break;
		case 11:
			delete_booking();
			break;
		case 12:
			show_booking();
			break;
		case 13:
			exit(0);
		default:
			cout<<"\n\n Invalid Choice...Please Try Again...";
	}
	getch();
	goto p;
	
}
void bus::new_bus()
{
	p:
	system("cls");
	fstream file;
	string t_no,tb_name,td_name;
	int t_seats,found=0;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	cout<<"\n\n Bus No : ";
	cin>>b_no;
	cout<<"\n\n Bus Name : ";
	cin>>b_name;
	cout<<"\n\n Total Seats : ";
	cin>>b_seats;
	cout<<"\n\n Driver Name : ";
	cin>>d_name;
	file.open("bus.txt",ios::in);
	if(!file)
	{
		file.open("bus.txt",ios::app|ios::out);
		file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
		file.close();
	}
	else
	{
		file>>t_no>>tb_name>>t_seats>>td_name;
		while(!file.eof())
		{
			if(b_no==t_no)
			{
				found++;
			}
			file>>t_no>>tb_name>>t_seats>>td_name;
		}
		file.close();
		if(found==0)
		{
			file.open("bus.txt",ios::app|ios::out);
			file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			file.close();
		}
		else
		{
			cout<<"\n\n Duplicate Record Found....";
			getch();
			goto p;
		}
	}
	cout<<"\n\n New Bus Record Inserted Successfully....";
}
void bus::view_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	cout<<"\n\n 1. single bus view";
	cout<<"\n 2. All bus view";
	cout<<"\n 3. Go Back";
	cout<<"\n\n Enter Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			single_view_bus();
			break;
		case 2:
			all_view_bus();
			break;
		case 3:
			menu();
		default:
			cout<<"\n\nInvalid Choice...Please Try Again...";
	}
	getch();
	goto p;
}
void bus::booking()
{
	p:
	system("cls");
	fstream file;
	int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount=0,r_amount;
	char x;
	string t_no,s_b_no,customer_name,phone,from,to;
	cout<<"\n\t\t_________________BUS MANGEMENT SYSTEM__________________";
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error......";
	}
	else
	{
		cout<<"\n\n Bus No. :";
		cin>>t_no;
		file.close();
		file.open("seat.txt",ios::in);
		if(file)
		{
		file>>s_b_no>>s_s_no;
		while(!file.eof())
		{
			if(t_no==s_b_no)
			{
				count++;
			}
			file>>s_b_no>>s_s_no;
		}
		file.close();
        }

		file.open("bus.txt",ios::in);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				seats=b_seats;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(seats-count==0)
		{
			cout<<"\n\n All seats is already reserved...";
		}
		else if(found==1)
		{
			do{
				h:
				cout<<"\n\n Seat No. : ";
				cin>>s_no;
				if(s_no>seats)
				{
					cout<<"\n\n Seat no. is invalid...Please Try again...";
					file.close();
					goto h;
				}
				file.open("seat.txt",ios::in);
			if(!file)
			{
				file.open("seat.txt",ios::app|ios::out);
				file<<t_no<<" "<<s_no<<"\n";
				file.close();
			}
			else
			{
				file>>s_b_no>>s_s_no;
				while(!file.eof())
				{
					if(t_no==s_b_no&&s_no==s_s_no)
					{
						cout<<"\n\n seat is already reserved....Please Try again...";
						file.close();
						goto h;
					}
					file>>s_b_no>>s_s_no;
				}
				file.close();
				file.open("seat.txt",ios::app|ios::out);
				file<<t_no<<" "<<s_no<<"\n";
				file.close();
				
			}
			ss_no[i]=s_no;
			i++;
				cout<<"\n\n Booking another seat(Y/N) : ";
				cin>>x;
				
			}while(x=='y'||x=='Y');
			system("cls");
			cout<<"\n\t\t_________________BUS MANGEMENT SYSTEM__________________";
			cout<<"\n\n Customer name : ";
			cin>>customer_name;
			cout<<"\n\n Phone no. : ";
			cin>>phone;
			cout<<"\n\n From : ";
			cin>>from;
			cout<<"\n\n to : ";
			cin>>to;
			cout<<"\n\n single seat amount : ";
			cin>>s_amount;
			total_amount=s_amount*i;
			//total_amount=s_amount*i;
			cout<<"\n\n Total Amount : "<<total_amount;
			cout<<"\n Recieve amount : ";
			cin>>r_amount;
			file.open("customer.txt",ios::app|ios::in);
			file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
			file.close();
			system("cls");
			cout<<"\n\t\t_________________BUS MANGEMENT SYSTEM__________________";
			cout<<"\n\n\t\t***********************************************************";
		
			cout<<"\n\t\t_________________Booking Information__________________";
			cout<<"\n\n\t\t***********************************************************";
			cout<<"\n\n\t\tName :                        "<<customer_name;
			cout<<"\n\t\tFrom :                          "<<from;
			cout<<"\n\t\tTo :                            "<<to;
			cout<<"\n\t\tTotal Seats :                   "<<i;
			cout<<"\n\t\tReserved Seats :                ";
			for(int a=0;a<i;a++)
			{
				if(a!=0)
				cout<<",";
				cout<<ss_no[a];
			}
			cout<<"\n\t\tSingle Seat Amount :            "<<s_amount;
			cout<<"\n\t\tTotal Amount :                  "<<total_amount;
			cout<<"\n\t\tRecieve Amount :                "<<r_amount;
			cout<<"\n\t\tReturn Amount :                 "<<r_amount-total_amount;
			cout<<"\n\n\t\t***********************************************************";
			cout<<"\n\n\t\t    Thanku You So Much For Booking";
			cout<<"\n\n\t\t***********************************************************";
		}
		else
		{
			cout<<"\n\n Bus No. is invalid....Please Try Again....";
			getch();
			goto p;
		}
	}
	file.close();
}
void bus::single_view_bus()
{
	system("cls");
	string t_no;
	fstream file;
	int found=0;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Openning Error....";
	}
	else
	{
		cout<<"\n\n Bus NO. : ";
		cin>>t_no;
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"BUS N0.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
				cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Invalid Bus No.....";
		}
	}
}
void bus::all_view_bus()
{
	system("cls");
	fstream file;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Openning Error....";
	}
	else
	{
		cout<<"\n\nBUS N0.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
	}
}
void bus::update_bus()
{
	system("cls");
	fstream file,file1;
	string t_no,no,t_name,td_name;
	int t_seats,found=0;
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error....";
	}
	else
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file1.open("bus1.txt",ios::app|ios::out);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"\n\n New Bus No. : ";
				cin>>no;
				cout<<"\n\n Bus Name : ";
				cin>>t_name;
				cout<<"\n\n No. of seats : ";
				cin>>t_seats;
				cout<<"\n\n Driver Name : ";
				cin>>td_name;
				file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
				cout<<"\n\n\t\t\tUpdate Bus Record Successfully..";
				found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("bus1.txt","bus.txt");
		if(found==0)
		{
			cout<<"\n\n Bus No. is Invalid....";
		}
	}
}
void bus::del_bus()
{
	system("cls");
	fstream file,file1;
	string t_no;
	int found=0;
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error....";
	}
	else
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file1.open("bus1.txt",ios::app|ios::out);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"\n\n\t\t\tDelete Bus Record Successfully..";
				found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("bus1.txt","bus.txt");
		if(found==0)
		{
			cout<<"\n\n Bus No. is Invalid....";
		}
	}
}
void bus::route_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM__________";
	cout<<"\n\n 1. 1ST ROUT DETAILS";
	cout<<"\n\n 2. 2ND ROUT DETAILS";
	cout<<"\n\n 3. 3RD ROUT DETAILS";
	cout<<"\n\n 4. 4TH ROUT DETAILS";
	cout<<"\n\n 5. 5TH ROUT DETAILS";
	cout<<"\n\n ENTER YOUR CHOICE: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout<<"\n\n  From Bhiwani to Delhi";
			cout<<"\n 9:00 am ............................. 11:00 am";
			cout<<"\n    From Manesar to Riwari";
			cout<<"\n 12:00 pm ............................ 2:30 pm";
			cout<<"\n    From Mumbai to Goa ";
			cout<<"\n 4:00 am ............................. 9:00 am";
			cout<<"\n    From Lucknow to Rohtak";
			cout<<"\n 7:00 am ............................. 2:00 am";
			cout<<"\n    From Bhiwani to Riwari";
			cout<<"\n 10:00 am ............................ 11:30 am";
			cout<<"\n    From Rohtak to Delhi";
			cout<<"\n 8:30 am ............................. 10:00 am";
			break;
		case 2:
			system("cls");
			cout<<"\n\n   From Hisar to Bhiwani";
			cout<<"\n 9:00 am ............................. 10:00 am";
			cout<<"\n    From Rohtak to Gurgaon";
			cout<<"\n 12:00 pm ............................ 1:00 pm";
			cout<<"\n    From Bhiwani to Delhi";
			cout<<"\n 10:00 am ............................. 11:00 am";
			break;
		case 3:
			system("cls");
			cout<<"\n\n  From Hisar to Rohtak";
			cout<<"\n 8:30 am ............................. 9:30 am";
			cout<<"\n    From Rohtak to Faridabad ";
			cout<<"\n 1:00 pm ............................ 2:30 pm";
			cout<<"\n    From Faridabad to Lucknow ";
			cout<<"\n 4:00 pm ............................. 4:30 pm";
			cout<<"\n    From Hisar to Goa";
			cout<<"\n 7:00 am ............................. 12:00 pm";
			cout<<"\n    From Mumbai to Delhi";
			cout<<"\n 8:00 am ............................ 10:00 am";
			break;
		case 4:
			system("cls");
			cout<<"\n\n  From Chandigarh to Bangluru";
			cout<<"\n 1:00 pm ............................. 10:00 pm";
			cout<<"\n   From Gujarat to Sikkim ";
			cout<<"\n 8:00 pm ............................10:00 pm";
			cout<<"\n   From Jammu to Kashmir ";
			cout<<"\n 11:00 am ............................. 1:30 pm";
			cout<<"\n   From Bhiwani to Haridwar";
			cout<<"\n 5:00 pm ............................. 10:00 pm";
			cout<<"\n   From Delhi to Goa";
			cout<<"\n 6:00 am ............................ 11:00 pm";
			cout<<"\n    From Bangluru to Delhi";
			cout<<"\n 7:30 am ............................. 5:00 pm";
			cout<<"\n   From Chandigarh to Bhiwani";
			cout<<"\n 9:00 am ............................ 5:00 pm";
	        break;
		case 5:
			system("cls");
			cout<<"\n\n  From Riwari to Manesar";
			cout<<"\n 8:00 pm ............................. 12:00 am";
			cout<<"\n    From Manesar to Mumbai";
			cout<<"\n 11:00 pm ............................ 3:30 am";
			cout<<"\n    From Bhiwani to Noida";
			cout<<"\n 3:00 am ............................. 3:00 pm";
			cout<<"\n    From Chandigarh to Bangluru";
			cout<<"\n 7:30 am ............................ 5:00 am";
			break;
		default:
			cout<<"\n\n Invalid Choice...Please Try Again...";
			getch();
			goto p;
			
	}
	
	
}
void bus::detail_bus()
{
	system("cls");
	fstream file,file1;
	string t_no,s_b_no,s_no;
	int count=0,found=0;
	cout<<"\n\t\t_____________________BUS MANAGEMENT SYSTEM________________________";
	file.open("bus.txt",ios::in);
	file1.open("seat.txt",ios::in);
	if(!file||!file1)
	{
		cout<<"\n\n File Opening Error....";
	}
	else
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file1>>s_b_no>>s_no;
		while(!file1.eof())
		{
			if(t_no==s_b_no)
			{
				count++;
			}
			file1>>s_b_no>>s_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				system("cls");
				cout<<"\n\t\t_____________________BUS MANAGEMENT SYSTEM________________________";
				cout<<"\n\n Total No. of Seats : "<<b_seats;
				cout<<"\n\n Reserved No. of seats : "<<count;
				cout<<"\n\n Empty No. of Seats : "<<b_seats-count;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Bus No. is Invalid....";
		}
	}
}
void bus::renew_bus()
{
	system("cls");
	fstream file;
	char x;
	cout<<"\n\t\t___________________BUS MANAGEMENT SYSTEM______________________";
	file.open("seat.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Openeing Error...";
	}
	else
	{
		cout<<"\n\n Do you want renew all seats(y/n) : ";
		cin>>x;
		if(x=='y'||x=='Y')
		{
			file.close();
			remove("seat.txt");
			cout<<"\n\n\t\t\t\t All seats are empty....";
		}
		else
		{
			cout<<"\n\n\t\t\t Thank You all seats Reservation saved....";
	    }
    }
}
void bus::search_booking()

{
	system("cls");
	fstream file;
	int t_seats,t_amo,found=0;
	string name,no,phone,t_name;
	cout<<"\n\t\t___________________BUS MANAGEMENT SYSTEM______________________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening error....";
	}
	else
	{
		cout<<"\n\n customer name : ";
		cin>>t_name;
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{
			if(t_name==name)
			{
				if(found==0)
				{
					system("cls");
					cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM_____________";
				}
				cout<<"\n\n\n customer name : "<<name;
				cout<<"\n\n\n Bus no. : "<<no;
				cout<<"\n\n\n phone No. : "<<phone;
				cout<<"\n\n\n Reserved seats. : "<<t_seats;
				cout<<"\n\n\n Total Amount : "<<t_amo;
				cout<<"\n\n=============================================";
				found++;
			}
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n customer name is invalid.........";
		}
	}
}
void bus::update_booking()
{
	system("cls");
	fstream file,file1;
	int t_seats,t_amo,found=0,del_seats,i=0;
	string name,no,phone,t_phone,del_no;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM_____________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening Error....";
	}
	else
	{
		cout<<"\n\n phone no. : ";
		cin>>t_phone;
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{
			if(t_phone==phone)
			{
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt",ios::app|ios::out);
				file>>name>>no>>phone>>t_seats>>t_amo;
				while(!file.eof())
				{
					if(t_phone==phone)
					{
						del_no=no;
						del_seats=t_seats;
						
					}
					if(t_phone!=phone)
					{
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";						
					}
					
					file>>name>>no>>phone>>t_seats>>t_amo;
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seat.txt",ios::in);
				file1.open("seat1.txt",ios::app|ios::out);
				file>>no>>t_seats;
				while(!file.eof())
				{
					if(!(del_no == no && i<del_seats))
					{
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
					
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt","seat.txt");
				booking();
				cout<<"\n\n\t\t\t update Booking Successfully............";
				found++;
				goto h;
			}
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		h:
			if(found==0)
			{
				cout<<"\n\n Phone NO. is invalid.....";
			}
	}
	
}
void bus::delete_booking()
{
	system("cls");
	fstream file,file1;
	int t_seats,t_amo,found=0,del_seats,i=0;
	string name,no,phone,t_phone,del_no;
	cout<<"\n\t\t___________BUS MANAGEMENT SYSTEM_____________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening Error....";
	}
	else
	{
		cout<<"\n\n phone no. : ";
		cin>>t_phone;
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{
			if(t_phone==phone)
			{
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt",ios::app|ios::out);
				file>>name>>no>>phone>>t_seats>>t_amo;
				while(!file.eof())
				{
					if(t_phone==phone)
					{
						del_no=no;
						del_seats=t_seats;
						
					}
					if(t_phone!=phone)
					{
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";						
					}
					
					file>>name>>no>>phone>>t_seats>>t_amo;
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				cout<<"\n\n\t\t\t Delete Booking Successfully............";
				file.open("seat.txt",ios::in);
				file1.open("seat1.txt",ios::app|ios::out);
				file>>no>>t_seats;
				while(!file.eof())
				{
					if(!(del_no==no && i<del_seats))
					{
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
					
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt","seat.txt");
				found++;
				goto h;
			}
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		h:
			if(found==0)
			{
				cout<<"\n\n Phone NO. is invalid.....";
			}
	    }
	}
void bus::show_booking()
{
	system("cls");
	fstream file;
	int t_seats,t_amo,found=0;
	string name,no,phone;
	cout<<"\n\t\t___________________BUS MANAGEMENT SYSTEM______________________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening error....";
	}
	else
	{
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{

				cout<<"\n\n\n customer name : "<<name;
				cout<<"\n\n\n Bus no. : "<<no;
				cout<<"\n\n\n phone No. : "<<phone;
				cout<<"\n\n\n Reserved seats :  : "<<t_seats;
				cout<<"\n\n\n Total Amount : "<<t_amo;
				cout<<"\n\n=============================================";
				found++;
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n no any booking record found....";
		}
	}
}
int main()
{
	bus b;
	p:
	system("cls");
	string email,pass;
	char ch;
	cout<<"\n\n\t\t     ***************************BUS RESERVATION PROJECT*************************** ";
	cout<<"\n\n BY USHA SHARMA";
	cout<<"\n\n\t\t\t\t\t****Security Are Required****";
	cout<<"\n\n Email : ";
	cin>>email;
	cout<<"\n\n Password : ";
	for(int i=1;i<=4;i++)
	{
		ch=getch();
		pass += ch;
		cout<<"*";
	}
	if(email=="usha282002@gmail.com" && pass=="usha")
	{
		cout<<"\n\n\n\t\t\tLoading";
		for(int i=1;i<=5;i++)
		{
			Sleep(500);
			cout<<".";
		}
		b.menu();
    }
	else{
		cout<<"\n\n\t\tYour Email & Password is wrong...";
		getch();
		goto p;
	}
	return 0;
}
