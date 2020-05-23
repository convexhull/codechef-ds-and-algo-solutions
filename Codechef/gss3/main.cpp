#include<bits/stdc++.h>
using namespace std;
vector<long long>v(50010);
struct segnode
{
    long long bls;
    long long brs;
    long long bsum;
    long long sum;
    void assign(long long t)
    {
        bls=t;
        brs=t;
        bsum=t;
        sum=t;
    }
    void merge(segnode &left, segnode &right)
    {
        bls=max(left.bls,left.sum+right.bls);
        brs=max(right.brs,right.sum+left.brs);
        bsum=max(max(left.bsum,right.bsum),left.brs+right.bls);
        sum=left.sum+right.sum;
    }
};
vector<segnode>tree(1000010);
void build(long long idx,long long lo,long long hi)
{
    if(lo==hi)
    {
        tree[idx].assign(v[lo]);
        return;
    }
    long long mid=(lo+hi)/2;
    build(2*idx,lo,mid);
    build(2*idx+1,mid+1,hi);
    tree[idx].merge(tree[2*idx],tree[2*idx+1]);
}
void update(long long idx,long long lo, long long hi,long long index,long long val)
{
    if(lo==hi)
    {
        tree[idx].assign(val);
        return;
    }
    long long mid=(lo+hi)/2;
    if(index<=mid)
        update(2*idx,lo,mid,idx,val);
    else
        update(2*idx+1,mid+1,hi,idx,val);
    tree[idx].merge(tree[2*idx],tree[2*idx+1]);
}
segnode query(long long idx,long long lo,long long hi,long long l,long long r)
{
    if(l==lo && r==hi)
        return tree[idx];
    long long mid=(lo+hi)/2;
    if(l>mid)
        return query(2*idx+1,mid+1,hi,l,r);
    if(r<=mid)
        return query(2*idx,lo,mid,l,r);
    segnode left,right,result;
    left=query(2*idx,lo,mid,l,mid);
    right=query(2*idx+1,mid+1,hi,mid+1,r);
    result.merge(left,right);
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>v[i];
    build(1,1,n);
    long long m;
    cin>>m;
    for(long long i=1;i<=m;i++)
    {
        long long a,x,y;
        cin>>a>>x>>y;
        if(a==1)
            cout<<query(1,1,n,x,y).bsum<<'\n';
        else
            update(1,1,n,x,y);
    }
    return 0;
}
