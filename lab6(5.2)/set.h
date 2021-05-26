#pragma once

#include <iterator>
#include <iostream>
#include <initializer_list>

template <typename T>
class Set
{
public:
	Set();

	Set(const std::initializer_list<T>& list);

	class Iterator;

	struct Node;

	Iterator begin();

	Iterator end();

	void insert(const T value);

	void erase(const T value);

	int size();

	bool empty();

	void clear();

	void show_set();

	T& next(const T value);

	T& previous(const T value);

	T& find(const T value);

	~Set();

private:
	Node* m_root_;

	int m_size_;

	Node* m_insert_(Node* x, T value, Node* next = nullptr, Node* previous = nullptr);

	Node* m_erase_(Node* x, T value);

	Node* m_find_(Node* x, T value);

	Node* m_find_min_(Node* x);

	Node* m_erase_min_(Node* x);

	void m_clear_(Node* x);

	void m_show_set_(Node* x);

	Node* m_next_(const T value);

	Node* m_previous_(const T value);

	int m_height_(Node* cur);

	int m_balance_factor_(Node* cur);

	void m_fix_height_(Node* cur);

	Node* m_rotate_left_(Node* x);

	Node* m_rotate_right_(Node* x);

	Node* m_balance_(Node* x);
};

template <typename T>
Set<T>::Set()
{
	m_root_ = nullptr;
	m_size_ = 0;
}

template <typename T>
Set<T>::Set(const std::initializer_list<T>& list)
{
	for (auto value : list) {
		this->insert(value);
	}
}

template <typename T>
class Set<T>::Iterator : std::iterator<std::bidirectional_iterator_tag, T>
{
public:
	Iterator(Set* tree, Node* other = NULL)
	{
		this->object = other;
		this->tree = tree;
	}

	T& operator*()
	{
		return this->object->key;
	}

	T* operator->()
	{
		return &(this->object->key);
	}

	Iterator& operator=(const Iterator& it)
	{
		this->object = it.object;
		return *this;
	}

	Iterator& operator++()
	{
		this->object = this->object->next;
		return *this;
	}

	Iterator& operator--()
	{
		this->object = this->object->previous;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		this->object = this->object->next;
		return temp;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		this->object = this->object->previous;
		return temp;
	}

	bool operator!=(const Iterator& it)
	{
		return this->object != it.object;
	}

	bool operator==(const Iterator& it)
	{
		return this->object == it.object;
	}

private:
	Node* object;
	Set* tree;
};

template <typename T>
struct Set<T>::Node
{
	Node(const T value = T(), Node* next = nullptr, Node* previous = nullptr)
	{
		this->key = value;
		this->right = nullptr;
		this->left = nullptr;
		this->next = next;
		this->previous = previous;
		this->height = 1;
	}
	Node(const Node& other)
	{
		this->key = other.key;
		this->right = other.right;
		this->left = other.left;
		this->next = other.next;
		this->previous = other.previous;
		this->height = other.height;
	}
	T key;
	Node* right;
	Node* left;
	Node* next;
	Node* previous;
	int height;
};

template <typename T>
typename Set<T>::Iterator Set<T>::begin()
{
	if (!m_root_)
		throw std::domain_error("no item found for the given key");
	Node* x = m_root_;
	while (x->left)
		x = x->left;
	Iterator* it = new Iterator(this, x);
	return *it;
}

template <typename T>
typename Set<T>::Iterator Set<T>::end()
{
	if (!m_root_)
		throw std::domain_error("no item found for the given key");
	Node* x = m_root_;
	while (x->right)
		x = x->right;
	Iterator* it = new Iterator(this, x);
	return *it;
}

template <typename T>
void Set<T>::insert(const T value)
{
	m_root_ = m_insert_(m_root_, value);
}

template <typename T>
void Set<T>::erase(const T value)
{
	m_root_ = m_erase_(m_root_, value);
}

template <typename T>
int Set<T>::size()
{
	return m_size_;
}

template <typename T>
bool Set<T>::empty()
{
	if (m_root_)
		return false;
	return true;
}

template <typename T>
void Set<T>::clear()
{
	m_clear_(m_root_);
}

template <typename T>
void Set<T>::show_set()
{
	m_show_set_(m_root_);
}

template <typename T>
T& Set<T>::next(const T value)
{
	Node* x = m_find_(m_root_, value);
	return x->next->key;
}

template <typename T>
T& Set<T>::previous(const T value)
{
	Node* x = m_find_(m_root_, value);
	return x->node->key;
}

template <typename T>
T& Set<T>::find(const T value)
{
	Node* temp = m_find_(m_root_, value);
	return temp->key;
}

template <typename T>
Set<T>::~Set()
{
	if (m_root_)
		this->clear();
}

