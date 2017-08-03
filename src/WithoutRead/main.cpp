#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <math.h>
#include "jitd.h"
#include "jitd.cpp"
#include "policyTypes.h"
#include "cogTypes.h"
#include "data.h"
#include "dataGenerator.h"
#define DATASEED 80
#define QUERYSEED 44

using namespace std;

int main(int argc, char* argv[]) {

    if(argc < 2){
        cout << "Please enter data size " << endl;
        return -1;
    }
    int size = atoi(argv[1]);
    int high = size;
    int loopvar = 10/size;
    vector<policy<data>* > policies;
    hybridPolicy<data>* p = new hybridPolicy<data>(policies);
    data* array;
    array = (data*)calloc(size-2, sizeof(data));
    dataGenerator(DATASEED, 0, high, array, size-2);
    vector<data>* vec = new vector<data>();
    data elem1(high/2,high/2);
    vec->push_back(elem1);
    for(int i = 0; i < size-2; i++)
    {
        vec->push_back(*(array + i));
    }
    data maxelem(high+1,high+1);
    
    vec->push_back(maxelem);
    using clock = std::chrono::steady_clock;
    clock::time_point startpoint;
    clock::time_point endpoint;
    clock::duration execution_time;
    vector<data>* result = new vector<data>();
    // /*Array Cog*/
    // cout<< "Array Cog : ";
    // cog* a = new arrayNode<data>(vec);
    // jitd<data> myJitd0(a,p);
    // startpoint = clock::now();
    // for(int i=0; i<loopvar;i++)
    // {
    //     result = new vector<data>();
    //     myJitd0.scan(maxelem,maxelem,*result);
    // }
    // endpoint = clock::now();
    // execution_time = endpoint - startpoint;
    // double timetaken =  (chrono::duration_cast<chrono::nanoseconds>(execution_time).count())/loopvar;
    // cout<<"Create Time for Array cog without crack " << timetaken << endl;
    


    policy<data>* crack = new crackPolicy<data>(size/2);

    vector<policy<data>* > policies2;
    policies2.push_back(crack);
    hybridPolicy<data>* p2 =  new hybridPolicy<data>(policies2);
    cog* a2 = new arrayNode<data>(*vec);
    jitd<data> myJitd1(a2,p2);
    startpoint = clock::now();
    for(int i=0; i<loopvar;i++)
    {
        result = new vector<data>();
        myJitd1.scan(maxelem,maxelem,*result);
    }
    endpoint = clock::now();
    execution_time = endpoint - startpoint;
    double timetaken2 =  (chrono::duration_cast<chrono::nanoseconds>(execution_time).count())/loopvar;
    cout<<"Create Time for Array cog with crack" << timetaken2;

    return 0;
}
