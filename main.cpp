#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// ПРОГРАММА РАБОТАЕТ ТОЛЬКО ПРИ ТАКОМ ЖЕ МАКЕТЕ (КОЛИЧЕВСТВО СТОЛБЦОВ РАВНА = 23), ДАННОГО ФАЙЛА

using namespace std;
#define ESS_TR 18 // Количевство оценок, за один триместр, для одного ученика 
#define FULL_TR 50 // Количевство выделенных строк под триместр
#define NUM_START 45 // Номер первого ученика в файле, и соответственно в массиве
#define DIGIT_STUDENT 22 // Число, по которому мы переходим на другую строчку файла, и соответственно в массиве (РАБОТАЕТ ТОЛЬКО ПРИ КОЛИЧЕВСТВЕ СТОЛБЦОВ В ИСХОДНОМ ФАЙЛЕ РАВНОМУ = 23!!!)
#define COUNT_EL 1150 // Произведение количевства строк и столбцов в первом симестре (23 * 50 = 1150), если кратко - количевство элементов
#define BEGIN_ESS 46 // Номер первой оценки первого ученика
#define END_ESS 65 // Номер последней оценки первого ученика
#define BEGIN_TR 1082 // Число, по которому мы переходим на следующий триместр, первую оценку первого ученика 
#define END_TR 1100 // Число, по которому мы переходим на следующий риместр, последнюю оценку первого ученика

int main(int argc, char* argv[]) {
    // Начало
    setlocale(LC_ALL, "ru");
    if (argc > 1) cout << argv[1] << endl;
    else {
        cout << "Отсутствует Аргумент" << endl << endl;

        system("pause");
        return 0;
    }
    //...............//

    // Инициализация Операндов, Открываем Исходный Файл
    string a, path = argv[1], b = argv[1], c = ".MOD.csv";
    int count = 0, count1 = 0, count2, d;
    string path2 = b + c;
    ifstream file(path, ifstream::in);
    ofstream file2(path2, ofstream::out);

    if (file.is_open()) cout << "Файл Один был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n\n";

    if (file2.is_open()) cout << "Файл Два был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n\n";
    //...............//

    // Находим Размер Будущих Массивов и Матриц
    while (!file.eof()) {
        a = "";
        getline(file, a, ';');

        count1++;
    }

    d = round((count1 / DIGIT_STUDENT) / FULL_TR); // Число, считающее сколько предстввленно триместров в исходном файле 
    count2 = d * ESS_TR; // Число, будущее количевство столбцов в матрице. Мы находим количевство всех оценок на одного человека за весь файл
    //...............//

    file.close();
    ifstream file3(path, ifstream::in);

    // Заполянем Динамический Массив Исходным Файлом
    string* Array = new string[count1]{};

    for (int i = 0; !file3.eof(); i++) {
        a = "";
        getline(file3, a, ';');

        Array[i] = a;
    }
    //...............//

    file3.close();

    // Находим Количевство Исходного ФИО
    for (int i = 0, n = 0; i < COUNT_EL; i++) {
        a = "";
        a = Array[i];

        if (i == (NUM_START + n) && a != "") {
            count++;
            n += DIGIT_STUDENT;
        }
    }
    //...............//


    // Создаём Динамический Массив, Заполняем Его ФИО
    string* Array1 = new string[count]{};

    for (int i = 0, n = 0, f = 0; i < COUNT_EL; i++) {
        a = "";
        a = Array[i];

        if (i == (NUM_START + n) && a != "") {
            Array1[f] = Array[i];
            n += DIGIT_STUDENT;
            f++;
        }
    }
    //...............//

    // Создание Матрицы для Оценок
    int** Matrix = new int* [count];

    for (int i = 0; i < count; i++) {
        Matrix[i] = new int[count2];
    }
    //...............//

    // Заполняем Массив Оценками
    for (int j = 0, r = 0; j < count; j++, r += DIGIT_STUDENT) {
        for (int i = (BEGIN_ESS + r), m = 0, f = 0; m < count2; i++, m++) {
            if (i == (END_ESS + r) + f) {
                i += BEGIN_TR;
                f += END_TR;
            }

            if (Array[i] == "5") {
                Matrix[j][m] = 5;
            }
            else if (Array[i] == "4") {
                Matrix[j][m] = 4;
            }
            else if (Array[i] == "3") {
                Matrix[j][m] = 3;
            }
            else if (Array[i] == "2") {
                Matrix[j][m] = 2;
            }
            else if (Array[i] == "") {
                Matrix[j][m] = 0;
            }
            else {
                Matrix[j][m] = -1;
            }
        }
    }
    //...............//

    // В Новый Файл Вписаваем ФИО, а Потом Соответствено Оценки
    for (int j = 0; j < count; j++) {
        file2 << Array1[j] << ";";

        for (int i = 0; i < count2; i++) {
            file2 << Matrix[j][i] << ";";
        }

        file2 << endl;
    }
    //...............//

    file2.close();
    delete[] Array;
    delete[] Array1;
    for (int i = 0; i < count; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    system("pause");
    return 0;
}