//Akash Sharma- CS211
#include <iostream>
using namespace std;
	int main (){
	int square;
	int b=1;
	
		while(true){
			square=b*b;
			if((b%10)%2==1 && (b/10)%2==1) {
				break;
		}else{
			b+=2;
		}
		cout<< "The first perfect square is " <<b<<endl;
	}
}
