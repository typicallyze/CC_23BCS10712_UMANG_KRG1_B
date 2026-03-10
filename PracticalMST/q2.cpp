#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxProd(vector<string> &words)
{
    int n = words.size();
    vector<int> bitmask(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (char c : words[i])
        {
            bitmask[i] |= (1 << (c - 'a'));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((bitmask[i] & bitmask[j]) == 0)
            {
                ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> words1 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    vector<string> words2 = {"a", "aa", "aaa", "aaaa"};

    cout << maxProd(words);
    cout << maxProd(words1);
    cout << maxProd(words2);

    return 0;
}