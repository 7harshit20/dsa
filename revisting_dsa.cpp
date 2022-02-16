#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

// ARRAYS

int findKey(int* arr, int size, int k)
{
    int i=0;
    while(i<size)
    {
        if(arr[i]==k)
            break;
        i++;
    }
    if(i==size)
        return -1;
    return i;
}

int binarySearch(vector<int> arr, int k) {
    int l=0, r=arr.size()-1, mid;
    while(r>=l) {
        mid=(l+r)/2;
        if(arr[mid]>k)r=mid-1;
        else if(arr[mid]<k)l=mid+1;
        else return mid;
    }
    return -1;
}

void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

vector<int> selectionSort(vector<int>& arr) {
    int n=arr.size(), mi=0;
    for(int i=0; i<n; i++) {
        mi=i;
        for(int j=i; j<n; j++) {
            if(arr[j]<arr[mi])mi=j;
        }
        swap(&arr[i], &arr[mi]);
    }
    return arr;
}

vector <int> bubbleSort(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) if(arr[j]>arr[j+1])swap(&arr[j], &arr[j+1]);
    }
    return arr;
}

vector <int> insertionSort(vector<int>& arr) {
    int n=arr.size();
    for(int i=1;i<n;i++) {
        int j=i;
        while(j>0 && arr[j]<arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
    return arr;
}

void maxtilli(vector<int>& arr) {
    for(int i=1;i<arr.size();i++)
        arr[i]=max(arr[i], arr[i-1]);
}

void sumOfSubarray(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum+=arr[j];
            cout<<sum<<" ";
        }
    }
}

void las(vector<int>& arr) {
    int i=0, ans=0;
    while(i<arr.size()-1) {
        int diff=arr[i+1]-arr[i], curr=1;
        while(arr[i+1]-arr[i] == diff) {
            curr++;
            i++;
        }
        ans=max(ans, curr);
    }
    cout<<ans<<endl;
}

void recordBreaking(vector<int>& arr) {
    int n=arr.size(), mxi=INT16_MIN, num=0;
    for(int i=0;i<n;i++) {
        if(arr[i]>mxi && (arr[i]>arr[i+1] || i==n))num++;
        mxi=max(mxi, arr[i]);
    }
    cout<<num<<endl;
}

void firstRepeatingElement(vector<int>& arr) {
    int n=arr.size(), mx=INT_MIN, sol=n;
    for(int i=0;i<n;i++) mx=max(mx, arr[i]);
    vector<int> occ;
    occ.assign(mx, -1);
    for(int i=0;i<n;i++) {
        if(occ[arr[i]]!=-1) sol=min(sol, occ[arr[i]]);
        occ[arr[i]]=i;
    }
    cout<<sol<<endl;
}

void q1(int area) {
    int num=sqrt(area);
    while(num>0) {
        if(area%num==0) {
            cout<<num<<" "<<area/num<<endl;
            return;
        }
        num--;
    }
}

int giveSubarraySum(vector<int>& arr, int k) {
    int i=0, j=0, sum=0, sol=0;
    while(j<arr.size() || i<arr.size()) {
        if(sum==k)sol++;
        if(sum>k) {
            sum-=arr[i];
            i++;
            continue;
        }
        sum+=arr[j];
        j++;
    }
    return sol;
}

int maxSubarraySum(vector<int>& arr) {
    int sol=INT_MIN, sum=0, i=0;
    while(i<arr.size()) {
        sum+=arr[i];
        sol=max(sol, sum);
        if(sum<0) sum=0;
        i++;
    }
    return sol;
}

int maxSubarraySumCircular(vector<int>& arr) {
    int size=arr.size(), sum=0, m1=maxSubarraySum(arr);
    for(int i=0;i<size;i++) {
        sum+=arr[i];
        arr[i]*=-1;
    }
    int m2=maxSubarraySum(arr);
    return max(m1, sum+m2);
}

vector<int> searchRange(vector<int>& arr, int k) {
    int s=0, e=arr.size()-1, mid;
    vector<int> sol;
    while(s<=e) {
        mid=(s+e)/2;
        if(arr[mid]>k)e=mid-1;
        else s=mid+1;
    }
    sol.push_back(s);
    s=0;e=arr.size()-1;
    while(s<=e) {
        mid=(s+e)/2;
        if(arr[mid]>=k)e=mid-1;
        else s=mid+1;
    }
    sol.push_back(e);
    return sol;
}



