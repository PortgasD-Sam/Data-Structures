#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

class BIT//Fenwick Tree is also known as Binary Indexed Tree
{
   public:
    BIT(vi sequence)// Building The Fenwick Tree - Time Complexity - O(n)
    {
        modified_sequence = vi(sequence.size()+1,0);
        for(int i=0;i<sequence.size();i++)
        modified_sequence[i+1] = sequence[i];
        for(int i=1;i<modified_sequence.size();i++)
        {
            int idx = i + (i & -i);
            if(idx < modified_sequence.size())
            modified_sequence[idx]+=modified_sequence[i];
        }
    }
    int prefix_query(int idx)//Prefix Query - Time Complexity - O(log n)
    {
        int result{};
        for(++idx;idx>0;idx-=idx & -idx)
        result+=modified_sequence[idx];
        return result;
    }
    int range_query(int from_idx,int to_idx)//Range Query - Time Complexity - O(log n)
    {
        if(from_idx == 0)
        return prefix_query(to_idx);
        else
        return prefix_query(to_idx)-prefix_query(from_idx-1);
    }
    void update(int idx,int add)//Update - Time Complexity - O(log n)
    {
        for(++idx;idx<modified_sequence.size();idx+=idx & -idx)
        modified_sequence[idx]+=add;
    }
  private: 
    vi modified_sequence;
};

int main()
{
    vi sequence = {1,2,3,4,5,6,7,8,9,10};
    BIT fenwick_tree(sequence);
    printf("Prefix query upto position 7 : %d\n",fenwick_tree.prefix_query(6));
    printf("Range query from position 7 upto 10 : %d\n",fenwick_tree.range_query(6,9));
    printf("Update value at position 5 by 25\n");
    fenwick_tree.update(4,25);
    printf("Range query from position 5 upto 7 : %d\n",fenwick_tree.range_query(4,6));
    return 0;
}