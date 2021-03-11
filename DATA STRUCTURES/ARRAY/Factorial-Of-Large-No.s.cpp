class Solution {
  public:
    vector<int> multiply(int i,vector<int> v)
    {
        int carry=0;
        for(int j=0;j<v.size();j++)
        {
            int prod=v[j]*i+carry;
            
            v[j]=prod%10;
            carry=prod/10;
            
        }
        while(carry)
        {
            v.push_back(carry%10);
            carry=carry/10;
        }
        return v;
    }  
    
    vector<int> factorial(int N){
        vector<int> v;
        v.push_back(1);
        for(int i=2;i<=N;i++)
           {
               v=multiply(i,v);
           }
        reverse(v.begin(),v.end());
        return v;
    }

};
