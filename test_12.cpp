
//力扣算法题
//非动态规划，利用双指指针解决


int maxProfit(int* prices, int pricesSize) {

    if (prices == NULL || pricesSize == 0)return 0;

    int min = prices[0];
    int max_profit = 0;


    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        if ((prices[i] - min) > max_profit)
        {
            max_profit = prices[i] - min;
        }
    }

    return max_profit;

}