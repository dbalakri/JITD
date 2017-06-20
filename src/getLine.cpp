#include "getLine.h"
#include <vector>
#include <string>
#include <iostream>
#include <istream>

using namespace std;

vector<string> getLine(istream &in){
    string line;
    getline (in,line);
    int noswords = 1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ')
            noswords++;
    }
    string strWords[noswords];
    int counter = 0;
    for (int i = 0; i<line.length(); i++){
        if (line[i] == ' ')
            counter++;
        else
            strWords[counter] += line[i];
    }
    vector<string> words;
    for (int i = 0; i < noswords; i++) {
        words.push_back(strWords[i]);
    }
    return words;
}
