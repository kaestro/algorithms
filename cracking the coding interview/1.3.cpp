#include <string>
#include <iostream>

using namespace std;

int main() {
    string input = "Mr John Smith    ";
    cout << input << endl;

    auto rit = input.rbegin();
    while (*rit == ' ')
        rit++;
    
    auto rcpy = input.rbegin();
    while (rit != input.rend())
    {
        if (*rit != ' ')
            *rcpy = *rit;
        else
        {
            *(rcpy++) = '0';
            *(rcpy++) = '2';
            *rcpy = '%';
        }
        rcpy++, rit++;
    }
    
    cout << input << endl;

    return 0;
}