//
// Created by abdelruhman on 7/2/24.
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


vi primes;

void seive(int n){
    vi arr(n+1);

    arr[1] = 1;

    for(int i = 2 ; i*i<=n ; i++){
        if(!arr[i]){
            for(int j = i*i; j<=n ; j+=i){
                arr[j]=1;
            }
        }
    }

    lp(i,   1 , n){
        if(!arr[i])
            primes.push_back(i);
    }
}

void YallaSolve() {
    seive(1e6);

    int n, m;
    cin>>n>>m;

    vvi mat(n , vi(m));
    vi row(n) , col(m);

    lp(i , 0 , n-1){
        lp(j ,  0 , m-1){
            cin>>mat[i][j];
            int k = lower_bound(all(primes) , mat[i][j]) - primes.begin();
            row[i]+=primes[k] - mat[i][j];
            col[j]+=primes[k] - mat[i][j];
        }
    }

    sort(all(row));
    sort(all(col));

    cout<<min(row[0] , col[0]);
}




void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
        cout << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
//            LotsOfTests();
}