//		Course Name: CS3420-001 Data Structure
//             Name: Evan Phillips
//				Date class to be implemented in container.cpp and used as data type for templated container class.

#include <iostream>
using namespace std;


class date{
	friend ostream& operator<<(ostream &out, date& dobj2);
public:
	date();
	date(int mm, int dd, int yyyy);
	bool operator>(date &dobj2);
	//postcondition: returns true if *thi9s > dobj2; returns false otherwise
	bool operator==(date &dobj2);
private:
	int month;
	int day;
	int year;
};

ostream& operator<<(ostream &out, date &dobj2){
	out<<dobj2.month<<"/"<<dobj2.day<<"/"<<dobj2.year;

	return out;
}

date::date(){
}

date::date(int mm, int dd, int yyyy){
	month = mm;
	day = dd;
	year = yyyy;
}
