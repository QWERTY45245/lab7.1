#include<Windows.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<algorithm>
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

// ������� ��� ���������� ������� �� ������� �������������
void sortMatrix(int matrix[ROWS][COLS]) {
    vector<pair<int, int>> sortingKeys;

    for (int j = 0; j < COLS; ++j) {
        sortingKeys.push_back({ matrix[0][j], j });
    }

    sort(sortingKeys.begin(), sortingKeys.end(), [&matrix](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            // ���� �������� ������� ����� ���, �� ���������� �� ���������� ������� �����
            if (matrix[1][a.second] != matrix[1][b.second]) {
                return matrix[1][a.second] < matrix[1][b.second];
            }
            else {
                // ���� �������� ������� � ������� ����� ���, �� ���������� �� ���������� �������� �����
                return matrix[2][a.second] < matrix[2][b.second];
            }
        }
        });

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = sortingKeys[j].first;
        }
    }
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

    sortMatrix(matrix);

    cout << "������������ ������� ���� �������� 2:" << endl;
    displayMatrix(matrix);

    return 0;
}

    
    


/*#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
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

// ������� ��� ��������� �� ��������� �������
void createAndDisplayMatrix(vector<vector<int>>& matrix) {
    cout << "����������� �������:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = generateRandomNumber(LOWER_BOUND, UPPER_BOUND);
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

// ������� ��� ���������� ������� �� ��������� ����������
void processMatrix(vector<vector<int>>& matrix, int& count, int& sum) {
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

// ������� ��� ������������� ������� �������� �� �������� ������ �������������
void sortMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < ROWS; ++i) {
        sort(matrix[i].begin(), matrix[i].end());
    }

    for (int i = 0; i < COLS; ++i) {
        vector<int> column;
        for (int j = 0; j < ROWS; ++j) {
            column.push_back(matrix[j][i]);
        }
        sort(column.begin(), column.end());
        for (int j = 0; j < ROWS; ++j) {
            matrix[j][i] = column[j];
        }
    }
}

// ������� ��� ��������� ������������ �������
void displaySortedMatrix(const vector<vector<int>>& matrix) {
    cout << "\n������������ �������:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    srand(static_cast<unsigned>(time(nullptr)));

    // ��������� �� ��������� ��������� �������
    vector<vector<int>> matrix(ROWS, vector<int>(COLS, 0));
    createAndDisplayMatrix(matrix);

    // ������� ������� �� ��������� ����������
    int count, sum;
    processMatrix(matrix, count, sum);
    cout << "\nʳ������ ��������, �� ������������� �������: " << count
        << "\n���� ��������, �� ������������� �������: " << sum;

    // ������������� �� ��������� ������������ �������
    sortMatrix(matrix);
    displaySortedMatrix(matrix);

    return 0;
}*/


    