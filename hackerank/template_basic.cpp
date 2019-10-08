#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
#define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
#define concatenate add
//https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull

template <class T>
class AddElements {
 private:
     T element;
 public:
    AddElements(T input):element(input)
    {}
    T add(const T& rhs) {
        return this->element + rhs;
    }
};

template<>
class AddElements< string > {
 private:
    string element;
 public:
    AddElements(string input):element(input)
    {}
    string concatenate(const string& rhs) {
        return this->element + rhs;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
