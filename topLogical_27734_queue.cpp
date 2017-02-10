#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, m,inDegree[maxn]={0};
vector<int> g[maxn],topOrder;
int topologicalSort() {
    int num = 0;    //��¼�����������еĶ�����
    priority_queue<int, vector<int>, greater<int> > q;    // С���ѵ����ȶ���
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);      //���������Ϊ0�Ķ������
        }
    }
    while(!q.empty()) {
        int u = q.top();      //ȡ���׶���u
        topOrder.push_back(u);
        q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];     //u�ĺ�̽��v
            inDegree[v]--;           //����v����ȼ�1
            if(inDegree[v] == 0) {   //����v����ȼ�Ϊ0�����
                q.push(v);
            }
        }
        g[u].clear();   //��ն���u�����г��ߣ����ޱ�Ҫ�ɲ�д��
        num++;              //�����������еĶ�������1
    }
    return num;
}
int main(){
	//freopen("G:\\PATdata\\codeup27734_topLogical.txt","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        inDegree[v]++;    // �ۼ����
        g[u].push_back(v);    // ����
    }
    int num = topologicalSort();    // ��������
    if(num == n) {
        printf("YES\n");
        for(int i = 0; i < n; i++) {
            printf("%d", topOrder[i]);
            if(i < n - 1) printf(" ");
            else printf("\n");
        }
    } else {
        printf("NO\n%d\n", n - num);    // �޷�����ĸ���
    }
    return 0;
}