#include<iostream>
using namespace std;
class tree
{
	  public:
    tree* left = nullptr;
    tree* right = nullptr;
    int data = -1;
    int height = 0;
};
void insert(tree* root, int value, int& height)
{
	while(root)
	{
		if(root->data < value)
		{
			if(root->right != nullptr)
			 root = root->right;
			else
			{
				root->right = new tree;
				root->right->data = value;
				root->right->height = root->height + 1;
				root = root->right;
				break;
			}
		}
		else if(root->data > value)
		{
			if(root->left != nullptr)
			 root = root->left;
			else
			{
				root->left = new tree;
				root->left->data = value;
				root->left->height += root->height;
				root = root->left;
				break;
			}
		}
	}
	height = root->height;
}
int main()
{
    int N = 0;
    cin>>N;
    int arr[N] = {0};
    for(int i = 0; i < N; i++)
        cin>>arr[i];
    //Height find
    tree* root = new tree;
    root->data = arr[0];
    root->height = 1;
    tree* temp = root;
    int height = 1;
    for(int i = 1; i < N; i++)
    	  insert(temp, arr[i], height);
    cout<<"Height = "<<height<<endl;
    return 0;
}
