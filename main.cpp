#include <iostream>
#include <string>
#include <thread> 
#include <chrono> 
#include "encryption.h"
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "\n\t\t\tДобро пожаловать в программу шифрования и дешифрования текста!" << endl;
    cout << "\n\tПожалуйста, обратите внимание, что данная программа поддерживает только английскую раскладку клавиатуры.\n" << endl;
    string str;
    string encryptedStr;
    int selection;

    do {
        cout << "Выберите операцию" << endl <<
            "1. Зашифровка" << endl <<
            "2. Дешифровка" << endl <<
            "3. Выход" << endl;
        cin >> selection;

        // Очистка буфера ввода (stdin) после считывания числа выбора
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (selection)
        {
        case 1:
            cout << "Введите сообщение которое будет зашифровано" << endl;
            getline(cin, str);
            encryptedStr = encrypt(str);
            cout << "Результат зашифровки\n" << encryptedStr << endl;
            break;
        case 2:
            if (!encryptedStr.empty()) {
                string decryptedStr = decrypt(encryptedStr);
                cout << "Результат дешифрования\n" << decryptedStr << endl;
            }
            else {
                cout << "Зашифрованное сообщение отсутствует. Пожалуйста, сначала выполните операцию зашифровки (1)." << endl;
            }
            break;
        case 3:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор операции." << endl;
            break;
        }
        // Задержка перед очисткой экрана и завершением программы
        this_thread::sleep_for(chrono::seconds(2));
        clearScreen();
    } while (selection != 3);

    return 0;
}
