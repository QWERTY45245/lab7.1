#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include<Windows.h>
using namespace std;

const int ROWS = 7;
const int COLS = 9;
const int LOWER_LIMIT = -12;
const int UPPER_LIMIT = 37;

// ������� ��� ��������� ������� � ����������� ����������
void generateMatrix(int matrix[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
        }
    }
}

// ������� ��� ���������� ������� �� ���� ��������, �� ������������� �������
void calculateAndReplace(int matrix[ROWS][COLS], int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 3 != 0) {
                count++;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

// ������� ��� ��������� ������� �� �����
void displayMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// ������� ��� ���������� ������� �� ������� ������������� (����������)
void sortMatrixRecursive(int matrix[ROWS][COLS], int currentRow) {
    if (currentRow >= ROWS) {
        return;
    }

    vector<pair<int, int>> sortingKeys;

    for (int j = 0; j < COLS; ++j) {
        sortingKeys.push_back({ matrix[currentRow][j], j });
    }

    sort(sortingKeys.begin(), sortingKeys.end(), [&matrix, currentRow](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            // ���� �������� ��������� ����� ���, �� ���������� �� ���������� ���������� �����
            return matrix[currentRow + 1][a.second] < matrix[currentRow + 1][b.second];
        }
        });

    for (int j = 0; j < COLS; ++j) {
        matrix[currentRow][j] = sortingKeys[j].first;
    }

    // ����������� ������ ��� ���������� �����
    sortMatrixRecursive(matrix, currentRow + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int matrix[ROWS][COLS];
    generateMatrix(matrix);

    cout << "��������� �������:" << endl;
    displayMatrix(matrix);

    int count, sum;
    calculateAndReplace(matrix, count, sum);

    cout << "ʳ������ ��������, �� ������������� �������: " << count << endl;
    cout << "���� ��� ��������: " << sum << endl;

    cout << "������������ ������� ���� �������� 1:" << endl;
    displayMatrix(matrix);

    // ����������� ������ ��� ���������� �� ������� �������������
    sortMatrixRecursive(matrix, 0);

    cout << "������������ ������� ���� �������� 2:" << endl;
    displayMatrix(matrix);

    return 0;
}

/*#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<Windows.h>
using namespace std;

const int ROWS = 7;
const int COLS = 9;
const int LOWER_BOUND = -12;
const int UPPER_BOUND = 37;

// ������� ��� ��������� ����������� ����� � �������� �������
int generateRandomNumber(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

// ������� ��� ��������� ������� � ������ �������
void displayMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

// ������� ��� ��������� ������� �� ������� �������
void generateAndProcessMatrix(vector<vector<int>>& matrix, int& count, int& sum) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = generateRandomNumber(LOWER_BOUND, UPPER_BOUND);
        }
    }

    count = 0;
    sum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 3 != 0) {
                count++;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

// ���������� ������� ��� ���������� �����
void recursiveSortRow(vector<int>& row, int index) {
    if (index == row.size()) {
        return;
    }

    for (int i = index + 1; i < row.size(); ++i) {
        if (row[i] < row[index]) {
            swap(row[i], row[index]);
        }
    }

    recursiveSortRow(row, index + 1);
}

// ���������� ������� ��� ���������� �������
void recursiveSortMatrix(vector<vector<int>>& matrix, int row) {
    if (row == ROWS) {
        return;
    }

    recursiveSortRow(matrix[row], 0);
    recursiveSortMatrix(matrix, row + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    // ��������� �� ��������� ��������� �������
    vector<vector<int>> matrix(ROWS, vector<int>(COLS, 0));
    int count, sum;

    generateAndProcessMatrix(matrix, count, sum);

    cout << "��������� �������:\n";
    displayMatrix(matrix);

    // ���������� �������
    recursiveSortMatrix(matrix, 0);

    

    cout << "\nʳ������ ��������, �� ������������� �������: " << count
        << "\n���� ��������, �� ������������� �������: " << sum;

cout << "\n������������ �� ������������ �������:\n";
    displayMatrix(matrix);
    return 0;
}*/
