#include <iostream>
#include <fstream> //to open file
#include <sstream>
#include <vector>

#include <map>
#include <cmath>

using namespace std;
void printNames(vector<string>namesVec);
int hashFunction(string hashNames); 
int alphValue(char in);
void printHist(map<int, int> freqMap); 
void printMap(map<int, int> freqMap);
void outputForHist(map <int,int> freqMap);
int main() {
	ifstream inFile; 
	string into,line;
	string names;
	vector<string> namesVec;

	inFile.open("app_c.csv");
	if (inFile.is_open()) {
		cout << "File opened" << endl;
	}
	else {
		cout << "NO FILE OPENED" << endl;
	}

	while(getline(inFile, into)){
		stringstream ss(into);
		if(ss.good()){
			getline(ss,names, ',');
			namesVec.push_back(names); //names stored in vector for input 
		}
	}

	//printNames(namesVec);

	vector<string> namesHalf;
	int randomIndex;
	int halfNames = (namesVec.size()/2);

	while(namesHalf.size() <= halfNames ){ //makes vector of random names half the size of original (50%) 
		
		randomIndex = rand() % namesVec.size();
		namesHalf.push_back(namesVec[randomIndex]);
	
	} 
	//printNames(namesHalf);

	vector<int> hashLocations; 
	
	int loc; 
	//hashing
	for(int i = 0; i < namesHalf.size(); i++){
		loc = hashFunction(namesHalf[i]);
		
		//cout << "Element: " << namesHalf[i] << " has location: " << loc << endl;
		hashLocations.push_back(loc); 

	} 
	map<int, int> freqMap;
	for( auto & elem : hashLocations){
		auto result = freqMap.insert(pair<int, int>(elem,1));
		if(result.second == false)
			result.first->second++;
	}

	//printMap(freqMap);
	
	printHist(freqMap);
	//outputForHist(freqMap);

	return 0;
}
void outputForHist(map <int,int> freqMap){
	
	ofstream out("prob2Hist.txt");

	for(auto & element : freqMap){
		out << element.first << " " << element.second << endl;
	}
	cout << "Wrote to file prob2Hist.txt" << endl;
}
void printHist(map<int, int> freqMap){
	//this is just a simple hist with stars
	for(auto & elem : freqMap){
		if(elem.second >= 1){
			cout << "\t" << elem.first << "\t| "; 
			for(int i = 0; i <= elem.second; i++){
				cout << "*";
			}
		}
		cout << endl;
	}




	
}
void printMap(map<int, int> freqMap){
	for(auto & elem : freqMap){
		if(elem.second > 1){
			cout << "Element: "<< elem.first << " Occurs: " << elem.second << endl; 
		}
	}
}
int hashFunction(string hashNames){
	//cout << "I got "<< hashNames << " sent into the funcion" << endl;
	int hashCount = 0; 
	int aValue = 0;
	int sum = 0;
	for (int i = 0; i < hashNames.size(); i++ ){
		aValue = alphValue(hashNames[i]);
		//cout << "The char value for " << hashNames[i] << " is: " << aValue << endl;
		sum = sum + aValue;
	}
	//cout << "Sum of " << hashNames << " : " << sum << endl;

	int location = sum % 175; 
	//cout << "Hash location of " << hashNames << " is: " << location << endl;
	return location; 
}

int alphValue(char in){
	const string alpha = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
	const auto pos = alpha.find(in); 
	int value = pos + 1 ;
	return value; 

}
void printLocs(vector<int>locs){
	for (int i =0; i < locs.size(); i++){
		cout << "Locations: " << locs[i] << endl;
	}
}
void printNames(vector<string>namesVec){
	for (int i =0; i < namesVec.size(); i++){
		cout << "Names: " << namesVec[i] << endl;
	}
}