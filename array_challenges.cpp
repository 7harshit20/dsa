#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int j=0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
void maxtilli(int arr[], int n)
{
    for(int i=1; i < n; i++)
    {
        arr[i]=max(arr[i], arr[i - 1]);
    }
    printArray(arr, n);
}
void sumOfSubarray(int arr[], int n)
{
    int sum=0;
    for(int i=0; i < n; i++)
    {
        for(int j=i; j < n; j++)
        {
            sum=sum + arr[j];
            cout << sum << " ";
        }
        sum=0;
    }
}
int longestAirthmeticSubarray(int arr[], int n)
{
    int pointer=0, highestlength=1, length=1;
    for(int i=0; i < n - 1; i++)
    {
        arr[i]=arr[i + 1] - arr[i];
    }
    while(pointer < n - 1)
    {
        while(arr[pointer + 1] == arr[pointer])
        {
            length++;
            pointer++;
        }
        highestlength=max(highestlength, length);
        length=1;
        pointer++;
    }
    return highestlength + 1;
}
int recordBreaking(int arr[], int n)
{
    int number=0;
    for(int i=1; i < n - 1; i++)
    {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            number++;
        }
        arr[i]=max(arr[i], arr[i - 1]);
    }
    if(arr[0] > arr[1])
        number++;
    if(arr[n - 1] > arr[n - 2])
        number++;
    return number;
}

int main()
{
    int n;
    cout << "enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "enter the array\n";
    for(int i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // maxtilli(arr,n);
    sumOfSubarray(arr, n);
    // cout<<longestAirthmeticSubarray(arr,n)<<endl;
    // cout<<recordBreaking(arr,n)<<endl;

    return 0;
}