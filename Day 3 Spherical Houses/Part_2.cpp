#include<iostream>
#include<fstream> // for file/IO
#include<utility> // for pair
#include<set> // for set

using namespace std;

void move(pair<int, int>& position, const char& direction, set<pair<int, int>>& houses){
    switch(direction){
        case '^' : position.second++; break;
        case 'v' : position.second--; break;
        case '>' : position.first++; break;
        case '<' : position.first--; break;
    }

    houses.insert(position);
}

int main(){

    /*
    // Making concept for Santa and Robo-Santa

    string sample = "<^<v^>v^<^^<>^^>^><>>^><>><^<v><^^^>>vv>^><vv>^^^^^";

    int sample_size = sample.size();

    cout<<"Sample size: "<<sample_size<<endl;
    cout<<sample<<endl;

    if(sample_size%2 == 1){
        for(int i=1; i<sample.size(); i+=2){
            cout<<sample[i-1]<<sample[i];
        }
        cout<<sample[sample_size-1];
    }
    else{
        for(int i=1; i<sample.size(); i+=2){
            cout<<sample[i-1]<<sample[i];
        }
    }

    */
    
    pair<int, int> position_santa = {0, 0};
    pair<int, int> position_robo_santa = {0, 0};

    set<pair<int, int>> houses {{0, 0}}; // visited houses

    ifstream inputfile("../example.txt");

    if(!inputfile){
        cerr<<"File 'input.txt' could not be opened."<<endl;
        return 1;
    }

    string line;

    while(getline(inputfile, line)){

        for(int i=0; i<line.size(); i++){
            if(line[i] != '^' && line[i] != '>' && line[i] != '<' && line[i] != 'v'){
                cerr<<"Inavlid character in input "<<line[i]<<endl;
                continue;
            }

            if(i%2 == 0){
                move(position_santa, line[i], houses);
            }
            else{
                move(position_robo_santa, line[i], houses);
            }
        }
    }

    inputfile.close();

    cout<<"Number of visited hourses: "<<houses.size();


    return 0;
}