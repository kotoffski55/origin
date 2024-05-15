#include<iostream>
#include<vector>
#include<string> 
#include<fstream>


void dfs(int v, const std::vector<std::vector<int>>& graph) {
    // Выводим индекс текущей вершины
    std::cout << v << " ";

    // Перебираем все соседей текущей вершины
    for (int i = 0; i < graph[v].size(); ++i) {
        if (graph[v][i] == 1 && i != v) { // Проверяем наличие связи и избегаем цикла
            dfs(i + 1, graph); // Рекурсивно посещаем следующего соседа
        }
    }
}

int main() {
    int N;
    std::ifstream fin("input.txt"); // Открываем файл для чтения
    fin >> N; // Читаем количество вершин

    // Создаем матрицу смежности размером N x N
    std::vector<std::vector<int>> graph(N, std::vector<int>(N));

    // Заполняем матрицу данными из файла
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> graph[i][j];
        }
    }

    // Закрываем файл
    fin.close();

    // Начинаем обход с вершины 1
    dfs(1, graph);

    return 0;
}
