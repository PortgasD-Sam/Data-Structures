#include <bits/stdc++.h>
using namespace std;

class BST
{
	public:
		int value;
		BST *left;
		BST* right;
		
		BST(int val)
		{
			value = val;
			left = NULL;
			right = NULL;
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(n) | Worst - O(n)
		BST& insert(int val)
		{
			if(val<value)
			{
				if(left==NULL)
				{
					BST* newBST = new BST(val);
					left = newBST;
				}
				else left->insert(val);
			}
			else
			{
				if(right==NULL)
				{
					BST *newBST = new BST(val);
					right = newBST;
				}
				else right->insert(val);
			}
			return *this;
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(n) | Worst - O(n)
		bool search(int val)
		{
			if(val<value)
			{
				if(left==NULL) return false;
				else return left->search(val);
			}
			else if(val>value)
			{
				if(right==NULL) return false;
				else return right->search(val);
			}
			else
			{
				return true;
			}
		}
		
		int getMinValue()
		{
			if(left==NULL) return value;
			else return left->getMinValue();
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(n) | Worst - O(n)
		BST& remove(int val,BST* parent = NULL)
		{
			if(val<value)
			{
				if(left!=NULL)
				{
					left->remove(val,this);
				}
			}
			else if(val>value)
			{
				if(right!=NULL)
				{
					right->remove(val,this);
				}
			}
			else if(left!=NULL && right!=NULL)
			{
				value = right->getMinValue();
				right->remove(value,this);
			}
			else if(parent==NULL)
			{
				if(left!=NULL)
				{
					value = left->value;
					right = left->right;
					left = left->left;
				}
				else if(right!=NULL)
				{
					value = right->value;
					left = right->left;
					right = right->right;
				}
				else
				{
					value = 0;
				}
			}
			else if(parent->left==this)
			{
				parent->left = (left!=NULL) ? left : right;
			}
			else if(parent->right==this)
			{
				parent->right = (left!=NULL) ? left : right;
			}
			return *this;
		}
};

int main()
{
	BST* tr = new BST(10);
	tr->insert(5);
	tr->insert(15);
	tr->insert(2);
	tr->insert(5);
	tr->insert(13);
	tr->insert(22);
	tr->insert(1);
	tr->insert(12);
	tr->insert(14);
	(tr->search(12)) ? printf("true\n") : printf("false\n");
	(tr->search(11)) ? printf("true\n") : printf("false\n");
	tr->remove(12);
	(tr->search(12)) ? printf("true\n") : printf("false\n");
	(tr->search(10)) ? printf("true\n") : printf("false\n");
	tr->remove(10);
	(tr->search(10)) ? printf("true\n") : printf("false\n");
	return 0;
}