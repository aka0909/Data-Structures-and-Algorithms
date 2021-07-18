/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*,Node*> mp;
    
    Node* clone(Node* node)
    {
        if(mp.find(node)==mp.end())
        {
            mp[node]=new Node(node->val,{});
            
            for(auto neighbor:node->neighbors)
            {
                mp[node]->neighbors.push_back(clone(neighbor));
            }
        }
        
        return mp[node];
    }
   
public:
    Node* cloneGraph(Node* node) {
        
        if(!node) return nullptr;
        
        return clone(node);
    }
    
    
};
