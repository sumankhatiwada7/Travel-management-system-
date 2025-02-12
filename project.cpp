#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>
#include <windows.h>
using namespace std;



// Function prototypes
void menu();

// Admin Class
class Admin {
private:
    string adminUsername = "adminadmin";
    string adminPassword = "admin@123";
public:
    bool login() {
        string inputUsername, inputPassword;
        char re = 'y';
        while (re == 'y' || re == 'Y') {
            cout << "Enter admin username: ";
            getline(cin, inputUsername);
            cout << "Enter admin password: ";
            getline(cin, inputPassword);

            if (adminUsername == inputUsername && adminPassword == inputPassword) {
                return true;
            } else {
                cout << "\nInvalid username or password!\n";
            }

            cout << "\nTry again? (y/n): ";
            cin >> re;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return false;
    }

    void displayStats() {
        cout << "\n--- System Statistics ---\n";
        ifstream customerFile("O.CUSTOMERDETAILS.txt");
        if (!customerFile) {
            cout << "No customer records found!\n";
        } else {
            int count = 0;
            string line;
            while (getline(customerFile, line)) {
                if (line.find("Customer ID") != string::npos) {
                    count++;
                }
            }
            cout << "Total Customers: " << count << endl;
        }
        customerFile.close();
        cout << "\n";
    }
};

class Customer {
protected:
    string name, gender, address,destination;;
    
    int age = 0;
  unsigned  long long mobileNumber = 0;
    int customerId ;
public:
   void details() {
    cout << "\n--- Customer Details ---\n";
    while (true) {
        cout << "Enter customer ID: ";
        if (cin >> customerId) {
           
            ifstream inFile("O.CUSTOMERDETAILS.txt");
            string line;
            bool idExists = false;

            while (getline(inFile, line)) {
                if (line.find("Customer ID: " + to_string(customerId)) != string::npos) {
                    idExists = true;
                    break;
                }
            }
            inFile.close();

            if (idExists) {
                cout << "Customer ID already exists! Please enter a unique ID.\n";
                continue;
            } else {
                break;
            }
        }
        cout << "Invalid input! Please enter numbers only.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter gender: ";
    getline(cin, gender);

    cout << "Enter address: ";
    getline(cin, address);
    int choice;
        while (true) {
            cout << "Choose Destination:\n1. Pokhara\n2. Chitwan\n3. Mustang\nEnter choice (1-3): ";
            cin >> choice;
            if (choice == 1) {
                destination = "Pokhara";
                break;
            } else if (choice == 2) {
                destination = "Chitwan";
                break;
            } else if (choice == 3) {
                destination = "Mustang";
                break;
            } else {
                cout << "Invalid choice! Please enter a number between 1 and 3.\n";
            }
        }

    while (true) {
        cout << "Enter age: ";
        if (cin >> age) break;
        cout << "Invalid input! Please enter numbers only.\n";
        cin.clear();
        cin.ignore();
    }

       while (true) {
        cout << "Enter a 10-digit mobile number: ";
        cin >> mobileNumber;

      
        if (cin.good() && mobileNumber >= 1000000000ULL && mobileNumber <= 9999999999ULL) {
            break;
        }
        cout << "Invalid input! Please enter exactly 10 digits.\n";
        
        cin.ignore(); 
    }

    ofstream details("O.CUSTOMERDETAILS.txt", ios::app);
    details << "Customer ID: " << customerId << "\n"
            << "Name: " << name << "\n"
            << "Mobile: " << mobileNumber << "\n"
            << "Gender: " << gender << "\n"
            << "Age: " << age << "\n"
            << "Address: " << address << "\n\n";
    details.close();

    cout << "\nDetails saved successfully!\n";
    sleep(1);
    system("cls");
}


    void showDetails() const {
        ifstream in("O.CUSTOMERDETAILS.txt");
        if (!in) {
            cout << "No customer records found!\n";
            return;
        }
        cout << "\n--- Customer Records ---\n";
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }

    void searchCustomer() {
        int searchId;
        cout << "Enter Customer ID to search: ";
        cin >> searchId;
        ifstream in("O.CUSTOMERDETAILS.txt");
        if (!in) {
            cout << "No customer records found!\n";
            return;
        }
        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find("Customer ID: " + to_string(searchId)) != string::npos) {
                found = true;
                cout << "\n--- Customer Found ---\n";
                cout << line << endl;
                for (int i = 0; i < 5; ++i) {
                    getline(in, line);
                    cout << line << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Customer not found!\n";
        }
        in.close();
    }

    void editCustomer() {
        int editId;
        cout << "Enter Customer ID to edit: ";
        cin >> editId;
        ifstream in("O.CUSTOMERDETAILS.txt");
        ofstream out("temp.txt");
        if (!in) {
            cout << "No customer records found!\n";
            return;
        }
        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find("Customer ID: " + to_string(editId)) != string::npos) {
                found = true;
                cout << "Editing Customer...\n";
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new gender: ";
                getline(cin, gender);
                cout << "Enter new address: ";
                getline(cin, address);
                cout << "Enter new age: ";
                cin >> age;
                cout << "Enter new mobile number: ";
                cin >> mobileNumber;

                out << "Customer ID: " << editId << "\n"
                    << "Name: " << name << "\n"
                    << "Mobile: " << mobileNumber << "\n"
                    << "Gender: " << gender << "\n"
                    << "Age: " << age << "\n"
                    << "Address: " << address << "\n\n";
                for (int i = 0; i < 5; ++i) getline(in, line);
            } else {
                out << line << "\n";
            }
        }
        if (!found) {
            cout << "Customer not found!\n";
        } else {
            cout << "Customer updated successfully!\n";
        }
        in.close();
        out.close();
        remove("O.CUSTOMERDETAILS.txt");
        rename("temp.txt", "O.CUSTOMERDETAILS.txt");
    }

