#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100001;
double a[maxn]={};

int main(){
	int n;
	//freopen("G://PATdata//A1104.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	double sum=0; /////����long long ��������
	for(int i=1;i<=n;i++){
		sum+=a[i]*i*(n+1-i);
	}
	printf("%.2f\n",sum);

	return 0;
}