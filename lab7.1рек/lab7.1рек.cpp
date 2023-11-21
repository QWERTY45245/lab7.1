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

// Функція для генерації матриці з випадковими значеннями
void generateMatrix(int matrix[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
        }
    }
}

// Функція для обчислення кількості та суми елементів, які задовольняють критерію
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

// Функція для виведення матриці на екран
void displayMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Функція для сортування матриці за ключами впорядкування (рекурсивна)
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
            // якщо елементи поточного рядка рівні, то сортування за елементами наступного рядка
            return matrix[currentRow + 1][a.second] < matrix[currentRow + 1][b.second];
        }
        });

    for (int j = 0; j < COLS; ++j) {
        matrix[currentRow][j] = sortingKeys[j].first;
    }

    // Рекурсивний виклик для наступного рядка
    sortMatrixRecursive(matrix, currentRow + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int matrix[ROWS][COLS];
    generateMatrix(matrix);

    cout << "Початкова матриця:" << endl;
    displayMatrix(matrix);

    int count, sum;
    calculateAndReplace(matrix, count, sum);

    cout << "Кількість елементів, які задовольняють критерію: " << count << endl;
    cout << "Сума цих елементів: " << sum << endl;

    cout << "Модифікована матриця після завдання 1:" << endl;
    displayMatrix(matrix);

    // Рекурсивний виклик для сортування за ключами впорядкування
    sortMatrixRecursive(matrix, 0);

    cout << "Модифікована матриця після завдання 2:" << endl;
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

// Функція для генерації випадкового числа в заданому діапазоні
int generateRandomNumber(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

// Функція для виведення матриці у вигляді таблиці
void displayMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

// Функція для генерації матриці та обробки критерію
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

// Рекурсивна функція для сортування рядка
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

// Рекурсивна функція для сортування матриці
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

    // Створення та виведення початкової матриці
    vector<vector<int>> matrix(ROWS, vector<int>(COLS, 0));
    int count, sum;

    generateAndProcessMatrix(matrix, count, sum);

    cout << "Початкова матриця:\n";
    displayMatrix(matrix);

    // Сортування матриці
    recursiveSortMatrix(matrix, 0);

    

    cout << "\nКількість елементів, що задовольняють критерію: " << count
        << "\nСума елементів, що задовольняють критерію: " << sum;

cout << "\nВпорядкована та модифікована матриця:\n";
    displayMatrix(matrix);
    return 0;
}*/
