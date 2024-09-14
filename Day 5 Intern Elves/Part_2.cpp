#include<bits/stdc++.h>

using namespace std;

// function for checking repeated pair of letter
bool repeated_pair(const string &s){
    regex pattern("([a-z]{2}).*\\1");

    return regex_search(s, pattern);
}

// function for checking is there any sandwitched letter in string
bool sandwitched_letter(const string &s){
    regex pattern("([a-z])[a-z]\\1"); 

    return regex_search(s, pattern);
}

bool isNice(const string &s){
    return repeated_pair(s) && sandwitched_letter(s);
}

int main(){

    fstream inputfile("input.txt");

    if(!inputfile){
        cerr<<"File 'input.txt' not found in the current working directory."<<endl;
        return 1;
    }

    string line;

    int counter = 0; // counter of nice strings

    while(getline(inputfile, line)){
        if(isNice(line))
            counter += 1;
    }

    inputfile.close();

    cout<<"There are "<<counter<<" nice strings in 'input.txt'."<<endl;

    string text = "xxyxx";
    cout<<isNice(text)<<endl;

    return 0;
}