template <typename T>
typename Set<T>::Node* Set<T>::m_insert_(Node* x, T value, Node* next, Node* previous)
{
	if (!x) {
		++m_size_;
		Node* temp = new Node(value, next, previous);
		if (next)
			next->previous = temp;
		if (previous)
			previous->next = temp;
		return temp;
	}
	if (value > x->key) {
		x->right = m_insert_(x->right, value, next, x);
	}
	else {
		x->left = m_insert_(x->left, value, x, previous);
	}
	return m_balance_(x);
}

template <typename T>
typename Set<T>::Node* Set<T>::m_erase_(Node* x, T value)
{
	if (!x)
		throw std::domain_error("no item found for the given key");
	else if (value > x->key)
		x->right = m_erase_(x->right, value);
	else if (value < x->key)
		x->left = m_erase_(x->left, value);
	else {
		--m_size_;
		Node* y = x->left;
		Node* z = x->right;
		if (z) {
			Node* min = m_find_min_(z);
			min->right = m_erase_min_(z);
			min->left = y;
			min->previous = x->previous;
			if (min->previous)
				min->previous->next = min;
			delete x;
			x = nullptr;
			return m_balance_(min);
		}
		else if (y) {
			if (x->next) {
				x->next->previous = y;
				y->next = x->next;
			}
			delete x;
			x = nullptr;
			return y;
		}
		else {
			x->next->previous = x->previous;
			if (x->previous)
				x->previous->next = x->next;
			delete x;
			x = nullptr;
			return nullptr;
		}
	}
	return m_balance_(x);
}

template <typename T>
typename Set<T>::Node* Set<T>::m_find_(Node* x, T value)
{
	if (!x)
		throw std::domain_error("no item found for the given key");
	else {
		if (value == x->key)
			return x;
		else if (value > x->key)
			return m_find_(x->right, value);
		else if (value < x->key)
			return m_find_(x->left, value);
	}
}

template <typename T>
typename Set<T>::Node* Set<T>::m_find_min_(Node* x)
{
	return x->left ? m_find_min_(x->left) : x;
}

template <typename T>
typename Set<T>::Node* Set<T>::m_erase_min_(Node* x)
{
	if (x->left)
		x->left = m_erase_min_(x->left);
	else {
		Node* temp = x->right;
		return temp;
	}
	return m_balance_(x);
}

template <typename T>
void Set<T>::m_clear_(Node* x)
{
	if (!x) {
		throw std::runtime_error("set is empty");
	}
	else {
		if (x->left) {
			m_clear_(x->left);
		}
		if (x->right) {
			m_clear_(x->right);
		}
		delete x;
		x = nullptr;
	}
	m_root_ = nullptr;
	m_size_ = 0;
}

template <typename T>
void Set<T>::m_show_set_(Node* x)
{
	{
		if (!x) {
			std::cout << "set is empty";
		}
		else {
			if (!x->left && !x->right) {
				std::cout << x->key << "\t";
			}
			else {
				if (x->left) {
					m_show_set_(x->left);
				}
				std::cout << x->key << "\t";
				if (x->right) {
					m_show_set_(x->right);
				}
			}
		}
	}
}

template <typename T>
typename Set<T>::Node* Set<T>::m_next_(const T value)
{
	Node* x = m_find_(m_root_, value);
	return x->next;
}

template <typename T>
typename Set<T>::Node* Set<T>::m_previous_(const T value)
{
	Node* x = m_find_(m_root_, value);
	return x->previous;
}

template <typename T>
int Set<T>::m_height_(Node* cur)
{
	return cur ? cur->height : 0;
}

template <typename T>
int Set<T>::m_balance_factor_(Node* cur)
{
	return m_height_(cur->left) - m_height_(cur->right);
}

template <typename T>
void Set<T>::m_fix_height_(Node* cur)
{
	int lHeight = m_height_(cur->left);
	int rHeight = m_height_(cur->right);
	lHeight > rHeight ? cur->height = lHeight + 1 : cur->height = rHeight + 1;
}

template <typename T>
typename Set<T>::Node* Set<T>::m_rotate_left_(Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	y->left = x;
	m_fix_height_(x);
	m_fix_height_(y);
	return y;
}

template <typename T>
typename Set<T>::Node* Set<T>::m_rotate_right_(Node* x)
{
	Node* y = x->left;
	x->left = y->right;
	y->right = x;
	m_fix_height_(x);
	m_fix_height_(y);
	return y;
}

template <typename T>
typename Set<T>::Node* Set<T>::m_balance_(Node* x)
{
	m_fix_height_(x);
	if (m_balance_factor_(x) == -2) {
		Node* y = x->right;
		if (m_balance_factor_(y) > 0)
			x->right = m_rotate_right_(y);
		return m_rotate_left_(x);
	}
	else if (m_balance_factor_(x) == 2) {
		Node* y = x->left;
		if (m_balance_factor_(y) < 0)
			x->left = m_rotate_left_(y);
		return m_rotate_right_(x);
	}
	return x;
}