// RECURSION

int binSearch(vector<int> arr, int start, int end, int key) {
    if(start>end)return -1;
    int mid=(start+end)/2;
    if(arr[mid]>key)return binSearch(arr, start, mid-1, key);
    else if(arr[mid]<key)return  binSearch(arr, mid+1, end, key);
    else return mid;
}

int prodOfDigit(int n) {
    if(n==0) return 1;
    return n%10*prodOfDigit(n/10);
}

int zero(int n) {
    if(n==0)return 0;
    return (n%10==0) + zero(n/10);
}

bool checkSorted(int* arr, int n) {
    if(n==1)return true;
    if(arr[0]>arr[1])return false;
    return checkSorted(arr+1, n-1);
}

int lastocc(int* arr, int n, int key) {
    if(n==0)return -1;
    if(arr[n-1]==key)return n;
    return lastocc(arr, n-1, key);
}

vector<int> findThemAll(vector<int> sample, int i, int key, vector<int> sol) {
    if(sample.size()==i)return sol;
    if(sample[i]==key)sol.push_back(i);
    return findThemAll(sample, i+1, key, sol);
}

vector<int> findThemAllwithoutArg(vector<int> sample, int i, int key) {
    if(sample.size()==i) {
        vector<int> sol;
        return sol;
    }
    vector<int> ans=findThemAllwithoutArg(sample, i+1, key);
    if(sample[i]==key)ans.push_back(i);
    return ans;
}

int findPivotInRotated(vector<int> arr, int s, int e) {
    if(s>e)return e;
    int mid=(s+e)/2;
    if(arr[0]<=arr[mid])return findPivotInRotated(arr, mid+1, e);
    return findPivotInRotated(arr, s, mid-1);
}

string removea(string s) {
    if(s.empty())return s;
    if(s[0]!='a')return s[0]+removea(s.substr(1));
    return removea(s.substr(1));
}

string removeApple(string s) {
    if(s.empty())return s;
    if(s.substr(0, 5)!="apple")return s[0]+removeApple(s.substr(1));
    return removeApple(s.substr(5));
}

string removeApp(string s) {
    if(s.empty())return s;
    if(s.substr(0, 3)=="app" && s.substr(0, 5)!="apple") return removeApp(s.substr(3));
    return s[0]+removeApp(s.substr(1));
}


vector<vector<int>> subsets(vector<int> nums) {
    if(nums.size()==1) {
        vector<vector<int>>sol={ {nums[0]}, {} };
        return sol;
    }
    int num=nums[0];
    nums.erase(nums.begin());
    vector<vector<int>> sol=subsets(nums);
    int n=sol.size();
    for(int i=0;i<n;i++) {
        sol.push_back(sol[i]);
        sol[i].push_back(num);
    }
    return sol;
}
void subsetsAliter(vector<int> nums, vector<int> sub, vector<vector<int>>& sol) {
    if(nums.size()==0) {
        sol.push_back(sub);
        return;
    }
    int num=nums[0];
    nums.erase(nums.begin());
    subsetsAliter(nums, sub, sol);
    sub.push_back(num);
    subsetsAliter(nums, sub, sol);
}

vector<string> subsetsString(string s) {
    // (returing all subsequences of string)
    if(s.length()==1) {
        vector<string> sol={ s,"" };
        return sol;
    }
    vector<string> sol=subsetsString(s.substr(1));
    int n=sol.size();
    for(int i=0;i<n;i++) {
        sol.push_back(sol[i]);
        sol[i]=s[0]+sol[i];
    }
    return sol;
}
void subsetsStringAliter(string s, string sub, vector<string>& sol) {
    if(s.length()==0) {
        sol.push_back(sub);
        return;
    }
    subsetsStringAliter(s.substr(1), sub, sol);
    subsetsStringAliter(s.substr(1), s[0]+sub, sol);
}

void subsetDuplicate(vector<int> nums, vector<int> sub, vector<vector<int>>& sol) {
    if(nums.size()==0) {
        sol.push_back(sub);
        return;
    }
    int i=0, j=0;
    while(j<nums.size()-1 && nums[j]==nums[j+1])j++;
    vector<int> temp(nums.begin()+j+1, nums.end());
    do {
        subsetDuplicate(temp, sub, sol);
        sub.push_back(nums[j]);
        i++;
    } while(i<=j+1);
}


