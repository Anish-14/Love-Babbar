#include<iostream>
#include<string>
#include "/Users/anish/Desktop/Anish_Coding/love babbar /Trie/STL_Trie/Trie_stl.cpp"
using namespace std;


// implementing phone directory.
// https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        isTerminal = false;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
    }

};

class Trie{
    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('a');
    }


    // will help us in deltion of a word.
    bool hasChildren(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return true;
            }
        }
        return false;
    }



    /********       Inserting word in Trie        ******* */




    // func used in insertWord function.
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return; 
        }

        // assuming all letters are in Upper case.
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if( root->children[index] != NULL ){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child; 
        }

        // recursive call
        return insertUtil(child, word.substr(1));
    }

    // function for inserting the data in Trie.
    void insertWord(string word){
        insertUtil(root, word);
    }




    /********       isPrefixPresent of a word in Trie        ********/




    // fun to chek ki ye prefix present hai ya nhi.
    bool startswithUtil(TrieNode* root, string word){
        // base case
        // agar pura word trie me pada hai then iska matlab vo prefix hai, irrespective of it being the terminal node.
        if(word.length() == 0){
            return true;
        }
        
        // indexing
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if( root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            return false;
        }

        return startswithUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startswithUtil(root, prefix);
    }



    /********       Removing a word in Trie        ********/




    void removeUtil(TrieNode* root, string word){

        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }
        
        // indexing
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if( root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            return;
        }

        return removeUtil(child, word.substr(1));
    }

    // fuction to remove a word from Trie.
    void removeWord(string word){
        return removeUtil(root, word);
    }

    
        
    /********       Removing a word in Trie with space deletion        ********/




    bool deleteUtil(TrieNode* root, string word, int depth = 0){
        // base case 
        if(root == NULL){
            return false;
        }

        if(word.size() == depth){
            if(root->isTerminal){
                root->isTerminal = false;
            }

            return !hasChildren(root);          // agar us root Node ke chidren hai then usko delete nhi karna because wo dusre word ka part hai.
        }

        int index = word[depth] - 'A';
        if(deleteUtil(root->children[index], word, depth + 1)){
            delete root->children[index];
            root->children[index] = NULL;

            // check sufficient condition and delete.
            // agar root ka terminal false hai and uske bachche nhi hai then we'll go and try to delete it.
            // terminal isliye check kiya because "TIME" && "TIMER" isme "E" per time end ho rha hai and while deleting time we don't want to delete time.
            return  (!root->isTerminal && !hasChildren(root) );       
        }

        return false;
    }

    // fuction to remove a word from Trie with space.
    bool deleteWord(string word){
        return deleteUtil(root, word);
    }


    void printSuggestion(TrieNode* curr, vector<string> &temp, string prefix){ 
        // base case
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestion(string str) {
        TrieNode *prev = root;
        vector<vector<string>> output;

        string prefix = "";

        for (int i = 0; i < str.length(); i++){
            char last = str[i];

            prefix.push_back(last);

            // check last character
            TrieNode* curr = prev->children[last - 'a'];

            // if not found
            if(curr == NULL){
                break;
            }

            // if found
            vector<string> temp;
            printSuggestion(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // creation of trie
    Trie* t = new Trie();

    // insert all contact in trie.
    for(int i = 0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    // return answer 
    return t->getsuggestion(queryStr);

}