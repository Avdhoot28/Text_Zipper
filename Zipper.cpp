#include<bits/stdc++.h>
using namespace std;
map<char, int> Counter;

int FileSize = 0;

class Node
{
private:
    /* data */
public:
    char value;
    string key;
    Node* left;
    Node* right;
    Node(char);
    ~Node();
};

Node::Node(char ivalue)
{
    value = ivalue;
    key = "0";
    left = NULL;
    right = NULL;
}

Node::~Node()
{
}

class BinaryTree
{
private:
    Node* root;
public:
    BinaryTree();
    void insert(char);
    void displayTree(Node*, char);
    Node* giveRoot();
    string giveKey(Node*, char);
    ~BinaryTree();
};

BinaryTree::BinaryTree()
{
    root = new Node('$');
}

void BinaryTree::insert(char ivalue)
{
    Node* temp = new Node(ivalue);
    Node* temp1 = new Node('$');    
    Node* q;
    string y = "1";
	q = root;
    if(q->left == NULL){
        q->left = temp;
    }
    else{
        while (q->right!=NULL)
        {
            y.append("1");
            q = q->right;
        }
        q->right = temp1;
        q = q->right;
        q->left = temp;
        y.append("0");
        q->left->key = y;
    }
    
}

void BinaryTree::displayTree(Node* q, char m)
{
    if(q==NULL){
        return ;
    }
    displayTree(q->left, m);
    if(q->value == m){
        cout <<q->key ;
        FileSize+= q->key.length();
    }
    displayTree(q->right, m);
}

Node* BinaryTree::giveRoot(){
    return this->root;
}

string BinaryTree::giveKey(Node* q, char m)
{
    if(q == NULL){
        cout << "Came here" ;
        return NULL;
    }
    // if(q->value == m){
    //     cout << q->value << endl;
    //     return q->key;
    // }
    giveKey(q->left, m);
    giveKey(q->right,m);
}

BinaryTree::~BinaryTree()
{
}


bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}
  
// Function to sort the map according
// to value in a (key-value) pairs
vector<pair<char, int> > sort(map<char, int>& M)
{
  
    // Declare vector of pairs
    vector<pair<char, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    // Print the sorted value
    return A;
}



int main(){
    BinaryTree Hoffman;
    // char z = 'a';
    // A.insert(z);
    // A.insert('c');
    // A.insert('b');
    // A.insert('d');
    // A.insert(' ');
    // A.displayTree(A.giveRoot());


    string filename("demofile.txt");
    ifstream input_file(filename);
    char byte = '0';
    while (input_file.get(byte)) {
        auto itr = Counter.find(byte);
        if (itr != Counter.end())
            itr->second++;
        else
            Counter.insert(pair<char, int>(byte, 1));
    }

    vector<pair<char, int> > A = sort(Counter);
    for (auto& it : A) {
        Hoffman.insert(it.first);
    }

    // for (auto itr = Counter.begin(); itr != Counter.end(); ++itr) {
    //     cout << '\t' << itr->first
    //          << '\t' << itr->second << '\n';
    // }
    // cout << endl;

    

    string filename1("demofile.txt");
    ifstream input_file1(filename1);
    char byte1 = '0';
    string finalAnswer = "";
    while (input_file1.get(byte1)) {
        // finalAnswer.append(Hoffman.giveKey(Hoffman.giveRoot(), byte1));
        Hoffman.displayTree(Hoffman.giveRoot(), byte1);
    }
    // cout << finalAnswer << endl;
    cout << endl;
    cout << FileSize;


    return 0;
}