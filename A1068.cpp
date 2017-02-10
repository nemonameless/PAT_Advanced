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
const int maxn=10010;
const int maxv=110;
int w[maxn],dp[maxn]={};
bool chose[maxn][maxv];   //��¼����dp[i][v]ʱѡ�����ĸ�����
//Ϊ1ʱ��dp[i][v]=dp[i-1][v-w[i]]+c[i]
//Ϊ0ʱ��dp[i][v]=dp[i-1][v]
bool f[maxn];  //////////��¼����ֵ�����и���Ʒ��ѡȡ���
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int main(){
	//freopen("G:\\PATdata\\A1068.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v] = dp[v-w[i]]+w[i];//////�����i����Ʒ
				chose[i][v]=1;
			}else
				chose[i][v]=0;			///���ŵ�i����Ʒ
		}
	}
	if(dp[m]!=m)    //�޽⣬���ܸ����ֵΪm�Ļ���
		printf("No Solution");
	else{
		int k=n,num=0,v=m;
		while(k>=0){
			if(chose[k][v]==1){/////////////////��¼����·��
				f[k]=true;
				v-=w[k];
				num++;
			}else if(chose[k][v]==0){
				f[k]=false;
			}
			k--;
		}
		for(int i=n;i>=1;i--){
			if(f[i]==true){
				printf("%d",w[i]);
				num--;
				if(num)
					printf(" ");
			}
		}
	}
	return 0;
}