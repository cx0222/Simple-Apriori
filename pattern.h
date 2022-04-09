//
// Created by 陈玄 on 2022/4/10.
//

#ifndef UNTITLED121_PATTERN_H
#define UNTITLED121_PATTERN_H

#include <iostream>
#include <vector>
#include "apriori.h"

using namespace std;

void get_subset(vector<vector<int>> *, vector<vector<int>> *, vector<int> *, int);

vector<vector<int>> pattern(vector<vector<int>> *, vector<vector<int>> *, double);

void get_subset(vector<vector<int>> *data, vector<vector<int>> *loop, vector<int> *dataset, int need) {
    vector<int> ind;
    int dim = int(dataset->size());
    for (int i = 0; i < dataset->size(); i++) {
        if (*(dataset->data() + i)) { ind.push_back(i); }
    }
    int n = int(ind.size());
    for (int i = 1; i < (1 << n) - 1; i++) {
        vector<int> tmp(dim);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { tmp[ind[j]] = 1; }
        }
        if (!count(loop->begin(), loop->end(), tmp)) {
            if (support(data, &tmp) + 1 > need) {
                loop->push_back(tmp);
            }
        }
    }
}

vector<vector<int>> pattern(vector<vector<int>> *data, vector<vector<int>> *fp_set, double conf) {
    vector<vector<int>> res;
    for (auto i: *fp_set) {
        int sup = support(data, &i);
        int need = int(conf * sup);
        get_subset(data, &res, &i, need);
    }
    return res;
}

#endif // UNTITLED121_PATTERN_H
