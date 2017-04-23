//Akash Sharma- CS211
#include <iostream>
using namespace std;

bool ok(int q[], int col){
    
    int mp[3][3]={{0, 2, 1},  //men's preference
        {0, 2, 1},
        {1, 2, 0}};
    int wp[3][3]={{2, 1, 0}, //women's preference
        {0, 1, 2},
        {2, 0, 1}};
    
    int cman; //current man
    int cwoman; // current woman
    int nman; //new man
    int nwoman; // new woman
    
    //declaring all the variables to be used
    
    for(int i=0; i<col; i++){
        cman=i; //current man assigned a index
        cwoman=q[i]; //current woman is now married to assigned to a lucky guy
        nman=col; //assigned the next column
        nwoman=q[col];  // woman is assigned the man
        
        if(nwoman==cwoman) //if the they are assigned the same man keep going
            return false;
    }
    
    for(int i=0; i<col; i++){
        cman=i; //current man assigned a index
        cwoman=q[i]; ///current woman is now married to assigned to a lucky guy
        nman=col;  //assigned the next column
        nwoman=q[col]; // woman is assigned the man
        
        if(mp[cman][cwoman]>mp[cman][nwoman]&& wp[nwoman][cman]<wp[nwoman][nman]) //if pref is greater than of new and pref is less of new woman and current man false
            return false;
        
        if(mp[nman][cwoman]<mp[nman][nwoman]&& wp[cwoman][nman]<wp[cwoman][cman])
            //if pref is less than of old couple and less with new man false
            return false;
    }
    //using the preferences we use the array of mp and wp to check if they are combaitble
    // if we passed those preferences tests then we can break the while loop and print
    return true;
};

void backtrack(int &col){ //pass by reference to update column values
    col--; //go back in column
    if(col==-1) exit(1); // iff you go out of range then program exits
};

void print(int q[]){
    static int count=1; //declare it a static so everytime it runs the value stays the same; from 1
    cout << "solution #:" << count++ << endl;
    cout << "Man Woman" << endl;
    for(int i=0; i<3; i++){
        cout << " " << i << "    " << q[i] << endl;
    }
    cout << endl << endl;
};

int main(){
    int q[3]; //declaring of an array with 3 values
    q[0]=0; //set the first value equal to 0 since we have a woman there
    int c=0; //starting from column -
    bool from_backtrack=false;
    
    while(true){
        while(c<3){ //less than index 3
            if(!from_backtrack)
                q[c]=-1;// start before the index
            while(q[c]<3){
                q[c]++; //increment to next column
                if(q[c]==3){ //reached the end then backtrack
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) // if the prefrences check out then we break out of the while loops and print, backtrack, etc
                    break;
            }
            c++;
            from_backtrack=false;
        }
        print(q); // goes to print
        backtrack(c); //backtrack to check for more solution
        from_backtrack=true;
    }
    return 0;
}
