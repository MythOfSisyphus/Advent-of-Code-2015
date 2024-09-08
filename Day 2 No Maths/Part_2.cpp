#include<bits/stdc++.h>

using namespace std;

/*
Remember these two functions are not optimized for other inputs.
I have wrote them for this specific task
*/

int perimeter(vector<int>& Vec){
    int result = 2*(Vec[0] + Vec[1]);
    return result;
}

int cubic_volume(vector<int>& Vec){
    int result = Vec[0]*Vec[1]*Vec[2];
    return result;
}

int main(){

    // file to be read
    ifstream inputfile("sample_input.txt");

    if(!inputfile){
        cerr<<"File not found!"<<endl;
        return 1;
    }

    string line; // variable for line in sample_input

    regex pattern("\\d+");

    unsigned int required_ribbon = 0;
    
    while(getline(inputfile, line)){
        auto word_begin = sregex_iterator(line.begin(), line.end(), pattern);
        auto word_end = sregex_iterator();

        vector<int> sides;

        for(sregex_iterator it = word_begin; it != word_end; it++){
            smatch match = *it;
            sides.push_back(stoi(match.str()));
        }

        // sorting the sides to easily find least product
        sort(sides.begin(), sides.end());

        int least_perimeter = perimeter(sides);

        int volume__ = cubic_volume(sides);

        required_ribbon += volume__ + least_perimeter;
        
    }

    inputfile.close(); // closing the file

    cout<<"Required ribbon : "<<required_ribbon<<" feet.";
    return 0;
}