#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int occurrences(char *s, char *s1) {
    int count = 0;
    int index = 0;
    int length2 = 0;
    int index2 = 0;
    bool flag = true;
    while (s1[length2] != '\0') {
        length2++;
    }
    while (s[index] != '\0') {
	if (s[index] != s1[0]) {
            index++;
        }
        else {
            index2 = 0;
            flag = true;
            while (s[index + index2] != '\0' && s1[index2] != '\0') {
                flag &= s[index + index2] == s1[index2];
		++index2;
            }
            if (flag && index2 == length2) {
                ++count;
		index += length2;
            }
            else {
                ++index;
            }
	}
    }
    return count;
}

int main() {
	char s[100];
	char s1[100];
        cout << "Введите первую строку: ";
	gets (s);
        cout << "Введите вторую строку: ";
	gets (s1);
        int count = occurrences(s, s1);
	cout << "Количество вхождений первой строки во вторую = " << count;
	return 0;
}