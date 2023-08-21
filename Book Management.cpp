#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Book{
 private:
    int bookid;
    char title[20];
    float price;
 public:
    Book(){
        bookid = 0;
        strcpy(title,"No Title");
        price = 0;
    }
    void get_bookdata(){
        cout<<"Enter book id , title and price: ";
        cin>>bookid;
        cin.ignore();
        cin.getline(title,19);
        cin>>price;
    }
    void show_bookdata(){
        cout<<"\n"<<bookid<<" "<<title<<" "<<price;
    }
    int store_book(){
        if(bookid == 0 && price == 0){
            cout<<"Book data not initialized!";
            return 0;
        }
        else{
            ofstream fout;
            fout.open("book.txt",ios::app|ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();
            return 1;
        }
    }
    void viewall_books(){
        ifstream fin;
        fin.open("book.txt",ios::in|ios::binary);
        if(!fin){
            cout<<"\nFile not found.";
        }
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                show_bookdata();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
    void searchBook(char *t){
        int counter = 0;
        ifstream fin;
        fin.open("book.txt",ios::in|ios::binary);
        if(!fin){
            cout<<"\nFile not found!!";
        }
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(!strcmp(t,title)){
                    show_bookdata();
                    counter++;
                }
                fin.read((char*)this,sizeof(*this));
            }
            if(counter == 0){
                cout<<"\nBook not found!!";
            }
            fin.close();
        }
    }
    void update_bookdata(char *t){
        fstream file;
        file.open("book.txt",ios::in|ios::out|ios::ate|ios::binary);
        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof()){
            if(!strcmp(t,title)){
                get_bookdata();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
    }
    void delete_bookdata(char *t){
        ifstream fin;
        ofstream fout;
        fin.open("book.txt",ios::in|ios::binary);
        if(!fin){
            cout<<"\nFile not found!!";
        }
        else{
            fout.open("tempfile.txt",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(strcmp(t,title)){
                    fout.write((char*)this,sizeof(*this));
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("book.txt");
            rename("tempfile.txt","book.txt");
        }
    }
};
int menu(){
    int choice;
    cout<<"\n\tBook Management";
    cout<<"\n\n1. Insert book record";
    cout<<"\n2. View all book records";
    cout<<"\n3. Search book record";
    cout<<"\n4. Delete book record";
    cout<<"\n5. Update book record";
    cout<<"\n6. Exit";
    cout<<"\nEnter choice: ";
    cin>>choice;
    return choice;
}
int main(){
    Book b1;
    char title[20];
    while(1){
        system("cls");
        switch(menu()){
        case 1:
            b1.get_bookdata();
            b1.store_book();
            break;
        case 2:
            b1.viewall_books();
            break;
        case 3:
            cout<<"\nEnter title to search: ";
            cin.ignore();
            cin.getline(title,19);
            b1.searchBook(title);
            break;
        case 4:
            cout<<"\nEnter title to delete record: ";
            cin.ignore();
            cin.getline(title,19);
            b1.delete_bookdata(title);
            break;
        case 5:
            cout<<"\nEnter book title to update record: ";
            cin.ignore();
            cin.getline(title,19);
            b1.update_bookdata(title);
            break;
        case 6:
            cout<<"Program ended.";
            exit(0);
            break;
        }
        getch();
    }
return 0;
}
