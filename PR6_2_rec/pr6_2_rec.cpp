// Лабораторна робота № 6.2, варіант 27
// Спосіб 2: рекурсивні функції
// Завдання: знайти індекс найменшого непарного елемента масиву a із n цілих чисел
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

// заповнює масив випадковими числами з діапазону [Low; High]
void Create(int* a, const int n, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < n - 1)
        Create(a, n, Low, High, i + 1);
}

// виводить масив у вигляді рядка
void Print(int* a, const int n, int i)
{
    cout << setw(4) << a[i];
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

// повертає індекс найменшого непарного елемента масиву;
// i – поточний індекс, imin – індекс найменшого непарного серед a[0..i-1] (-1, якщо такого ще немає);
// початковий виклик: IndexOfMinOdd(a, n, 0, -1)
int IndexOfMinOdd(int* a, const int n, int i, int imin)
{
    if (i == n)
        return imin;
    if (a[i] % 2 != 0 && (imin == -1 || a[i] < a[imin]))
        imin = i;
    return IndexOfMinOdd(a, n, i + 1, imin);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));        // ініціалізація генератора випадкових чисел

    const int n = 20;
    int a[n];
    int Low = -20, High = 50;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int imin = IndexOfMinOdd(a, n, 0, -1);
    if (imin == -1)
        cout << "Непарних елементів немає" << endl;
    else
        cout << "Індекс найменшого непарного елемента: " << imin
        << " (a[" << imin << "] = " << a[imin] << ")" << endl;

    return 0;
}