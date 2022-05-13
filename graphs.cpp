#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

void print(vector<int> graph[], int n) {
    for(int i=1;i<n+1;i++) {
        for(auto ele: graph[i])cout<<ele<<" ";
        cout<<endl;
    }
}

void bfs(vector<int> graph[], int n) {
    bool vis[n+1]={ 0 };
    queue<int> q;
    for(int i=1;i<n+1;i++) {
        if(!vis[i]) {
            q.push(i);
            vis[i]=1;
            while(!q.empty()) {
                int ele=q.front();
                for(auto i: graph[ele]) {
                    if(!vis[i]) {
                        q.push(i);
                        vis[i]=1;
                    }
                }
                q.pop();
                cout<<ele<<" ";
            }
        }
    }
}

void dfsSol(vector<int> graph[], int n, bool vis[], int i) {
    cout<<i<<" ";
    vis[i]=1;
    for(auto it: graph[i]) {
        if(!vis[it]) {
            dfsSol(graph, n, vis, it);
        }
    }
}
void dfs(vector<int> graph[], int n) {
    bool vis[n+1]={ 0 };
    for(int i=1;i<n+1;i++) {
        if(!vis[i]) {
            dfsSol(graph, n, vis, i);
        }
    }
}

bool cdudSol(vector<int> graph[], int n, int i, bool vis[], int pre) {
    vis[i]=1;
    for(auto ele: graph[i]) {
        if(!vis[ele]) {
            if(cdudSol(graph, n, ele, vis, i)) return true;
        }
        else if(ele!=pre) return true;
    }
    return false;
}
bool cdud(vector<int> graph[], int n) {
    bool vis[n+1]={ 0 };
    for(int i=1;i<n+1;i++) {
        if(!vis[i]) {
            if(cdudSol(graph, n, i, vis, -1)) return true;
        }
    }
    return false;
}

bool cdubSol(vector<int> graph[], bool vis[], int i) {
    queue<pair<int, int>> q;
    q.push({ i,-1 });
    vis[i]=1;
    while(!q.empty()) {
        int curr=q.front().first;
        int parent=q.front().second;
        for(auto ele: graph[curr]) {
            if(!vis[ele]) q.push({ ele,curr });
            else if(ele!=parent) return true;
            vis[ele]=1;
        }
        q.pop();
    }
    return false;
}
bool cdub(vector<int> graph[], int n) {
    bool vis[n+1]={ 0 };
    for(int i=1;i<n+1;i++) {
        if(!vis[i]) {
            if(cdubSol(graph, vis, i))return true;
        }
    }
    return false;
}

bool cdddSol(vector<int> graph[], bool vis[], bool currVis[], int i) {
    vis[i]=1;
    currVis[i]=1;
    for(auto ele: graph[i]) {
        if(!vis[ele]) {
            if(cdddSol(graph, vis, currVis, ele))return true;
        }
        else if(currVis[ele])return true;
    }
    currVis[i]=0;
    return false;
}
bool cddd(vector<int> graph[], int n) {
    bool vis[n+1]={ 0 };
    bool currVis[n+1]={ 0 };
    for(int i=1;i<n+1;i++) {
        if(!vis[i]) {
            if(cdddSol(graph, vis, currVis, i))return true;
        }
    }
    return false;
}

void topolgicaldfsSol(vector<int> graph[], int i, stack<int>& st, bool vis[]) {
    vis[i]=1;
    for(auto ele: graph[i]) {
        if(!vis[ele])topolgicaldfsSol(graph, ele, st, vis);
    }
    st.push(i);
}
vector<int> topologicaldfs(vector<int> graph[], int n) {
    bool vis[n]={ 0 };
    stack<int> st;
    vector<int> sol;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            topolgicaldfsSol(graph, i, st, vis);
        }
    }
    while(!st.empty()) {
        sol.push_back(st.top());
        st.pop();
    }
    return sol;
}

vector<int> topobfs(vector<int> graph[], int n) {
    queue<int> q;
    vector<int> inDegree(n, 0);
    vector<int> ans;
    for(int i=0;i<n;i++) {
        for(auto ele: graph[i])inDegree[ele]++;
    }
    for(int i=0;i<n;i++) {
        if(inDegree[i]==0)q.push(i);
    }
    while(!q.empty()) {
        int ele=q.front();
        q.pop();
        ans.push_back(ele);
        for(auto node: graph[ele]) {
            inDegree[node]--;
            if(inDegree[node]==0)q.push(node);
        }
    }
    // for(auto ele: ans)cout<<ele<<endl;
    return ans;
}

bool cddb(vector<int> graph[], int n) {
    queue<int> q;
    vector<int> inDegree(n, 0);
    vector<int> ans;
    for(int i=0;i<n;i++) {
        for(auto ele: graph[i])inDegree[ele]++;
    }
    for(int i=0;i<n;i++) {
        if(inDegree[i]==0)q.push(i);
    }
    while(!q.empty()) {
        int ele=q.front();
        q.pop();
        ans.push_back(ele);
        for(auto node: graph[ele]) {
            inDegree[node]--;
            if(inDegree[node]==0)q.push(node);
        }
    }
    return ans.size()!=n;
}

