//Akash Sharma- CS211
#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
    double area=0.0; // Set the variable area equal to 0.0, so basically like a reset everytime it runs
        for(double i=a; i<b; i+=0.0001) // for loop set up using a double since there are decimals involved
            area += (0.0001)*(f(i)); // area= area+ value  multiplied by the function
    return area;
    
}

double line(double x){
    return x;
}

double square(double x){
    return x*x;
}

double cube(double x){
    return x*x*x;
}

int main() {
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // The answers is 12 -rounded up
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // The answer is 41.3333
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // The answer is 156 -rounded up
    return 0;
}
