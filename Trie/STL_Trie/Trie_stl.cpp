#include<iostream>
using namespace std;

// Implementing Tries
// Assuming all capital letters are used in strings.
// will implement insertion, searching, searching a prefix, deleting .
// Trie is best used for dictionary implementation
// it has better space complexity than map other things equal.

// Path of this file  
// /Users/anish/Desktop/Anish_Coding/love babbar /Trie/STL_Trie/Trie_stl.cpp 


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



    /********       Inserting word in Trie        ********/


    // func used in insertWord function.
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return; 
        }

        // assuming all letters are in Upper case.
        int index = word[0] - 'A';
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



    /********       Searching a word in Trie        ********/


    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        // indexing
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if( root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    // function to search a word.
    bool searchWord(string word){
        return searchUtil(root, word);
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
        int index = word[0] - 'A';
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
        int index = word[0] - 'A';
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

};



// This code is working fine I have commented the int main function so that we can include this file 
// whenever we are needed in a program and there we can create a int main fuction.



// int main(){
//     Trie* t = new Trie();

//     t->insertWord("ANISH");
//     t->insertWord("SHREYAS");
//     t->insertWord("AKHIL");
//     t->insertWord("ARPIT");

//     cout<<"is present "<< t->searchWord("AKHIL")<<endl;     // 1
//     cout<<"is present "<< t->searchWord("ISHANT")<<endl;    // 0
//     cout<<"is present "<< t->searchWord("ANIS")<<endl;      // 0

//     cout<< "is prefix present "<< t->startsWith("ANI")<<endl;   // 1 

//     // REMOVED THE WORD BUT SPACE IS STILL OCCUPIED AS WE ONLY COVERTED IS_TERMINAL FALSE.
//     cout<<"is present "<< t->searchWord("ANISH")<<endl;     // 1
//     t->removeWord("ANISH");
//     cout<<"is present "<< t->searchWord("ANISH")<<endl;     // 0

//     // below line gives 1 as output that shows that "ANISH" puri tarah se delete nhi hua.
//     cout<< "is prefix present "<< t->startsWith("ANI")<<endl;   // 1


//     // puri tarah se delte i.e. space also freed.
//     t->deleteWord("ANISH");
//     cout<< "is prefix present "<< t->startsWith("ANIS")<<endl;   // 0
//     cout<< "is prefix present "<< t->startsWith("A")<<endl;   // 1

// }


