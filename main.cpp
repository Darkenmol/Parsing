#include <iostream>
#include <fstream>
#include <string>

// ПРОГРАММА РАБОТАЕТ ТОЛЬКО ПРИ ТАКОМ ЖЕ МАКЕТЕ (КОЛИЧЕВСТВО СТОЛБЦОВ РАВНА = 23), ДАННОГО ФАЙЛА

using namespace std;
#define CELLSY_MATRIX 35
#define CELLSX_MATRIX 126
#define NUM_START 45
#define DIGIT_STUDENT 22 // Число, по которому мы переходим на на другую строчку файла (РАБОТАЕТ ТОЛЬКО ПРИ КОЛИЧЕВСТВЕ СТОЛБЦОВ В ИСХОДНОМ ФАЙЛЕ РАВНОМУ = 23!!!)
#define COUNT_EL 1150 // Произведение колчевства строк и столбцов в первом симестре (23 * 50 = 1150), если кратко - количевство элементов
#define BEGIN_ESS 46 // Номер первой оценки первого ученика
#define END_ESS 64 // Номер последней оценки первого ученика
#define BEGIN_TR 1082 // Число, по которому мы переходим на следующий триместр, первую оценку первого ученика 
#define END_TR 1100 // Число, по которому мы переходим на следующий риместр, последнюю оценку первого ученика

int main(int argc, char* argv[]) {
    // Начало
    setlocale(LC_ALL, "ru");
    if (argc > 1)// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
    {
        cout << argv[1] << endl; // вывод второй строки из массива указателей на строки(нумерация в строках начинается с 0 )

        
    }
    else
    {
        cout << "Отсутствует Аргумент" << endl << endl;

        system("pause");
        return 0;
    }
    //...............//

    // Инициализация Операндов, Открываем Исходный Файл
    string a, path = argv[1], b = argv[1], c = "\b\b\b\b";
    int count = 0, count1 = 0;
    string d 
    string path2 = d + ".MOD.csv";

    // C:\\Users\student\Documents\Algebra.csv

    ifstream file(path, ifstream::in);
    ofstream file2(path2, ofstream::out);
  
    if (file.is_open()) cout << "Файл Один был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n\n";

    if (file2.is_open()) cout << "Файл Два был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n\n";
    //...............//
    
    // Находим Размер Будущего Массива
    while (!file.eof()) {
        a = "";
        getline(file, a, ';');

        count1++;
    }
    //...............//

    file.close();
    ifstream file3(path, ifstream::in);
   
    // Заполянем Массив Исходным Файлом
    string* Array = new string[count1]{};

    for (int i = 0; !file3.eof(); i++) {
        a = "";
        getline(file3, a, ';');

        Array[i] = a;
    }
    //...............//

    file3.close();

    // Находим Количевство Искохдного ФИО
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
    int** Matrix = new int *[count];

    for (int i = 0; i < count; i++) {
        Matrix[i] = new int[CELLSX_MATRIX];
    }
    //...............//
    
    // Заполняем Массив Оценками
    for (int j = 0, r = 0; j < count; j++, r += DIGIT_STUDENT) {
        for (int i = (BEGIN_ESS + r), m = 0, f = 0; m < CELLSX_MATRIX; i++, m++) {
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

        for (int i = 0; i < CELLSX_MATRIX; i++) {
            file2 << Matrix[j][i] << ";";
        }

        file2 << endl;
    }
    //...............//

    file2.close();
    delete[] Array;
    delete[] Array1;
    delete[] Matrix;
    system("pause");
    return 0;
}