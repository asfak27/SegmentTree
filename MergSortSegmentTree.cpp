///problem link-> https://www.spoj.com/problems/ADATREE/en/
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        300005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll arr[N];
vector<ll>tree[N*4];

void merge(vector<ll>&a, vector<ll>&b, vector<ll>&v)
{
    ll len1=a.size();
    ll len2=b.size();
    ll i=0,j=0;
    while(i<len1 && j<len2)
    {
        if(a[i]<b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else
        {
            v.push_back(b[j]);
            j++;
        }
    }
    while(i<len1)
    {
        v.push_back(a[i]);
        i++;
    }
    while(j<len2)
    {
        v.push_back(b[j]);
        j++;
    }
    /*for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
}
void build_tree(ll node,ll b,ll e)
{
    if(b==e)
    {
        vector<ll>v;
        v.push_back(arr[b]);
        tree[node]=v;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    build_tree(left,b,mid);
    build_tree(right,mid+1,e);

    merge(tree[left],tree[right],tree[node]);
    /*vector<ll>v=tree[node];
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
}

ll query(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if (b>=i && e<=j)
    {
        auto it=lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
        if(it==0 && tree[node][it]>val)
        {
            return 0;
        }
        if(tree[node][it]==val)
        {
            return val;
        }
        return tree[node][it-1];
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    ll x=query(left,b,mid,i,j,val);
    ll y=query(right,mid+1,e,i,j,val);
    return max(x,y);
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
    while(k--)
    {
        ll val;
        cin>>l>>r>>val;
        l++;
        r++;
        x=query(1,1,n,l,r,val);
        cout<<x<<endl;
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
