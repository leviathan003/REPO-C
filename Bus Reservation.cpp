#include<iostream>
#include<conio.h>
using namespace std;
class Bus{
 private:
     string bus_name;
     int busnum;
     string route;
     int totseat;
     string pass_name;
     int seatnum;
     int seat;
     int up_seat;
 public:
     Bus(){
        bus_name = "No Name.";
        busnum = 0;
        route = "NA";
        totseat = 0;
        pass_name = "NA";
        seatnum = 0;
        seat = 0;
     }
    void book_ticket(){
        cout<<"Enter name of passenger: ";
        cin.ignore();
        getline(cin,pass_name);
        cout<<"Enter the seat number: ";
        cin>>seatnum;
        if(seatnum > totseat){
            cout<<"Seat not found!!";
        }
        else{
        up_seat = totseat;
        up_seat--;
        cout<<"Booked"<<endl;
        }
        cout<<"\n"<<endl;
    }
    void set_data(){
        cout<<"Enter bus number: ";
        cin>>busnum;
        cout<<"Enter bus name: ";
        cin.ignore();
        getline(cin,bus_name);
        cout<<"Enter route: ";
        cin.ignore();
        getline(cin,route);
        cout<<"Enter total seats: ";
        cin>>totseat;
        cout<<"\n"<<endl;
    }
    void show_data(){
        cout<<"\nName: "<<bus_name<<endl;
        cout<<"Bus no.: "<<busnum<<endl;
        cout<<"Route: "<<route<<endl;
        cout<<"Seats available: "<<up_seat<<endl;
        cout<<"\n"<<endl;
    }
    void chck_code(int code){
        if(code == busnum){
            show_status();
        }
        else{
            cout<<"Invalid Code!!";
        }
        cout<<"\n"<<endl;
    }
    void cancel_ticket(){
        cout<<"Enter seat number: ";
        cin>>seat;
        cout<<"Cancelled";
        up_seat++;
        cout<<"\n"<<endl;
    }
    void show_status(){
        int i;
        for(i=1;i<=totseat;i++){
            if(i == seatnum && seat != seatnum){
                cout<<i<<" Booked By "<<pass_name<<endl;
            }
            else{
                cout<<i<<" Unbooked "<<endl;
            }
        }
        cout<<"\n"<<endl;
    }
};
int main(){
    Bus b1;
    while(1){
    system("cls");
    int choice;
    cout<<"Enter choice: "<<endl;
    cout<<"1. Set bus data"<<endl;
    cout<<"2. Show data"<<endl;
    cout<<"3. Book Ticket"<<endl;
    cout<<"4. Show Status"<<endl;
    cout<<"5. Cancel ticket"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Choice ->";
    cin>>choice;
    switch(choice){
    case 1:
        b1.set_data();
        break;
    case 2:
        b1.show_data();
        break;
    case 3:
        b1.book_ticket();
        break;
    case 4:
        int code;
        cout<<"Enter the bus number: ";
        cin>>code;
        b1.chck_code(code);
        break;
    case 5:
        b1.cancel_ticket();
        break;
    case 6:
        exit(0);
        break;
    }
    getch();
  }
return 0;
}
