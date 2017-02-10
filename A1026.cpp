#include <cstdio>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=111,inf=1e9;
int round(double f){
	if((int)f+0.5>f)
		return (int)f;
	else
		return (int)f+1;
}
struct Player{
	int arriveTime,startTime,trainTime;
	bool isvip;
}newplayer;
struct Table{
	int endtime,numserver;
	bool isvip;
}table[maxn];
vector<Player> player;
int changetime(int h,int m,int s){
	return h*3600+m*60+s;
}
bool cmpArriveTime(Player a,Player b){
	return a.arriveTime<b.arriveTime;
}
bool cmpStartTime(Player a,Player b){
	return a.startTime<b.startTime;
}
int nextvipplayer(int vipi){
	vipi++;
	while(vipi<player.size() && player[vipi].isvip==0)
		vipi++;
	return vipi;
}
void allotTable(int pid,int tid){
	if(player[pid].arriveTime<=table[tid].endtime){
		player[pid].startTime = table[tid].endtime;
	}else{
		player[pid].startTime = player[pid].arriveTime;
	}
	table[tid].endtime=player[pid].startTime+player[pid].trainTime;
	table[tid].numserver++;
}
int main(){
	int n,k,m,viptable;
	//freopen("G:\\PATdata\\A1026.txt","r",stdin);
	scanf("%d",&n);
	int sttime=changetime(8,0,0);
	int edtime=changetime(21,0,0);
	for(int i=0;i<n;i++){
		int h,m,s,traintime,isvip;			/////////////////////////////
		scanf("%d:%d:%d %d %d",&h,&m,&s,&traintime,&isvip);
		newplayer.arriveTime=changetime(h,m,s);
		newplayer.startTime=edtime;			///////////////////////
		if(newplayer.arriveTime >= edtime)
			continue;
		newplayer.trainTime=traintime<=120 ? traintime*60 :7200;/////////
		newplayer.isvip=isvip;
		player.push_back(newplayer);
	}
	scanf("%d%d",&k,&m);
	for(int i=1;i<=k;i++){
		table[i].endtime=sttime;		//////��ʼ��k������
		table[i].numserver=0;
		table[i].isvip=0;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&viptable);
		table[viptable].isvip=1;		////////////
	}
	sort(player.begin(),player.end(),cmpArriveTime);
	int i=0,vipi=-1;
	vipi=nextvipplayer(vipi);			///////////Ѱ��
	while(i<player.size()){
		int idx=-1,minendtime=inf;		///////////idxΪ������е��������
		for(int j=1;j<=k;j++){
			if(table[j].endtime < minendtime){
				minendtime=table[j].endtime;
				idx=j;

			}
		}
		if(table[idx].endtime>=edtime)		//����
			break;
		if(player[i].isvip==1 && i<vipi){	//���i����VIP��Ա����vipi>i��˵��i����Ա�Ѿ���ѵ��
			i++;
			continue;
		}

		if(table[idx].isvip==1 && player[i].isvip==1){
			allotTable(i,idx);//////////////////////������idx�����i����Ա
			if(vipi==i)
				vipi=nextvipplayer(vipi);
			i++;						//i����Աѵ��������ɨ���������һ��
		}else if(table[idx].isvip==1 && player[i].isvip==0){
			if(vipi<player.size() && player[vipi].arriveTime<=table[idx].endtime){
									//�����ǰ���׵�vip��Ա��vip�����絽
				allotTable(vipi,idx);			//�Ͱ�����vipi�������
				vipi=nextvipplayer(vipi);
			}else{
				allotTable(i,idx);	//�����ǰ���׵�vip��Ա��vip����������Ȼ������idx�������
				i++;
			}	
		}else if(table[idx].isvip==0 && player[i].isvip==0){
			allotTable(i,idx);	//������idx�����i
				i++;
		}else if(table[idx].isvip==0 && player[i].isvip==1){
			int vipidx=-1,minvipendtime=inf;//////vipidxΪ������е�vip�������
			for(int j=1;j<=k;j++){
				if(table[j].isvip==1 && table[j].endtime<minvipendtime){
					minvipendtime=table[j].endtime;
					vipidx=j;
				}
			}
			if(vipidx!=-1 && player[i].arriveTime>=table[vipidx].endtime){
									//���vip���ڣ��ҿ���ʱ�����Ա������
				allotTable(i,vipidx);
				if(vipi==i)
					vipi=nextvipplayer(vipi);
				i++;
			}else{					//��Աi��ʱ��vip������δ���У��Ͱ�����idx�������
				allotTable(i,idx);
				if(vipi==i)
					vipi=nextvipplayer(vipi);
				i++;
			}
		}
	}
	sort(player.begin(),player.end(),cmpStartTime);
	for(int i=0;i<player.size() && player[i].startTime<edtime;i++){
		int t1=player[i].arriveTime;
		int t2=player[i].startTime;
		printf("%02d:%02d:%02d ",t1/3600,t1%3600/60,t1%60);
		printf("%02d:%02d:%02d ",t2/3600,t2%3600/60,t2%60);
		 printf("%.0f\n", round((t2 - t1)*1.0 / 60.0));
	}
	for(int i=1;i<=k;i++){
		printf("%d",table[i].numserver);
		if(i<k)
			printf(" ");
	}
	return 0;
}