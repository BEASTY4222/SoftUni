#pragma once
#include "Vector.h"
#include <vector>
template<class V, class VLC>
class ReverseComparer {
public:
	bool operator()(const Vector& a, const Vector& b) const {
		VLC comp;
		return !comp(a,b);
	}

};
class VectorLengthComparer {
public:
	bool operator()(const Vector& a, const Vector& b) const {
		return a.getLength() < b.getLength();
	}


};