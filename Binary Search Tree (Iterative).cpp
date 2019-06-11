#include<bits/stdc++.h>
using namespace std;

class BST
{
	public:
		int value;
		BST* left;
		BST* right;
		
		BST(int val)
		{
			value = val;
			left = NULL;
			right = NULL;
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(1) | Worst - O(1)
		BST& insert(int val)
		{
			BST* currentNode = this;
			while(true)
			{
				if(val<currentNode->value)
				{
					if(currentNode->left==NULL)
					{
						BST* newNode = new BST(val);
						currentNode->left = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if(currentNode->right==NULL)
					{
						BST* newNode = new BST(val);
						currentNode->right = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}
			return *this;
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(1) | Worst - O(1)
		bool search(int val)
		{
			BST* currentNode = this;
			while(currentNode!=NULL)
			{
				if(val<currentNode->value) currentNode = currentNode->left;
				else if(val>currentNode->value) currentNode = currentNode->right;
				else return 1;
			}
			return 0;
		}
		
		int getMinValue()
		{
			BST* currentNode = this;
			while(currentNode->left!=NULL) currentNode = currentNode->left;
			return currentNode->value;
		}

		//Time Complexity - Average - O(log(n)) | Worst - O(n)
		//Space Complexity - Average - O(1) | Worst - O(1)
		BST& remove(int val,BST *parentNode = NULL)
		{
			BST* currentNode = this;
			while(currentNode!=NULL)
			{
				if(val<currentNode->value)
				{
					parentNode = currentNode;
					currentNode = currentNode->left;
				}
				else if(val>currentNode->value)
				{
					parentNode = currentNode;
					currentNode = currentNode->right;
				}
				else
				{
					if(currentNode->left!=NULL && currentNode->right!=NULL)
					{
						currentNode->value = currentNode->right->getMinValue();
						currentNode->right->remove(currentNode->value,currentNode);
					}
					else if(parentNode==NULL)
					{
						if(currentNode->left!=NULL)
						{
							currentNode->value = currentNode->left->value;
							currentNode->right = currentNode->left->right;
							currentNode->left = currentNode->left->left;
						}
						else if(currentNode->right!=NULL)
						{
							currentNode->value = currentNode->right->value;
							currentNode->left = currentNode->right->left;
							currentNode->right = currentNode->right->right;
						}
						else
						{
							currentNode->value = 0;
						}
					}
					else if(parentNode->left==currentNode)
					{
						parentNode->left = (currentNode->left!=NULL) ? currentNode->left : currentNode->right;
						parentNode->right = (currentNode->left!=NULL) ? currentNode->left : currentNode->right;
					}
					break;
				}
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