bool bipartiteBfs(vector<vector<int>> graph) {
    int n=graph.size();
    queue<int> q;
    vector<int> vis(n, -1);
    for(int i=0;i<n;i++) {
        if(vis[i]==-1) {
            vis[i]=0;
            q.push(i);
            while(!q.empty()) {
                int ele=q.front();
                q.pop();
                for(auto node: graph[ele]) {
                    if(vis[node]==-1) {
                        q.push(node);
                        vis[node]=!vis[ele];
                    }
                    else if(vis[node]==vis[ele]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool bipartiteDfsSol(vector<vector<int>> graph, int toColor, vector<int> color, int node) {
    color[node]=toColor;
    for(auto ele: graph[node]) {
        if(color[ele]==-1) {
            if(!bipartiteDfsSol(graph, 1-toColor, color, ele))return false;
        }
        else if(color[ele]==toColor)return false;
    }
    return true;
}
bool bipartiteDfs(vector<vector<int>> graph) {
    int n=graph.size();
    vector<int> color(n, -1);
    for(int i=0;i<n;i++) {
        if(color[i]==-1) {
            if(!bipartiteDfsSol(graph, 0, color, 0))return false;
        }
    }
    return true;
}

vector<int> shortestPathUnitUndirected(vector<int> graph[], int n) {
    queue<int> q;
    bool vis[n]={ 0 };
    vector<int> sol(n, 0);
    q.push(0);
    vis[0]=1;
    while(!q.empty()) {
        int ele=q.front();
        q.pop();
        for(auto it: graph[ele]) {
            if(!vis[it]) {
                q.push(it);
                vis[it]=1;
                sol[it]=sol[ele]+1;
            }
        }
    }
    return sol;
}

// Read notes to understand why the below algo is wrong
// vector<int> dijkstra(vector<pair<int, int>> graph[], int n, int s) {
//     queue<int> q;
//     bool vis[n]={ 0 };
//     vector<int> sol(n, INT_MAX);
//     q.push(s);
//     vis[s]=1;
//     sol[s]=0;
//     while(!q.empty()) {
//         int ele=q.front();
//         q.pop();
//         for(auto it: graph[ele]) {
//             if(!vis[it[0]]) {
//                 q.push(it[0]);
//                 vis[it[0]]=1;
//             }
//             //cout<<ele<<" "<<sol[ele]<<" "<<it[1]<<endl;
//             sol[it[0]]=min(sol[it[0]], sol[ele]+it[1]);4
//         }
//     }
//     for(int i=0;i<n;i++) {
//         for(auto ele: graph[i]) {
//             for(int j=0;j<ele.size();j++) {
//                 cout<<ele[j]<<" ";
//             }
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return sol;
// }

vector<int> dijkstra(vector<int> graph[], int n, int source) {
    vector<int> ans(n, INT_MAX);
    ans[source]=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
    pq.push({ 0, source });
    while(!pq.empty()) {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto ele: graph[node]) {
            if(ans[ele[0]]> dis+ele[1]) {
                ans[ele[0]]=dis+ele[1];
                pq.push({ ans[ele[0]], ele[0] });
            }
        }
    }
    return ans;
}

int spanningTreePrims(int n, vector<vector<int>> graph[]) {
    int ans=0;
    bool vis[n]={ 0 };
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
    pq.push({ 0,0 });
    while(!pq.empty()) {
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        ans+=dis;
        for(auto ele: graph[node]) {
            if(!vis[ele[0]]) {
                pq.push({ ele[1],ele[0] });
            }
        }
    }
    return ans;
}

int rank[1000];
int parent[1000];

void makeSet(int n) {
    for(int i=0;i<n;i++) {
        rank[i]=0;
        parent[i]=i;
    }
}
void union(int a, int b) {
    int pa=findParent(a);
    int pb=findParent(b);
    if(rank[pa]>rank[pb]) {
        parent[pb]=pa;
    }
    else if(rank[pb]>rank[pa]) {
        parent[pa]=pb;
    }
    else {
        parent[pb]=pa;
        rank[pa]++;
    }
}
int findParent(int node) {
    if(parent[node]==node)return node;
    parent[node]=findParent(parent[node]);
    return parent[node];
}

int kruskelAlgo(vector<vector<int>> edges) {
    int n=edges.size();
    int ans=0;
    for(int i=0;i<n;i++) {
        if(findParent(edges[i][0])!=findParent(edges[i][1])) {
            union(edges[i][0], edges[i][1]);
            ans+=edges[i][2];
        }
    }
}

void bridgesSol(int n, vector<int> graph[], bool vis[], int node) {
    vis[node]=1;
    for(auto ele: graph[node]) {
        if(!vis[ele])bridgesSol(n, graph, vis, ele);
    }
}
void bridges(int n, vector<int> graph[]) {
    bool vis[n]={ 0 };
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            bridgesSol(n, graph);
        }
    }
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    // adjacent matrix
    // int n, m;
    // cin>>n>>m;
    // int graph[n+1][n+1]={ {0} };
    // for(int i=0;i<n+1;i++) {
    //     for(int j=0;j<n+1;j++) {
    //         graph[i][j]=0;
    //     }
    // }
    // for(int i=0;i<m;i++) {
    //     int a, b;
    //     cin>>a>>b;
    //     graph[a][b]=1;
    //     graph[b][a]=1;
    // }
    // for(int i=0;i<n+1;i++) {
    //     for(int j=0;j<n+1;j++) {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // adjacency list
    int n, m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        // comment lower for directed
        // graph[b].push_back(a);
    }

    print(graph, n);
    // bfs(graph, n);
    // dfs(graph, n);
    // cout<<cdud(graph, n);
    // cout<<cdub(graph, n);
    // cout<<cddd(graph, n);
    // topologicaldfs(graph, n);
    // topobfs(graph, n);
    // cout<<cddb(graph, n)<<endl;
    // shortestPathUnitUndirected(graph, n);

    return 0;
}