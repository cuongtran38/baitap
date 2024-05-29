#include<bits/stdc++.h>
using namespace std;
void DuyetTruoc(int a[], int i, int n){
	if( i>=n) return;
	cout<<a[i]<<" ";
	DuyetTruoc(a,2*i+1, n );
	DuyetTruoc(a,2*i+2, n);
} 
void DuyetGiua(int a[], int i, int n){
	if( i>=n) return;
	DuyetGiua(a,2*i+1, n );
	cout<<a[i]<<" ";
	DuyetGiua(a,2*i+2, n);
}
void DuyetSau(int a[], int i, int n){
	if( i>=n) return;
	DuyetSau(a,2*i+1, n );
	DuyetSau(a,2*i+2, n);
	cout<<a[i]<<" ";
}
void heapify(int a[], int i, int n){
	int left=2*i+1;
	int right=2*i+2;
	int largest= i;
	if(left<n && a[left]>a[largest]){
		largest= left;
	}
	if(right<n && a[right]>a[largest]){
		largest= right;
	}
	if(largest!= i){
		swap(a[i], a[largest]);
		heapify(a, largest, n);
	}
}
void heapsort(int a[], int n){
	int i,x=1;
	for(int i= n/2-1; i>=0; i--){
		heapify(a, i , n);
	}
		cout<<"cay da vun dong theo thu tu duyet truoc: ";
		DuyetTruoc(a, 0, n);
		cout<<endl;

	for(int i=n-1; i>=0; i--){
		swap(a[i], a[0]);
		heapify(a, i, 0);
		cout<<"gia tri phan tu theo buoc "<<x<<" sap xep cay da vun dong theo thu tu truoc:\n";
		DuyetTruoc(a, 0, n);
		cout<<"\n"; 
		x++;
	}
}
int main(){
	int i, n, x=1;

	cout<<"nhap so phan tu: ";
	cin>>n;
	int a[n]; 
	cout<<"nhap cac phan tu vao cay:\n";
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	heapsort(a, n);
	cout<<"cay da vun dong theo thu tu duyet truoc: ";
	DuyetTruoc(a, 0, n);
	cout<<"\ncay da vun dong theo thu tu duyet giua: ";
	DuyetGiua(a, 0, n);
	cout<<"\ncay da vun dong theo thu tu duyet sau: ";
	DuyetSau(a, 0, n);
	return 0;
}
