#ifndef SET_HPP
#define SET_HPP

#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "tree_iterator.hpp"
#include "red_black_tree.hpp"
#include <memory>

namespace ft
{


template < class Key,                        // set::key_type/value_type
           class Compare = ft::less<Key>,        // set::key_compare/value_compare
           class Alloc = std::allocator<Key>      // set::allocator_type
           >
class set
{
public:
	typedef Key												key_type;
	typedef Key												value_type;
	typedef size_t											size_type;
	typedef ptrdiff_t										difference_type;
	typedef Compare											key_compare;
	typedef Compare											value_compare;
	typedef Alloc											allocator_type;
	typedef value_type&										reference;
	typedef const value_type&								const_reference;
	typedef typename Alloc::pointer							pointer;
	typedef typename Alloc::const_pointer					const_pointer;
	typedef typename ft::tree_const_iterator<value_type>	iterator;
	typedef typename ft::tree_const_iterator<value_type>	const_iterator;
	typedef	ft::reverse_iterator<iterator>					reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;


	explicit set (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		:
			_comp(comp),
			_alloc(alloc),
			_tree(value_compare(), alloc)
		{}

template <class InputIterator>
	set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
	:
		_comp(comp),
		_alloc(alloc),
		_tree(value_compare(), alloc)
	{
		_tree.insert(first, last);
	}

	set (const set& x)
	:
		_comp(x._comp),
		_alloc(x._alloc),
		_tree(x._tree)
	{}
	~set () {}
	set& operator= (const set& x)
	{
		if (this == &x)
			return (*this);
		this->_tree = x._tree;
		return (*this);
	}

// Iterators:
	iterator				begin() { return (_tree.begin()); }
	const_iterator			begin() const  { return (_tree.begin()); }
	iterator				end() { return (_tree.end()); }
	const_iterator			end() const { return (_tree.end()); }
	reverse_iterator		rbegin() { return (_tree.rbegin()); }
	const_reverse_iterator	rbegin() const { return (_tree.rbegin()); }
	reverse_iterator		rend() { return (_tree.rend()); }
	const_reverse_iterator	rend() const { return (_tree.rend()); }


// Capacity:
	bool					empty() const { return (this->_tree.empty()); }
	size_type				size() const { return (this->_tree.size()); }
	size_type				max_size() const { return (_tree.max_size()); }


// Modifiers:
	pair<iterator,bool>		insert (const value_type& val) { return (_tree.insert(val)); }
	iterator				insert (iterator position, const value_type& val)
	{ (void)position; return (_tree.insert(val).first); }
template <class InputIterator>
	void					insert (InputIterator first, InputIterator last)
	{ return (_tree.insert(first, last)); }

	void					erase (iterator position) { return (_tree.erase(position)); }
	size_type				erase (const value_type& k){ return (_tree.erase(k)); }
	void					erase (iterator first, iterator last)
	{ return (_tree.erase(first, last)); }

	void					swap (set& x) { return (_tree.swap(x._tree)); }
	void					clear() { return (_tree.clear()); }

// Observers:
	key_compare				key_comp() const { return (key_compare()); }
	value_compare			value_comp() const { return (value_compare()); }
// Operations:
	iterator				find (const value_type& k) const { return (_tree.find(k)); }
	size_type				count (const value_type& k) const { return (_tree.count(k)); }
	iterator				lower_bound (const value_type& k) const
	{
		iterator	it1 = this->begin();
		iterator	it2 = this->end();
		while (it1 != it2)
		{
			if (_comp(*it1, k) == false)
				break;
			++it1;
		}
		return (it1);
	}
	iterator				upper_bound (const value_type& k) const
	{
		iterator	it1 = this->begin();
		iterator	it2 = this->end();
		while (it1 != it2)
		{
			if (_comp(k, *it1) == true)
				break;
			++it1;
		}
		return (it1);
	}
	pair<iterator,iterator>	equal_range (const value_type& k) const
	{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
	allocator_type 			get_allocator() const
	{ return (allocator_type()); }


private:
	key_compare 	_comp;
	allocator_type	_alloc;
	red_black_tree<value_type, key_compare>	_tree;

};

template< class Key, class Compare, class Alloc >
void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs )
{ lhs.swap(rhs); }

template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{ return !(lhs == rhs); }
template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{ return (!(rhs < lhs)); }
template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{ return (rhs < lhs); }
template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{ return (!(lhs < rhs)); }
}

#endif
