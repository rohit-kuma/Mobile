#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void kthLargest(Node *root, int k);
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		Node *root = NULL;
		int n;
		cin>>n;
		int a;
		cin>>a;
		root = insert(root, a);
		for(int i=0;i<n-1;i++)
		{
			cin>>a;
			insert(root,a);
		}
		int k;
		cin>>k;
		kthLargest(root, k);
	}
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */
/*Complete the function below*/
#include<set>
void inordered(Node *root, set<int> &v)
{
    if(NULL == root)
    return;
    inordered(root->left, v);
    v.insert(root->key);
    inordered(root->right, v);
}
void kthLargest(Node *root, int k)
{
    //Your code here
    if(NULL == root)
    return;
    set<int> v;
    inordered(root, v);
    //cout<<"size = "<<v.size()<<endl;
    int size = v.size();
    for(set<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++ )
    {
        k--;
        if( 0 == k)
        cout<<*it<<endl;
    }
}
