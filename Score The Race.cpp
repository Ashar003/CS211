//Akash Sharma- CS211
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string get_team( string race ){
    char a;  //declare
    string team;  //declare
    sort(race.begin(), race.end()); //sort the races
    a = race[0];  //set to the first element
    team = team + a;
    for(int b = 0; b < race.length(); b++){
        if( race[b] != a){
            a = race[b];
            team = team + a;
        }
    }
    return team;
    
}
double score( string race, char team ){
    int a = 0;  //declare and intilizaize
    double b = 0;  //declare and intilizaize
    for (int c = 0; c < race.length();  c++){
        if( race[c] == team){
            b += c + 1;
            a++;
        }
    }
    return b / a; //return the average
    
}

int main(){
    string race; //declaring of strings race and team
    string team;
    
    while(true){ // So the process of asking for results keeps going through
        
        
        cout << " Enter the race outcome;Teams names should be in capital. Enter done to exit" << endl;
        cout << endl;
        cin >> race;
        if(race == "done"){ //if done is entered the while loop breaks, ending the program.
            break;
        }
        team = get_team(race);
        cout << " " << endl;
        cout << "There are " << team.length() << " teams participating." << endl; //Gives you the number of teams participating
        cout << " " << endl;
        cout << "Each team has " << race.length() / team.length() << " members." << endl; //The members are calcualated
        cout << " " << endl;
        cout << " " << "Team" << " " << "Positions" << endl << endl;
        
        double minScore = score( race, team[0] );
        for( char c : team ){
            double s = score( race, c );
            cout << " " << c << " " << score( race, c ) << endl;
            if( s < minScore){
                minScore = s;
            }
        }
        cout << endl << "The minium score is equal to:" << minScore << endl;
        system( "pause" );
    }
    
}

