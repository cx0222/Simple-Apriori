//
// Created by 陈玄 on 2022/4/9.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "apriori.h"
#include "pattern.h"
#include "pprint.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> import;
    vector<vector<int>> res;
    vector<vector<int>> pat;

    cout << "[Welcome] Simple-Apriori version 2.0\n";
    cout << "[Author] *cx2020 [2022 Apr 10]\n\n";

    cout << "[Input] Please input file name...\n";
    string filename;
    cin >> filename;

    ifstream file1(filename);
    if (file1.is_open()) {
        string buffer;
        while (getline(file1, buffer, '\n')) {
            vector<int> tmp;
            for (auto i: buffer) {
                if (i == '0') {
                    tmp.push_back(0);
                } else if (i == '1') {
                    tmp.push_back(1);
                }
            }
            import.push_back(tmp);
        }
    } else {
        cout << "[Exception] File cannot be open.\n";
        return 0;
    }

    cout << "[Input] Please input min_sup...\n";
    double min_sup;
    cin >> min_sup;

    cout << "[Input] Please input min_conf...\n";
    double min_conf;
    cin >> min_conf;

    int dim = int(import.data()->size());

    res = apriori(&import, int(min_sup * dim), dim);
    pprint(&res);

    pat = pattern(&import, &res, min_conf);
    pprint(&pat);

    return 0;
}
