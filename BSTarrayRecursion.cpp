#include<iostream>
using namespace std;
void disp(int* arr)
{
	for(auto i = 0; i < 10; i++)
   cout<<arr[i]<<" ";
  cout<<endl;
}
class tree
{
	public:
	tree* left = NULL;
	tree* right = NULL;
	int data = -1;
	tree(int val)
	{
		left = NULL;
		right = NULL;
		data = val;
	}
};
tree* insert(tree* root, int val)
{
	if(NULL == root)
	 return new tree(val);
	if(root->data > val )
	 root->left = insert(root->left, val);
	else if(root->data < val )
	 root->right = insert(root->right, val);
	return root;
}
void displayInordered(tree* root)
{
	if(NULL == root)
	 return;
	displayInordered(root->left);
	cout<<root->data<<" ";
	displayInordered(root->right); 
}
tree* search(tree* root, int val)
{
	if(root == NULL || root->data == val)
	 return root;
	if(root->data > val)
	 search(root->left, val);
	else if(root->data < val)
	 search(root->right, val);
}
void insertToBST(int* arr)
{
	tree* root = NULL;
	for(int i = 0; i < 10; i++)
	 root = insert(root, arr[i]);
	cout<<"Tree Traversal"<<endl;
	displayInordered(root);
	cout<<endl;
	
	
	cout<<"Searched Item"<<endl;
	int chk = 99;
	tree* temp = search(root, chk);
	if(NULL != temp)
	 cout<<temp->data<<endl;
	else
	 cout<<chk<<" Not Found"<<endl;
}
int main()
{
	int arr[10] = {5,4,6,3,7,2,8,1,9,0};
  cout<<"Array elements"<<endl;
  disp(arr);
  insertToBST(arr);
  return 0;
}
