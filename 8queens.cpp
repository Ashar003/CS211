//Akash Sharma- CS211
#include <iostream>
using namespace std;

int main(){
    
    int b[8][8]={0};//Every position is now set to 0; If not then, the computer can't search where there is nothing.
    int r; //Initialize
    int c=0; //Initialize
    int count=0; // Because we are starting off from solution 1
    b[0][0]=1;  //We put a queen in the top position.
    
next_col: c++; //Next column
    if(c==8)
        goto print; //Solution found
    r=-1;
    
next_row: r++;
    if(r==8)
        goto Backtrack; //If last row is reached without a solution, it will backtrack
    
    //Row test
    for(int i=0; i<c; i++){
        if(b[r][i]==1)
            goto next_row;
    }
    
    //Up-diagonal test
    for(int j=1; ((c-j)>=0)&&((r-j)>=0); j++){
        if(b[r-j][c-j]==1)
            goto next_row;
    }
    
    //Down-diagonal test
    for(int k=1; ((c-k)>=0)&&((r+k)<8); k++){
        if(b[r+k][c-k]==1)
            goto next_row;
    }
    
    //Given that those 3 tests were passed.
    b[r][c]=1; //Place a queen, given all those tests were passed
        goto next_col;
    
Backtrack: //Backtrack
    c--; //Move back 1 column
        if(c==-1) return 0; // End the program if it goes out of border.
            r = 0; //Finding the queen can only be down from the row 0.
        while(b[r][c]!=1) r++; //While you can't find a Queen, let's keep going to the next row.
            b[r][c]=0; //Change the position we are on to 0, given those above cirucmtances.
                goto next_row;
    
print:
    count++;
        cout << "Solution # " << count<< endl;
            for(int i=0; i<8; i++){
                for(int n=0; n<8; n++){
                    cout << b[i][n] << " "; //Print out what's in each of rows/column.
        }
        cout << endl;
    }
        cout << endl;
    goto Backtrack;
    
}
