#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>
#include <cstddef>
#include <cstdint>
#include <cassert>

class union_find {
	size_t n;
	std::vector<int32_t> aux; 
public:
	union_find(size_t _n) : n(_n), aux(_n, -1) {}
	size_t which(size_t x) {
		assert(x < n);
		if (aux[x] < 0) return x;
		return aux[x] = which(aux[x]);
	}
	bool same(size_t a, size_t b) {
		a = which(a); b = which(b);
		return a == b;
	}
	bool unite(size_t a, size_t b) {
		a = which(a); b = which(b);
		if (a == b) return false;
		if (-aux[a] < -aux[b]) 
			std::swap(a, b);
		aux[b] = a;
		aux[a] += aux[b];
		return true;
	}
	size_t size(size_t x) {
		return -aux[which(x)];
	} 
};

#endif 