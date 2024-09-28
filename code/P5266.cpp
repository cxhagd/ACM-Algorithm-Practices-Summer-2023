#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> db; // 数据库简称为 db
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int op;
        cin >> op;
        string name;
        int score;

        switch (op) {
            case 1: // 插入或修改
                cin >> name >> score;
                db[name] = score;
                cout << "OK" << endl;
                break;
            case 2: // 查询
                cin >> name;
                if(db.find(name) == db.end()) cout << "Not found" << endl;
                else cout << db[name] << endl;
                break;
            case 3: // 删除
                cin >> name;
                if(db.find(name) == db.end()) cout << "Not found" << endl;
                else {
                    db.erase(name);
                    cout << "Deleted successfully" << endl;
                }
                break;
            case 4: // 汇总
                cout << db.size() << endl;
                break;
        }
    }
    return 0;
}