    void deleteCustomer() {
        int deleteId;
        cout << "Enter Customer ID to delete: ";
        cin >> deleteId;
        ifstream in("O.CUSTOMERDETAILS.txt");
        ofstream out("temp.txt");
        if (!in) {
            cout << "No customer records found!\n";
            return;
        }
        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find("Customer ID: " + to_string(deleteId)) != string::npos) {
                found = true;
                for (int i = 0; i < 6; ++i) getline(in, line);
            } else {
                out << line << "\n";
            }
        }
        if (!found) {
            cout << "Customer not found!\n";
        } else {
            cout << "Customer deleted successfully!\n";
        }
        in.close();
        out.close();
        remove("O.CUSTOMERDETAILS.txt");
        rename("temp.txt", "O.CUSTOMERDETAILS.txt");
    }
    void manageCustomers() {
        int choice;
        while (true) {
            system("cls");
            cout <<  "\n--- Customer Management ---\n";
            cout << "1. Add Customer\n";
            cout << "2. Show Customers\n";
            cout << "3. Search Customer\n";
            cout << "4. Edit Customer\n";
            cout << "5. Delete Customer\n";
            cout << "6. Return to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    details();
                    break;
                case 2:
                    showDetails();
                    break;
                case 3:
                    searchCustomer();
                    break;
                case 4:
                    editCustomer();
                    break;
                case 5:
                    deleteCustomer();
                    break;
                case 6:
                    menu();
                default:
                    cout << "Invalid choice! Try again.\n";
                    sleep(1);
            }
        }
    }
    virtual ~Customer() {}  

};


