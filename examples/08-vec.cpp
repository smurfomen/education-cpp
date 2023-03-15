#pragma once
#include <stdexcept>
#include <algorithm>
template <typename T>
class vec
{
	T* m_data;
	size_t m_data_size;
	size_t m_count;

public:
	vec(std::initializer_list<T>&& il) : vec()
	{
		reallocate(il.size());
		std::copy(il.begin(), il.end(), m_data);
		m_count = il.size();
	}

	vec()
		: m_data(nullptr), m_data_size(0), m_count(0)
	{ }

	vec(const vec& rhs) : vec() {
		reallocate(rhs.m_data_size);
		std::copy(rhs.m_data, rhs.m_data + rhs.m_count, m_data);
	}

	vec(vec&& rhs) : vec() {
		std::swap(m_data, rhs.m_data);
		std::swap(m_count, rhs.m_count);
		std::swap(m_data_size, rhs.m_data_size);
	}

	vec& operator=(const vec& rhs) {
		if (this != &rhs) {
			reallocate(rhs.m_data_size);
			std::copy(rhs.m_data, rhs.m_data + rhs.m_count, m_data);
		}

		return *this;
	}

	vec& operator=(vec&& rhs) {
		if (this != &rhs) {
			std::swap(m_data, rhs.m_data);
			std::swap(m_count, rhs.m_count);
			std::swap(m_data_size, rhs.m_data_size);
		}

		return *this;
	}

	virtual ~vec() {
		if (m_data)
			delete[] m_data;
	}

	T at(int index) const {
		return operator[](index);
	}

	T& operator[](int index) const& {
		if (index >= m_count || index < 0)
			throw std::out_of_range("index out of range");

		return m_data[index];
	}

	T& operator[](int) && = delete;

	void push_back(T&& value) {
		insert(std::forward<T>(value), m_count);
	}

	void push_front(T&& value) {
		insert(std::forward<T>(value), 0);
	}

	void insert(T&& value, int index) {
		if (index > m_count || index < 0)
			throw std::out_of_range("index out of range");

		if (is_full())
			reallocate(std::max<int>(m_data_size, 1) * 2);

		for (int i = m_count - 1; i >= index; --i) {
			m_data[i + 1] = m_data[i];
		}

		m_data[index] = std::forward<T>(value);
		m_count++;
	}

	void clear() {
		m_count = 0;
	}

	size_t size() const {
		return m_count;
	}

	size_t capacity() const {
		return m_data_size;
	}

	T pop_back() {
		if (!m_count)
			throw std::out_of_range("tryed pop element from empty collecton");

		return m_data[--m_count];
	}

	T pop_front() {
		if (!m_count)
			throw std::out_of_range("tryed pop element from empty collecton");

		T tmp = m_data[0];
		for (int i = 1; i < m_count; ++i) {
			m_data[i - 1] = m_data[i];
		}

		m_count--;
		return tmp;
	}

private:
	bool is_full() {
		return m_count == m_data_size;
	}

	T* reallocate(int new_size) {
		if (!new_size)
			return m_data;

		T* tmp = new T[new_size];
		if (m_data) {
			m_count = std::min<size_t>(m_count, new_size);
			std::copy(m_data, m_data + m_count, tmp);
			delete[] m_data;
		}
		else
			m_count = 0;

		m_data = tmp;
		m_data_size = new_size;

		return tmp;
	}
};


