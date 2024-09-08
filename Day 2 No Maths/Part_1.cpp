#include<bits/stdc++.h>

using namespace std;

/*
Remember these two functions are not optimized for other inputs.
I have wrote them for this specific task
*/

// function to find least product
int least_product(vector<int>& Vec){
    return (Vec[0] * Vec[1]);
}

int calculate_area(vector<int>& Vec){
    int result = 2 *(Vec[0]*Vec[1] + Vec[1]*Vec[2] + Vec[2]*Vec[0]);

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

    unsigned int required_wrapping_paper = 0;
    
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

        int least__ = least_product(sides);
        int sum_of_areas  = calculate_area(sides);

        required_wrapping_paper += sum_of_areas + least__;

        // cout<<"Area : "<<sum_of_areas<<", area of least side : "<<least__<<", total required: "<<sum_of_areas + least__<<endl;

    }

    inputfile.close(); // closing the file

    cout<<"Hence, Santa needed to order : "<<required_wrapping_paper<<" square feet of wrapping paper.";

    return 0;
}