// Cabs Class
class Cabs {
protected:
    float lastCost = 0;
public:
    void cabDetails(int id) {
        int cabChoice;
        int customerId=id;
        float km;
        bool valid = false;

        while (!valid) {
            system("cls");
            cout << "\n--- Cab Booking ---\n";
            cout << "1. Standard Cab (Rs.15/km)\n"
                 << "2. Luxury Cab (Rs.25/km)\n"
                 << "3. Return to Main Menu\n"
                 << "Enter choice: ";

            if (!(cin >> cabChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter numbers only.\n";
                sleep(1);
                continue;
            }

            if (cabChoice == 3) return;

            if (cabChoice < 1 || cabChoice > 2) {
                cout << "Invalid choice! Try again.\n";
                sleep(1);
                continue;
            }

            cout << "Enter kilometers to travel: ";
            while (!(cin >> km) || km <= 0) {
                cout << "Invalid input! Enter positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            float rate = (cabChoice == 1) ? 15 : 25;
            float cost = km * rate;
            cout << "\nEstimated cost: Rs." << cost << endl;

            int confirmation;
            cout << "1. Confirm booking\n2. Recalculate\nChoice: ";
            cin >> confirmation;

            if (confirmation == 1) {
                lastCost = cost;
                
                valid = true;
                sleep(2);
            }
        }
               ofstream cabFile("CABBOOKINGS.txt", ios::app);
        cabFile << "Customer ID: " << customerId << "\n"
                << "Cab Type: " << ((cabChoice == 1) ? "Standard" : "Luxury") << "\n"
                << "Total Cost: Rs." << lastCost << "\n\n";
        cabFile.close();
        cout << "\nBooking confirmed! Rs." << lastCost << " charged.\n";
    }
};

// Booking Class
class Booking{
protected:
    float hotelCost = 0;
public:
    void hotels (int id) {
    	int customerId=id;
        int choice;
        while (true) {
            system("cls");
            cout << "\n--- Hotel Booking ---\n";
            cout << "1. Avendra Hotel\n"
                 << "2. ChoiceYou Hotel\n"
                 << "3. ElephantBay Hotel\n"
                 << "4. Return to Main Menu\n"
                 << "Enter choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!\n";
                sleep(1);
                continue;
            }

            if (choice == 4) return;

            if (choice < 1 || choice > 3) {
                cout << "Invalid choice!\n";
                sleep(1);
                continue;
            }

            handleHotelChoice(choice);
            break;
        }
    }

private:
	int customerId;
    void handleHotelChoice(int hotel) {
        system("cls");
        int package;
        switch (hotel) {
            case 1:
                cout << "\n--- Avendra Hotel ---\n";
                cout << "1. Standard Pack - Rs.5000\n"
                     << "2. Premium Pack - Rs.10000\n"
                     << "3. Luxury Pack - Rs.15000\n"
                     << "4. Back\n"
                     << "Enter package: ";
                break;
            case 2:
                cout << "\n--- ChoiceYou Hotel ---\n";
                cout << "1. Family Pack - Rs.15000\n"
                     << "2. Couple Pack - Rs.10000\n"
                     << "3. Single Pack - Rs.5000\n"
                     << "4. Back\n"
                     << "Enter package: ";
                break;
            case 3:
                cout << "\n--- ElephantBay Hotel ---\n";
                cout << "1. Special Pack - Rs.5000\n"
                     << "2. Back\n"
                     << "Enter package: ";
                break;
        }

        while (!(cin >> package) || package < 1) {
            cout << "Invalid input! Enter valid package: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if ((hotel == 3 && package == 2) || package == 4) {
            hotels(customerId);

            return;
        }

        switch (hotel) {
            case 1:
                hotelCost = (package == 1) ? 5000 : (package == 2) ? 10000 : 15000;
                break;
            case 2:
                hotelCost = (package == 1) ? 15000 : (package == 2) ? 10000 : 5000;
                break;
            case 3:
                hotelCost = 5000;
                break;
        }

        ofstream hotelFile("HOTELBOOKINGS.txt", ios::app);
        hotelFile << "Customer ID: " << customerId << "\n"
                  << "Hotel Cost: Rs." << hotelCost << "\n\n";
        hotelFile.close();

        cout << "\nBooking successful! Rs." << hotelCost << " charged.\n";
        sleep(2);
    }
};

// Charges Class
class Charges :public  Customer,  public Cabs,  public Booking {
public:
  void printBill(int id) {
    int customerId = id;
    ofstream receipt("receipt.txt");
    receipt << "----- ABC Travel Agency -----\n"
            << "	RECEIPT	\n"
            << "Customer ID: " << Customer::customerId << "\n" 
            << "Name: " << Customer::name << "\n"              
            << "	\n"
            << "Cab Charges: Rs." << lastCost << "\n"
            << "Hotel Charges: Rs." << hotelCost << "\n"
            << "	\n"
            << "Total Charges: Rs." << (lastCost + hotelCost) << "\n"
            << "	\n";
    receipt.close();
    cout << "\n----- ABC Travel Agency -----\n";
    cout << "	RECEIPT	\n";
    cout << "Customer ID: " << customerId << "\n";
    cout << "Name: " << Customer::name << "\n";                
    cout << "	\n";
    cout << "Cab Charges: Rs." << lastCost << "\n";
    cout << "Hotel Charges: Rs." << hotelCost << "\n";
    cout << "	\n";
    cout << "Total Charges: Rs." << (lastCost + hotelCost) << "\n";
    cout << "	\n";
    cout << "Receipt saved to 'receipt.txt'\n";
    cout << "\nPress 1 to return to the main menu: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        menu();
    }
}
};


void menu() {
    Admin admin;
    Customer customer;
    Cabs cabs;
    Booking booking;
    Charges charges;
    int customerId;
    while (true) {
        system("cls");
        cout << "----- ABC Travel Agency -----\n";
      
        cout<<"1.. customermanagment\n";
        cout << "2.. Book Cab\n";
        cout << "3.. Book Hotel\n";
        cout << "4.. Generate Bill\n";
        cout << "5.. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            
            case 1:
            	
                customer. manageCustomers();
                break;
           
            case 2:
                cout << "Enter Customer ID: ";
                cin >> customerId;
                cabs.cabDetails(customerId);
                break;
            case 3:
                cout << "Enter Customer ID: ";
                cin >> customerId;
                booking.hotels(customerId);
                break;
                break;
            case 4:
                cout << "Enter Customer ID: ";
                cin >> customerId;
                charges.printBill(customerId);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
                sleep(2);
        }
    }

}

int main() {
    Admin admin;
    if(admin.login()){
    	  menu();
    }
    return 0;
}

