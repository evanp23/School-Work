#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int daysOnTrip();
double * departure(); 
double * arrival(); 
double * taxiFees(int days);
double airfare(), carRentals(), conference();
double hotel_expenses(int days), miles(), parking(int days);
double * mealExpenses(int arrival, int departure, int days);

const double PARKING_COVERED = 6, HOTEL_COVERED = 90, BREAKFAST_COVERED = 9,
             LUNCH_COVERED = 12, DINNER_COVERED = 16;

int main(){
    int days;
    double airFare, parkingFees, arrive, depart;
    double rentals, milesDriven, taxiTotal, taxiExcess;
    double conferenceExpense, hotel, totalExpenses = 0;
    double owed = 0, totalExpense, saved = 0, totalAllowed, totalExcess = 0;
    double parkingComp, hotelComp, taxiComp;
    double breakfastTotal, lunchTotal, dinnerTotal, mealsTotal;
    double breakfastComp, lunchComp, dinnerComp, mealsComp;
    double * meals;
    double * taxifees;
    double** departAndArrival = new double*[2];

	days = daysOnTrip();

	departAndArrival[0] = departure();
	departAndArrival[1] = arrival();
    arrive = departAndArrival[1][0];
    depart = departAndArrival[0][0];

    airFare = airfare();

    rentals = carRentals();

    milesDriven = miles();

    parkingFees = parking(days);
    parkingComp = PARKING_COVERED * days;

    taxifees = taxiFees(days);
    taxiTotal = taxifees[0];
    taxiComp = taxifees[2];

    conferenceExpense = conference();

    hotel = hotel_expenses(days);
    hotelComp = HOTEL_COVERED * days;
    
    meals = mealExpenses(arrive, depart, days);
    breakfastTotal = meals[0];
    breakfastComp = BREAKFAST_COVERED * days;

    lunchTotal = meals[1];
    lunchComp = LUNCH_COVERED * days;

    dinnerTotal = meals[2];
    dinnerComp = DINNER_COVERED * days;

    mealsTotal = meals[3];
    mealsComp = breakfastComp + lunchComp + dinnerComp;

    totalExpenses = airFare + rentals + milesDriven + parkingFees + taxiTotal +
                    conferenceExpense + hotel;
    totalAllowed = taxiComp + parkingComp + hotelComp + mealsComp;
    totalExcess = totalExpenses - totalAllowed;

    cout << endl << "All Expenses" << endl;
    cout << "============" << endl;
    cout << "Depart Time: " << departAndArrival[0][0] << ":" << departAndArrival[0][1] << "\n";
    cout << "Arrival Time: " << departAndArrival[1][0] << ":" << departAndArrival[1][1] << "\n";
    cout << "Airfare Expense: $" << fixed << showpoint << setprecision(2) << airFare << endl;
    cout << "Car Rentals: $" << fixed << showpoint << setprecision(2) << rentals << endl;
    cout << "Miles driven Expense: $" << fixed << showpoint << setprecision(2) << milesDriven << endl;
    cout << "Parking Fees: $" << fixed << showpoint << setprecision(2) << parkingFees << endl;
    cout << "Taxi Fees: $" << fixed << showpoint << setprecision(2) << taxiTotal << endl;
    cout << "Conference and seminar expenses: $" << fixed << showpoint << setprecision(2) << conferenceExpense << endl;
    cout << "Hotel Expenses: $" << fixed << showpoint << setprecision(2) << hotel << endl;
    cout << "Breakfast Expenses: $" << fixed << showpoint << setprecision(2) << breakfastTotal << endl; 
    cout << "Lunch Expenses: $" << fixed << showpoint << setprecision(2) << lunchTotal << endl;
    cout << "Dinner Expenses: $" << fixed << showpoint << setprecision(2) << dinnerTotal << endl;
    cout << "Total Meal Expenses: $" << fixed << showpoint << setprecision(2) << mealsTotal << endl;
    cout << "Total Expenses Accrued By Businessperson: $" << fixed << showpoint << setprecision(2) << totalExpenses << endl << endl;

    cout << "Total Allowable Expenses" << endl;
    cout << "========================" << endl;
    cout << "*** Only taxi fees, parking fees, hotel expenses and meals are covered by the company.*** " << endl;
    cout << "Taxi Covered: $" << fixed << showpoint << setprecision(2) << taxiComp << endl;
    cout << "Parking Covered: $" << fixed << showpoint << setprecision(2) << parkingComp << endl;
    cout << "Hotel Covered: $" << fixed << showpoint << setprecision(2) << hotelComp << endl;
    cout << "Breakfast Covered: $" << fixed << showpoint << setprecision(2) << breakfastComp << endl;
    cout << "Lunch Covered: $" << fixed << showpoint << setprecision(2) << lunchComp << endl;
    cout << "Dinner Covered: $" << fixed << showpoint << setprecision(2) << dinnerComp << endl;
    cout << "Total for meals covered: $" << fixed << showpoint << setprecision(2) << mealsComp << endl;
    cout << "Total allowable expenses: $" << fixed << showpoint << setprecision(2) << totalAllowed << endl << endl;

    if(totalExcess > 0)
    {
        cout << "The businessperson owes the company $" << fixed << showpoint << setprecision(2) << totalExcess << endl; 
    }
    else if(totalExcess < 0)
    {
        totalExcess = totalExcess * -1;
        cout << "The company saved $" << fixed << showpoint << setprecision(2) << totalExcess << endl;
    }
    else
        cout << "The expenses broke even." << endl;

    return 0;
}

