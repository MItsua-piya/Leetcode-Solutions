class Node{
    public:
    unordered_map<char,Node*>child;
    bool end=false;

};
class Trie{
public:
Node *root;

Trie(){
root=new Node();
}
void insert(string key ){
Node *temp=root;
for(int i=0;i<key.size();i++){
    if(temp->child.count(key[i])==0){
        temp->child[key[i]]=new Node();
    }
    temp=temp->child[key[i]];
   
}
 temp->end=true;
}
   string getPrefix() {
        string ans = "";
        Node* temp = root;

        while (temp->child.size() == 1 && !temp->end) {
            auto it = temp->child.begin();   // only child
            ans += it->first;
            temp = it->second;
        }

        return ans;
   }
};





class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie T;
        for(auto ch:strs){
            T.insert(ch);
        }
       return T.getPrefix();
    }
};