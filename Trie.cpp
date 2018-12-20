/*This is a simple implementation of Trie
*The two operations performed in this implemntation are - insert and search
*/
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vs = vector<string>;

struct Vertex
{
    vi next = vi (26,0);
    bool endOfWord = false;
};

class radix_tree//Trie is also known as prefix tree, radix tree and digital tree
{
    public:
        radix_tree(): t(1){}
        void insert(string const &s)//Insert - Time Complexity - O(L) [L is the length of the string key]
        {
            int v{};
            for(char ch:s)
            {
                int idx = ch - 'a';
                if(!t[v].next[idx])
                {
                    t[v].next[idx] = t.size();
                    t.emplace_back();
                }
                v = t[v].next[idx];
            }
            t[v].endOfWord = true;
        }
        bool search(string const &key)//Search - Time Complexity - O(L) [L is the length of the string key]
        {
            int v{};
            for(int i=0;i<key.length();i++)
            {
                int idx = key[i] - 'a';
                if(!t[v].next[idx])
                return false;
                v = t[v].next[idx];
            }
            return t[v].endOfWord;
        }
    private:
        vector<Vertex> t;
};

int main()
{
    vs keys = {"the","a","there","accessor","any","by","bye","their"};
    radix_tree trie;
    for(int i=0;i<keys.size();i++)
    trie.insert(keys[i]);
    trie.search("the")?cout<<"Yes\n":cout<<"No\n";
    trie.search("accessed")?cout<<"Yes\n":cout<<"No\n";
    return 0;
}