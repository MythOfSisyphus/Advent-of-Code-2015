#include<bits/stdc++.h>

using namespace std;

int main(){

    ifstream inputfile("input.txt");

    if(!inputfile){
        cerr<<"No file!"<<endl;
        return 1;
    }

    string line;

    int sum = 0;
    int position = 0;

    while(getline(inputfile, line)){
        if(sum == -1){
            break;
        }

        for(int i=0; i<line.size(); i++){
            if(line[i] == '('){
                position++;
                sum++;
                if(sum == -1){break;}
            }
            else if(line[i] == ')'){
                position++;
                sum--;
                if(sum == -1){break;}
            }
            else{
                continue;
            }
        }
    }

    inputfile.close();
    cout<<sum<<" at position "<<position<<endl;

    return 0;
}