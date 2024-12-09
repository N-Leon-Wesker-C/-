#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph {
    int V; // 顶点的数量
    struct Node {
        int dest;
        struct Node* next;
    };

    struct Node** adj; // 邻接表

public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void DFS(int v); // 深度优先搜索
    void BFS(int v); // 广度优先搜索
};

Graph::Graph(int V) {
    this->V = V;
    adj = new Node*[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;
}

void Graph::addEdge(int v, int w) {
    Node* newNode = new Node;
    newNode->dest = w;
    newNode->next = adj[v];
    adj[v] = newNode;

    newNode = new Node;
    newNode->dest = v;
    newNode->next = adj[w];
    adj[w] = newNode;
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    stack<int> stack;
    visited[v] = true;
    stack.push(v);

    while (!stack.empty()) {
        v = stack.top();
        cout << v << " ";
        stack.pop();

        Node* temp = adj[v];
        while (temp) {
            int adjV = temp->dest;
            if (!visited[adjV]) {
                stack.push(adjV);
                visited[adjV] = true;
            }
            temp = temp->next;
        }
    }
}

void Graph::BFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> queue;
    visited[v] = true;
    queue.push(v);

    while (!queue.empty()) {
        v = queue.front();
        cout << v << " ";
        queue.pop();

        Node* temp = adj[v];
        while (temp) {
            int adjV = temp->dest;
            if (!visited[adjV]) {
                queue.push(adjV);
                visited[adjV] = true;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph g(4); // 创建一个有4个顶点的图

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "深度优先搜索结果:";
    g.DFS(2);
    cout<<endl;
    cout << "广度优先搜索结果:";
    g.BFS(2);

    return 0;
}
