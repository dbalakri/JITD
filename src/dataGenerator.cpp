#include "randUniform.h"
#include "dataGenerator.h"
#include "data.h"

void dataGenerator(int seed, int min, int max, data d[], int length){
    randUniform generator(seed, min, max);
    for(int i = 0; i < length; i++){
    	int x = generator.getRand();
        d[i].key = x;
        d[i].value = x;
    }
}
