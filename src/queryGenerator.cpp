#include "queryGenerator.h"
#include <tuple>
#include <vector>
#include "randUniform.h"

using namespace std;

vector<tuple<int,int> > queryGenerator(int seed, int num, int min, int max, int rangeSize, double pData, double pQuery){
    vector<tuple<int,int> > queries;
    int n = max - min + 1; // total size of range
    int m = (int)(pData * n); // size of range for heavyhitter
    int r = n - m; // size of remaining range
    randUniform hhStart(seed, min, min + r + 1);
    int dataMin = hhStart.getRand();
    int dataMax = dataMin + m - 1;
    randUniform lpMin(seed, min, max - m);
    randUniform hpMin(seed, dataMin, dataMax);
    
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0,1.0);
    
    for(int i = 0; i < num; i++){
        int qMin, qMax;
        double x = distribution(generator);
        if(x <= pQuery){
            qMin = hpMin.getRand();
        }else{
            qMin = lpMin.getRand();
            if(qMin >= dataMin){
                qMin += m;
            }
        }
        qMax = qMin;
        tuple<int,int> query(qMin,qMax);
        queries.push_back(query);
    }
    return queries;
}
