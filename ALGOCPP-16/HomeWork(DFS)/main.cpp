#include <iostream>
#include <fstream>
#include <vector>
int** createMatrix(int x, int y)
{
    int** matrix;
    matrix = new int* [x];
    for (int i = 0; i < x; ++i)
    {
        matrix[i] = new int[y];
    }
    return matrix;
}
void deleteMatrix(int** matrix, int x, int y)
{
    for (int i = 0; i < x; ++i)
    {
        delete matrix[i];
    }
    delete[] matrix;
}
void fillMatrix(int** matrix, int x, int y, std::ifstream& _in)
{
    while (!_in.eof())
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                _in >> matrix[i][j];
            }
        }
    }
}
void printMatrix(int** matrix, int x, int y)
{
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
           std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void DFS(int** &matrix, std::vector<int> &result_visited,int size_matrix)
{
    for (int ver = 0; ver < size_matrix; ver++)
    {
        result_visited.push_back(ver + 1);
        for (int edge = 0; edge < size_matrix; edge++)
        {
            if (matrix[ver][edge] == 1);
            //result_visited.push_back(ver + 1);
        }
    }
}
int main()
{
    std::vector<int> result_visited{ 0 };
    std::ifstream in;
    in.open("input.txt"); // окрываем файл для чтения
    int N;//размер матрицы
    in >> N;
    int** matrix = createMatrix(N, N);
    fillMatrix(matrix, N, N, in);

    //Обход графа в глубину !!!!!!!!!!!!!

    //DFS(matrix, result_visited, N);
   
    printMatrix(matrix, N, N);
    deleteMatrix(matrix, N, N);
    return 0;

}