#include<bits/stdc++.h>

using namespace std;

bool three_vowels(const string &s){
    regex pattern("[aeiou].*[aeiou].*[aeiou]");

    if(regex_search(s, pattern)){
        return true;
    }
    return false;
}

bool double_letter(const string &s){
    regex pattern("([a-z])\\1");

    if(regex_search(s, pattern)){
        return true;
    }
    return false;
}

bool isThere(const string &s){
    regex pattern("ab|cd|pq|xy");

    if(regex_search(s, pattern)){
        return true;
    }
    return false;
}

bool isNice(const string &s){
    if(isThere(s)){
        return false;
    }
    if(three_vowels(s) && double_letter(s)){
        return true;
    }
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

    return 0;
}