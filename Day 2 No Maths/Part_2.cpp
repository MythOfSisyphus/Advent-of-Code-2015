#include<bits/stdc++.h>

using namespace std;


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

        int least_perimeter = 2 * accumulate(sides.begin(), sides.begin() + 2, 0);

        int volume_of_box = accumulate(sides.begin(), sides.end(), 1, multiplies<int>());

        required_ribbon += volume_of_box + least_perimeter;
        
    }

    inputfile.close(); // closing the file

    cout<<"Required ribbon : "<<required_ribbon<<" feet.";
    return 0;
}