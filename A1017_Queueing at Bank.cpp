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
const int maxn=111,inf=1e9;
struct Customer{
	int cometime,servetime;
}newCustomer;
vector<Customer> custom;
int changeTime(int h,int m,int s){
	return h*3600+m*60+s;
}
bool cmp(Customer a,Customer b){
	return a.cometime<b.cometime;
}
int endTime[111];
int main(){
	int c,w,totTime=0;
	//freopen("G:\\PATdata\\A1017.txt","r",stdin);
	cin>>c>>w;
	int stTime=changeTime(8,0,0);
	int edTime=changeTime(17,0,0);
	for(int i=0;i<w;i++)
		endTime[i]=stTime;///////////i�Ŵ��ڵĵ�ǰ�������ʱ�� ��ʼ��ΪstTime
	for(int i=0;i<c;i++){
		int h,m,s,serverTime;
		scanf("%d:%d:%d %d",&h,&m,&s,&serverTime);
		int comeTime=changeTime(h,m,s);
		if(comeTime>edTime)  /////////����17��00:00�����Ĳ���
			continue;
		newCustomer.cometime=comeTime;
		newCustomer.servetime= serverTime<=60?serverTime*60:3600;////////////
		custom.push_back(newCustomer);
	}
	sort(custom.begin(),custom.end(),cmp);//////////������ʱ���Ⱥ�
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=inf;
		for(int j=0;j<w;j++){       //////////һ��������ѭ��
			if(endTime[j]<minEndTime){//////////ѡ��ǰ�����������Ĵ��ڣ����Ϊidx
				minEndTime=endTime[j];
				idx=j;
			}
		}
		if(endTime[idx]<=custom[i].cometime) ///////custom[i]�ڴ��ڿ���֮���������ֱ�ӽ��ܷ���
			endTime[idx]=custom[i].cometime+custom[i].servetime;
		else{
			totTime+=(endTime[idx]-custom[i].cometime);///////custom[i]����̫�磬��ȴ�
			endTime[idx]+=custom[i].servetime;
		}
	}
	if(custom.size()==0)
		printf("0.0");
	else
		printf("%.1f",totTime*1.0/60/custom.size());

	return 0;
}