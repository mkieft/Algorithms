
using namespace std;
bool findAdjDuplicates(int A[], int i);
int main()
{
    //main is for testing purposes
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int A[n];
    cout << "Enter the values for the array:\n";
    for(int i =0; i < n; i++){
        cin >> A[i];
    }

    //int n = sizeof(A)/sizeof(A[0]); //for size if entered Array manually

    cout << "Was there duplicates in the array?\n";
    bool dups = findAdjDuplicates(A,n);
    if(dups == true){
        cout << "Yes an adjacent duplicate was found.\n" << endl;
    }
    else{
        cout << "No adjacent duplicates were found!" << endl;
    }




    return 0;
}
//Answer to question 3 Problem set 2
bool findAdjDuplicates(int A[], int n){

   if(n == 0){
        return false;
   }
    else if(A[n]==A[n-1]){
        return true;
    }
    else{
        findAdjDuplicates(A, n-1);
    }++
}
