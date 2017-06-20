#include "randUniform.h"
#include <random>

using namespace std;

randUniform::randUniform(int seed, int x, int y): generator(seed), min(x), max(y), distribution(x,y) {}
int randUniform::getRand(){
    return distribution(generator);
}
