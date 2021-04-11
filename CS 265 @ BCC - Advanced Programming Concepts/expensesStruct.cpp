#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MonthlyBudget{
	double housing;
	double utilities;
	double household;
	double transport;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothes;
	double misc;
};

MonthlyBudget input(){
	
	MonthlyBudget in;
	
	cout<<"Total spent on housing this month: ";
	cin>>in.housing;
		
	cout<<"Total spent on utilities this month: ";
	cin>>in.utilities;
	
	cout<<"Total spent on household expenses this month: ";
	cin>>in.household;
	
	cout<<"Total spent on transportation this month: ";
	cin>>in.transport;
	
	cout<<"Total spent on food this month: ";
	cin>>in.food;
	
	cout<<"Total spent on medical this month: ";
	cin>>in.medical;
	
	cout<<"Total spent on insurance this month: ";
	cin>>in.insurance;
	
	cout<<"Total spent on entertainment this month: ";
	cin>>in.entertainment;
	
	cout<<"Total spent on clothing this month: ";
	cin>>in.clothes;
	
	cout<<"Total spent on miscellaneous this month: ";
	cin>>in.misc;
	cout<<endl;
	
	return in;
}

int main(){
	MonthlyBudget norm;
	norm.housing = 500.00;
	norm.utilities = 150.00;
	norm.household = 65.00;
	norm.transport = 50.00;
	norm.food = 250.00;
	norm.medical = 30.00;
	norm.insurance = 100.00;
	norm.entertainment = 150.00;
	norm.clothes = 75.00;
	norm.misc = 50.00;
	
	MonthlyBudget in = input();
	
	double normTotalBudget = norm.housing + norm.utilities + norm.household + norm.transport + norm.food + norm.medical + norm.insurance + norm.entertainment + norm.clothes + norm.misc;
	double inTotalBudget = in.housing + in.utilities + in.household + in.transport + in.food + in.medical + in.insurance + in.entertainment + in.clothes + in.misc;
	
	
	
	if(in.housing > norm.housing){
		cout<<"Housing: over by $" << (in.housing - norm.housing)<<endl;
	}
	else if(norm.housing > in.housing){
		cout<<"Housing: under by $" << (norm.housing - in.housing)<<endl;
	}
	else if(norm.housing == in.housing){
		cout<<"Housing same at $" << in.housing<<endl;
	}
	
	if(in.utilities > norm.utilities){
		cout<<"Utilities: over by $" << (in.utilities - norm.utilities)<<endl;
	}
	else if(norm.utilities > in.utilities){
		cout<<"Utilities: under by $" << (norm.utilities - in.utilities)<<endl;
	}
	else if(norm.utilities == in.utilities){
		cout<<"Utilities same at $" << in.utilities<<endl;
	}
	
	if(in.household > norm.household){
		cout<<"Household Expenses: over by $" << (in.household - norm.household)<<endl;
	}
	else if(norm.household > in.household){
		cout<<"Household Expenses: under by $" << (norm.household - in.household)<<endl;
	}
	else if(norm.household == in.household){
		cout<<"Household Expenses same at $" << in.household<<endl;
	}
	
	if(in.transport > norm.transport){
		cout<<"Transportation: over by $" << (in.transport - norm.transport)<<endl;
	}
	else if(norm.transport > in.transport){
		cout<<"Transportation: under by $" << (norm.transport - in.transport)<<endl;
	}
	else if(norm.transport == in.transport){
		cout<<"Transportation same at $" << in.transport<<endl;
	}
	
	if(in.food > norm.food){
		cout<<"Food: over by $" << (in.food - norm.food)<<endl;
	}
	else if(norm.food > in.food){
		cout<<"Food: under by $" << (norm.food - in.food)<<endl;
	}
	else if(norm.food == in.food){
		cout<<"Food same at $" << in.food<<endl;
	}
	
	if(in.medical > norm.medical){
		cout<<"Medical: over by $" << (in.medical - norm.medical)<<endl;
	}
	else if(norm.medical > in.medical){
		cout<<"Medical: under by $" << (norm.medical - in.medical)<<endl;
	}
	else if(norm.medical == in.medical){
		cout<<"Medical same at $" << in.medical<<endl;
	}
	
	if(in.insurance > norm.insurance){
		cout<<"Insurance: over by $" << (in.insurance - norm.insurance)<<endl;
	}
	else if(norm.insurance > in.insurance){
		cout<<"Insurance: under by $" << (norm.insurance - in.insurance)<<endl;
	}
	else if(norm.insurance == in.insurance){
		cout<<"Insurance same at $" << in.insurance<<endl;
	}
	
	if(in.entertainment > norm.entertainment){
		cout<<"Entertainment: over by $" << (in.entertainment - norm.entertainment)<<endl;
	}
	else if(norm.entertainment > in.entertainment){
		cout<<"Entertainment: under by $" << (norm.entertainment - in.entertainment)<<endl;
	}
	else if(norm.entertainment == in.entertainment){
		cout<<"Entertainment same at $" << in.entertainment<<endl;
	}
	
	if(in.clothes > norm.clothes){
		cout<<"Clothing: over by $" << (in.clothes - norm.clothes)<<endl;
	}
	else if(norm.clothes > in.clothes){
		cout<<"Clothing: under by $" << (norm.clothes - in.clothes)<<endl;
	}
	else if(norm.clothes == in.clothes){
		cout<<"Clothing same at $" << in.clothes<<endl;
	}
	
	if(in.misc > norm.misc){
		cout<<"Miscellaneous: over by $" << (in.misc - norm.misc)<<endl;
	}
	else if(norm.misc > in.misc){
		cout<<"Miscellaneous: under by $" << (norm.misc - in.misc)<<endl;
	}
	else if(norm.misc == in.misc){
		cout<<"Miscellaneous same at $" << in.misc<<endl;
	}
	cout<<endl;
	
	if(normTotalBudget > inTotalBudget){
		cout<<"This month's spending is $" << normTotalBudget - inTotalBudget << " under budget.";
	
	}
	
	else if(inTotalBudget > normTotalBudget){
		cout<<"This month's spending is $" << inTotalBudget - normTotalBudget << " over budget.";
	}
	
	else if(inTotalBudget == normTotalBudget){
		cout<<"This month's spending is on par with your budget.";
	}
}
