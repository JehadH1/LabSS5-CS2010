#include <iostream>
#include <vector>
using namespace std;



template <class T>
using ELEM = vector<T>;

template <class T>
using VEC = vector<ELEM<T>>;

template <class T>
using action_t = T(*) (int);

template <class T>
using pred_t = bool (*) (T);

template <class T>
using map_t = T(*) (T, T);

void lines() {
    cout << string(10, '*')<< '\n';
}

template <class T> void printElem(const ELEM<T>& v) {
    cout << "(";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << ")";
}

template <class T> void initVec(VEC<T>& v, ELEM<T>&& cons) {
    v.resize(1, vector<int>(cons.size()));
        for(int i  = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++) {
                v[i][j] = cons[j];
            }
}

template <class T> void printVec(VEC<T>& v) {
    for (const auto& e : v) {
        printElem(e);
        cout << endl; 
    }

}

template <class T> VEC<T> generate(int N, action_t<T> f);

template<class T> VEC<T> zip(VEC<T>& v, VEC<T>& w) {
    
}

template<class T> VEC<T> filter(VEC<T>& v, pred_t<T> f);

template<class T> VEC<T> map(VEC<T>& v, action_t<T> f);

template<class T> ELEM<T> reduce(VEC<T>& v, map_t<T> f, ELEM<T> ident);

int main() {
    VEC<int> v;
    initVec(v, ELEM<int>{1, 2, 3, 4});

    VEC<int> w;
    initVec(w, ELEM<int>{-1, 3, -3, 4});

    printVec(v);
    lines();

    printVec(w);
    lines();


}
