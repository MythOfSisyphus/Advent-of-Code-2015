#include<bits/stdc++.h>

using namespace std;

// bool checker(const pair<int, int>& A, const vector<pair<int, int>>& Vec){
//     for(const auto &x : Vec){
//         if(x.first == A.first && x.second == A.second)
//             return false;
//     }
//     return true;
// }

int main(){
    
    /*
    pair<int, int> position {0, 0};

    vector<pair<int, int>> visited_houses {{0, 0}};

    string elf = "^>v<";

    for(char c : elf){
        if(c == '^'){
            position.second++;
            if(checker(position, visited_houses))
                visited_houses.push_back(position);
        }
        else if(c == '>'){
            position.first++;
            if(checker(position, visited_houses))
                visited_houses.push_back(position);
        }
        else if(c == 'v'){
            position.second--;
            if(checker(position, visited_houses))
                visited_houses.push_back(position);
        }
        else if(c == '<'){
            position.first--;
            if(checker(position, visited_houses))
                visited_houses.push_back(position);
        }
    }

    for(auto corrdinate : visited_houses){
        cout<<"("<<corrdinate.first<<", "<<corrdinate.second<<")" ;
    }

    */
    
    set<pair<int, int>> visited_houses {{0, 0}};

    pair<int, int> position {0, 0};

    ifstream inputfile("input.txt");

    if(!inputfile){
        cerr<<"File 'input.txt' could not be opened."<<endl;
        return 1;
    }

    string line;

    while(getline(inputfile, line)){
        for(int i=0; i<line.size(); i++){
            if(line[i] != '^' && line[i] != '>' && line[i] != '<' && line[i] != 'v'){
                cerr<<"Inavlid character in input "<<line[i]<<endl;
                return 1;
            }

            if(line[i] == '^'){
                position.second++;
                visited_houses.insert(position);
            }
            else if(line[i] == '>'){
                position.first++;
                visited_houses.insert(position);
            }
            else if(line[i] == '<'){
                position.first--;
                visited_houses.insert(position);
            }
            else if(line[i] == 'v'){
                position.second--;
                visited_houses.insert(position);
            }
        }
    }

    inputfile.close();

    // for(const auto& x : visited_houses)
    //     cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    
    // cout<<endl;
    cout<<"Number of visited hourses: "<<visited_houses.size();

    return 0;
}