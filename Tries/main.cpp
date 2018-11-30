#include <iostream>
#include <unordered_map>
using namespace std;



class Node{
public:
    unordered_map<char, Node*> children;
    bool isACompleteWord = false;
    Node() {}
    ~Node() {}

};

class Trie {
public:
    Node* head = NULL;
    Trie() {
        this->head = new Node();
    }
    void AddWord(string word) {
        Node* current = this->head;
        for(auto c : word) {
            if(current->children.find(c) == current->children.end()){
                current->children.insert(pair<char, Node*>(c, new Node()));
            }
            current = current->children.at(c);
        }
        current->isACompleteWord = true;
    }

    bool wordExists(string word) {
        Node* current = this->head;
        bool isLastVisitedCompleteWord = false;
        for(auto c : word) {
            if(current->children.find(c) != current->children.end()) {
                current = current->children.at(c);
            }
            else
                return false;
        }
        return current->isACompleteWord;
    }

//    vector<string> startWith(string prefix) {
//
//    }

};

int main() {
    //In this project first create tries datastructure
    //Then insert some words into that tries (dictionay)

    Trie t;
    t.AddWord("Maz");
    t.AddWord("Reza");
    t.AddWord("Sofie");
    t.AddWord("Ali");

    cout << "Maz : " << (t.wordExists("Maz") ? "Exist!" : "Not Found!") << endl;
    cout << "OOOps : " << (t.wordExists("OOOps") ? "Exist!" : "Not Found!") << endl;
    cout << "Ali : " << (t.wordExists("Ali") ? "Exist!" : "Not Found!") << endl;
    cout << "Allie : " << (t.wordExists("Allie") ? "Exist!" : "Not Found!") << endl;
    cout << "Goli : " << (t.wordExists("Goli") ? "Exist!" : "Not Found!") << endl;
    //validate a word using the Tries
    return 0;
}