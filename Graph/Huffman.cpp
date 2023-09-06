#include <bits/stdc++.h>
using namespace std;

int numc[30];
vector<char> coun;
vector<pair<char,string>> ans;

class Node {
public:
    char c;
    Node* par;
    Node* right;
    Node* left;
    int f;
    Node(char a, int fr) {
        c = a;
        f = fr;
        par = NULL;
        left = NULL;
        right = NULL;
    }

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};


struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->f > b->f;
    }
};

void inorder(Node *r, string s)
{
    if (r == NULL)
        return;
    
    if (r->c >= 'a' && r->c <= 'z')
    {
        ans.push_back({r->c, s});
        cout << r->c << " " << s << endl;
    }

    if (r->left)
        inorder(r->left, s + '0');

    if (r->right)
        inorder(r->right, s + '1');
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        numc[s[i] - 'a']++;
    }

    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    
    for (int i = 0; i < 30; i++) {
        if (numc[i] != 0) {
            Node *n = new Node('a'+i, numc[i]);
            pq.push(n);
        }
    }
    Node *root;
    if(pq.size()==1){
        root = new Node('/', INT_MAX);
        Node* a = pq.top();
        root->left = a;
    }

    else{
        Node* n = new Node('*',INT_MAX);
        pq.push(n);
        while(pq.size()>0){
            Node* r = pq.top();
            pq.pop();
            Node* l = pq.top();
            pq.pop();
            if(l->f == INT_MAX){
                root = r;
                break;
            }
            else{
                int numa = r->f+l->f;
                Node *p = new Node('/',numa);
                p->right = r;
                p->left = l;
                pq.push(p);
                r->par = p;
                l->par = p;
            }
        }
    }
    string co = "";
    inorder(root,co);
    return 0;
}
