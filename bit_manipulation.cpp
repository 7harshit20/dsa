#include <iostream>
#include <math.h>
using namespace std;

int getbit(int n, int pos)
{
    return (n & (1 << pos)) == 0 ? 0 : 1;
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int clearbit(int n, int pos)
{
    // return (n & ~(1<<pos));
    return ~(~n | (1 << pos));
}
int updatebit(int n, int pos, int value)
{
    return clearbit(n, pos) | value << pos;
}

bool ispowerof2(int n)
{
    // int i=0;
    // while(getbit(n,i)==0)i++;
    // return n==(1<<i);

    return n && !(n & (n - 1));
}
int totalone(int n)
{
    int num = 0;
    while (n)
    {
        n = (n & n - 1);
        num++;
    }
    return num;
}
void subsets(int n, char arr[])
{
    for (int i = 0; i < pow(2, n); i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (getbit(i, j))
                cout << arr[n - 1 - j];
        }
        cout << endl;
    }
}

int unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}
void twounique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int i = 0;
    while (xorsum & (1 << i) == 0)
        i++;
    int fn = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << i))
        {
            fn ^= arr[i];
        }
    }
    cout << fn << endl;
    // int sn=0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==fn)continue;
    //     sn^=arr[i];
    // }
    cout << (fn ^ xorsum) << endl;
}
int uniquefromthree(int arr[], int n)
{
    int digits[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (getbit(arr[j], i))
            {
                digits[i]++;
            }
        }
        digits[i] = digits[i] % 3;
    }
    int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num += (pow(2, i) * digits[i]);
    }
    return num;
}

int main()
{
    // cout<<(1<<3)<<endl;;
    // cout<<getbit(11,2)<<endl;
    cout << setbit(4, 0) << endl;
    // cout<<clearbit(5,2)<<endl;
    // cout<<updatebit(5,1,1)<<endl;

    // cout<<ispowerof2(0);
    // cout<<totalone(7);
    // char arr[]= {'a','b','c','d','e'};
    // subsets(5,arr);

    // int arr[]={55,3,55,3,55,3,1,1,99,1};
    // cout<<unique(arr,11);
    // twounique(arr,8);
    // cout<<uniquefromthree(arr,10);

    return 0;
}