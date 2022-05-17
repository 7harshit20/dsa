#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int maxLen(vector<int> arr, int n) {
    unordered_map<int, int> mp;
    mp[0]=-1;
    int a=0, b=0, ans=-1;
    for(int i=0;i<n;i++) {
        if(arr[i])b++;
        else a++;
        if(mp.find(a-b)!=mp.end())ans=max(ans, i-mp[a-b]);
        else mp[a-b]=i;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // set<string> s;
    // s.insert("my");
    // s.insert("name");
    // s.insert("is");
    // s.insert("harshit");
    // s.insert("true");
    // cout<<s.size()<<endl;
    // for(auto ele: s)cout<<ele<<" ";

    unordered_set<string> s;
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("a");
    s.insert("your");
    s.insert("harshit");
    s.insert("true");
    s.insert("ta");
    s.insert("game");
    s.insert("apple");

    // if(s.find("apple")!=s.end())s.erase("true");
    // if(s.count("ta"))s.erase("ta");
    // cout<<s.bucket_count()<<endl;
    // cout<<s.max_size()<<endl;
    // cout<<s.load_factor()<<endl;
    // for(auto i=s.begin();i!=s.end();i++) cout<<*i<<" ";

    unordered_map<string, int> mp;
    mp["Harshit"]=97;
    mp["dev"]=71;
    mp["ved"]=231;
    mp["priyansh"]=145;
    mp["way"]++;
    mp["way"]++;
    cout<<mp["dev"]<<endl;
    if(mp.find("ved")!=mp.end())cout<<mp.find("ved")->second<<endl;
    for(auto it=mp.begin();it!=mp.end();it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    // for(auto ele: mp)cout<<ele.first<<" "<<ele.second<<endl;
    // cout<<mp["random"]<<endl;
    if(mp.find("random")==mp.end())cout<<"random not found"<<endl;

    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxLen(arr, n)<<endl;

    return 0;
}