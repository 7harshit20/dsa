#include <iostream>
using namespace std;

int main()
{
    // int a, b;
    // cin >> a >> b;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < b; j++)
    //     {
    //         if (i == 0 || i == a - 1)
    //         {
    //             cout << "* ";
    //         }
    //         else if (j == 0 || j == b - 1)
    //         {
    //             cout << "* ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     cout<<"\n";
    // }

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<"  ";
    //     }
    //     for(int k=0; k<i+1; k++){
    //         cout<<"* ";
    //     }
    //     cout<<"\n";
    // }

    // int n,m=1;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<m<<" ";
    //         m++;
    //     }
    //     cout<<endl;
    // }

    // int n,temp;
    // cin>>n;
    // for(int i=0;i<2*n;i++){
    //     if(i<=n){
    //         for(int j=0;j<2*n;j++){
    //         if(j<=i || j>=2*n-i-1){
    //             cout<<"* ";
    //         }else{
    //             cout<<"  ";
    //         }
    //      }
    //         cout<<"\n";
    //     }
    //     else{
    //         temp=2*n-i-1;
    //         for(int j=0;j<2*n;j++){
    //         if(j<=temp || j>=2*n-temp-1){
    //             cout<<"* ";
    //         }else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<"\n";
    //     }
    // }

    //    for(int i=0;i<n-1;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     for(int j=0;j<2*n-2*i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=n;i>-1;i--){
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     for(int j=0;j<2*n-2*i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<"\n";
    // }

    // int n;
    // cin>>n;
    // for(int i=1; i<=n; i++){
    //     for(int j=1;j<=n-i+1;j++){
    //         cout<<j<<" "
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;
    // for(int i=1; i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         if((i+j)%2==0)cout<<"1 ";
    //         else cout<<"0 ";
    //     }
    //     cout<<endl;
    // }

    //  int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<=n;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //  int n;
    //  cin>>n;
    //  for(int i=1;i<=n;i++){
    //      for(int j=1;j<=n-i;j++){
    //          cout<<"  ";
    //      }
    //      for(int j=i;j>=1;j--){
    //         cout<<j<<" ";
    //      }
    //      for(int j=2;j<=i;j++){
    //          cout<<j<<" ";
    //      }
    //      cout<<endl;
    //  }

    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i*2-1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i*2-1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // int n,k,l,a,b,c;
    // cin>>n;
    // k=n%4;
    // l=n/4;
    // a=k==3?l+1:l;
    // b=k>1?l*2+1:l*2;
    // c=k!=0?l+1:l;
    // cout<<"    ";
    // for(int j=1;j<=a;j++){
    //         cout<<"*       ";
    //     }
    // cout<<"\n  ";
    // for(int j=1;j<=b;j++){
    //         cout<<"*   ";
    //     }
    // cout<<endl;
    // for(int j=1;j<=c;j++){
    //         cout<<"*       ";
    //     }

    int n;
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((j + i) % 4 == 0)
                cout << "* ";
            else if (i == 2 && (j + i) % 4 == 2)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0;
}