int daysOnTrip(){
	double days;
	
	while(true){
		cout << "How many days did you spend on the trip? ";
		cin >> days;
		if(days < 1){
			cout<<"The number of days must be 1 or greater. Please try again.\n";
		}
		else{
			break;
		}
	}
	
	return days;
}

double * departure(){
	
    double time;
    static double hm[2];
	
	while (true){
	
		cout << "What time did you depart on the first day? (hh.mm): ";
		cin >> time;
		
		int hr = time;
		double min = time - hr;
		
		
		
		if(hr < 0){
			cout<<"Sorry, that is not a time! Please try again.\n";
		}
		else if(hr == 23 && min > 0.59){
			cout<<"Sorry, that is not a time! Please try again.\n";
			
		}
		else if(hr > 23 || min > .59){
			cout<<"Sorry, that is not a time!. Please try again.\n";
		}
		else{
			min = min * 100;
			hm[0] = hr;
			hm[1] = min;
			break;
		}
    }
    return hm;
		
}

double * arrival(){
	
	double time;
	static double hm[2];
	
	while (true){
	
		cout<<"What time did you arrive home on the last day? (hh.mm): ";
		cin>>time;
		
		int hr = time;
		double min = time - hr;
		
		
		
		if(hr < 0){
			cout<<"Sorry, that is not a time! Please try again.\n";
		}
		else if(hr == 23 && min > 0.59){
			cout<<"Sorry, that is not a time! Please try again.\n";
			
		}
		else if(hr > 23 || min > .59){
			cout<<"Sorry, that is not a time!. Please try again.\n";
		}
		else{
			min = min * 100;
			hm[0] = hr;
			hm[1] = min;
			break;
        }
		
	}	
	return hm;
		
}

double airfare(){
    int yesNo;
    double airfare;
    cout << "Did you take a plane to get to your destination? (enter 1 for 'yes' or 2 for 'no') " << endl;
    cin >> yesNo;
    while(yesNo != 1 && yesNo != 2)
    {
        cout << "Enter 1 for yes or 2 for no." << endl;
        cout << "Did you take a plane to get to your destination? (enter 1 for 'yes' or 2 for 'no') " << endl;
        cin >> yesNo;
    }
    if ( yesNo == 1) 
    {
        cout << "How much was the airfare?" << endl;
        cin  >> airfare;
        while(airfare < 0)
        {
            cout << "The value for airfare must be at least 0" << endl;
            cout << "How much was the airfare?" << endl;
            cin  >> airfare;
        }
    }
    if (yesNo == 2)
    {
        airfare = 0;
    }
    return airfare;
}

