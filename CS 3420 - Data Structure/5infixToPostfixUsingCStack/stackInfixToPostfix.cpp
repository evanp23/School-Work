//		   Course: CS3420 Data Structures
//	  	     Name: Phillips, Evan
//	   Assignment: Program 6
//  Date Assigned: 10/2020
//       Date Due: 11/24/2020
// Date Handed in: 10/31/2020
//		   Remark: Program to convert infix to postfix notation by taking string input,
//				removing spaces and converting in convertInfixToPostfix()

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <assert.h>
#include <ctype.h>

using namespace std;

string inputString(){
	//postcondition: getline string input infix and return infix in given form.
	
	string expr;
	cout<<"Please type areithmetic expression in infix form: ";
	getline(cin, expr);
	
	return expr;
}

string removeEmbeddedSpaces(string expr){
	//precondition: expr is not empty string.
	//postcondition: remove spaces and return expr
	
	assert(expr != "");
	
	string::iterator end_pos = remove(expr.begin(), expr.end(), ' ');
	expr.erase(end_pos, expr.end());
	
	cout<<"After removing spaces, infix expression is: "<< expr<<endl;
	
	return expr;
}

int checkPriority(char op){
	//precondition: char is passed
	//postcondition: passed char is checked against array of ops[]. prior[] is parallel array.
	//Returns the char's precedence based on its position in its own array. If char is
	//not found in array, 0 is returned.
	
	
	char ops[] = {'+', '-', '*', '/'};
	int prior[] = {1, 1, 2, 2};
	
	for(int i = 0; i < 4; i ++){
		if(op == ops[i]){
			return prior[i];
		}
		else if(i == 3){
			return 0;
		}
	}
}

string convertInfixToPostfix(string infix){
	//postondition: converts infix to postfix and returns postfix notation
	char ch;
	string postfix = "";
	stack<char> operators;
	int chPriority;
	char opTop;
	
	for(int i = 0; i < infix.length(); i++){
		ch = infix[i];
		if(isalnum(ch)){
			postfix += ch;
		}
		else if(ch == '('){
			operators.push(ch);
		}
		else if(ch == ')'){
			while(operators.top() != '('){
				postfix += operators.top();
				operators.pop();
			}
			if(operators.top() == '('){
				operators.pop();
			}
		}
		else{
			while(!operators.empty() && checkPriority(operators.top()) >= checkPriority(ch)){
				postfix += operators.top();
				operators.pop();
			}
			operators.push(ch);
		}
	}
	while(!operators.empty()){
		postfix += operators.top();
		operators.pop();
	}
	
	return postfix;
	
}

int main(){
	string infix = inputString();
	
	infix = removeEmbeddedSpaces(infix);
	
	cout<<endl<<"Converted to postfix, the expression is: "<<convertInfixToPostfix(infix)<<endl;
}


























