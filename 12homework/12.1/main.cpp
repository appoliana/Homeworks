#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>


using namespace std;

void algorithmKMP (string s, string p)
{
    int i, j, N, M;
    N = s.length();
    M = p.length();
    string uniqElement = "@";
    string sum = p + uniqElement + s;
    cout << sum << endl;
    int *result = new int[s.length() + p.length()];
    int *value = new int[N + M + 1];
    value[0] = 0;
    for (i = 1; i < N + M + 1; i++) 
    {
        j = 0;
        if (sum[i] != sum[j]) 
        {
            value[i] = 0;
            continue;
        }
        else 
        {
            while (sum[i] == sum[j]) 
            {
                value[i] = j + 1;
                j++;
                i++;
            }
        } 
        i--; 
    }
 
    for (int i = 0; i < N + M + 1; i++) 
    {
        if (value[i] == M){
            cout << i - 3 << " - вхождение" << endl;
        }
    }
    
    delete[] value;
}

int main(int argc, char** argv) {
    string s = "ababba";
    cout << "Исходная строка s: " << s << endl;
    string p = "ab";
    cout << "Образец p: " << p << endl;
  
    algorithmKMP(s, p);
   
    return 0;
}

