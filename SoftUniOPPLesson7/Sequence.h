#pragma once
#include <vector>
#include <climits>

template<typename T, class Generator>
class Sequence {
	std::vector<int> data;

	Generator gen;
public:

	class Iterator {
		std::vector<int> &data;
		unsigned long idx;

	public:
		Iterator(std::vector<int>& data, unsigned long idx) 
			:data(data), idx(idx) {}

		Iterator& operator++() {
			idx++;
			return *this;
		}

		T& operator *() {
			return data[idx];
		}

		bool operator == (const Iterator& other)const {
			if (&this->data != &other.data) 
				return false;
			
			if (this->isAtTheEnd() && other.isAtTheEnd()) {
				return true;
			}

			return this->idx == other.idx;
		}

		bool operator !=(const Iterator& other)const {
			return !(*this == other);
		}

	private:
		bool isAtTheEnd()const { return idx >= data.size(); }
	};
	Iterator begin() { return Iterator(data, 0); }
	Iterator end() { return Iterator(data, ULONG_MAX); }

	void generateNext(int &numToGenerate) {
		while (numToGenerate--) {
			data.push_back(gen());
		}
	}
	
};