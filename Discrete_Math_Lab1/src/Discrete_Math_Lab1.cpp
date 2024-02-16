#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector<short int> iVect;

void PrintMtr(std::vector <iVect>& matrix, char nameVert, char nameHor, int n, int m) {
    std::cout << "\t";
    for (int i = 0; i < m; i++) {
        std::cout << nameHor << i + 1 << "\t";
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << nameVert << i + 1 << "\t";
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int n, m;

    std::ifstream input("Data/input.txt");
    if (!input) {
        std::cout << "Файл не найден\n";
        return 0;
    }
    input >> n >> m;

    std::vector<iVect> matrix(n, iVect(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            input >> matrix[i][j];

    std::vector<iVect> newMatrix(n, iVect(n, 0));

    for (int j = 0; j < m; j++) {
        int in=-1, out=-1;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) continue;
            if (matrix[i][j] == 1) { 
                if (in == -1)
                    in = i;
                else { out = i; newMatrix[out][in] = 1; break; }
            }
            if (matrix[i][j] == -1) out = i;
            if (matrix[i][j] == 2) { newMatrix[i][i] = 1; break; }
            }
        if (in==-1 && out==-1) continue;
        newMatrix[in][out] = 1;
        }
    std::cout << "Матрица инцидентности\n";
    PrintMtr(matrix, 'x', 'a', n, m);
    std::cout << "Матрица смежности из матрицы инцидентности\n";
    PrintMtr(newMatrix, 'x', 'x', n, n);

    matrix.clear();

    for(int i = 0; i<n; i++)
        for (int j = 0; j < n; j++) {
            if (newMatrix[i][j] == 0) continue;
            if (newMatrix[i][j] == 1) {
                iVect current(n, 0);
                if (newMatrix[j][i] == 1) {
                    if(i==j)
                        current[i] = 2;
                    else {
                        current[i] = 1;
                        current[j] = 1;
                    }
                }
                else if (newMatrix[j][i] == 0) {
                    current[i] = 1;
                    current[j] = -1;
                }
                newMatrix[i][j] = 0;
                newMatrix[j][i] = 0;
                matrix.push_back(current);
            }
        }

    m = matrix.size();

    std::cout << "Матрица инцидентности из матрицы смежности\n\t";
    for (int i = 0; i < m; i++) {
        std::cout << 'a' << i + 1 << "\t";
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << 'x' << i + 1 << "\t";
        for (int j = 0; j < m; j++)
            std::cout << matrix[j][i] << "\t";
        std::cout << "\n";
    }
    return 0;
}