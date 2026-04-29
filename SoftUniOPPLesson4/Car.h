#ifndef CAR_H
#define CAR_H

using namespace std;

class Car {
	string brand;
	string model;
	int year;

	public:

		Car(string nBrand,string nModel,int nYear) :
			brand(nBrand),
			model(nModel),
			year(nYear){}

		inline string GetBrand() const{
			return brand;
		}
		inline string GetModel() const {
			return model;
		}
		inline int GetYear() const {
			return year;
		}

};

#endif // !CAR_H
