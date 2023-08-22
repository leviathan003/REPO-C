#include<iostream>
#include<fstream>
using namespace std;
class atm{
 private:
     int acc_num;
     string holder;
     int balance;
 public:
    void deposit(){
        int sum;
        cout<<"Enter amount: ";
        cin>>sum;
        balance = balance+sum;
    }
    void withdrawal(){
        int sum;
        cout<<"Enter the amount: ";
        cin>>sum;
        balance = balance-sum;
    }
    void set_data(){
        cout<<"Enter the details below to proceed: "<<endl;
        cout<<"Name of Holder: ";
        cin.ignore();
        getline(cin,holder);
        cout<<"Acc number: ";
        cin>>acc_num;
        cout<<"Enter balance: ";
        cin>>balance;
    }
    void show_data(){
        cout<<"Name of Holder: "<<holder<<endl;
        cout<<"Acc number: "<<acc_num<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    void show_balance(){
        cout<<"Balance: "<<balance<<endl;
    }
};
int main(){
    atm a1;
    while(1){
    int choice;
    cout<<"\nEnter the choice: "<<endl;
    cout<<"1. Enter name,acc number and balance"<<endl;
    cout<<"2. Show the data"<<endl;
    cout<<"3. Deposit Money"<<endl;
    cout<<"4. Withdraw Money"<<endl;
    cout<<"5. Show total balance"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Choice ->";
    cin>>choice;
    switch(choice){
    case 1:
        a1.set_data();
        break;
    case 2:
        a1.show_data();
        break;
    case 3:
        a1.deposit();
        break;
    case 4:
        a1.withdrawal();
        break;
    case 5:
        a1.show_balance();
        break;
    case 6:
        exit(0);
        break;
        }
    }
return 0;
}
