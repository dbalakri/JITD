#include "data.h"

using namespace std;

data::data(int k, int v): key(k), value(v){}

bool data::operator<(const data& other) const{
	return key < other.key;
}

bool data::operator>(const data& other) const{
	return key > other.key;	
}

bool data::operator<=(const data& other) const{
	return key <= other.key;
}

bool data::operator>=(const data& other) const{
	return key >= other.key;
}

bool data::operator==(const data& other) const{
	return key == other.key;
}

bool data::operator!=(const data& other) const{
	return key != other.key;
}
