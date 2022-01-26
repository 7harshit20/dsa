#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool mycompare(pair<int,int>p1,pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){

    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto elements:v){
        cout<<elements<<" ";
    }cout<<endl;
    vector<int> v2 (3,10);
    swap(v,v2);
    // for(auto ele:v){
    //     cout<<ele<<" ";
    // }cout<<endl;
    // for(auto ele:v){
    //     cout<<ele<<" ";
    // }
    // do check out other function
    sort(v2.begin(),v2.end());

    pair<int,char> p;
    p.first=34;
    p.second='$';

    int arr[]={10,16,7,14,5,3,2,9};
    vector < pair <int,int> > v3;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        // v3[i].first=arr[i];
        // v3[i].second=i;
        v3.push_back(make_pair(arr[i],i));
    }
    // sort(v.begin(),v.end(),mycompare);
    // for(int i=0;i<v3.size();i++){
    //     arr[v3[i].second]=i;
    // }
    // vector<int> ct(3);
    // ct[2]=20;
    // ct.push_back(209);
    // for(int i=0;i<=3;i++)cout<<ct[i]<<" ";
    // cout<<endl<<ct[0];
    // cout<<endl<<ct[1];
    return 0;
}