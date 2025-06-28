#include<iostream>
#include<string>
#include "/Users/anish/Desktop/Anish_Coding/love babbar /Trie/STL_Trie/Trie_stl.cpp"
using namespace std;


// Longest common prefix dhundhna hai in some given words.
// we included the Trie file so to use it.


// fuction to return if a root have more than one children.
bool moreThanOneChildren(TrieNode* root){
    if (root == NULL) 
        return false;
    
    int count = 0;
    for(int i = 0; i<26; i++){
        if(root->children[i]){
            count++;
        }
        if(count > 1){
            return true;
        }
    }
    return false;
}

string longestPrefix(TrieNode* root, string &ans){
    // Check if root is NULL
    if (root == NULL) 
        return ans;
    
    // no more common prefix from here
    if(moreThanOneChildren(root) || root->isTerminal){
        return ans;
    }
    else{
        // have common prefix because it has only one child.
        int index = -1;
        for(int i = 0; i<26; i++){
            if(root->children[i]){
                index = i;
                break;
            }
        }
        
        // Check if we found a valid child
        if (index == -1) return ans;
        
        // Check if the child exists before accessing its data
        if (root->children[index] != NULL) {
            ans.push_back(root->children[index]->data);
            return longestPrefix(root->children[index], ans);
        }
        return ans;
    }
}


int main(){
    Trie* t = new Trie();

    string data;
    cin>>data;

    // inserting strings in trie.
    while(data != "-1"){
        t->insertWord(data);
        cin>>data;
    }

    // for empty trie
    if (t->root == nullptr) {
        cout << "No words inserted." << endl;
        return 0;
    }

    // finding the longest prefix.
    string ans = "";
    string value = longestPrefix(t->root, ans);

    
    if(value.empty()){
        cout<<"No common prefix"<<endl;
    }
    else{
        cout<<"logest common prefix is "<<value<<endl;
    }

}

