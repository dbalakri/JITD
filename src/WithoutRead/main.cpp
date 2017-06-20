#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

#include "jitd.h"
#include "jitd.cpp"
#include "policyTypes.h"
#include "cogTypes.h"
#include "tester.h"
#include "getLine.h"
#include "data.h"
#include "dataGenerator.h"


#define DATASEED 80
#define QUERYSEED 44

using namespace std;

int main(int argc, char* argv[]) {

    if(argc < 2){
        cout << "Please enter testscript file" << endl;
        return -1;
    }
    vector<policy<data>* > policies;
    vector<string> line;
    ifstream ifile(argv[1]);
    line = getLine(ifile);
    string pol("policy");
    if(line[0].compare(pol) == 0){
        string crack("crack");
        string sort("sort");
        for (int i = 1; i < line.size(); ++i) {
            if(line[i].compare(crack) == 0) {
                int s = stoi(line[++i]);
                policy<data>* p1 = new crackPolicy<data>(s);
                policies.push_back(p1);
            }
            else if(line[i].compare(sort) == 0) {
                policy<data>* p2 = new sortPolicy<data>();
                policies.push_back(p2);
            }
        }
    }
    else {
        return 0;
    }
    hybridPolicy<data>* p = new hybridPolicy<data>(policies);
    data* array;
    int size = 100;
    int high = size;
    array = (data*)calloc(size, sizeof(data));
    dataGenerator(DATASEED, 0, high, array, size);
    vector<data> vec;
    for(int i = 0; i < size; i++)
    {
        vec.push_back(*(array + i));
        //cout << vec[i].value << ",";
    }
   sort(vec.begin(), vec.end());
    /*SORTED ARRAY COG*/
    cog* s = new sortedarrayNode<data>(vec);
    jitd<data> myJitd1(s,p);
    /*CONCAT COG*/
    vector<data> lB, rB, lC, rC;
    for (int i = 0; i < vec.size(); ++i) {
        if(i%2 == 0){
            lC.push_back(vec[i]);
        }
        else {
            rC.push_back(vec[i]);
        }
    }   
    cog* l = new sortedarrayNode<data>(lC);
    cog* r = new sortedarrayNode<data>(rC);
    cog* c = new concatNode(l,r);
    jitd<data> myJitd2(c,p);
    /*BTREE COG*/
    data k = vec[vec.size()/2];
    for(int i=0;i<vec.size();i++)
    {
        if(i<(vec.size()/2))
        {
            lB.push_back(vec[i]);
        }
        else
        {
            rB.push_back(vec[i]);
        }
    }
    cog* lBT = new sortedarrayNode<data>(lB);
    cog* rBT = new sortedarrayNode<data>(rB);
    cog* b = new btreeNode<data>(k,lBT,rBT);
    jitd<data> myJitd3(b,p);
    tester myTester(DATASEED, QUERYSEED, &myJitd1);
    //tester myTester(DATASEED, QUERYSEED, &myJitd2);
    //tester myTester(DATASEED, QUERYSEED, &myJitd3);
    
    string end("end");
    string insert("insert");
    string scan("scan");
    do{
            line = getLine(ifile);
            if(line[0].compare(insert) == 0){
            int queryCount = stoi(line[1]);
            int dataMin = stoi(line[2]);
            int dataMax = stoi(line[3]);
            int dataSize = stoi(line[4]);
            myTester.insert(queryCount, dataSize, dataMin, dataMax);
        }
        else if(line[0].compare(scan) == 0){
            int queryCount = stoi(line[1]);
            int dataMin = stoi(line[2]);
            int dataMax = stoi(line[3]);
            int rangeSize = stoi(line[4]);
            double hhDataRange = stod(line[5]);
            double hhProbability = stod(line[6]);    
            myTester.scan(queryCount, dataMin, dataMax, rangeSize, hhDataRange, hhProbability);
        }
    } while(line[0].compare(end) != 0);    
    // cout << "RUNTIMES:" << endl << myTester.runtimes[0];
    // for (int i = 1; i < myTester.runtimes.size(); ++i){
    //     cout << endl << myTester.runtimes[i];
    // }
    cout << "The total runtime is :" << myTester.total_time;
    cout << endl;
    // for (int i = 0; i < result.size(); ++i){
    //  cout << result[i] << endl;
    // }

    return 0;
}
