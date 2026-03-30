#include <vector>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> prices(n, 1e9);
        prices[src] = 0;
        
        for (int i = 0; i <= k; i++) {
            std::vector<int> tmpPrices = prices;
            
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];
                
                if (prices[u] != 1e9 && prices[u] + price < tmpPrices[v]) {
                    tmpPrices[v] = prices[u] + price;
                }
            }
            
            prices = tmpPrices;
        }
        
        return prices[dst] == 1e9 ? -1 : prices[dst];
    }
};
