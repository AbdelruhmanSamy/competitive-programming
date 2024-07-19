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
#define oo 1e18


void YallaSolve() {
    int n, m;
    cin>>n>>m;
    vvll arr(n , vll(m));
    if(n==1 && m==1)
    {
        int a; cin>>a;
        cout<<-1<<"\n";
        return;
    }

    int a;
    lp(i , 0 , n-1){
        lp(j , 0 , m-1){
            cin>>a;
            if(i==n-1 && j==m-1)
                continue;
            else if(j == m-1)
                arr[i+1][0] = a;
            else
                arr[i][j+1] = a;

        }
    }

    arr[0][0] = a;
    lp(i , 0 , n-1){
        lp(j , 0 , m-1){
            cout<<arr[i][j]<<" ";
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
    LotsOfTests();
//        YallaSolve();
}
