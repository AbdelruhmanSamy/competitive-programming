//
// Created by abdelruhman on 6/21/24.
//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i <= n; i++)
#define vi vector<int>
#define popcnt(a) __builtin_popcount(a)
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define veclp(n) for(auto it=n.begin() ; it!=n.end();it++)
#define pi 3.141592654
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e9
#define rep(i ,v) for(int i =0 ; i<v.size() ; i++)

map<pii , bool>vis;
int dfs(vvi& graph, vi& cat, int node, int counter , int m){

    if(cat[node])
        counter++;
    else
        counter =  0;

    if(counter > m)
        return 0;

    int ans = 0;
    bool f = 0;
    veclp(graph[node]){
        if(!vis[{node, *it}]){
            f = 1;
            vis[{*it , node}] = 1;
            ans+= dfs(graph ,cat, *it , counter, m);
        }
    }
    if(!f)
        return 1;
    return ans;
}

void YallaSolve() {
    ll n , m;
    cin>>n>>m;

    vi cat(n);
    vvi graph(n );

    lp(i , 0 , n-1)
        cin>>cat[i];

    lp(i , 0 , n-2){
        int a, b;
        cin>>a>>b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout<<dfs(graph ,cat, 0 , 0 , m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}