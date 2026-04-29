#pragma once
#include <sstream>

class Box {
	int l;
	int b;
	int h;


public:
	inline Box():l(0),b(0),h(0){}
	inline Box(const int &l, const int &b, const int &h) :l(l),b(b),h(h) {}
	inline Box(Box& other) {
		this->l = other.getLength(); 
		this->b = other.getBreadth();
		this->h = other.getHeight();
	}

	inline int getLength()const { return this->l; }
	inline int getBreadth()const { return this->b; }
	inline int getHeight()const { return this->h; }

	inline long long CalculateVolume()const { return 1LL * l * b * h; }

	inline bool operator<(const Box& o)const {
		if (this->l < o.getLength()) {
			return true;
		}
		else if (this->b < o.getBreadth() && this->l == o.getLength()) {
			return true;
		}
		else if (this->h < o.getHeight() && this->b == o.getBreadth() && this->l == o.getLength()) {
			return true;
		}
		else
			return false;
	}
};

inline std::ostream& operator<<(std::ostream& out ,const Box& box) {
	out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();

	return out;
}