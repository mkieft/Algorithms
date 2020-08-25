#include <iostream> 
#include <random> 
#include <ctime> 
using namespace std;
long long * randomArray(long long n); 
void mergeSort(long long *myArray, long long n); 
void mergeSortRun(long long *myArray, long low, long high); 
void merge(long long *myArray, long low, long high, long mid);
void printArray(long long *myArray, long long n); 
long long count; 
long long avgCount; 
int main(){
	
	for(int i = 0; i < 5; i++){
	long long n = 0;

	cout << "Enter n: ";
	cin >> n; 
	//cout << "n is: " << n <<  endl;
	cout << "Calling random array" << endl; 
	long long *p = randomArray(n); 
	 // cout << "***** Random Array *****" << endl; 
	 // for (int i = 0; i < n; i++){
	 // 	cout << "Element at index " << i << ": " << *(p+i) << endl; 
	 // }
	 cout << "random array returned" << *p << endl; 
	
	 cout << "Calling merge sort" << endl; 
	 mergeSort(p, n);  
	 cout << "merge sort finished" << endl; 
	 cout << "adding count" << endl; 
	 avgCount = avgCount + count;
	 count = 0; 

	//delete []p;
	}
	cout << "Average atomic operations: " << avgCount/5 << endl; 

	return 0; 

}

void mergeSort(long long *myArray, long long n){
	// for(int i = 0; i < n; i++){
	// 	cout << "Array element at index " << i << ": " << *(myArray+i) << endl;  
	// }
	count = count + 1; // for n-1  
	mergeSortRun(myArray, 0, n-1);
	printArray(myArray, n); 
	delete[]myArray; 

}
void printArray(long long *myArray, long long n){
	//cout << "****Sorted Array ****" << endl; 
	for (int i = 0; i < n; i++){
		//cout << "Element at index " << i << ": " << *(myArray+i) << endl; 
	}
	cout << "Number of atomic operations: " << count << endl; 
	//delete[]myArray; 
}
void mergeSortRun(long long *myArray, long low, long high){
	count++; //function call 

	long mid;
	if(low<high){
		count++; //comparison
		mid = (low+high)/2; 
		count = count + 3; //for + and / operations, and setting to mid
	
		mergeSortRun(myArray, low, mid);
		count++; //for mid+1

		mergeSortRun(myArray, mid+1, high); 
		merge(myArray, low, high, mid); 
	}
	
}
void merge(long long *myArray, long low, long high, long mid){

	count++; //for function call
	long i, j, k;
	long *temp = new long[high-low+1];
	count = count + 2; // for - and +  operations
	i = low;
	k = 0;
	j = mid + 1;
	count = count + 4; //for + operation and setting(=)  

	while(i <= mid && j <= high){
		count = count + 2; // for 2 comparisons
		if(*(myArray+i) < *(myArray+j)){
			
			temp[k] = *(myArray+i);
			count = count + 2; //for comparison and setting = 
			k++;
			i++; 
		}
		else{
			temp[k] = *(myArray+j); 
			count = count + 2; //comparison and setting =
			k++;
			j++; 
		}
	}

	while(i <= mid){
		
		temp[k] = *(myArray+i);
		count = count + 2; //comparison and setting =
		k++;
		i++;
	}
	while(j <= high){
		temp[k] = *(myArray+j);
		count = count + 2; //comparison and setting =
		k++;
		j++;
	}
	for(i = low; i <= high; i++){
		*(myArray+i) = temp[i-low]; 
		count = count + 3; //for - operation and setting = and for loop 
	}
	delete[]temp; 
}
long long * randomArray(long long n){
	long long *randArray = new long long[n]; 

	srand(time(NULL));
	for (int i =0; i < n; i++){
		randArray[i] = rand()% n+1;  

	}
	return randArray; 
}

