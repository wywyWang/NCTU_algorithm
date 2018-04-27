#include <iostream>
#include<vector>

using namespace std;

int cnt1,cnt2;

int partion(long long int a[],int p,int r){
    int j;
    int x=a[r];
    int i=p-1;
    for(j=p;j<r;j++){
        cnt1++;
        if(a[j]<=x){
            i++;
            if(i!=j){
                long long int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    long long int fnl=a[i+1];
    a[i+1]=a[j];
    a[j]=fnl;

    return i+1;
}

void quicksort(long long int a[],int p,int r){
    int q;
    if(p<r){
        q=partion(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cnt1=0;
        cnt2=(n*(n-1))/2;
        quicksort(a,0,n-1);

        if(cnt1==cnt2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        //cout<<"CNT1="<<cnt1<<" cnt2="<<cnt2<<endl;
    }
}
