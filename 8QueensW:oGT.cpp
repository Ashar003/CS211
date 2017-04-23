//Akash Sharma- CS211
#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;


bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
}

void backtrack(int &col){
    col--;
    if(col==-1) exit(1);
}

void print(int q[]){
    static int count =0;
    count++;
    cout<<"Solution Number: "<<count<<endl;
    for(int i=0; i<8; i++)
        cout<<q[i];
    cout<<endl<<endl;
}

int main(){
    int q[8]; //board setup section
    q[0]=0; //Set position 0 to a value of 0
    int c=0;
    bool from_backtrack=false;
    
    while(true){
        while(c<8){
            if(!from_backtrack)
                q[c]=-1;// Initizalize row number
        while(q[c]<8){
            q[c]++; //  Increasing row number
                if(q[c]==8){ //Check the row number and call backtrack if it has reached row 8
                    backtrack(c);
                        continue; //Continue the function once it comes from backtrack
                }
                if(ok(q,c))// If the function is true, then it breaks out of the while loop
                    break;
            }
            c++; //Increment row number
            from_backtrack=false;
        }
        print(q); //To call the print function to print
        backtrack(c); //To backtrack
        from_backtrack=true;
    }
}
