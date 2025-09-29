#include <iostream>
using namespace std;

int age;

int main(){
    cin >> age;

    cout << (age >= 6 && age <= 11)*590 + (age >= 12 && age <= 17)*790 + (age >= 18 && age <= 59)*890 + (age >= 60)*399;
}
