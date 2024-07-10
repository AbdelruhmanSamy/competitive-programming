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
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)


void YallaSolve(){
    int n , m , k;
    cin>>n>>m>>k;

    //first -> col , sec -> order

    vpi row(n ,mp(0 , 0)) , col(m, mp(0 , 0));
    int curr=1;

    while(k--){
        int a , b ,  c;
        cin>>a>>b>>c;
        b--;
        if(a==1){
            row[b]= mp(curr , c);
        }
        else{
            col[b] = mp(curr , c);
        }
        curr++;
    }

    lp(i , 0 , n-1){
        lp(j , 0  , m-1){
            int val = (row[i].first > col[j].first)?row[i].second:col[j].second;
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}
void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
//            YallaSolve();
        cout << "\n";
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
