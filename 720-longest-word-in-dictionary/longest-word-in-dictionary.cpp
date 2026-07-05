class Node{
public:
unordered_map<char,Node*>child;
bool end;

Node(){
    end=false;
}
};
class Tries{
    public:
    Node *root;
    Tries(){
        root=new Node();
    }
    void insert(string key){
        Node *temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->child.count(key[i])==0){
                temp->child[key[i]]=new Node();
            }
            temp=temp->child[key[i]];
        }
        temp->end=true;

    }
    void helper(Node*root,string &ans, string temp){
       for(auto ch:root->child){
        if(ch.second->end){
            temp+=ch.first;
            if ((temp.size() == ans.size() && temp < ans) ||
                (temp.size() > ans.size())) {
                ans = temp;
            }
 helper(ch.second,ans,temp);
   temp = temp.substr(0, temp.size() - 1);
        }
       
           
       }

    }
    string count(){
        string ans="";
helper(root,ans,"");
return ans;
    }


};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Tries T;
        for(auto ch:words){
            T.insert(ch);
        }
       return T.count();
    }
};