double * taxiFees(int days){
    int yesNo, compCount = 0;
    double taxiFees, total = 0, compExpense, covered = 10, excess;
    static double taxiTotalAndExcess[3];
    cout << "Did you take a taxi anywhere? (enter 1 for 'yes' or 2 for 'no') " << endl;
    cin >> yesNo;
    while(yesNo != 1 && yesNo != 2)
    {
        cout << "Enter 1 or 2." << endl;
        cout << "Did you take a taxi anywhere during your trip? (enter 1 for 'yes' or 2 for 'no') " << endl;
        cin >> yesNo;
    }
    if (yesNo == 1) 
    {
        for(int count = 1; count <= days; count++)
        {
            cout << "How much money did you spend on taxis on day " << count << " (Enter 0 for days where a taxi wasn't used):" <<endl;
            
            cin >> taxiFees;
            while (taxiFees < 0)
            {
                cout << "Taxi fees has to be at least 0." << endl;
                cout << "How much money did you spend on taxis on day " << count << " (Enter 0 for days where a taxi wasn't used):" <<endl;
                cin >> taxiFees;
            }
            total = total + taxiFees;
            if(taxiFees > 0)
                compCount++;

        }
        compExpense =  covered * compCount;
        excess = total - compExpense;

    }
    if (yesNo == 0) 
    {
        total = 0;
        excess = 0;
    }
    taxiTotalAndExcess[0] = total;
    taxiTotalAndExcess[1] = excess;
    taxiTotalAndExcess[2] = compExpense;
    return taxiTotalAndExcess;
}

double carRentals(){
    double totalfees = 0.00, fees = 0.00;
    double cars = 0;
    cout << "How many cars were rented during the trip: ";
    cin >> cars; 

    while (cars < 0)
    {
        cout << "Input Validation: Negative numbers not accepted.\n";
        cout << "How many cars were rented during the trip: ";
        cin >> cars;	
    }
    cars = int(cars);

    for (int count = 1; count <= cars; count++)
    {
        cout << "How much did it cost to rent Car " << count << ": ";
        cin >> fees;
        
        while (fees < 0)
        {
            cout << "Input Validation: Negative numbers not accepted.\n";
            cout<<"How much did it cost to rent car " << cars <<" :";
            cin >> fees;
        }
    totalfees = totalfees + fees;
        
    }
    return totalfees; 
}

double conference(){

	double totalfees = 0.00, fees = 0.00;
	int cons = 0, semis = 0;

	cout << "Enter how many Conferences were attended: ";
	cin >> cons;

    while (cons < 0)
    {
        cout << "Input Validation: Negative numbers not accepted.\n";
        cout << "Enter how many Conferences were attended: ";
        cin >> cons;
    }	

	cout << "Enter how many Seminars were attended: ";
	cin >> semis;

	while (semis < 0)
	{
		cout << "Input Validation: Negative numbers not accepted.\n";
	    cout << "Enter how many Seminars were attended: ";
		cin >> semis;
	}

    if (cons > 0)
    {
        for (int count = 1; count <= cons; count++)
        {
            cout << "How much was paid for Conferences " << count << ": ";
            cin >> fees;

            while (fees < 0)
            {
                cout << "Input Validation: Negative numbers not accepted.\n";
                cout <<  "How much was paid for Conferences " << count << ": ";
                cin >> fees;
            }

            totalfees = totalfees + fees;
        }
    }

    if (semis > 0)
    {
        for (int count = 1; count <= semis; count++)
        {
            cout << "How much was paid for Seminar Registration" << count << ": ";
            cin >> fees;

        while (fees < 0)
            {
                cout << "Input Validation: Negative numbers not accepted.\n";
                cout << "How much was paid for Seminar Registration " << count << ": ";
                cin >> fees;
            }

        totalfees = totalfees + fees;  
        } 
    }
    return totalfees; 
}

