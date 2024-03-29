#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node{
    bool trigger = false;
    int left = -1, right = -1;
};

int main(){
    int loop;
    cin >> loop;
    for(int k = 0; k < loop; k++){
        int depth, ball;
        cin >> depth >> ball;

        queue<int> pre;
        vector<node> tree;
        node null;
        tree.push_back(null);
        tree.push_back(null);
        pre.push(1);
        int index = 2;
        for(int i = 2; i <= depth; i++){
            for(int j = 0; j < 1<<(i-1); j++){
                node tmp;
                tree.push_back(tmp);
                pre.push(tree.size()-1);
            }
            for(int j = 0; j < 1<<(i-2); j++){
                int now = pre.front();
                pre.pop();
                tree[now].left = index;
                index++;
                tree[now].right = index;
                index++;
            }
            //cout << "depth build++";
        }

        /*for(int i = 0; i < tree.size(); i++){
            cout << i << " " << tree[i].left << " " << tree[i].right << endl;
        }*/

        int endnum;
        for(int i = 0; i < ball; i++){
            int j = 1;
            for(; tree[j].left != -1;){
                if(tree[j].trigger){
                    tree[j].trigger = false;
                    j = tree[j].right;
                }
                else{
                    tree[j].trigger = true;
                    j = tree[j].left;
                }
            }
            endnum = j;
        }
        cout << endnum << endl;
    }
}
