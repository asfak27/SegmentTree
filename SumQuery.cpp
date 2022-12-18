///Segment Tree allows answering range queries over an array effectively
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        1000005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll arr[N];
ll tree[N*4];///tree array
///initilization tree array
void build_tree(ll node,ll b,ll e)///b=begin node,e=end node
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    ll leftnode = node*2;///indexing child left and right node
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    build_tree(leftnode,b,mid);///break the array into two part
    build_tree(rightnode,mid+1,e);
    tree[node]=tree[leftnode]+tree[rightnode];///store the value in parent node
}
ll query(ll node,ll b,ll e,ll i,ll j)///i and j=expected range in query
{
    if(i>e || j<b) ///if the given range in not able in the range
    {
        return 0;
    }
    if (b>=i && e<=j)///if the given range in not able in the range
    {
        return tree[node];
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    ll x=query(leftnode,b,mid,i,j);
    ll y=query(rightnode,mid+1,e,i,j);
    return x+y;///sum of both side
}

void update(ll node,ll b,ll e,ll i,ll newvalue)///change the value of ith index
{
    if(i>e || i<b) ///if the given range in not able in the range
    {
        return;
    }
    if (b>=i && e<=i)///find element->leap node
    {
        tree[node]=newvalue;///update the value
        return;
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    update(leftnode,b,mid,i,newvalue);
    update(rightnode,mid+1,e,i,newvalue);
    tree[node]=tree[leftnode]+tree[rightnode];///store the value in parent node after the updating new value
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    build_tree(1,1,n);
    for(i=0; i<k; i++)
    {
        cin>>r>>x>>y;
        if(r==1)
        {
            update(1,1,n,x,y);
        }
        else
        {
            ll ans=query(1,1,n,x,y);
            cout<<ans<<endl;
        }

    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
/*
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        100005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
struct Segment_Tree
{
    ll tree[N*4];
    void build_tree(ll node,ll b,ll e)
    {
        if(b==e)
        {
            tree[node]=0;
            return;
        }
        ll leftnode = node*2;
        ll rightnode = node*2+1;
        ll mid = (b+e)/2;
        build_tree(leftnode,b,mid);
        build_tree(rightnode,mid+1,e);
        tree[node]=tree[leftnode]+tree[rightnode];
    }
    ll query(ll node,ll b,ll e,ll i,ll j)
    {
        if(i>e || j<b)
        {
            return 0;
        }
        if (b>=i && e<=j)
        {
            return tree[node];
        }
        ll leftnode = node*2;
        ll rightnode = node*2+1;
        ll mid = (b+e)/2;
        ll x=query(leftnode,b,mid,i,j);
        ll y=query(rightnode,mid+1,e,i,j);
        return x+y;
    }
    void update(ll node,ll b,ll e,ll l,ll r,ll newvalue)
    {
        if(b>r || e<l)
        {
            return;
        }
        if(b>=l && e<=r)
        {
            tree[node]+=newvalue;
            return;
        }
        ll leftnode = node*2;
        ll rightnode = node*2+1;
        ll mid = (b+e)/2;
        update(leftnode,b,mid,l,r,newvalue);
        update(rightnode,mid+1,e,l,r,newvalue);
        tree[node]=tree[leftnode]+tree[rightnode];
    }
};
Segment_Tree a[3];
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>row;
    map<ll,ll>col;
    ll n,i,j,k;
    cin>>n>>k;
    a[0].build_tree(1,1,n);
    a[1].build_tree(1,1,n);

    while(k--)
    {
        ll x;
        cin>>x;

        if(x==1)
        {
            ll p,q;
            cin>>p>>q;
            row[p]++;
            col[q]++;
            if(row[p]==1)a[0].update(1,1,n,p,p,1);
            if(col[q]==1)a[1].update(1,1,n,q,q,1);
        }
        else if(x==2)
        {
            ll p,q;
            cin>>p>>q;
            row[p]--;
            col[q]--;
            if(row[p]==0)a[0].update(1,1,n,p,p,-1);
            if(col[q]==0)a[1].update(1,1,n,q,q,-1);
        }
        else
        {
            ll p1,q1,p2,q2;
            cin>>p1>>q1>>p2>>q2;

            bool f=false;
            bool ff=false;

            ll ans=a[0].query(1,1,n,p1,p2);
            if(ans==(p2-p1)+1)f=true;

            ans=a[1].query(1,1,n,q1,q2);
            if(ans==(q2-q1)+1)f=true;

            if(f || ff)yes;
            else no;
        }
    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

*/
