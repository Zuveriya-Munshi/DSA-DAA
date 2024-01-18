#include<iostream>
//#include<ctime>
#include<vector>
#include<sys/time.h>
#include<time.h>
#include<math.h>
using namespace std;

// Function for Selection sort
void selectionSort(vector<int> &arr, string s)
{
    struct timeval t;
gettimeofday(&t,NULL);
double t1=(double)t.tv_sec + t.tv_usec * 0.000001;
int flag=0;
double compare=0;
    int i, j, min_idx;
    int n = arr.size();
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
                compare++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }

    gettimeofday(&t,NULL);
      double t2 = (double)t.tv_sec + t.tv_usec * 0.000001;

      double total = t2 - t1;
      cout<<s<<" Time = "<<total;
      cout<<"\nComparisons : "<<compare<<endl;
}

// Function to print an array
void printArray(vector<int> arr)
{
    int i;
    int size = arr.size();
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}

// Driver program
int main()
{
        vector<int> arr;
    int n;
    cout<<"Enter Number of Elements : ";
    cin>>n;
    for(int i =0;i<n;i++){
        arr.push_back(i);
    }
    selectionSort(arr,"Best");
    arr.clear();

    for(int i =0;i<n;i++){
        int x = rand() % n;
        arr.push_back(x);
    }
    selectionSort(arr,"Average");

    arr.clear();
    for(int i =n;i>0;i--){
        arr.push_back(i);
    }
    selectionSort(arr,"Worst");
   // printArray(arr);
    return 0;
}


