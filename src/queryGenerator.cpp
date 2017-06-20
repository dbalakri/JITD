#include "queryGenerator.h"
#include <tuple>
#include <vector>
#include "randUniform.h"

using namespace std;

vector<tuple<int,int> > queryGenerator(int seed, int num, int min, int max, int rangeSize, double pData, double pQuery){
    vector<tuple<int,int> > queries;
    
    randUniform hhStart(seed, min, (int)(min+(1-pData)*(max-min+1))-1);
    int dataMin = hhStart.getRand();
    int dataMax = (int)(dataMin+(pData)*(max-min+1))-1;
    pQuery = pQuery - (1 - pQuery); // excess probability
    
    // randUniform lpMin(seed, min, max-rangeSize);
    randUniform lpMin(seed, min, max);
    randUniform hpMin(seed, dataMin, dataMax);
    //randUniform range(seed, 0, rangeSize);
    
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0,1.0);
    
    for(int i = 0; i < num; i++){
        int qMin, qMax;
        double x = distribution(generator);
        if(x <= pQuery){
            qMin = hpMin.getRand();
        }else{
            qMin = lpMin.getRand();
        }
        // qMax = qMin + range.getRand();
        // if(qMax > max){
        //     qMax = max;
        // }
        qMax = qMin;
        tuple<int,int> query(qMin,qMax);
        queries.push_back(query);
    }
    return queries;
}
