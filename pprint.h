//
// Created by 陈玄 on 2022/4/9.
//

#ifndef UNTITLED121_PPRINT_H
#define UNTITLED121_PPRINT_H

using namespace std;

inline void pprint(vector<int> *);

inline void pprint(vector<vector<int>> *);

inline void pprint(vector<int> *v) {
    for (auto i: *v) {
        cout << "\t" << i;
    }
    cout << "\n";
}

inline void pprint(vector<vector<int>> *u) {
    cout << "[Count] " << u->size() << "\n";
    for (auto i: *u) {
        pprint(&i);
    }
}

#endif //UNTITLED121_PPRINT_H
