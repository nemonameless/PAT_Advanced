//paste.ubuntu.com/15334524/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50;
const int INF = 0x3fffffff;
struct node {
    int data;
    int lchild;
    int rchild;
}Node[maxn];
int in[maxn];    //����
vector<int> pre, post;
int num = 0;    // �ѷ���Ľ�����
int newNode(int x) {    // ������
    Node[num].data = x;
    Node[num].lchild = Node[num].rchild = -1;    // -1��ʾNULL
    return num++;
}
//��ǰ�������Ĳ�������Ϊlayer��������������Ϊ[inL, inR]
//create�������ع������Ķ������ĸ�����ַ
int create(vector<int> layer, int inL, int inR) {
    if(layer.size() == 0) {
        return -1;
    }
    int root = newNode(layer[0]);  //�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
    int k;
    for(k = inL; k <= inR; k++) {    // ���������Ҹ����
        if(in[k] == layer[0]) {
            break;
        }
    }
    vector<int> layerLeft;    // ����������
    vector<int> layerRight;    // ������������
    for(int i = 1; i < layer.size(); i++) {    // ʣ������Ԫ��
        bool isLeft = false;    // �Ƿ���������
        for(int j = inL; j < k; j++) {    // ����������layer[i]
            if(layer[i] == in[j]) {    // �ҵ�layer[i]
                isLeft = true;    // layer[i]��������
                break;
            }
        }
        if(isLeft) layerLeft.push_back(layer[i]);    // ���layer[i]������������ô��������������
        else layerRight.push_back(layer[i]);    // ���layer[i]������������ô��������������
    }
    Node[root].lchild = create(layerLeft, inL, k - 1);    // ����������
    Node[root].rchild = create(layerRight, k + 1, inR);    // ����������
    return root;  //���ظ�����ַ
}
void preOrder(int root) {    // ����
    if(root == -1) {
        return;
    }
    pre.push_back(Node[root].data);
    preOrder(Node[root].lchild);
    preOrder(Node[root].rchild);
}
void postOrder(int root) {    // ����
    if(root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    post.push_back(Node[root].data);
}
int ans1 = 0;    // �����������
void rightToLeftDFS(int root, int depth) {
    if(root == -1) {
        return;
    }
    if(depth > ans1) ans1 = depth;    // ����ans1
    rightToLeftDFS(Node[root].lchild, depth + 1);    // ���Ӹ��Һ��ӵ���ȶ���1
    rightToLeftDFS(Node[root].rchild, depth + 1);
}
int ans2 = 0;    // �����������£����ҵĴ���
void rightupToLeftdownDFS(int root, int right) {
    if(root == -1) {
        return;
    }
    if(right > ans2) ans2 = right;    // ����ans2
    rightupToLeftdownDFS(Node[root].lchild, right);    // ����ʱ��������right����
    rightupToLeftdownDFS(Node[root].rchild, right + 1);    // ����ʱ��������right��1
}
int minLeft = 0, maxRight = 0;    // �������£���С��ֵ�������ֵ
void upToDownDFS(int root, int balance) {
    if(root == -1) {
        return;
    }
    if(balance > maxRight) maxRight = balance;    // ����maxRight
    if(balance < minLeft) minLeft = balance;    // ����minLeft
    upToDownDFS(Node[root].lchild, balance - 1);    // ����ʱ��������balance��1
    upToDownDFS(Node[root].rchild, balance + 1);    // ����ʱ��������balance��1
}
int main() {
    vector<int> layer;
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        layer.push_back(temp);    // ����
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);    // ����
    }
    int root = create(layer, 0, n - 1);    //����
    preOrder(root);    // ����
    postOrder(root);    // ����
    for(int i = 0; i < n; i++) {
        printf("%d", pre[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf("%d", post[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    rightToLeftDFS(root, 1);    // �������󣬸�������Ϊ1
    rightupToLeftdownDFS(root, 1);    // �����������£����ڵ�Ϊ��һ�����
    upToDownDFS(root, 0);    // �������£�������Ȳ�������
    printf("%d\n%d\n%d\n", ans1, ans2, maxRight - minLeft + 1);    // ������
    return 0;
}
