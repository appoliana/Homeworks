#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//структура, которая хранит записи обо всех пользователях
struct  Directory { 
    string name;
    string phone;
};

//функция, которая добавляет запись об абоненте
void read (Directory *array, int count) {  
    cout << "Введите имя пользователя: ";
    cin >> array[count].name;
            
    cout << "Введите номер пользователя: ";
    cin >> array[count].phone;
}

//функция, которая печатает все имеющиеся записи
void printAll (Directory *array, int count) { 
    for (int j = 0; j < count; ++j) {
        cout << array[j].name << " " << array[j].phone << endl; 
    }
}

//поиск номера пользователя по имени
void foundPhone (Directory *array, int count) { 
    cout << "Введите имя пользователя: ";
    string dopName;
    cin >> dopName;
    for (int j = 0; j < count; j++) {
        if (dopName == array[j].name) {
            cout << "Найденный номер " << array[j].phone << endl;
            return;
        }
    }
    cout << "Пользователь с таким именем не найден." << endl;
}

//поиск имени пользователя по его номеру
void foundName (Directory *array, int count) { 
    cout << "Введите номер пользователя: ";
    string dopPhone;
    cin >> dopPhone;
    for (int j = 0; j < count; ++j) {
        if (dopPhone == array[j].phone) {
            cout << "Имя пользователя: " << array[j].name << endl;
            return;
        }
    }
    cout << "Пользователь с таким номером не найден." << endl;
}

//сохранение всех имеющихся записей в файл
void save (Directory *array, int count) { 
    ofstream output("File.txt", ios_base::trunc);
    for (int i = 0; i < count; ++i) {
    output <<  array[i].name << " " << array[i].phone << endl;        
    }  
    output.close();
}

int main(int argc, char** argv) {
    Directory *array = new Directory[100];
    for (int i = 0; i < 100; i++) {
        array[i].name = ""; 
        array[i].phone = ""; 
    }
    ifstream input("File.txt");
    int count = 0;
    while (input) {
        string name;
        input >> name;
        if (name.size())
        {
            array[count].name = name;
            input >> array[count].phone ;
            count++;
        }
    } input.close();
    
    int dop = 1;
    
    while (dop != 0) {
        cout << "Список возможных команд" << endl;
        cout << "0 - выйти" << endl;
        cout << "1 - добавить запись (имя и телефон)" << endl;
        cout << "2 - распечатать все имеющиеся записи" << endl;
        cout << "3 - найти телефон по имени" << endl;
        cout << "4 - найти имя по телефону" << endl;
        cout << "5 - сохранить текущие данные в файл " << endl;
        cout << "Введите команду: ";
        cin >> dop;
        cout << endl;
        switch (dop) {
            case 0:
            {
                delete[] array;
                break;
            } 
            case 1:
            {
                read(array, count);
                count++;
                break;
            } 
            case 2:
            {
                printAll(array, count);
                break;
            }
            case 3:
            {
                foundPhone(array, count);
                break;
            }
            case 4:
            {
                foundName(array, count);
                break;
            }
            case 5:
            {
                save(array, count); 
                break;
            }   
            default:
            {
                cout << "Такая команда не найдена";
                break;
            }    
        }
    } 
    return 0;
}

