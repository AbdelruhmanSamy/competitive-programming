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


void YallaSolve() {
    int n , k;
    cin>>n>>k;

    queue<pii> q;
    map<int , pii> m;
    int ind = 0;
    int unread = 0;
    while(k--){
        int a , b;
        cin>>a>>b;
        if(a == 1){
            q.push(mp(ind , b));
            unread++;
            m[b].second++;
            ind++;
        }
        else if(a == 2){
            unread -= m[b].second;
            m[b].first = ind;
            m[b].second = 0;
        }
        else{
            while(q.size() && q.front().first < b){
                pii p = q.front();
                q.pop();
                if(p.first >= m[p.second].first) {
                    unread--;
                    m[p.second].second--;
                }
            }
        }

        cout<<unread<<"\n";
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
//      LotsOfTests();
    YallaSolve();
}