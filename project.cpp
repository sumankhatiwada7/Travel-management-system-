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
