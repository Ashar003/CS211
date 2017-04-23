//Akash Sharma- CS211
#include <iostream>
#include <cmath>
using namespace std;


//created with help of Waxman's template

void backtrack(int &col){
    col--;// decrement col
    if(col==-1){ // If it goes out of border exit program
        exit(1); //exit
    }
}

bool ok(int q[], int c){
    for(int i=0; i<c; i++)
        if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) // we check to see if a queens interferes
            return false;
    return true;
}



void print(int q[]) {
    
    
    static int solution = 0; //starting off from solution 0
    solution++;
    cout<<"solution number:"<<solution<<endl<<endl;
    
    int i;
    int j;
    int k;
    int l;
    
    //declaring of the variables used in the loops
    
    typedef char box[5][7]; // make box a type 5 x 7 array
    box bb;
    box wb;
    box *board[8][8];
    //declaring of different boxes
    
    char b = char(219); // set b = to asci code 219

    
    //Filling in off the black box and whitebox
    for(i=0;i<5;i++)
        for( j=0;j<7;j++){
            wb[i][j]=' '; //set that eual to blank space
            bb[i][j]=char(219); //this is equal to asci code 219
        }


   static box bq = //using the declared char b, we set up the crown, black queen
    {
        b, b, b, b, b, b, b,
        b, ' ', b, ' ', b, ' ', b,
        b, ' ', ' ', ' ', ' ', ' ', b,
        b, ' ', ' ', ' ', ' ', ' ', b,
        b, b, b, b, b, b, b };
    
   static box wq =  //using the declared char b, we set up the crown, white queen
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', b, ' ', b, ' ', b, ' ',
        ' ', b, b, b, b, b, ' ',
        ' ', b, b, b, b, b, ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    
    for(i=0;i<8;i++)    // Fill board with pointers to bb and wb in alternate positions.
        for(j=0;j<8;j++)
            if((i+j)%2==0){ //to check if it's Even
                if(q[i]==j){
                    board[i][j]=&wq;    // You are setting the position equal to the address
                } else {
                    board[i][j]=&wb;    // You are setting the position equal to the address
                }
            } else {
                if(q[i]==j){
                    board[i][j]=&bq;  // You are setting the position equal to the address
                } else {
                    board[i][j]=&bb;    // You are setting the position equal to the address
                }
            }
    

    
    // Upper border is printed
    for (i=0; i<7*8; i++)
        cout << '_';
    cout << "\n";
    
    // Board is printed now
    for (i=0; i<8; i++)          // for each board row
        for (k=0; k<5; k++) {     // for each box row
            cout << char(179);
            for (j=0; j<8; j++)    // for each board column
                for (l=0; l<7; l++) // for each box column
                    cout << (*board[i][j])[k][l]; // cout what is being pointed to
            cout << char(179) << "\n";
        }
    
    // Lower border is printed
    cout << " ";
    for (i=0; i<7*8; i++)
        cout << char(196);
    cout << "\n\n";
}
    

int main(){
    int q[8]; // declrare an array with 8 value
     q[0]=0; // set the first valueof the array with a queen
    int c=1; // start column from 1
    
    bool backtracking =false;
    
    while(true){ // it will keep running while it is true
        while(c<8){  //while you are in bounds of column
            
            if(backtracking == false)
                q[c]=-1; //
            backtracking =true;
            
            while(q[c]<8){ // while we are less than column
                q[c]++;
                
                if(q[c]==8){ // if you are column 8 , lets go to backtrack function
                    backtracking = true;
                    backtrack(c);
                    break; //break
                }
                
                if(ok(q,c)){ //check using the function ok
                    backtracking =false;
                    c++;
                    break;
                }
                
            }
            
        }
        print(q); // go to print function, print q
        backtracking =true; 
        backtrack(c);
    }
    
    return 0;
}