double hotel_expenses(int days){ // cost per night
	double cost, total = 0;
	
	cout << " * The company will pay off a maximum of $90 per day.\n" << endl;
	 
	for(int count = 1; count<=days; count++)
    {
        do // input & input validation
        {
            cout << "Enter hotel expenses for day " << count << ": ";
            cin >> cost; // input, must be a positive number.
            cout << endl;
        
            if(cost < 0) // input validation message
                cout << " > Hotel expenses cannot be negative , ";
            total = total + cost;
        
        }while(cost < 0); // will keep looping until the user inputs a positive number.
    }
	
	return total; // sends total hotel expenses back to main function.
}

double miles(){
	double milesDRIVEN;
	double vehicleEXPENSE = 0;
	int answer;
	
	cout << "Was the private vehicle used: Type 1(yes) or 2(no): ";
	cin >> answer; // user input either yes or no
    while (answer != 1 && answer != 2)
    {
        cout << "Please enter 1 for yes or 2 for no." << endl;
        cout << "Was the private vehicle used: Type 1(yes) or 2(no): ";
	    cin >> answer;
    }
	
	if(answer == 1)
	{
		cout << "How many miles was the car driven?" << endl;
		cin >> milesDRIVEN;
        while(milesDRIVEN < 0)
        {
            cout << "Miles driven cannot be a negative number." << endl;
            cout << "How many miles was the car driven?" << endl;
		    cin >> milesDRIVEN;
        }
		vehicleEXPENSE = (milesDRIVEN * 0.27); //Calculation 
		
	}
	else if(answer == 2)
	{
	    vehicleEXPENSE = 0;
	}
	
    return vehicleEXPENSE; 
}


double parking(int DAYS){
    double PARKING_FEES, total;
    double feesPerDay;


	for(int count = 1; count <= DAYS; count++)
    {
        cout << "What is your parking fee for day " << count << ": ";
        cin >> PARKING_FEES;
        while(PARKING_FEES < 0)
        {
            cout << "Please enter a positive value or 0." << endl;
            cout << "What is your parking fee for day " << count << ": ";
            cin >> PARKING_FEES;
        }
        total = total + PARKING_FEES;
    }
	
	return total;
}

