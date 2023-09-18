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
    cout << "\n\t\t\t����� ���������� � ��������� ���������� � ������������ ������!" << endl;
    cout << "\n\t����������, �������� ��������, ��� ������ ��������� ������������ ������ ���������� ��������� ����������.\n" << endl;
    string str;
    string encryptedStr;
    int selection;

    do {
        cout << "�������� ��������" << endl <<
            "1. ����������" << endl <<
            "2. ����������" << endl <<
            "3. �����" << endl;
        cin >> selection;

        // ������� ������ ����� (stdin) ����� ���������� ����� ������
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (selection)
        {
        case 1:
            cout << "������� ��������� ������� ����� �����������" << endl;
            getline(cin, str);
            encryptedStr = encrypt(str);
            cout << "��������� ����������\n" << encryptedStr << endl;
            break;
        case 2:
            if (!encryptedStr.empty()) {
                string decryptedStr = decrypt(encryptedStr);
                cout << "��������� ������������\n" << decryptedStr << endl;
            }
            else {
                cout << "������������� ��������� �����������. ����������, ������� ��������� �������� ���������� (1)." << endl;
            }
            break;
        case 3:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "������������ ����� ��������." << endl;
            break;
        }
        // �������� ����� �������� ������ � ����������� ���������
        this_thread::sleep_for(chrono::seconds(2));
        clearScreen();
    } while (selection != 3);

    return 0;
}
