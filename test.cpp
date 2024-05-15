#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

struct my_struct{
    int x;
    double y;
    string s;
	my_struct(){ // 多寫的預設建構子
		x = 45;
		y = 1.23;
		s = "sdaf";
	}
	my_struct(int a,double b,string c){
		x = a;
		y = b;
		s = c;
	}
};//要有分號

int main(){
    my_struct a;
	my_struct b(45,45.45455,"sdfsd");
    cout<<a.x<<" \n"<<a.y<<" \n"<<a.s<<'\n';
    cout<<b.x<<" \n"<<b.y<<" \n"<<b.s<<'\n';
}