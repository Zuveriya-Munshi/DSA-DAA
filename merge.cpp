#include <iostream>
#include<sys/time.h>
#include<time.h>
#include<math.h>
using namespace std;

/* Function to merge the subarrays of a[] */
void merge_s(int a[], int beg, int mid, int end)
{

    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2]; //temporary arrays

    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
    LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
    RightArray[j] = a[mid + 1 + j];

    i = 0; /* initial index of first sub-array */
    j = 0; /* initial index of second sub-array */
    k = beg;  /* initial index of merged sub-array */

    while (i < n1 && j < n2)
    {
        if(LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
    struct timeval t;

gettimeofday(&t,NULL);
    double start=(double)t.tv_sec + t.tv_usec * 0.000001;
void mergeSort(int a[], int beg, int end)
{

    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge_s(a, beg, mid, end);
    }

}
    double endt = (double)t.tv_sec + t.tv_usec * 0.000001;

    double time_taken = endt - start;
        cout<<"Best Time = "<<time_taken;

/* Function to print the array */
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout<<endl<<a[i]<<" ";
}

int main()
{
    int n, i, ch;
    cout << "\n1) Best Case\n2) Worst Case\n3) Average Case\n4) Exit\nSelect your case: ";
    cin >> ch;
    cout << "Enter the number of inputs: ";
    cin >> n;
    int arr[n];
    switch (ch)
    {

    case 1:
        for (i = 0; i < n; i++)
            arr[i] = i + 1;
        mergeSort(arr,0,n-1);
        break;
    case 2:
        for (i = 0; i < n; i++)
            arr[i] = n - i;
        mergeSort(arr,0,n-1);

        break;
    case 3:
        for (i = 0; i < n; i++)
            arr[i] = rand() % n;
        mergeSort(arr,0,n-1);

        break;
    case 4:
        return 0;
        break;
    default:
        cout << "Invalid Choice";
        break;
    }

    return 0;
}

