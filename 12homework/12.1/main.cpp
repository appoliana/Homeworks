#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>


using namespace std;

void algorithmKMP (string s, string p)
{
    const int n = s.length();
    const int m = p.length();
    string uniqElement = "@";
    string sum = p + uniqElement + s;
    cout << sum << endl;
    int *prefixFunction = new int[n + m + 1]{};
    for (int i = 1; i < n + m + 1; i++) 
    {
        int j = 0;
        if (sum[i] != sum[j]) 
        {
            prefixFunction[i] = 0;
            continue;
        }
        else 
        {
            while (sum[i] == sum[j]) 
            {
                prefixFunction[i] = j + 1;
                j++;
                i++;
            }
        } 
        i--; 
    }
 
    for (int i = 0; i < n + m + 1; i++) 
    {
        if (prefixFunction[i] == m) {
            cout << i - m - 1 << " - вхождение" << endl;
        }
    }
    delete[] prefixFunction;
}

int main(int argc, char** argv) {
    string s = "jdiojcskdjsoijfdj";
    cout << "Исходная строка s: " << s << endl;
    string p = "dj";
    cout << "Образец p: " << p << endl;
  
    algorithmKMP(s, p);
   
    return 0;
}

