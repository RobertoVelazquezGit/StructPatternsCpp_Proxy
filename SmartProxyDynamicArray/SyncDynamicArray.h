#pragma once
#include <mutex>

#include "DynamicArray.h"
template<typename T>
class SyncDynamicArray
{
	DynamicArray<T> m_DArray;
	mutable std::mutex m_Mtx; // Can be modified even inside const functions
public:
	SyncDynamicArray() = default;
	SyncDynamicArray(std::initializer_list<T> list) :m_DArray{ list } {

	}
	void Add(const T& element) {
		std::lock_guard<std::mutex> lck{ m_Mtx };
		m_DArray.Add(element);
	}
	void Insert(std::size_t index, const T& element) {
		std::lock_guard<std::mutex> lck{ m_Mtx };
		m_DArray.Insert(index, element);
	}
	void Erase(std::size_t index) {
		std::lock_guard<std::mutex> lck{ m_Mtx };
		m_DArray.Erase(index);
	}
	const T& operator[](std::size_t index)const {
		std::lock_guard<std::mutex> lck{ m_Mtx };  // mutable m_Mtx
		return m_DArray[index];
	}
	T& operator[](std::size_t index) {
		std::lock_guard<std::mutex> lck{ m_Mtx };
		return m_DArray[index];
	}
	std::size_t Size()const {
		std::lock_guard<std::mutex> lck{ m_Mtx };
		return m_DArray.Size();
	}
};


