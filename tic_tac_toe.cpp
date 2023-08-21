#include <bits\stdc++.h>
using namespace std;

vector<char> grid = {'1','2','3','4','5','6','7','8','9'};

void display(){
    printf("\n ------- TIC TAC TOE --------\n");
    printf("\t-------------\n");
    printf("\t| %c | %c | %c |",grid[0],grid[1],grid[2]);
    printf("\n\t-------------");
    printf("\n\t| %c | %c | %c |",grid[3],grid[4],grid[5]);
    printf("\n\t-------------");
    printf("\n\t| %c | %c | %c |",grid[6],grid[7],grid[8]);
    printf("\n\t-------------\n");
}

bool conditions(){
    if(grid[0]==grid[1] && grid[1]==grid[2] || grid[3]==grid[4] && grid[4]==grid[5] || 
    grid[6]==grid[7] && grid[7]==grid[8]){
        return true;
    }
    if(grid[0]==grid[3] && grid[3]==grid[6] || grid[1]==grid[4] && grid[4]==grid[7] || 
    grid[2]==grid[5] && grid[5]==grid[8]){
        return true;
    }
    if(grid[0]==grid[4] && grid[4]==grid[8] || grid[2]==grid[4] && grid[4]==grid[6]){
        return true;
    }
    return false;
}

void driver(){
    int x_pos,o_pos,count=9;
    char end;
    bool check;
    while(count>0){
        cout<<"Enter position of X: ";
        cin>>x_pos;
        while(grid[x_pos-1] == 'X' || grid[x_pos-1] == 'O'){ 
        cout<<"Position already occupied!\n";
        cout<<"Enter position of X: ";
        cin>>x_pos;
        }
        grid[x_pos-1] = 'X';
        display();
        check = conditions();
        if(check){
            cout<<"\n\nX wins!!\n";
            cout<<"Press 0 to End!";
            cin>>end;
            break;    
        }
        count = count-1;
        if(count == 0){
            cout<<"\n\nGG!! Draw match!\n";
            cout<<"Press 0 to End!";
            cin>>end;
        }
        if(!check && count>0){
            cout<<"Enter position of O: ";
            cin>>o_pos;
            while(grid[o_pos-1] == 'X' || grid[o_pos-1] == 'O'){ 
            cout<<"Position already occupied!\n";
            cout<<"Enter position of O: ";
            cin>>o_pos;
            }
            grid[o_pos-1] = 'O';
            display();
            check = conditions();
        }
        count = count-1;
        if(check){
            cout<<"\n\nO wins!!\n";
            cout<<"Press 0 to End!";
            cin>>end;
            break;
        }
    }
   
}

int main(){
    display();
    driver();
    return 0;
}