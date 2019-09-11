#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);} 
       merge(root1,root2);
        cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
#include<set>
void inordered(Node* root, multiset<int> &s)
{
	if(NULL == root)
	return;
	inordered(root->left, s);
	s.insert(root->data);
	inordered(root->right, s);
}
void merge(Node *root1, Node *root2)
{
   //Your code here
   multiset<int> s;
   if(root1 == NULL && root2 == NULL)
   return;
   if(NULL != root1)
   inordered(root1, s);
   if(NULL != root2)
   inordered(root2, s);
   for(multiset<int>::iterator it = s.begin(); it != s.end(); it++ )
   {
   	cout<<*it<<" ";
   }
   cout<<endl;	
}
