#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie *children[26];
    bool isLeaf;

    Trie(){
        isLeaf = false;
        fill_n(children, 26, nullptr);
    }

    ~Trie(){
        for(auto i=0; i<26; ++i) delete children[i];
    }
};

// Function to insert a word in Trie
void insertWord(Trie *root, string& word){
    int pos = 0, len = word.size();
    while(pos < len){
        if(root->children[word[pos] - 'a'] == nullptr) root->children[word[pos] - 'a'] = new Trie();
        root = root->children[word[pos++] - 'a'];
    }
    root->isLeaf = true;
}

// Function to check if the given string is present in the Trie or not
bool check(Trie *root, string& word){
    int pos = 0, len = word.size();
    while(pos < len){
        if(root->children[word[pos] - 'a'] == nullptr) return false;
        root = root->children[word[pos++] - 'a'];
    }
    return root->isLeaf;
}


//  Function to build a trie from a given vector of strings
Trie *buildTrie(vector<string>& words){
    Trie *root = new Trie();
    for(auto word: words) insertWord(root, word);
    return root;
}

void testcase(){
    vector<string> input = {"fuzzface", "ibiza", "mxey", "ubah", "jeemzz", "danucd", "chocotaco"}; // name of my favorite pubg players
    Trie *root = buildTrie(input);

    int n;
    cin >> n;
    while(n--){
        string word;
        cin >> word;
        cout << check(root, word) <<'\n';
    }
    delete root;
}

signed main() {

#ifdef AKP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
    }
}