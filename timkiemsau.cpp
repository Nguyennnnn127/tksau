#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;


void dfs(const unordered_map<int, vector<int>>& graph, int dinhdau, unordered_set<int>& visited) {
    
    visited.insert(dinhdau);
    cout << dinhdau << " ";


    for (int neighbor : graph.at(dinhdau)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph;
    int sodinh, socanh;

  
   
    cout << "Nhap so luong dinh: ";
    cin >> sodinh;

    cout << "Nhap so luong canh: ";
    cin >> socanh;

    if (sodinh <= 0 || socanh < 0) {
        cout << "So dinh va so canh phai hop le!" << endl;
        return 1;
    }

    cout << "Nhap cac canh (dinh dang: u v, trong do u và v la cac dinh):" << endl;
    for (int i = 0; i < socanh; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || v < 0 || u >= sodinh || v >= sodinh) {
            cout << "Canh khong hop le! dinh phai thuoc khoang [0, " << sodinh - 1 << "]." << endl;
            return 1;
        }

        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    int dinhdau;
    cout << "Nhap dinh bat dau: ";
    cin >> dinhdau;

    if (dinhdau < 0 || dinhdau >= sodinh) {
        cout << "Dinh bat dau khong hop le!" << endl;
        return 1;
    }

    unordered_set<int> visited;

    cout << "DFS tra ve : ";
    dfs(graph, dinhdau, visited);

    cout << endl;

    return 0;
}
