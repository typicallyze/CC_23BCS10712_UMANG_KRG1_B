#include <vector>

using namespace std;

class Solution
{
    void mergeSort(vector<pair<int, int>> &v, int left, int right, vector<int> &count, vector<pair<int, int>> &temp)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid, count, temp);
        mergeSort(v, mid + 1, right, count, temp);

        int i = left;
        int j = mid + 1;
        int k = left;
        int right_smaller = 0;

        while (i <= mid && j <= right)
        {
            if (v[i].first <= v[j].first)
            {
                count[v[i].second] += right_smaller;
                temp[k++] = v[i++];
            }
            else
            {
                right_smaller++;
                temp[k++] = v[j++];
            }
        }

        while (i <= mid)
        {
            count[v[i].second] += right_smaller;
            temp[k++] = v[i++];
        }

        while (j <= right)
        {
            temp[k++] = v[j++];
        }

        for (int p = left; p <= right; ++p)
        {
            v[p] = temp[p];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> count(n, 0);

        vector<pair<int, int>> v(n);
        vector<pair<int, int>> temp(n);

        for (int i = 0; i < n; ++i)
        {
            v[i] = {nums[i], i};
        }

        mergeSort(v, 0, n - 1, count, temp);

        return count;
    }
};