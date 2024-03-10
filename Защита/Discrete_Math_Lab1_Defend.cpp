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
    int n;

    std::ifstream input("Data/input.txt");
    if (!input) {
        std::cout << "���� �� ������\n";
        return 0;
    }
    input >> n;

    std::vector<iVect> matrix(n, iVect(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            input >> matrix[i][j];

    std::cout << "������� ���������\n";
    PrintMtr(matrix, 'x', 'x', n, n);

    std::cout << "������\n";

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1) count++;
        std::cout << "����� x" << i + 1 << " ����� " << count << "\n";
    }
    std::cout << "������\n";
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (matrix[j][i] == 1) count++;
        std::cout << "����� x" << i + 1 << " ����� " << count << "\n";
    }
   
    return 0;
}