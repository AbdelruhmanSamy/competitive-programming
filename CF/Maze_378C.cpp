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
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)

int x[]= {1 , 0  , -1 , 0};
int y[]= {0 , -1 , 0 , 1};

vvi vis;
int n , m , k;

bool isValid(int i , int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

void dfs(vvch& mat , int i , int j){
    if(vis[i][j])
        return;

    vis[i][j] = 1;

    lp(ind, 0 , 3){
        int a = i+x[ind] , b=j+y[ind];
        if(isValid(a , b) && mat[a][b] == '.'){
            dfs(mat , a , b);
        }
    }

    if(k){
        k--;
        mat[i][j] = 'X';
    }

}

void YallaSolve(){
    cin>>n>>m>>k;
    vis.resize(n , vi(m , 0));

    vvch mat(n , vch(m));

    int i_in , j_in;
    lp(i , 0 , n-1){
        lp(j , 0 , m-1){
            cin>>mat[i][j];
            if(mat[i][j] == '.') {
                i_in = i;
                j_in = j;
            }
        }
    }

    dfs(mat , i_in , j_in);

    lp(i , 0 , n-1){
        lp(j , 0 , m-1){
            cout<<mat[i][j];
        }
        cout<<"\n";
    }


}
void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
//            cout << "\n";
    }
}

void PLAY() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    PLAY();
//        LotsOfTests();
    YallaSolve();
}