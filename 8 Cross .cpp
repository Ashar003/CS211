//Akash Sharma- CS211
#include <iostream>
using namespace std;

void backtrack(int &c){// Pass by reference for square number
    c--; //Goes to the previous square
    if(c==-1) exit(1); // Program will exit if it goes out of border
}

bool ok(int a[8], int c){
    int hp[8][4]=       {{-1, -1, -1, -1},  //helper array to test each column
                        {0, -1, -1, -1},
                        {1, -1, -1, -1},
                        {0, 1, 2, -1},
                        {1, 2, 3, -1},
                        {0, 3, 4, -1},
                        {3, 4, 5, -1},
                        {2, 4, 6, -1}};
    for(int i=0; i<c; i++){
        if(a[i]==a[c]) return false;  // One of the tests that the array go through; The array is checking through the previous values of the array to see if there is a repeat
    }
    for(int j=0; hp[c][j]!=-1; j++){
        if(abs(a[c]-a[hp[c][j]])==1) return false; //The second test that the array goes through using the helper array
    }
    return true; //The function will return ok if both of tests are passed.
}

void print(int a[8]){   //The print function
    static int count=1;
    cout << endl<< "solution: "<<count++;
    cout<<endl;
    cout << "  " << a[1] << " " << a[2] <<" "<< a[0] << " " << a[3] << " " << a[4] << " " << a[7]<< "  " << a[5] << " " << a[6] << endl;// Arranged in a specific order
}

int main(){
    int a[8]={0}; //Intiliaze an array with 8 spots all having 0 inside
    int c=0; // Square that we start of with
    bool from_backtrack=false;
    
    while(true){ //Until the backtrack is true this function will run
        while(c<8){
            if(!from_backtrack)// While it's false, keep running
                a[c]=0;
            while(a[c]<9){ //While you haven't reached the 8th square keep going up
                a[c]++;
                if(a[c]==9){ //If you reach the 9th square, call of backtrack function.
                    backtrack(c);
                    continue;
                }
                if(ok(a,c)) break;   //If it checks out then break out of the while loop
            }
            c++;
            from_backtrack=false;   // Goes to print and backtrack right after
        }
        print(a);
        backtrack(c);
        from_backtrack=true; //To get into the first while loop
    }
    return 0;
}


