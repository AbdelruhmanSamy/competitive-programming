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
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18
const ll MOD =  1e9 + 7;
const double PI = acos(-1.0);

vector<vector<string>> v;

bool isMatch(string a , string b){
    return (a[0] == b[0] || a[1] == b[1]);
}

void YallaSolve() {
    string s;
    cin>>s;
    while(s[0]!='#'){
        v.resize(52);
        v[0].push_back(s);

        lp(i , 1, 51) {
            cin>>s;
            v[i].push_back(s);
        }


        lp(i , 1 , v.size()-1){
            int pre3 = i-3;
            int pre1 = i-1;

            if (pre3 >=0 && isMatch(v[i].back(), v[pre3].back())
                || pre1 >=0 && isMatch(v[i].back(), v[pre1].back())) {

                if (pre3 >=0 && isMatch(v[i].back(), v[pre3].back())) {
                    v[pre3].push_back(v[i].back());
                    v[i].pop_back();

                    if(v[i].empty())
                        v.erase(v.begin() + i , v.begin() + i + 1);

                    i = pre3-1;
                } else {
                    v[pre1].push_back(v[i].back());
                    v[i].pop_back();

                    if(v[i].empty())
                        v.erase(v.begin() + i , v.begin() + i + 1);
                    i = pre1-1;
                }
            }
        }


        cout<<v.size();
        if(v.size() > 1)
            cout<<" piles remaining:";
        else
            cout<<" pile remaining:";

        lp(i , 0 , v.size()-1){
            cout<<" "<<v[i].size();
        }
        cout<<"\n";

        v.clear();
        cin>>s;
    }

}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
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
