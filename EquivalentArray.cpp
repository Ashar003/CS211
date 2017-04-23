//Akash Sharma- CS211
#include <iostream>
using namespace std;
void rightShift(int a[], int size){
    int temp = a[0];// Var temp is assigned the first value of the array.
    for (int i = 0; i < (size-1); i++){
        a[i] = a[i + 1]; // Current 'i' is assigned the right next value
    }
    a[size-1] = temp; // Last value is assigned the original first value
}


bool equivalent (int a[], int y[], int size){
    for(int i=0; i< size; i++)
        if (a[i] == y[i])
            return true;
    return false;
    
    
}

int main(){
    int a[5]= {1,2,3,4,5};
    int y[5]= {2,3,4,5,1};
    bool isEqual = false;
    
    while( isEqual != true){ //As long "isEqual" is not true, the while loop will continue running.
        if (equivalent(a, y, 5)){
            isEqual = true; 
        }
        else if (isEqual == false){
            rightShift(a, 5);   // If isEqual is false, then rightShift is called.
        }
        else{ //If the arrays aren't equal even after right shifting, then the while loop will be broke.
            isEqual=false;
            break;
        }
    }
    
    if (isEqual== true) {
        cout<< "Arrays, a & y, are equivalent" <<endl;
    }
    
    else if(isEqual== false) {
        cout<< "Arrays, a & y, are not equivalent" <<endl;
    }
    
    
    return 0;
}