void permutation(vector<int> nums, vector<vector<int>>& sol) {
    // Brute force approach
    if(nums.size()==0)return;
    vector<int> next(nums.begin()+1, nums.end());
    permutation(next, sol);
    int n=sol.size(), m=sol[0].size();
    for(int i=0; i < n; i++) {
        vector<int> temp(sol[0].begin(), sol[0].end());
        for(int j=0; j <= m; j++) {
            temp.insert(temp.begin()+j, nums[0]);
            sol.push_back(temp);
            temp.erase(temp.begin()+j);
        }
        sol.erase(sol.begin());
    }
}
void permutations_2(string s, string ans, vector<string>& sol) {
    if(s.length()==0) {
        sol.push_back(ans);
        return;
    }
    for(int i=0;i<s.length();i++) permutations_2(s.substr(0, i)+s.substr(i+1), ans+s[i], sol);
}
void permutations_2(vector<int>& nums, int start, vector<vector<int>>& sol) {
    if(nums.size()==start) {
        sol.push_back(nums);
        return;
    }
    for(int i=start;i<nums.size();i++) {
        swap(nums[start], nums[i]);
        permutations_2(nums, start+1, sol);
        // swap(nums[start], nums[i]); may or may not be used
        // IMP: essential to be not used in duplicate variant
    }
}

void permutationsDuplicate(vector<int> nums, vector<int> ans, vector<vector<int>>& sol) {
    if(nums.size()==0) {
        sol.push_back(ans);
        return;
    }
    for(int i=0;i<nums.size();i++) {
        if(i>0 && nums[i]==nums[i-1])continue;
        vector<int> temp(ans.begin(), ans.end());
        vector<int> temp2(nums.begin(), nums.end());
        temp.push_back(nums[i]);
        temp2.erase(temp2.begin()+i);
        permutationsDuplicate(temp2, temp, sol);
    }
}
void permutationDuplicate(string s, string ans, vector<string>& sol) {
    if(s.length()==0) {
        sol.push_back(ans);
        return;
    }
    for(int i=0;i<s.length();i++) {
        if(i>0 && s[i]==s[i-1])continue;
        permutationDuplicate(s.substr(0, i)+s.substr(i+1), ans+s[i], sol);
    }
}
void permutationDuplicate_2(vector<int>& nums, int start, vector<vector<int>>& sol) {
    if(nums.size()==start) {
        sol.push_back(nums);
        return;
    }
    for(int i=start;i<nums.size();i++) {
        if(i!=start && nums[i]==nums[start])continue;
        swap(nums[start], nums[i]);
        permutationDuplicate_2(nums, start+1, sol);
    }
}

