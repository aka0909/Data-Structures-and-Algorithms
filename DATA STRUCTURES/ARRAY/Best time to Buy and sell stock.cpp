class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0,min=INT_MAX,max{};
      for(int i=0;i<prices.size();i++){
          if(prices[i]<min)
              min=prices[i];
          else if(prices[i]-min>max)
              max=prices[i]-min;
      }
      return max;
      
    }
};
