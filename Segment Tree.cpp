/*The following implentation of segment tree is iterative
*This implentation of segment tree calculates the minimum value over ranges in a sequence of integers
*/
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
class statistic_tree//Segment Tree is also known as Statistic Tree
{
    public:
        statistic_tree(vi sequence)//Building the Segment Tree - Time Complexity - O(n)
        {
            n = sequence.size();
            tree =vi(2*n,0);
            copy(sequence.begin(),sequence.end(),&tree[0] + n);
            for(int i=n-1;i>0;i--)
            tree[i]=min(tree[i<<1],tree[i<<1|1]);
        }
        void modify(int idx,int value)//Update - Time Complexity - O(log n)[point range modification]
        {
            idx+=n;
            for(tree[idx]=value;idx > 1;idx>>=1)
            tree[idx>>1]=min(tree[idx],tree[idx^1]);
        }
        int query(int l,int r)//Query - Time Complexity - O(log n)
        {
            int result = numeric_limits<int>::max();
            for(l+=n,r+=n;l < r;l>>=1,r>>=1)
            {
                if(l&1) result = min(result,tree[l++]);
                if(r&1) result = min(result,tree[--r]);
            }
            return result;
        }
    private:
        int n;
        vi tree;
};
int main()
{
    vi sequence = {6,4,17,8,15,10,16,2,13,3};
    statistic_tree segment_tree(sequence);
    printf("Minimum value :[0,10) = %d\n",segment_tree.query(0,10));
    printf("Modifying value at index 9 with 1\n");
    segment_tree.modify(7,1);
    printf("Minimum value :[0,10) = %d\n",segment_tree.query(0,10));
    printf("Minimum value :[2,6) = %d\n",segment_tree.query(2,6));
    return 0;
}