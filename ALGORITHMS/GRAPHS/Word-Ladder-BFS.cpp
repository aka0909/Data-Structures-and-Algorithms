class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> us;
        for(int i=0;i<wordList.size();i++)
            us.insert(wordList[i]);
        if(us.find(endWord)==us.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                string start=q.front();
                q.pop();
                if(start==endWord)
                    return res+1;
                for(int j=0;j<start.length();j++)
                {
                    string temp=start;
                    for(char letter='a';letter<='z';letter++)
                    {
                        temp[j]=letter;
                        
                        if(us.find(temp)!=us.end() && start!=temp)
                        {
                            q.push(temp);
                            us.erase(temp);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
