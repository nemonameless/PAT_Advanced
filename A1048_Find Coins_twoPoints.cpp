#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+1;
int has[maxn]={};
int a[maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<maxn;i++){
		has[i]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n && a[i]<m;i++){
		has[a[i]]++;
	}
	int flag=0;
	for(int i=0;i<n && a[i]<m;i++){
		if(has[a[i]]>0 && has[m-a[i]]>0 && !(a[i]==m-a[i] && has[a[i]]<=1 )){ 
			////////��ֹ14 ����һ��7�����ǲ�����ģ�ҲҪ��ֹ����7��������
			flag=1;
			printf("%d %d",a[i],m-a[i]);
			break;
		}
	}
	if(flag==0)
		printf("No Solution");


	return 0;
}