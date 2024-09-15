#include<iostream>
#include<fstream>
#include<cmath>
#include<regex>
#include<vector>
#include<utility>
#include<string>

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
        cerr<<"your file samples.txt can't be found in cwd."<<endl;
        return 1;
    }
    
    string line;
    
    while(getline(inputfile, line)){
        string santa_instruct = instructions(line, pattern_2);
        vector<int> coordinates_x_y = coordinates(line, pattern);

        int start_x = min(coordinates_x_y[0], coordinates_x_y[2]);
        int end_x = max(coordinates_x_y[0], coordinates_x_y[2]);

        int start_y = min(coordinates_x_y[1], coordinates_x_y[3]);
        int end_y = max(coordinates_x_y[1], coordinates_x_y[3]);

        if(santa_instruct == "turn on"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j]++;
                }
            }
        }
        else if(santa_instruct == "turn off"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j] = (Vec[i][j] == 0) ? 0 : (--Vec[i][j]);
                }
            }
        }
        else if(santa_instruct == "toggle"){
            for(int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){
                    Vec[i][j] += 2;
                }
            }
        }
    }

    inputfile.close();

    int lit_brightness = 0;

    for(const auto& i : Vec){
        for(const auto& j : i){
            lit_brightness += j;
        }
    }

    cout<<"Brightness increased by: "<<lit_brightness<<endl;

    return 0;
}