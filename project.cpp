#include<iostream>
#include<fstream>

#include<string>
using namespace std;

class Customer{
	private:
	string name,gender,address;
	int age,mobileNumber,customerId;
	public:
		void details(){
			ofstream details("O.CUSTOMERDETAILS.txt",ios::app);{
			cout<<"Enter name:"<<endl;
			getline(cin,name);
			cout<<"Enter gender:"<<endl;
			getline(cin,gender);
			cout<<"Enter address:"<<endl;
			getline(cin,address);
			cout<<"Enter age:"<<endl;
			cin>>age;
			cout<<"Enter mobileNumber:"<<endl;
			cin>>mobileNumber;
			cout<<"Enter customerId:"<<endl;
			cin>>customerId;
		}
		 details<<"customerId:"<<customerId<<endl
		 <<"name:"<<name<<endl
		 <<"mobileNumber:"<<mobileNumber<<endl
		 <<"gender:"<<gender<<endl
		 <<"age:"<<age<<endl
		 <<"address:"<<address<<endl;
		}
		void showdetails(){
			
		}
};
class Cabs{
	private:
		int cabchoice;
		int km;
		float cost;
		float lastcost;
	public:
		void cabdetails(){
			
		cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------ABC Cabs-----------\n" << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;
        int hirecab;
        if(cabchoice==1){
        	cost=km*15;
        	cout<<"your cost for standard cab is "<<cost<<endl;
        	cout<<"press 1 to hire this car "<<endl;
        	cout<<"or"<<endl;
        	cout<<"press 2 to select another cab";
        	cin>>hirecab;
        	system("cls");
        	if(hirecab==1){
        		lastcost=cost;
        		cout<<"You have successfully hired a standard cab"<<endl;
        		cout<<"goto menu and take recipt"<<endl;
			}
			else if(hirecab==2){
				cabdetails();
			}
			else{
				cout<<"INVALID INPUT! REDERCATING TO PREIVOUS MENU"<<endl;
				sleep(999);
				system("cls")
				cabdetails();
			}
		}
		}
	
};
class Booking{
	
};
class Charges{
	
};
intmain(){
	Customer obj;
	obj.details();
	return 0;
}