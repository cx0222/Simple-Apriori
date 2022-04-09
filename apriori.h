//
// Created by 陈玄 on 2022/4/9.
//

#ifndef UNTITLED121_APRIORI_H
#define UNTITLED121_APRIORI_H

#include "pprint.h"

using namespace std;

int support(vector<vector<int>> *, vector<int> *);

bool combine(vector<int> *, vector<int> *, vector<int> *, int);

vector<vector<int>> generate(vector<vector<int>> *, vector<vector<int>> *, int, int, int);

vector<vector<int>> apriori(vector<vector<int>> *, int, int);

int support(vector<vector<int>> *data, vector<int> *ind) {
    int sup = 0;
    bool is_subset;
    for (auto i: *data) {
        is_subset = true;
        for (int j = 0; j < ind->size(); j++) {
            if (*(ind->data() + j)) {
                if (!*(i.data() + j)) { is_subset = false; }
            }
            if (!is_subset) { break; }
        }
        if (is_subset) { sup++; }
    }
    return sup;
}

bool combine(vector<int> *set1, vector<int> *set2, vector<int> *res, int k_gen) {
    int ind;
    int count = 0;
    for (int i = 0; i < res->size(); i++) {
        ind = *(set1->data() + i) or *(set2->data() + i);
        if (ind) {
            *(res->data() + i) = ind;
            count++;
        }
    }
    return count == k_gen;
}

vector<vector<int>>
generate(vector<vector<int>> *data, vector<vector<int>> *candidate_set, int k_gen, int min_sup, int dim) {
    vector<vector<int>> new_set;
    for (int i = 0; i < candidate_set->size(); i++) {
        for (int j = i + 1; j < candidate_set->size(); j++) {
            vector<int> res(dim);
            combine((candidate_set->data() + i), (candidate_set->data() + j), &res, k_gen);
            if (!count(new_set.begin(), new_set.end(), res)) {
                if (support(data, &res) + 1 > min_sup) {
                    new_set.push_back(res);
                }
            }
        }
    }
    return new_set;
}

vector<vector<int>> apriori(vector<vector<int>> *data, int min_sup, int dim) {
    vector<vector<int>> init;
    for (int i = 0; i < dim; i++) {
        vector<int> tmp(dim);
        *(tmp.data() + i) = 1;
        init.push_back(tmp);
    }

    int k_gen = 1;
    bool continue_loop_flag = true;
    vector<vector<int>> loop = init;
    vector<vector<int>> previous;

    while (continue_loop_flag) {
        k_gen++;
        pprint(&loop);
        previous = loop;
        loop = generate(data, &loop, k_gen, min_sup, dim);
        continue_loop_flag = loop.size() > 1;
        if (loop.empty()) {
            pprint(&previous);
            return previous;
        }
    }

    return loop;
}

#endif // UNTITLED121_APRIORI_H
