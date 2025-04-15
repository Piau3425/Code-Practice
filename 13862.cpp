#include<bits/stdc++.h>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info() {
            return 
                "Name:" + this->name + ",\n" + 
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};

void Person::describe(string* arr, int now, int len) {
    
}

Person* Person::getRelative (string* arr, int now, int len) {
    if (now == len-2) {
        if (arr[now] == "name") this->name = arr[now+1];
        if (arr[now] == "age") this->age = stoi(arr[now+1]);
        if (arr[now] == "gender") this->gender = arr[now+1];
        if (arr[now] == "personality") this->personality = arr[now+1];
        return;
    }
    if (arr[now] == "parentA") return this->parentA->describe(arr, now+1, len);
    if (arr[now] == "parentB") return this->parentB->describe(arr, now+1, len);
    if (arr[now] == "mate") return this->mate->describe(arr, now+1, len);
    if (arr[now] == "child") return this->child->describe(arr, now+1, len);
}

string* ParseStatement(string statement) { // return the parsed array
    stringstream ss;
    vector<string> v;
    ss << statement;
    while (ss >> statement) v.push_back(statement);
    string* ret = new string[v.size()];
    for (int i = 0; i < v.size(); ++i) {
        ret[i] = v[i];
    }
    return ret;
}

int getParseStatementLength(string statement) {
    stringstream ss;
    ss << statement;
    int ret = 0;
    while (ss >> statement) ++ret;
    return ret;
}

int main () {
    Person* narrator = new Person();

    narrator->name = "Pineapple Senpai";
    narrator->age = 21;
    narrator->gender = MALE;
    narrator->personality = "seasick";

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        // input type of the query
        int type;
        cin >> type;
        // get the parsed array
        string statement;
        getline(cin, statement);
        string* arr = ParseStatement(statement);
        // compute the length of the array
        int len = getParseStatementLength(statement);
        switch(type) {
            case 1:
                narrator = narrator->getRelative(arr, 0, len);
                break;
            case 2:
                narrator->describe(arr, 0, len);
                break;
            case 3:
                cout << narrator->info() << "\n";
                break;
        }
        delete[] arr;
    }
    return 0;
}
