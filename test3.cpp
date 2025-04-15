#include <iostream>
using namespace std;

class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string str);
        String_Calculator& Add(const string str);
        String_Calculator& Subtract(const string str);
        String_Calculator& DividedBy(const string str);
        void output() const;

    private:
        string s = "";
};

String_Calculator::String_Calculator(const string str) {
    s = str;
}

String_Calculator& String_Calculator::Add(const string str) {
    s += str;
    return *this;
}

String_Calculator& String_Calculator::Subtract(const string str) {
    size_t pos = s.find(str);
    if (pos != string::npos) {
        s.erase(pos, str.length());
    } else {
        s = "error";
    }
    return *this;
}

String_Calculator& String_Calculator::DividedBy(const string str) {
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(str, pos)) != string::npos) {
        count++;
        pos += str.length();
    }
    s = to_string(count);
    return *this;
}

void String_Calculator::output() const {
    cout << s << endl;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string x, xx;
        cin >> x >> xx;
        String_Calculator a(x);
        a.Subtract(xx).Add(xx).DividedBy(xx).output();
    }
}