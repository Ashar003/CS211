//Akash Sharma- CS211
#include <iostream>
using namespace std;

int main(){
    int q[8]; //Declaring of an array with 8 values.
    int c=0;
    int count=0;
    q[0]=0; //Place a queen in the upper left corner
    
NC:
    c++;
    if(c==8)
        goto Print;
    q[c]=-1;
    
NR:
    q[c]++;
    if(q[c]==8)
        goto Backtrack;
    
    //Test
    for(int i=0; i<c; i++){
        if((q[i]==q[c])||(abs(q[c]-q[i])==(c-i)))
            goto NR;
    }
    goto NC;
    
Backtrack:
    c--;
        if(c==-1) return 0;
            goto NR;
    
Print:
    count++;
        cout << "Solution #" << count << endl;
            for(int i=0; i<8; i++){
                cout<<q[i]; //Go through array and print
        
    }
        cout << endl<<endl;
    goto Backtrack;
}
