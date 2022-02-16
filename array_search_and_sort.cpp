#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void linearSearch(int arr[], int n, int key)
{
    bool a=false;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            cout<<"key matches";
            a=1;
            break;
        }
    }
    if(!a)
        cout<<"key does not match";
}
int binarySearch(int arr[], int n, int key)
{
    int a=0, b=n-1, i;
    do
    {
        i=(a+b)/2;
        if(arr[i]>key)
        {
            b=i;
        }
        else if(arr[i]<key)
        {
            a=i;
        }
        else
        {
            return i;
        }
    } while(b-a!=1);
    return -1;
}

void selectionSort(int arr[], int n)
{
    int minindex=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        swap(&arr[i], &arr[minindex]);
        minindex=i+1;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i;
        while(arr[j]<arr[j-1]&&j>=0)
        {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{

    int n, key=5;
    cout<<"enter the size of array \n";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // cout<<"enter the key \n";
    // cin>>key;
    // linearSearch(arr,n,key);
    // cout<<"\n"<<binarySearch(arr,n,key)<<endl;

    // selectionSort(arr,n);
    // bubbleSort(arr,n);
    // insertionSort(arr,n);

    return 0;
}