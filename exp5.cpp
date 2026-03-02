#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int MAX_LEN = 600005;
const ull P = 313; 
ull p_pow[MAX_LEN];

void precompute() {
    p_pow[0] = 1;
    for (int i = 1; i < MAX_LEN; ++i) {
        p_pow[i] = p_pow[i - 1] * P;
    }
}

ull compute_hash(const string& s) {
    ull h = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        h += s[i] * p_pow[i];
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<ull> hashes;
    hashes.reserve(n);
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        hashes.push_back(compute_hash(s));
    }

    sort(hashes.begin(), hashes.end());

    for (int i = 0; i < m; ++i) {
        string q;
        cin >> q;
        ull h = compute_hash(q);
        bool found = false;

        for (size_t j = 0; j < q.length() && !found; ++j) {
            char original_char = q[j];
            
            for (char c : {'a', 'b', 'c'}) {
                if (c != original_char) {
                    ull new_hash = h - (original_char * p_pow[j]) + (c * p_pow[j]);
                    
                    if (binary_search(hashes.begin(), hashes.end(), new_hash)) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
