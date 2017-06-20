#ifndef DATA_H_
#define DATA_H_

using namespace std;

class data {
	public:
		int key;
		int value;
		data(int k, int v);
		bool operator<(const data& other) const;
		bool operator>(const data& other) const;
		bool operator<=(const data& other) const;
		bool operator>=(const data& other) const;
		bool operator==(const data& other) const;
		bool operator!=(const data& other) const;
};

#endif /* DATA_H_ */