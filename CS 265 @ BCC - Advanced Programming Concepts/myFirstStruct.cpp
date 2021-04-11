#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct MovieData{
		string title;
		string director;
		int year;
		double rTime;
	};

MovieData movie(int count){
	MovieData movies [2];
	
	movies[0].title = "Breakfast Club";
	movies[0].director = "John Hughes";
	movies[0].year = 1985;
	movies[0].rTime = 97;
	
	movies[1].title = "Forrest Gump";
	movies[1].director = "Robert Zemeckis";
	movies[1].year = 1994;
	movies[1].rTime = 142;
	
	return movies[count];
	
}

int main(){
	
	for(int i = 0; i < 2; i++){
		cout<<"Movie Title: " << movie(i).title<<endl;
		cout<<"Director: " << movie(i).director<<endl;
		cout<<"Year Released: " << movie(i).year<<endl;
		cout<<"Running Time: " << movie(i).rTime << " minutes"<<endl;
		cout<<endl;
		
	}
}
