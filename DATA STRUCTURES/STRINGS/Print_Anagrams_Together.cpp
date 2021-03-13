vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    unordered_map<string,vector<string>> m;
    for(auto word:string_list)
    {
        string s=word;
        sort(s.begin(),s.end());
        if(m.find(s)!=m.end())
        {
            auto it=m.find(s);
            it->second.push_back(word);
        }
        else
        {
            vector<string>  v;
            v.push_back(word);
             m.insert(make_pair(s,v));
        }
       
    }
    vector<vector<string>> res;
    for(auto ele:m)
    {
        vector<string> v1;
        for(int i=0;i<ele.second.size();i++)
             v1.push_back(ele.second[i]);
        res.push_back(v1);
    }
    return res;
}
