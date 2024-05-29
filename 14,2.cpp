#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int data;
	struct node*pLeft;
	struct node*pRight; 
} ;
void TaoCay (node*&t)
{
	t= NULL;
}
void ThemNode (node*&t, int x)
{
	if (t== NULL){
		node*p = new node;
		p-> data=x;
		p-> pLeft = NULL;
		p-> pRight = NULL;
		t=p;
	}
	else{

	if (t-> data<x)
	ThemNode(t-> pRight, x);
	else if(t-> data>x)
	ThemNode(t-> pLeft, x);
}
}
void duyetTruoc(node*t){
	if(t!= NULL)
	{
		cout<<t->data<<" ";
		duyetTruoc(t->pLeft);
		duyetTruoc(t->pRight);
	}
}
void duyetGiua(node*t){
	if(t!= NULL)
	{
		duyetGiua(t->pLeft);
		cout<<t->data<<" ";
		duyetGiua(t->pRight);
	}
}
void duyetSau(node*t){
	if(t!= NULL)
	{
		duyetSau(t->pLeft);
		duyetSau(t->pRight);
		cout<<t->data<<" ";
	}
}
int main()
{	 
    int i ,n;
 	node* t= NULL; 
	TaoCay (t);
    cout<<"nhap so phan tu: ";
    cin>>n;
    cout<<"nhap cac phan tu vao cay\n";
    int a[n]; 
    for( i=0; i<n; i++){
        cin>>a[i];
        ThemNode(t, a[i]);
    }
	cout<<"duyet theo thu tu truoc: " ;
    duyetTruoc(t);
    cout<<"\nduyet theo thu tu giua: " ;
    duyetGiua(t);
    cout<<"\nduyet theo thu tu sau: " ;
    duyetSau(t);
    return 0;
}