string keypad[10]={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
void keypadLetterCombinations(string s, string ans, vector<string>& sol) {
    if(s.length()==0) {
        sol.push_back(ans);
        return;
    }
    for(char ch : keypad[s[0]-'0']) keypadLetterCombinations(s.substr(1), ans+ch, sol);
}

void combination(vector<int> nums, int target, int i, vector<int>& ans, vector<vector<int>>& sol) {
    if(i==nums.size()) {
        if(target==0) sol.push_back(ans);
        return;
    };
    if(target>=nums[i]) {
        ans.push_back(nums[i]);
        combination(nums, target-nums[i], i, ans, sol);
        ans.pop_back();
    }
    combination(nums, target, i+1, ans, sol);
}
void combinationDuplicate(vector<int> nums, int target, int i, vector<int>& ans, vector<vector<int>>& sol) {
    int size=nums.size();
    if(i==size) {
        if(target==0) {
            sol.push_back(ans);
            return;
        }
    };
    if(target>=nums[i]) {
        int s=i, e=i;
        while(s<size-1 && nums[e]==nums[e+1])e++;
        do {
            ans.push_back(nums[e]);
            combination(nums, target-nums[e], e+1, ans, sol);
            s++;
        } while(s<=e);
        // ans.pop_back();
    }
    combination(nums, target, i+1, ans, sol);
}

void combinationAliter(vector<int> nums, int target, int start, vector<int>& ans, vector<vector<int>>& sol) {
    // This solve the combination problem similar to permutation problem, first pos p ek-ek karke sabko daal do
    if(target==0) {
        sol.push_back(ans);
        return;
    }
    for(int i=start;i<nums.size()&&target>=nums[i];i++) {
        if(i>start && nums[i]==nums[i-1])continue;
        ans.push_back(nums[i]);
        combinationAliter(nums, target-nums[i], i+1, ans, sol);
        ans.pop_back();
    }
}







// BACKTRACKING

bool attackCheck(vector<string>& ans) {
    int x=ans.size()-1, y=ans[ans.size()-1].find('1');

    for(int i=0;i<x;i++) {
        int j=ans[i].find('1');
        if(j==y || i+j==x+y || i-j==x-y)return false;
    }
    return true;
}
void NQueens(int n, vector<string>& ans, vector<vector<string>>& sol, string str) {
    // if(ans.size()>=n) {
    //     for(auto ele: ans)cout<<ele<<" ";
    //     cout<<endl;
    //     return;
    // }
    // if(pos>=n) {
    //     if(ans.size()==0)return;
    //     int pre=ans[ans.size()-1].find('1');
    //     ans.pop_back();
    //     NQueens(n, ans, sol, pre+1, str);
    //     return;
    // }
    // str[pos]='1';
    // ans.push_back(str);
    // str[pos]='0';
    // if(attackCheck(ans)) NQueens(n, ans, sol, 0, str);
    // ans.pop_back();
    // NQueens(n, ans, sol, pos+1, str);

    if(ans.size()==n) sol.push_back(ans);
    for(int i=0; i < n; i++) {
        str[i]='1';
        ans.push_back(str);
        str[i]='0';
        if(attackCheck(ans))NQueens(n, ans, sol, str);
        ans.pop_back();
    }

}


bool checkSudoko(vector<vector<char>>& board, int x, int y) {
    for(int i=0;i<9;i++)
        if(i!=x && board[i][y]==board[x][y])return false;
    for(int j=0;j<9;j++)if(j!=y && board[x][j]==board[x][y])return false;
    int a=3*(x/3), b=3*(y/3);
    for(int i=a;i<a+3;i++)
        for(int j=b;j<b+3;j++)if(board[i][j]==board[x][y] && (i!=x||j!=y))return false;
    return true;
}
void sudoko(vector<vector<char>>& board, int i, int j, bool* solved) {
    if(i==9) {
        *solved=true;
        return;
    }
    if(board[i][j]!='.') {
        if(j==8)sudoko(board, i+1, 0, solved);
        else sudoko(board, i, j+1, solved);
        return;
    }
    for(int num=1; num < 10; num++) {
        board[i][j]=num+'0';
        if(checkSudoko(board, i, j)) {
            if(j==8)sudoko(board, i+1, 0, solved);
            else sudoko(board, i, j+1, solved);
        }
        if(*solved) break;
        board[i][j]='.';
    }
}

bool checkPalindrome(string& s) {
    int n=s.length();
    for(int i=0;i<n/2;i++)if(s[i]!=s[n-i-1])return false;
    return true;
}
void palindromePartitioning(string s, vector<string>& ans, vector<vector<string>>& sol) {
    int n=s.length();
    if(n==0) {
        sol.push_back(ans);
        return;
    }
    for(int i=1;i<=n;i++) {
        string curr=s.substr(0, i);
        if(checkPalindrome(curr)) {
            ans.push_back(curr);
            palindromePartitioning(s.substr(i), ans, sol);
            ans.pop_back();
        }
    }
}

string kthperumte(string s, int start, int& k) {
    int n=s.length();
    if(start>=n) {
        if(k==1)return s;
        k--;
    }
    for(int i=start;i<n;i++) {
        swap(s[start], s[i]);
        string next=kthperumte(s, start+1, k);
        if(!next.empty())return next;
    }
    return "";
}

void ratInMaze(vector<vector<int>>& maze, string s, vector<string>& sol, vector<vector<int>>& visited, int i, int j, int n) {
    // Use loop instead of 4 ifs
    if(i==n-1 && j==n-1) {
        sol.push_back(s);
        return;
    }
    if(i<n-1 && maze[i+1][j] && !visited[i+1][j]) {
        visited[i+1][j]=1;
        ratInMaze(maze, s+'D', sol, visited, i+1, j, n);
        visited[i+1][j]=0;
    }
    if(j>0 && maze[i][j-1] && !visited[i][j-1]) {
        visited[i][j-1]=1;
        ratInMaze(maze, s+'L', sol, visited, i, j-1, n);
        visited[i][j-1]=0;
    }

    if(j<n-1 && maze[i][j+1] && !visited[i][j+1]) {
        visited[i][j+1]=1;
        ratInMaze(maze, s+'R', sol, visited, i, j+1, n);
        visited[i][j+1]=0;
    }

    if(i>0 && maze[i-1][j] && !visited[i-1][j]) {
        visited[i-1][j]=1;
        ratInMaze(maze, s+'U', sol, visited, i-1, j, n);
        visited[i-1][j]=0;
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    // int n;
    // vector<int> v={ 2,3,5,9,14,16,18 };
    // cout<<searchRange(v, 7);
    // for(int i=0; i<v.size(); i++)cout<<v[i]<<" ";

    // vector<int> v={ 1,2,14,2,16,18,16,16,17 };
    // int arr[]={ 1,-3,4,19,4,95,19 };
    // vector<int> sol;
    // sol=findThemAll(v, 0, 2, sol);
    // sol=findThemAllwithoutArg(v, 0, 2);
    // for(int num : sol)cout<<num<<" ";
    // cout<<removeApp("harsapphiappt_apple");

    // vector<int> v={ 1,2,3 };
    // vector<vector<int>> sol;
    // vector<int> v2(v.begin(), v.begin()+2);
    // for(int num : v2)cout<<num<<" ";
    // vector<vector<int>> sol=subsets(v);
    // subsetsAliter(v, {}, sol);
    // for(vector<int> subset: sol) {
    //     for(int num : subset)cout<<num<<" ";
    //     cout<<endl;
    // }
    // vector<string> v=subsetsString("har");
    // vector<string> v=;
    // subsetsStringAliter("har", "", v);
    // for(string subset : v) {
    //     cout<<subset;
    //     cout<<endl;
    // }

    // vector<int> v={ 1,2,3 };
    // vector<vector<int>> sol={ {} };
    // int i=0, size=v.size();
    // sort(v.begin(), v.end());
    // while(i<size) {
    //     int n=sol.size(), index=0;
    //     vector<int> temp;
    //     do {
    //         temp.push_back(v[i]);
    //         for(int j=0; j<n; j++) {
    //             // vector<int> to_push(sol[j].begin(), sol[j].end());
    //             // to_push.insert(to_push.end(), temp.begin(), temp.end());
    //             // sol.push_back(to_push);
    //             sol.push_back(sol[j]);
    //             sol[n+j].insert(sol[n+j].end(), temp.begin(), temp.end());
    //         }
    //         i++;
    //     } while(i<size && v[i]==v[i-1]);
    // }
    // for(vector<int> subset: sol) {
    //     for(int num : subset)cout<<num<<" ";
    //     cout<<endl;
    // }

    // vector<string> sol;
    // permutationDuplicate("aabc", "", sol);
    // for(string s : sol)cout<<s<<endl;
    // vector<int> nums={ 1,2,3,4,5,6 };
    // vector<vector<int>> sol;
    // permutations_2(nums, {}, sol);
    // for(vector<int> subset: sol) {
    //     for(int num : subset)cout<<num<<" ";
    //     cout<<endl;
    // }
    // vector<vector<int>> sol;
    // combination({ 2,3,6,7 }, 7, 0, {}, sol);
    // for(auto ele: sol) {
    //     for(auto num: ele)cout<<num<<" ";
    //     cout<<endl;
    // }

    // vector<vector<string>> sol;
    // int n=5;
    // vector<string> ans;
    // string str(n, '0');
    // NQueens(n, ans, sol, str);
    // cout<<sol.size()<<endl;
    // for(auto ele: sol) {
    //     for(auto num: ele)cout<<num<<" ";
    //     cout<<endl;
    // }

    // vector<vector<char>> board={ {'.','.','.','.','.','7','.','.','9'},{'.','4','.','.','8','1','2','.','.'},{'.','.','.','9','.','.','.','1','.'},{'.','.','5','3','.','.','.','7','2'},{'2','9','3','.','.','.','.','5','.'},{'.','.','.','.','.','5','3','.','.'},{'8','.','.','.','2','3','.','.','.'},{'7','.','.','.','5','.','.','4','.'},{'5','3','1','.','7','.','.','.','.'} };
    // bool solved=false;
    // sudoko(board, 0, 0, &solved);
    // for(auto vec: board) {
    //     for(auto ele: vec)cout<<ele<<" ";
    //     cout<<endl;
    // }
    // if(i>0 && maze[i-1][j] && !visited[i-1][j]) {
    //     visited[i-1][j]=1;
    //     ratInMaze(maze, s+'U', sol, visited, i-1, j, n);
    //     visited[i-1][j]=0;
    // }

    return 0;
}