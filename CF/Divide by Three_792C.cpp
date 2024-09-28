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
    #define MAX (1<<8)
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD =  1e9;
    const double PI = acos(-1.0);

    void YallaSolve() {
        string s;
        cin>>s;

        vi ones , twos;
        int sum = 0;
        lp(i , 0 , s.size()-1){
            int val = s[i]-'0';
            if(val %3 == 1) {
                ones.push_back(i);
            }
            else if(val%3 == 2){
                twos.push_back(i);
            }
            sum+= val%3;
            sum%=3;
        }

        map<int , int>m = {{0 , 0} , {3 , 0}, {6 , 0}, {9 , 0} , {2 , 1}, {5 , 1}, {8 , 1} , {1 , 2}, {4 , 2}, {7 , 2}};
        int oneInd = ones.size()-1, twoInd = twos.size()-1;
        int i;
        string ans;

        for(i = s.size()-1 ; i>=0 ; i--){
            int val = s[i] - '0';
            sum= (sum - (val%3) + 3)%3;

            if(oneInd>-1 && ones[oneInd] >= i)
                oneInd--;
            if(twoInd>-1 && twos[twoInd] >= i)
                twoInd--;

            if(m[val] == sum) {
                ans = ans.size()> s.size()? ans:s;
            }
            else if(m[val] == (sum-1+3)%3 && (oneInd>=0 || twoInd >= 1)){
                if(oneInd>=0){
                    string temp = s;
                    temp.erase(ones[oneInd] , 1);
                    temp.erase(0, temp.find_first_not_of('0'));

                    if (temp.empty()) {
                        temp = "0";
                    }
                    ans = ans.size()> temp.size()? ans:temp;
                }
                if(twoInd >= 1){
                    string temp = s;
                    temp.erase(twos[twoInd-1] , 1);
                    temp.erase(twos[twoInd]-1 , 1);
                    temp.erase(0, temp.find_first_not_of('0'));

                    if (temp.empty()) {
                        temp = "0";
                    }
                    ans = ans.size()> temp.size()? ans:temp;
                }
            }
            else if(m[val] == (sum-2+3)%3 && (twoInd>=0 || oneInd >= 1)){
                if(twoInd>=0 && (oneInd<1 || twos[twoInd] > 0 || s.substr(1 , 2)!="00")){
                    string temp = s;
                    temp.erase(twos[twoInd] , 1);
                    temp.erase(0, temp.find_first_not_of('0'));

                    if (temp.empty()) {
                        temp = "0";
                    }
                    ans = ans.size()> temp.size()? ans:temp;

                }
                else{
                    string temp = s;
                    temp.erase(ones[oneInd-1] , 1);
                    temp.erase(ones[oneInd]-1 , 1);
                    temp.erase(0, temp.find_first_not_of('0'));

                    if (temp.empty()) {
                        temp = "0";
                    }
                    ans = ans.size()> temp.size()? ans:temp;
                }

            }
            s.erase(i);
        }

        if(ans.size())
            cout<<ans;
        else
            cout<<-1;
    }


    void LotsOfTests() {
        int t;
        cin >> t;
        lp(i , 1 , t) {
            YallaSolve();
            cout << "\n";
        }
    }
    void PLAY() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        cout << fixed << setprecision(0);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int main() {
        PLAY();
    //        LotsOfTests();
        YallaSolve();
    }