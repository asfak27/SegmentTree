///Segment Tree allows answering range queries over an array effectively
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000000007
#define N        1000005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll arr[N];
ll tree[N*4];///tree array
///initilization tree array
void init(ll node,ll b,ll e)///b=begin node,e=end node
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    ll leftnode = node*2;///indexing child left and right node
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    init(leftnode,b,mid);///break the array into two part
    init(rightnode,mid+1,e);
    tree[node]=min(tree[leftnode],tree[rightnode]);///store the value in parent node
}
ll query(ll node,ll b,ll e,ll i,ll j)///i and j=expected range in query
{
    if(i>e || j<b) ///if the given range in not able in the range
    {
        return mod;
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
    return min(x,y);///minimum of both side
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
    tree[node]=min(tree[leftnode],tree[rightnode]);///store the value in parent node after the updating new value
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
    init(1,1,n);
    for(i=0; i<k; i++)
    {
        cin>>x>>l>>r;
        if(x==1)
        {
            update(1,1,n,l,r);///updating value l=ith insex r=newvalue
            continue;
        }
        ll mn=query(1,1,n,l,r);
        cout<<mn<<endl;
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

