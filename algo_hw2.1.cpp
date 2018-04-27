#include <iostream>
#include<vector>

using namespace std;

void maxHeapify(vector<long long> &a,int root,int sz){
    int l=root*2;
    int r=root*2+1;
    int largest;
    if(l<=sz&&a[l]>a[root])
        largest=l;
    else
        largest=root;
    if(r<=sz&&a[r]>a[largest])
        largest=r;
    if(largest!=root){
        long long int tmp=a[root];
        a[root]=a[largest];
        a[largest]=tmp;
        maxHeapify(a,largest,sz);
    }
}

void buildMaxHeap(vector<long long> &a){
    int sz=a.size();
    for(int i=(int)(sz)/2;i>=1;i--){
        maxHeapify(a,i,sz-1);
    }
}

void HeapSort(vector<long long> &a){
    buildMaxHeap(a);
    for(int i=1;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    int sz=a.size()-1;
    for(int i=(a.size()-1);i>=2;i--){
        long long int tmp=a[1];
        a[1]=a[i];
        a[i]=tmp;
        sz--;
        maxHeapify(a,1,sz);
    }
    for(int i=1;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> a(n+1);
    a[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    HeapSort(a);
}
