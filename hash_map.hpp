#include <bits/stdc++.h>
using namespace std;
#include "hash_map.h"
#include <cmath>

int hashing_function(int value, int capacity);

hash_map::hash_map(size_t capacity)
{
    _size = 0;
    _capacity = capacity;
    _head = new hash_list[_capacity];
    for(size_t i = 0; i < _capacity; i++)
    {
        _head[i] = hash_list();
    }
}

//
hash_map::hash_map(const hash_map &other)
{
    
    // create empty hashmap
    _size = 0;
    _capacity = other._capacity;
    _head = new hash_list[_capacity];
    for(size_t i = 0; i < _capacity; i++)
    {
        _head[i] = other._head[i];
    }
    _size = other._size;
    return;
}

hash_map &hash_map::operator=(const hash_map &other)
{
    if(this == &other){
        return *this;
    }
    _capacity = other._capacity;
    _size = other._size;
    for(size_t i = 0; i < _capacity; i++)
    {
        _head[i] = other._head[i];
    }
    return *this;
}

void hash_map::insert(int key, float value)
{
    int i = hashing_function(key, _capacity); // get index
    _size -= _head[i].get_size();
    _head[i].insert(key, value);
    _size += _head[i].get_size();
}

std::optional<float> hash_map::get_value(int key) const
{
    int i = hashing_function(key, _capacity); // get index
    return _head[i].get_value(key);
}

bool hash_map::remove(int key)
{
    int i = hashing_function(key, _capacity);
    _size -= _head[i].get_size();
    bool isSuccessful = _head[i].remove(key);
    _size += _head[i].get_size();
    return isSuccessful;
}

size_t hash_map::get_size() const
{
    return _size;
}


size_t hash_map::get_capacity() const
{
    return _capacity;
}

void hash_map::get_all_keys(int *keys)
{   int count = 0;
    for (size_t i = 0; i < _capacity; i++)
    {   
_head[i].reset_iter();
        while (! _head[i].iter_at_end())
        {   
            keys[count] = * _head[i].get_iter_value().value().first;
            _head[i].increment_iter();
            count++; 
        }
        
    }
}


void hash_map::get_bucket_sizes(size_t * buckets)
{
    for (size_t i = 0; i < _capacity; i++)
    {
        buckets[i] = _head[i].get_size();
    }
    return;
}

hash_map::~hash_map()
{
    delete[] _head ;
}

// this is the hashing function
int hashing_function(int value, int capacity)
{
    return (int(abs(value)) % (capacity));
}