#include <string>
#include "trieNode.h"
using namespace std;

class Trie{
  TrieNode* root;
  
  
  
public:
  Trie(){
      this->root = new TrieNode('\0');
  }
  
private:
  void insertWord(TrieNode* root, string word){
      //base case
      if(word.size() == 0){
        this->root->isTerminal = true;
        return;
      }
      
      // small calculation
      int index = word[0] - 'a';
      TrieNode* child;
      if(this->root->children[index] != NULL){
        child = this->root->children[index];
      }else{
        // create a new node
        child = new TrieNode(word[0]);
        this->root->children[index] = child;
      }
      
      // recursive call;
      insertWord(child, word.substr(1));
  }
  
  bool searchWord(TrieNode* root, string word){
      if(word.size() == 0 && root->isTerminal == true){
          return true;
      }else{
          int index = word[0] - 'a';
          if(root->children[index]){
            return searchWord(root->children[index], word.substr(1));  
          }else{
              return false;
          }
      }
  }
  
public:
  void insertWord(string word){
    insertWord(this->root, word);
  }
  
  bool searchWord(string word){
      return searchWord(this->root, word);
  }
};