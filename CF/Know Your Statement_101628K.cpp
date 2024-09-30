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

    const ll MOD = 1e9;
    const double PI = acos(-1.0);

    struct TrieNode {
        TrieNode *children[26];
        set<int> ind;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    struct Trie {
        TrieNode *root;

        Trie() {
            root = new TrieNode();
        }

        void insert(string &word, int i) {

            TrieNode *ptr = root;

            for (auto c: word) {
                if (!ptr->children[c - 'a']) {
                    ptr->children[c - 'a'] = new TrieNode();
                }
                ptr = ptr->children[c - 'a'];
            }
            ptr->ind.insert(i);
        }

        // query 2
        bool searchPrefix(string &word, int l, int r) {
            TrieNode *ptr = root;

            for (auto c: word) {
                if (!ptr->children[c - 'a']) {
                    return false;
                }
                ptr = ptr->children[c - 'a'];

                if (ptr->ind.size()) {
                    auto it = ptr->ind.lower_bound(l);
                    if (it != ptr->ind.end() && *it <= r)
                        return true;
                }
            }
            return false;
        }

        // query 3
        bool searchRange(string &word, int l, int r) {
            TrieNode *ptr = root;

            for (auto c: word) {
                if (!ptr->children[c - 'a'])
                    return false;
                ptr = ptr->children[c - 'a'];
            }

            return searchRangePrivate(word, ptr, l, r);
        }


        void deleteWord(string &word , int i) {
            deleteNodePrivate(word , root->children[word[0] - 'a'] , root , 0  , i);
        }

    private:
        bool deleteNodePrivate(string &word, TrieNode *ptr, TrieNode *prev, int pos , int i) {
            if (!ptr)
                return true;
            if (pos < word.size()-1) {
                deleteNodePrivate(word, ptr->children[word[pos+1] - 'a'], ptr, pos + 1, i);
            }

            int count = 0;
            lp(j, 0, 25) {
                if (ptr->children[j]) {
                    count++;
                }
            }
            if(!count && ((pos == word.size()-1 && ptr->ind.size() <= 1) || (ptr->ind.size() == 0))) {
                delete ptr;
                prev->children[word[pos] - 'a'] = nullptr;
                return  true;
            }
            else if (pos == word.size() - 1) {
                ptr->ind.erase(i);
                return false;
            }

            return true;
        }

        bool searchRangePrivate(string &word, TrieNode *ptr, int l, int r) {
            auto it = ptr->ind.lower_bound(l);
            if (it != ptr->ind.end() && *it <= r)
                return true;

            lp(i, 0, 25) {
                if (ptr->children[i] && searchRangePrivate(word, ptr->children[i], l, r))
                    return true;
            }

            return false;
        }

    };

    void YallaSolve() {
        ll n;
        cin >> n;

        vector<string> arr(n);
        scn(arr);

        Trie tr;
        lp(i, 1, n)tr.insert(arr[i - 1], i);

        ll q;
        cin >> q;
        while (q--) {
            int who, l, r;
            string s;
            cin >> who;
            if (who == 1) {
                int ind;
                cin >> ind >> s;
                tr.deleteWord(arr[ind - 1] , ind);
                arr[ind-1] = s;
                tr.insert(s, ind);
            } else {
                cin >> l >> r >> s;
                bool ans;
                if (who == 2) {
                    ans = tr.searchPrefix(s, l, r);
                } else {
                    ans = tr.searchRange(s, l, r);
                }

                if (ans)
                    cout << "Y";
                else
                    cout << "N";
                cout << "\n";
            }
        }

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
        //        LotsOfTests();
        YallaSolve();
    }