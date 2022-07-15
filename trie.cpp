#include<bits/stdc++.h>
using namespace std;
// insert and search O(|S|) S = lengthOfString
int numberOfNodesCreated = 0;
struct node{
    node *nxt[26];
    bool isEnd;
    node(){
        for(int i = 0; i < 26; i ++)
            nxt[i] = NULL;
        isEnd = false;
        numberOfNodesCreated ++;
    }
};
node* root;

void insertTrie(string s){
    node *curr = root;
    for(char ch : s){
        int imap = ch - 'a';
        if(curr->nxt[imap] == NULL)
            curr->nxt[imap] = new node();

        curr = curr->nxt[imap];
    }
    curr->isEnd = true;
}
bool searchTrie(string s){
    node *curr = root;
    for(char ch : s){
        int imap = ch - 'a';
        if(curr->nxt[imap] == NULL)
            return false;

        curr = curr->nxt[imap];
    }
    return curr->isEnd;
}
int main(){
    int n;
    cin>>n;

    root = new node();
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        insertTrie(s);
    }
    if(searchTrie("sourav"))
        cout<<"YES";
    else
        cout<<"NO";
    cout <<"numberOfNodesCreated -- >"<<numberOfNodesCreated<<endl;
    return 0;
}