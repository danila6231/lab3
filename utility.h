#pragma once

template <class T>
T decrement(T x) {
    return x-1;
}

template <class T>
bool more_then_three(T x) {
    return x > 3;
}

template <class T>
T multiply_items(T x, T y) {
    return x*y;
}

template <class T>
std::vector<T> middle_elements(std::vector<T> v) {
    if (v.size() == 1) {
        return {v[0]};
    }
    else if (v.size() == 0) {
        return {};
    }
    else if (v.size() == 2) {
        return v;
    }
    else {
        int middle_num = v.size() / 2 - ((int)!(v.size()%2));
        std::vector<T> middle = {*(v.begin()+middle_num)};
        std::vector<T> v1(v.begin(), v.begin()+middle_num);
        std::vector<T> v2(v.begin()+middle_num+1, v.end());
        std::vector<T> vl = middle_elements(v1);
        std::vector<T> vr = middle_elements(v2);
        middle.insert(middle.end(), vl.begin(), vl.end());
        middle.insert(middle.end(), vr.begin(), vr.end());
        return middle;
    }
}