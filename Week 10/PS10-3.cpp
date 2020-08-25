#include <iostream> 
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
	
	int count;
	if(argc == 1){
		cout << "Entered only one element of array, it is already sorted: " << argv[0] << endl;
	}
	if(argc > 2){
		cout << "Length of array is: " << argc << endl;
		cout << "Array elements are: ";
		for(counter = 0; counter < argc; counter++){
			cout << counter << ": " << "\t" << argv[counter]; 
		}
	}
	



	return 0; 

}