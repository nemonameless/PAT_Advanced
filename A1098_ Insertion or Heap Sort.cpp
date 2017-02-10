#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int maxn=110;
int origin[maxn],tmpOri[maxn],changed[maxn];
int n;
void show(int a[]){
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)
			cout<<" ";
		else
			cout<<endl;
	}
}
bool issame(int a[],int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])
			return false;
	}
	return true;
}
bool insertSort() {
    bool flag = false;
    for(int i = 2; i <= n; i++) {
        if(i > 2 && issame(tmpOri, changed)) {
            flag = true;
        }
		sort(tmpOri,tmpOri+1+i);
        if(flag == true) {
            return true;
        }
    }
    return false;
}
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){      //////////////////���ں���<=
		if(j+1<=high && tmpOri[j+1]>tmpOri[j]){/////////�����Һ��ӣ����Һ��ӱ����Ӵ�,<=,>
			j=j+1;       /////��j�洢�Һ����±�
		}
		if(tmpOri[j]>tmpOri[i]){
			swap(tmpOri[j],tmpOri[i]);   ////////����� �� ���׽���
			i=j;     
			j=2*i;/////������һ��
		}else{
			break;
		}
	}
}
void heapSort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--){ ////////////�� n/2��ǰ
		downAdjust(i,n);///////////����
	}
	for(int i=n;i>1;i--){
		if(i!=n && issame(tmpOri,changed))////////////////////�Ǻ�changed�Աȣ�����origin
			flag=true;
		swap(tmpOri[i],tmpOri[1]);/////////////�����Ѷ�
		downAdjust(1,i-1);//////�����Ѷ�
		if(flag == true){
			show(tmpOri);
			return;
		}
	}
}
int main(){
//	freopen("G:\\PATdata\\A1098.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>origin[i];
		tmpOri[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		cin>>changed[i];
	}
	if(insertSort()){////////////insertSort���������ţ�����ʼ�����Insertion Sort
		cout<<"Insertion Sort"<<endl;
		show(tmpOri);
	}else{
		cout<<"Heap Sort"<<endl;
		for(int i=1;i<=n;i++){
			tmpOri[i]=origin[i];
		}
		heapSort();
	}
	return 0;
}