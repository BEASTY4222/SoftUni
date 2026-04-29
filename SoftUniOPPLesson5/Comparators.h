#ifndef _COMPARATORS_H__
#define _COMPARATORS_H__


template<class t> class LessThan {
public:
	bool operator()(const t& a, const t& b) const {
		return a < b;
	}
};


template<class t,typename c> class Reverse {
public:
	bool operator()(const t& a, const t& b) const {
		c comp;
		return !comp(a, b);
	}
};


#endif 