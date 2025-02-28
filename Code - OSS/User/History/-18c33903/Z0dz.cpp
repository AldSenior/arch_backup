#include <iostream>
#include <limits>
using namespace std;

void swapUsingPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int random_generate() {
    random_device rd;               // Источник энтропии
    mt19937 gen(rd());               // Генератор Mersenne Twister
    uniform_int_distribution<> distrib(1, 100);
    return distrib(gen);
}

int CheckLengthMass(int &sizeMass) {
    try {
        if (!(cin >> sizeMass) || sizeMass <=0) {
            throw runtime_error("Массив не может быть с отрицательной длинной или пустым");
        }
        return 1;
    }catch (const exception& e) {
        cout << e.what() << "\n";
    }

}

void Task1(){
    int a, b;
    cout << "Введите два целых числа (a и b): ";
    cin >> a >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    // Увеличиваем значение переменной a в 2 раза
    *ptrA *= 2;

    // Меняем местами значения переменных a и b
    swapUsingPointers(ptrA, ptrB);

    cout << "После обработки:\n";
    cout << "a: " << a << "\nb: " << b << "\n";
}

void Task2() {
    int sizeP, sizeQ;

    cout << "Введите размер массива p: ";
    CheckLengthMass(sizeP);

    int* p = new int[sizeP];
    cout << "Элементы массива:\n";
    for (int i = 0; i < sizeP; i++) {
        p[i] = random_generate();
        cout << p[i] << "\n";
    }

    cout << "Введите размер массива q: ";
    CheckLengthMass(sizeQ);

    int* q = new int[sizeQ];
    cout << "Элементы массива:\n";
    for (int i = 0; i < sizeQ; i++) {
        q[i] = random_generate();
        cout << q[i] << "\n";
    }

    int negativeCountP = 0, negativeCountQ = 0;
    for (int i = 0; i < sizeP; ++i) {
        if (p[i] < 0) negativeCountP++;
    }
    for (int i = 0; i < sizeQ; ++i) {
        if (q[i] < 0) negativeCountQ++;
    }

    if (negativeCountP > negativeCountQ) {
        cout << "В массиве p больше отрицательных элементов." << endl;
    } else if (negativeCountP < negativeCountQ) {
        cout << "В массиве q больше отрицательных элементов." << endl;
    } else if (negativeCountP == 0) {
        cout << "В массивах нет отрицательных чисел." << endl;
    } else {
        cout << "Количество отрицательных элементов в обоих массивах одинаково." << endl;
    }

    delete[] p;
    delete[] q;
}

void Task3(){
    int size;
    cout << "Введите размер массива p: ";
    CheckLengthMass(size);

    int* p = new int[size];
    cout << "Введите элементы массива p:\n";
    for (int i = 0; i < size; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < size; ++i) {
        if (p[i] > 0) {
            p[i] = p[i] * p[i]; // возводим в квадрат
        }
    }

    cout << "Массив после обработки:\n";
    for (int i = 0; i < size; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;
}

void Task4() {
    struct Center {
        double x;
        double y;
    };

    struct Circle {
        double radius;
        Center center;
    };

    int n;
    cout << "Введите количество окружностей: ";
    CheckLengthMass(n);

    Circle* circles = new Circle[n];

    for (int i = 0; i < n; ++i) {
        cout << "Введите координаты центра (x, y) окружности " << i + 1 << ":\n";
        cin >> circles[i].center.x >> circles[i].center.y;

        cout << "Введите радиус окружности " << i + 1 << ":\n";
        while (!(cin >> circles[i].radius) || circles[i].radius <= 0) {
            cout << "Радиус окружности не может быть отрицательным числом или 0. Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    Circle largestCircle = circles[0];

    for (int i = 1; i < n; ++i) {
        if (circles[i].radius > largestCircle.radius) {
            largestCircle = circles[i];
        }

    }

    cout << "Координаты центра окружности с максимальным радиусом: ("
         << largestCircle.center.x << ", " << largestCircle.center.y << ")\n";

    delete[] circles;
}

int main() {
    int task;
    cout << "Выберите номер задачи (от 1 до 4): ";
    cin >> task;

    switch (task) {
        case 1:
            Task1();
        break;
        case 2:
            Task2();
        break;
        case 3:
            Task3();
        break;
        case 4:
            Task4();
        break;
        default:
            cout << "Некорректный номер задачи. Пожалуйста, выберите от 1 до 4." << endl;
    }
    return 0;
}
