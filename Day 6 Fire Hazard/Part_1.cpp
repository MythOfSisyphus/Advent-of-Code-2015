#include<iostream>
#include<regex>
#include<string>
#include<vector>
#include<fstream>
#include<cmath> // for abs()
#include<utility>

using namespace std;

// function to get instruction for light
string instructions(const string &s, const regex &pttrn){
    smatch match; // for storing given instruction

    regex_search(s, match, pttrn); // searching with regex engine

    return match[0]; // returning santa's instruction
}

// vector for storing starting and ending corrdinates
vector<int> coordinates(const string &s, const regex &pttrn){
    vector<int> positions;

    auto str_begin = sregex_iterator(s.begin(), s.end(), pttrn);
    auto str_end = sregex_iterator();

    for(sregex_iterator it = str_begin; it != str_end; it++){
        positions.push_back(stoi(it->str()));
    }

    return positions;
}

int main(){

    regex pattern("\\d+"); 

    regex pattern_2("turn on|turn off|toggle");

    vector<vector<int>> Vec(1000, vector<int>(1000, 0));

    ifstream inputfile("samples.txt");

    if(!inputfile){
        cerr<<"Can't open file."<<endl;
        return 1;
    }

    string line;

    while(getline(inputfile, line)){

        string santa_instruct = instructions(line, pattern_2);
        vector<int> x_y_in_grid = coordinates(line, pattern);

        int start_x = min(x_y_in_grid[0], x_y_in_grid[2]);
        int end_x = max(x_y_in_grid[0], x_y_in_grid[2]);

        int start_y = min(x_y_in_grid[1], x_y_in_grid[3]);
        int end_y = max(x_y_in_grid[1], x_y_in_grid[3]);

        if(santa_instruct == "turn on"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j] = 1;
                }
            }
        }
        else if(santa_instruct == "turn off"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j] = 0;
                }
            }
        }
        else if(santa_instruct == "toggle"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j] = (Vec[i][j] == 0) ? 1 : 0;
                }
            }
        }
    }

    inputfile.close();

    int lit_lights = 0;

    for(const auto& i : Vec){
        for(const auto& j : i){
            if(j == 1)
                lit_lights += 1;
        }
    }

    cout<<"lit lights : "<<lit_lights<<endl;

    return 0;
}