#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>


using namespace std;

/*void countElements(int &length) 
{
    FILE * File = fopen("text.txt", "r");
    int p = 0;
    while (!feof(File)) {
	fscanf(File, "%d", &p);
	++length;
    }
    fclose(File);
}
*/

string algorithmKMP (string s, string p)
{
    int i, j, N, M;
    N = s.length();
    M = p.length();
    string uniqElement = "@";
    string sum = p + uniqElement + s;
    
    string result;
    int *value = new int[N + M + 1];
    value[0] = 0;
    int count = 0;
    for (i = 1; i < N + M + 1; i++) {
        j = 0;
        if (sum[i] != sum[j]) {
            value[i] = 0;
            continue;
        }
        else {
            while (sum[i] == sum[j]) {
                value[i] = j + 1;
                j++;
                i++;
            }
        } 
        if (value[i] == M){
            result[count] = i - M + 1;
            count ++;
        }
    }
    delete[] value;
    return result;
}

int main(int argc, char** argv) {
    /*int lengthS = 0;
    countElements(lengthS);
    int *s = new int[lengthS];
    cout << lengthS << endl;
    FILE * File = fopen("text.txt", "r");
    for (int i = 0; i < length; ++i) {
	fscanf(File, "%d", &s[i]);
    }
    fclose(File);
    */
    
    /*cout << "Введите строку: " << endl;
    char *s = new char[10];
    cin >> s;
    int lengthS = strlen(s);
    
    
    cout << "Введите образ: " << endl;
    char *p = new char[10];
    cin >> p;
    int lengthP = strlen(p) + strlen(s) + 1;
    */
    string s = "ababba";
    string p = "ab";
    string result = 0;
  
    //for (int i = 0; i < lengthS; i++) {
      //  
    //}
    
    result = algorithmKMP(s, p);
    
    cout << "Вхождения образа p в строку s: " << endl;
    for (int i = 0; i < result.length(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

