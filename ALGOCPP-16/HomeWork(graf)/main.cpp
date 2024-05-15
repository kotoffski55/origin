#include<iostream>
#include<vector>
#include<string> 
#include<fstream>


void dfs(int v, const std::vector<std::vector<int>>& graph) {
    // ������� ������ ������� �������
    std::cout << v << " ";

    // ���������� ��� ������� ������� �������
    for (int i = 0; i < graph[v].size(); ++i) {
        if (graph[v][i] == 1 && i != v) { // ��������� ������� ����� � �������� �����
            dfs(i + 1, graph); // ���������� �������� ���������� ������
        }
    }
}

int main() {
    int N;
    std::ifstream fin("input.txt"); // ��������� ���� ��� ������
    fin >> N; // ������ ���������� ������

    // ������� ������� ��������� �������� N x N
    std::vector<std::vector<int>> graph(N, std::vector<int>(N));

    // ��������� ������� ������� �� �����
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> graph[i][j];
        }
    }

    // ��������� ����
    fin.close();

    // �������� ����� � ������� 1
    dfs(1, graph);

    return 0;
}
