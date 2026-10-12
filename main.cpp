#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class mystring
{
private:
    char *ch = nullptr;
    int len = 0;

public:
    // Default constructor
    mystring()
    {
        ch = nullptr;
        len = 0;
    }
    
    // Constructor with length and character
    mystring(int _len, char c)
    {
        len = _len;
        ch = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ch[i] = c;
        }
        ch[len] = '\0';
    }
    
    // Constructor from string
    mystring(string &c)
    {
        len = c.length();
        ch = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ch[i] = c[i];
        }
        ch[len] = '\0';
    }
    
    // Destructor
    ~mystring()
    {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }
    
    // Subscript operator
    char operator[](int x) const
    {
        if (x >= 0 && x < len) {
            return ch[x];
        }
        return '\0';
    }
    
    // Less than operator
    bool operator<(const mystring &other) const
    {
        int min_len = min(len, other.len);
        for (int i = 0; i < min_len; i++) {
            if (ch[i] < other.ch[i]) return true;
            if (ch[i] > other.ch[i]) return false;
        }
        // If all compared characters are equal, shorter string is smaller
        return len < other.len;
    }
    
    // Equality operator
    bool operator==(const mystring &other) const
    {
        if (len != other.len) return false;
        for (int i = 0; i < len; i++) {
            if (ch[i] != other.ch[i]) return false;
        }
        return true;
    }
    
    // Concatenation function (ADD)
    void ADD(const mystring &other)
    {
        char *new_ch = new char[len + other.len + 1];
        
        // Copy current string
        for (int i = 0; i < len; i++) {
            new_ch[i] = ch[i];
        }
        
        // Append other string
        for (int i = 0; i < other.len; i++) {
            new_ch[len + i] = other.ch[i];
        }
        
        new_ch[len + other.len] = '\0';
        
        // Clean up old memory
        delete[] ch;
        ch = new_ch;
        len = len + other.len;
    }
    
    // Output function
    void out() const
    {
        if (ch != nullptr) {
            cout << ch;
        }
    }
    
    // Get length function
    int get_len() const
    {
        return len;
    }
};

string str_in1, str_in2;
int n, id;
int main()
{
    cin >> id;
    if (id == 1)
    {
        mystring str1(100,'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    }
    else if (id == 2)
    {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str2[x] << endl;
        }
    }
    else if (id == 3)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << endl;
    }
    else if (id == 4)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    else
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str3[x] << endl;
        }
        cout << str2.get_len() << " " << str3.get_len() << endl;
        cout << (int)(str2 < str3) << endl;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << endl;
    }
    return 0;
}