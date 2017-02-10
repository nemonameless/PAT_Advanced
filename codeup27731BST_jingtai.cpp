#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 40;
struct node {    // ��������̬д��
    int data;
    int lchild;
    int rchild;
} Node[maxn * 2];
int n, data1[maxn], data2[maxn];    // data1��data2��Ų�������
int num = 0;    // ���н�����
int newNode(int x) {    // ������
    Node[num].data = x;
    Node[num].lchild = -1;
    Node[num].rchild = -1;
    return num++;
}
void insert(int &root, int x) {    // ����x
    if(root == -1) {
        root = newNode(x);    // ��ѯʧ�ܣ��ڴ˴�����
        return;
    }
    if(x < Node[root].data) {    // ����������
        insert(Node[root].lchild, x);
    } else {    // ����������
        insert(Node[root].rchild, x);
    }
}
int Create(int data[]) {    // ����
    int root = -1;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}
// �����������򣬵�һ�õĺ��򡢲�������ȫ��ģ��
vector<int> pre1, pre2, post, layer;
void preOrder(vector<int> &pre, int root) {
    if(root == -1) {
        return;
    }
    pre.push_back(Node[root].data);
    preOrder(pre, Node[root].lchild);
    preOrder(pre, Node[root].rchild);
}
void postOrder(int root) {
    if(root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    post.push_back(Node[root].data);
}
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        layer.push_back(Node[now].data);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
int main() {
//    freopen("4.in", "r", stdin);
//    freopen("4.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data1[i]);    // ��һ������
    }
    int root1 = Create(data1);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data2[i]);    // �ڶ�������
    }
    int root2 = Create(data2);
    preOrder(pre1, root1);    // ��һ������
    preOrder(pre2, root2);    // �ڶ�������
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(pre1[i] != pre2[i]) {    // �ж������Ƿ��в�ͬ
            flag = false;
            break;
        }
    }
    if(flag) printf("YES\n");    // ��ͬһ��
    else printf("NO\n");    // ����ͬһ��
    postOrder(root1);    // ����
    layerOrder(root1);    // ����
    for(int i = 0; i < n; i++) {    // ���
        printf("%d", post[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf("%d", layer[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
