    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    #define pii pair<int , int>
    #define pll pair<ll , ll>
    #define lp(i, j, n) for (int i = j; i <= n; i++)
    #define vi vector<int>
    #define popcnt(a) __builtin_popcount(a)
    #define vvi vector<vector<int>>
    #define vll vector<ll>
    #define vch vector<char>
    #define vvll vector<vector<ll>>
    #define vvch vector<vector<char>>
    #define vpi vector<pii>
    #define vpl vector<pll>
    #define veclp(n) for(auto it=n.begin() ; it!=n.end();it++)
    #define mp make_pair
    #define all(v) v.begin() , v. end()
    #define MAX (1<<8)
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD = 1e9;
    const double PI = acos(-1.0);

    ll n , totStringSz;

    struct Trie{
        struct TrieNode{
            TrieNode* child[26];
            ll totLength , count , EndCount;
            bool isEnd;

            TrieNode(){
                lp(i , 0 , 25){
                    child[i] = nullptr;
                }
                totLength = 0;
                count = 0;
                isEnd = 0;
                EndCount = 0;
            }
        };

        TrieNode* root;

        Trie(){
            root = new TrieNode();
        }

        void insert(string& word){
            TrieNode* ptr  = root;

            for(int i = word.size()-1 ; i>=0 ; i--){
                char c = word[i];
                int ind = c - 'a';
                if(!ptr->child[ind]){
                    ptr->child[ind] = new TrieNode();
                }
                ptr = ptr->child[ind];
                ptr->count++;
                ptr->totLength+=(i+1);
            }
            ptr->isEnd = 1;
            ptr->EndCount++;
        }

        ll search(string & word){

            if(!word.size())
                return totStringSz;

            TrieNode* ptr  = root;

            ll ans = 0;
            TrieNode* temp = ptr->child[word[0] - 'a'];
            if(!temp)
                return totStringSz + n*word.size();

            ans+= (n - temp->count) * word.size() + (totStringSz - temp->totLength);

            for(int i = 0 ; i<word.size() ; i++){
                int ind = word[i]-'a';

                if(!ptr->child[ind]){
                    return ans;
                }

                ptr = ptr->child[ind];

                lp(j, 0, 25) {
                    ll c = 0;
                    if (ptr->child[j] &&  j != (word[i + 1] - 'a')) {
                        ans += ptr->child[j]->totLength;
                        c += ptr->child[j]->count;
                    }
                    ans += c * (word.size() - (i+1));
                }

                if(ptr->isEnd){
                    ans+= (word.size() - (i+1)) * ptr->EndCount;
                }


            }

            return ans;
        }


    };


    void YallaSolve() {
        cin>>n;
        vector<string> str(n);

        Trie tr;
        lp(i , 0 , n-1){
            cin>>str[i];
            totStringSz += str[i].size();
            tr.insert(str[i]);
        }

        ll ans = 0;
        lp(i , 0 , n-1){
            ans+= tr.search(str[i]);
        }

        cout<<ans;
    }


    void LotsOfTests() {
        int t;
        cin >> t;
        lp(i, 1, t) {
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
    //            LotsOfTests();
        YallaSolve();
    }