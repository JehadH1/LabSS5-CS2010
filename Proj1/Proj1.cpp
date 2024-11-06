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
	cout << string(10, '*') << '\n';
}

template <class T> void printElem(const ELEM<T>& v) {
	if (v.size() > 1) cout << "(";
	for (auto e : v)
		cout << e << " ";
	if (v.size() > 1) cout << ")";
}

template <class T> void initVec(VEC<T>& v, ELEM<T>&& cons) {
	v.resize(cons.size(), vector<int>(1));
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++) {
			v[i][j] = cons[i];
		}
}

template <class T> void printVec(VEC<T>& v) {
	int i = 0;
	cout << "[";
	for (const auto& e : v) {
		i++;
		printElem(e);
		if (i < v.size()) cout << ", ";
	}
	cout << "]";
	cout << "\n";
}

template <class T> VEC<T> generate(int N, action_t<T> f) {
	VEC<int> newVec;
	newVec.resize(N, vector<int>(1));
	int square = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++) {
			square = f(i);
			newVec[i][j] = square;
		}
	}
	return newVec;
}

int f(int i) {
	return i * i;
}

template<class T> VEC<T> zip(VEC<T>& v, VEC<T>& w) {
	int len = v.size();
	int width = v[0].size() * 2;

	VEC<T> newVec;
	newVec.resize(len, vector<int>(width));

	for (int i = 0; i < len; i++) {
		int v_index = 0;
		int w_index = 0;
		for (int j = 0; j < width; j++) {
			if (j < (width / 2)) {
				newVec[i][j] = v[i][v_index];
				v_index++;
			}
			if (j >= (width / 2)) {
				newVec[i][j] = w[i][w_index];
				w_index++;
			}
		}
	}
	return newVec;
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

	VEC<int> z = zip(v, w);
	printVec(z);
	lines();

	VEC<int> x = zip(z, z);
	printVec(x);
	lines();

	VEC<int> a = generate(10, f);
	printVec(a);
	lines();
}