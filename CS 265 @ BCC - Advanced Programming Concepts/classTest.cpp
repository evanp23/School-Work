#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;
		string mName;
	
	public:
		Date();
		Date(int, int, int, string);
		~Date(){}
		
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setMName(string);
		
		void toString1();
		void toString2();
		void toString3();
};
Date::Date(){
	month = 0;
	day = 0;
	year = 0;
}

Date::Date (int Month, int Day, int Year, string MonthName){
	month = Month;
	day = Day;
	year = Year;
	mName = MonthName;
}

void Date::setMonth(int newMonth){
	month = newMonth;
}

void Date::setDay(int newDay){
	day = newDay;
}

void Date::setYear(int newYear){
	year = newYear;
}

void Date::setMName(string newName){
	mName = newName;
}

void Date::toString1(){
	cout<< month << "/" << day << "/" << year <<endl;
}

void Date::toString2(){
	cout<< mName << " " << day << ", " << year <<endl;	
}

void Date::toString3(){
	cout<< day << " " << mName << " " << year << endl;
}

int main(){
	
	int Month;
	int Day;
	int Year;
	
	cout<<"This magic program will print your birthday in three different formats!"<<endl;
	cout<<"-----------------------------------------------------------------------";
	
	while(true){
		cout<<endl<<"Enter your birth month: ";
		cin>>Month;
		
		if(Month < 1 || Month > 12){
			cout<<endl<<"Sorry, that's not a month!";
		}
		else{
			break;
		}
	}
	
	while(true){
		cout<<endl<<"Enter the day (1-31): ";
		cin>>Day;
		
		if(Day < 1 || Day > 31){
			cout<<endl<<"Sorry, that's not a valid date!";
		}
		else{
			break;
		}
	}
	
	cout<<endl<<"Enter the year of your birth: ";
	cin>>Year;
	
	string months [] = {"January", "February", "March", "April", "May",
							"June", "July", "August", "September", "October",
								"November", "December"};

	
	Date birthday(Month, Day, Year, months[Month - 1]);
	cout<<endl<<"Your birthday is: ";
	birthday.toString1();
	cout<<endl<<"or: ";
	birthday.toString2();
	cout<<endl<<"or: ";
	birthday.toString3();
	
	
}

