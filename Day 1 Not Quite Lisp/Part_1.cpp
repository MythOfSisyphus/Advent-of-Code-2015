#include <bits/stdc++.h>

using namespace std;

int main(){

    ifstream inputfile("input.txt");

    if (!inputfile){
        cerr << "There is no file.";
        return 1;
    }

    string line;

    int sum = 0;

    while (getline(inputfile, line)){
        for (int i = 0; i < line.size(); i++){
            if (line[i] == '(')
                sum++;
            else if (line[i] == ')'){
                sum--;
            }
            else{
                continue;
            }
        }
    }

    inputfile.close();

    cout<<sum<<endl;

    return 0;
}