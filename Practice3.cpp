#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
void write_interface() {
    cout << "Выберите действие:" << endl << "1.Заполнить матрицу порядка N" << endl << "2.Переставить блоки матрицы" << endl << "3.Отсортировать матрицу"
        << endl << "4.Изменить элементы матрицы" << endl << "5.Вывести матрицу" << endl << "Нажмите 0, чтобы выйти" << endl;
}
void quick_sort(int* M, int begin, int end) {
    int mid;
    int* f = (M + begin), * l = (M + end);
    mid = *(f + (l - f)/2);
    while (f < l) {
        while (*f < mid) f++;
        while (*l > mid) l--;
        if (f <= l) {
            swap(*(f), *(l));
            f++;
            l--;
        }
    }
    if (begin < l - M) quick_sort(M, begin, (l - M));
    if (f - M < end) quick_sort(M, (f - M), end);
}
void task1(int *M, int N) {
    srand(time(NULL));
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int ans;
    cout << "Выберите схему заполнения матрицы:" << endl << "1.Змейкой" << endl << "2.Спиралью" << endl;
    cin >> ans;
    system("cls");
    switch (ans) {
    case 1: {
        for (int value = 0, top = 0, left = 0, bot = N - 1, right = N - 1; value < N * N;) {
            for (int j = 0; j < N / 2; j++) {
                for (int i = top; i <= bot; i++) {
                    value++;
                    *(M + i * N + left) = (rand() % (N * N) + 1);
                    destCoord.X = left * 4;
                    destCoord.Y = i * 2;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(M + i * N + left);
                    cout.flush();
                    value++;
                    Sleep(300);
                }
                ++left;
                for (int i = bot; i >= top; i--) {
                    value++;
                    *(M + i * N + left) = (rand() % (N * N) + 1);
                    destCoord.X = left * 4;
                    destCoord.Y = i * 2;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(M + i * N + left);
                    cout.flush();
                    value++;
                    Sleep(300);
                }
                ++left;
            }
        }
        break;
    }
    case 2: {
        for (int value = 0, top = 0, left = 0, bot = N - 1, right = N - 1; value < N * N;) {
            for (int i = left; i <= right; i++) {
                *(M + top * N + i) = (rand() % (N * N) + 1);
                destCoord.X = i * 4;
                destCoord.Y = top * 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(M + top * N + i);
                cout.flush();
                value++;
                Sleep(300);
            }
            ++top;
            for (int i = top; i <= bot; i++) {
                *(M + i * N + right) = (rand() % (N * N) + 1);
                destCoord.X = right * 4;
                destCoord.Y = i * 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(M + i * N + right);
                cout.flush();
                value++;
                Sleep(300);
            }
            --right;
            for (int i = right; i >= left; i--) {
                *(M + bot * N + i) = (rand() % (N * N) + 1);
                destCoord.X = i * 4;
                destCoord.Y = bot * 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(M + bot * N + i);
                cout.flush();
                value++;
                Sleep(300);
            }
            --bot;
            for (int i = bot; i >= top; i--) {
                *(M + i * N + left) = (rand() % (N * N) + 1);
                destCoord.X = left * 4;
                destCoord.Y = i * 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(M + i * N + left);
                cout.flush();
                value++;
                Sleep(300);
            }
            ++left;
        }
        break;
    } 
    }
    Sleep(2000);
}
void task2(int* M, int N) {
    system("cls");
    int ans;
    cout << "Каким образом переставить блоки?" << endl << "1.По часовой стрелке" << endl << "2.Крест-накрест" << endl << "3.Вертикально" << endl << "4.Горизонтально" << endl;
    cin >> ans;
    switch (ans) {
    case 1: {
        for (int x = 0; x < N/2; x++) {
            for (int y = 0; y < N / 2; y++) {
                swap(*(M + x + y * N), *(M + y * N + x + N * (N / 2)));
                swap(*(M + y * N + x + N * (N / 2)), *(M + N * (N / 2) + x + (N / 2) + y * N));
                swap(*(M + N * (N / 2) + x + (N / 2) + y * N), *(M + y * N + x + (N/2)));
            }
        }
        break;
    }
    case 2: {
        for (int x = 0; x < N / 2; x++) {
            for (int y = 0; y < N / 2; y++) {
                swap(*(M + x + y * N), *(M + x + y * N + N / 2 + N * (N / 2)));
            }
        }
        for (int x = N/2; x < N; x++) {
            for (int y = 0; y < N / 2; y++) {
                swap(*(M + x + y * N), *(M + y * N + N * (N/2) + x - N/2));
            }
        }
        break;
    }
    case 3: {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N / 2; y++) {
                swap(*(M + x + y * N), *(M + x + y * N + N * (N/2)));
            }
        }
        break;
    }
    case 4: {
        for (int x = 0; x < N/2; x++) {
            for (int y = 0; y < N; y++) {
                swap(*(M + x + y * N), *(M + x + y * N + N/2));
            }
        }
        break;
    }
    }
}
void task3(int* M, int N) {
    system("cls");
    int ans;
    cout << "Какую сортировку использовать?" << endl << "1.Shaker" << endl << "2.Comb"  << endl << "3.Insert" << endl << "4.Quick" << endl;
    cin >> ans;
    switch (ans) {
    case 1: { //Shaker
        bool swapped = true;
        int* start = M, *end = M + N * N;
        while (swapped) {
            swapped = false;
            for (int* i = start; i < end; i++) {
                if (*i > *(i + 1)) {
                    swap(*i, *(i + 1));
                    swapped = true;
                }
            }
            if (!swapped) break;
            --end;
            for (int* i = end - 1; i >= start; --i) {
                if (*i > *(i + 1)) {
                    swap(*i, *(i + 1));
                    swapped = true;
                }
            }
            ++start;
        }
        break;
    }
    case 2: { //Comb
        int s = N*N - 1;
        float k = 1.247;
        while (s >= 1) {
            for (int* i = M; i + s < M + N * N; i++) {
                if (*i > *(i + s)) {
                    swap(*i, *(i + s));
                }
                s /= k;
            }
        }
        break;
    }
    case 3: { //Insert
        int key, *j = 0;
        for (int* i = M + 1; i < M + N * N; i++) {
            key = *i;
            j = i - 1;
            while (j >= M && *j > key) {
                *(j + 1) = *j;
                --j;
            }
            *(j + 1) = key;
        }
        break;
    }
    case 4: { //Quick
        quick_sort(M, 0, N*N - 1);
        break;
    }
    }
}
void task4(int* M, int N) {
    system("cls");
    int ans, value;
    cout << "Какое действие выполнить?" << endl << "1.Умножение" << endl << "2.Деление" << endl << "3.Сложение" << endl << "4.Вычитание" << endl;
    cin >> ans;
    cout << endl << "На какое число?";
    cin >> value;
    for (int* i = M; i < M + N * N; i++) {
        switch (ans) {
        case 1: {
            *i *= value;
            break;
        }
        case 2: {
            *i /= value;
            break;
        }
        case 3: {
            *i += value;
            break;
        }
        case 4: {
            *i -= value;
            break;
        }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int globalAnswer, orderAnswer, N, Matrix[10][10] = { 0 };
    cout << "Выберите порядок матрицы:" << endl << "1.6" << endl << "2.8" << endl << "3.10" << endl;
    cin >> orderAnswer;
    switch (orderAnswer) {
    case 1: {
        N = 6;
        break;
    }
    case 2: {
        N = 8;
        break;
    }
    case 3: {
        N = 10;
        break;
    }
    }
    do {
        system("cls");
        write_interface();
        cin >> globalAnswer;
        switch (globalAnswer) {
        case 1: {
            system("cls");
            task1(&Matrix[0][0], N);
            break;
        }
        case 2: {
            task2(&Matrix[0][0], N);
            break;
        }
        case 3: {
            task3(&Matrix[0][0], N);
            break;
        }
        case 4: {
            task4(&Matrix[0][0], N);
            break;
        }
        case 5: {
            system("cls");
            HANDLE hStdout;
            COORD destCoord;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            for (int* i = &Matrix[0][0], *j = &Matrix[0][0] + N * N; i < j; i++) {
                destCoord.X = ((i - &Matrix[0][0]) % N) * 4;
                destCoord.Y = ((i - &Matrix[0][0]) / N) * 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *i << " ";
                cout.flush();
            }
            Sleep(4000);
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "Введено некорректное значение, попробуйте еще раз...";
            globalAnswer = 1;
        }
        }
    } while (globalAnswer);
}