double * mealExpenses(int arrival, int departure, int days){
	double breakfast = 0, lunch = 0, dinner = 0, total = 0;
    double bTotal = 0, lTotal = 0, dTotal = 0;
    static double totals[4];
	if (departure < 7)
	{
	    cout << "Enter the price for breakfast before leaving for your trip: ";
        cin >> breakfast;
        while (breakfast < 0)
        {
            cout << "The price for breakfast cannot be less than 0." << endl;
            cout << "Enter the price for breakfast before leaving for your trip: ";
            cin >> breakfast;
        }
        bTotal = bTotal + breakfast;

        cout << "Enter the price for lunch before leaving for your trip: ";
        cin >> lunch;
        while (lunch  < 0)
        {
            cout << "The price for lunch cannot be less than 0." << endl;
            cout << "Enter the price for lunch before leaving for your trip: ";
            cin >> lunch;
        }
        lTotal = lTotal + lunch;

        cout << "Enter the price for dinner before leaving for your trip: ";
        cin >> dinner;
        while (dinner  < 0)
        {
            cout << "The price for dinner cannot be less than 0." << endl;
            cout << "Enter the price for dinner before leaving for your trip: ";
            cin >> dinner;
        }
        dTotal = dTotal + dinner;

        total = breakfast + lunch + dinner;
    }

    else if (departure < 12 && departure >= 7)
    {
        breakfast = 0;
        cout << "Enter the price for lunch before leaving for your trip: ";
        cin >> lunch;
        while (lunch  < 0)
        {
            cout << "The price for lunch cannot be less than 0." << endl;
            cout << "Enter the price for lunch before leaving for your trip: ";
            cin >> lunch;
        }
        lTotal = lTotal + lunch;

        cout << "Enter the price for dinner before leaving for your trip: ";
        cin >> dinner;
        while (dinner  < 0)
        {
            cout << "The price for dinner cannot be less than 0." << endl;
            cout << "Enter the price for dinner before leaving for your trip: ";
            cin >> dinner;
        }
        dTotal = dTotal + dinner;
        total = breakfast + lunch + dinner;
    }
    else if (departure < 18 && departure >= 12)
    {
        breakfast = 0;
        lunch = 0;
        cout << "Enter the price for dinner before leaving for your trip: ";
        cin >> dinner;
        while (dinner  < 0)
        {
            cout << "The price for dinner cannot be less than 0." << endl;
            cout << "Enter the price for dinner before leaving for your trip: ";
            cin >> dinner;
        }
        dTotal = dTotal + dinner;
        total = breakfast + lunch + dinner;
    }

        

    for(int count = 1; count <= days; count++)
        {
        cout << "Enter the price for breakfast on day " << count << ": ";
        cin >> breakfast;
        while (breakfast  < 0)
        {
            cout << "The price for breakfast cannot be less than 0." << endl;
            cout << "Enter the price for breakfast on day " << count << ": ";
            cin >> breakfast;
        }
        bTotal = bTotal + breakfast;

        cout << "Enter the price for lunch on day " << count << ": ";
        cin >> lunch;
        while (lunch  < 0)
        {
            cout << "The price for lunch cannot be less than 0." << endl;
            cout << "Enter the price for lunch on day " << count << ": ";
            cin >> lunch;
        }
        lTotal = lTotal + lunch;

        cout << "Enter the price for dinner on day " << count << ": ";
        cin >> dinner;
        while (dinner  < 0)
        {
            cout << "The price for dinner cannot be less than 0." << endl;
            cout << "Enter the price for dinner on day " << count << ": ";
            cin >> dinner;
        }
        dTotal = dTotal + dinner;
        total = total + breakfast + lunch + dinner;
        }

    if (arrival > 8 && arrival <= 13)
    {
        cout << "Enter the price for breakfast after arriving from your trip: ";
        cin >> breakfast;
        while (breakfast  < 0)
        {
            cout << "The price for breakfast cannot be less than 0." << endl;
            cout << "Enter the price for breakfast after arriving from your trip: ";
            cin >> breakfast;
        }
        bTotal = bTotal + breakfast;
        total = total + breakfast;
    }
    else if (arrival > 13 && arrival <= 19)
    {
        cout << "Enter the price for breakfast after arriving from your trip: ";
        cin >> breakfast;
        while (breakfast  < 0)
        {
            cout << "The price for breakfast cannot be less than 0." << endl;
            cout << "Enter the price for breakfast after arriving from your trip: ";
            cin >> breakfast;
        }
        bTotal = bTotal + breakfast;

        cout << "Enter the price for lunch after arriving from your trip: ";
        cin >> lunch;
        while (lunch  < 0)
        {
            cout << "The price for lunch cannot be less than 0." << endl;
            cout << "Enter the price for lunch after arriving from your trip: ";
            cin >> lunch;
        }
        lTotal = lTotal + lunch;
        total = total + breakfast + lunch;

    }
    else if (arrival > 19)
    {
        cout << "Enter the price for breakfast after arriving from your trip: ";
        cin >> breakfast;
        while (breakfast < 0)
        {
            cout << "The price for breakfast cannot be less than 0." << endl;
            cout << "Enter the price for breakfast after arriving from your trip: ";
            cin >> breakfast;
        }
        bTotal = bTotal + breakfast;

        cout << "Enter the price for lunch after arriving from your trip: ";
        cin >> lunch;
        while (lunch < 0)
        {
            cout << "The price for lunch cannot be less than 0." << endl;
            cout << "Enter the price for lunch after arriving from your trip: ";
            cin >> lunch;
        }
        lTotal = lTotal + lunch;

        cout << "Enter the price for dinner after arriving from your trip: ";
        cin >> dinner;
        while (dinner < 0)
        {
            cout << "The price for dinner cannot be less than 0." << endl;
            cout << "Enter the price for dinner after arriving from your trip: ";
            cin >> dinner;
        }
        dTotal = dTotal + dinner;

        total = total + breakfast + lunch + dinner;
        totals[0] = bTotal;
        totals[1] = lTotal;
        totals[2] = dTotal;
        totals[3] = total;
        }
    return totals;
}
