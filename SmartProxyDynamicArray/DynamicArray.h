#pragma once
#include <vector>

template<typename T>
class DynamicArray {
	std::vector<T> m_Vector;
public:
	DynamicArray() = default;
	DynamicArray(std::initializer_list<T> list) :m_Vector{ list } {

	}
	void Add(const T& element) {
		m_Vector.push_back(element);
	}
	void Insert(std::size_t index, const T& element) {
		m_Vector.insert(begin(m_Vector) + index, element);
	}
	void Erase(std::size_t index) {
		m_Vector.erase(begin(m_Vector) + index);
	}
	const T& operator[](std::size_t index)const {
		return m_Vector[index];
	}
	T& operator[](std::size_t index) {
		return m_Vector[index];
	}
	std::size_t Size()const {
		return m_Vector.size();
	}
};

