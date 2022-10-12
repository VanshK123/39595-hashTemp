#include "hash_list.h"

#include<bits/stdc++.h>
using namespace std;

node *_insnode(int key, float value);

// Constructor
hash_list::hash_list()
{
    size = 0;
    head = NULL;
    iter_ptr = NULL;
    
}

// Copy Constructor
hash_list::hash_list(const hash_list &other)
{
     size = 0;
     head = NULL;
     iter_ptr = NULL;
     //recreate new linked_list
     node* cnode = other.head;
    
     while(cnode != NULL)
     {
        insert(cnode->key, cnode->value);
        cnode = cnode->next;
     }
    
}

// Assignment operator
hash_list &hash_list::operator=(const hash_list &other)
{
    
    if(head == other.head){
        return *this;
    }
    
    hash_list Tempobject = hash_list(other);
    node *ptr = NULL;
    ptr = this -> head;
    this -> head = Tempobject.head;
    this -> size = Tempobject.size;
    Tempobject.head= ptr;
    return *this;
   
}

// Insert Node Function
void hash_list::insert(int key, float value)
{
    // Find the head node, set current to head
    node *current = head;
    node *previousNode = head;
    bool hasWritten = false;

    // Check if first, update head if is
    if (current == NULL)
    {
        //// std::cout << "(INSERT) head is null, writing here" << std::endl;
        current = _insnode(key, value);
        head = current;
        size += 1;
        return;
    }

    // Traverse list
    while (current != NULL)
    {

        // If you find a key that matches, update value and bool
        if (current->key == key)
        {
            //// std::cout << "(INSERT) Found duplicate, overwriting" << std::endl;
            current->value = value;
            hasWritten = true;
        }
        if (current != NULL)
        {
            previousNode = current;
        }
        current = current->next;
    }

    // If no values have been updated (new key), make a new node and append to end
    if (hasWritten == false)
    {
        //// std::cout << "(INSERT) Appending node" << std::endl;
        current = _insnode(key, value);
        previousNode->next = current;
        size += 1;
    }

    return;
}

// Get Value Function
std::optional<float> hash_list::get_value(int key) const
{
    node *current = head;
    while (current != NULL)
    {
        // finds
        if (current->key == key)
        {
            // std::cout << "(GETVALUE) Value: " << current->value << std::endl;
            return current->value;
        }
        current = current->next;
    }
    // std::cout << "(GETVALUE) Did not Find" << std::endl;
    return {};
}
node *_insnode(int key, float value)
{
    // create node
    node *newNode = new (node);
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

bool hash_list::remove(int key)
{
    node *current = head;
    node *prev = head;

    if (head != NULL && (head->key == key))
    {
        node *temp = head;
        head = head->next;
        delete temp;
        // std::cout << "(REMOVE) Did remove Head: "<< "Key: " << key  << std::endl;
        size -= 1;
        return true;
    }

    while (current != NULL)
    {
        if (current == NULL)
        {
            // DID NOT FIND TO REMOVE
            //  std::cout << "(REMOVE) Did Not Find: "<< "Key: " << key  << std::endl;
            return false;
        }

        if (current->key == key)
        {
            prev->next = current->next;
            // free current
            delete current;
            // std::cout << "(REMOVE) Did Find: "<< "Key: " << key  << std::endl;
            size -= 1;
            return true;
        }

        prev = current;
        current = current->next;
    }
    // std::cout << "(REMOVE) Did Not Find: "<< "Key: " << key  << std::endl;
    return false;
}

size_t hash_list::get_size() const
{
    // std::cout << size << std::endl;
    return size;
}

hash_list::~hash_list()
{
    node *current;

    while (head != NULL)
    {
        current = head;
        // std::cout << current->key << std::endl;
        head = head->next;
        delete current;
    }

    //// std::cout << "(DESTRUCTOR)  Destruct Finished" << std::endl;
}

/** Dont modify this function for this lab. Leave it as is */
void hash_list::reset_iter() {
    if(head == NULL){
        iter_ptr = NULL;
    }
    iter_ptr = head;
    return;
}

/** Dont modify this function for this lab. Leave it as is */
/**
     * Moves the iterator to the next element. If the iterator points to the last element
     * of the list when this is called the iterator is set to NULL. If the iterator is NULL
     * when this function is called then this function does nothing
     */
void hash_list::increment_iter() {
    if(iter_ptr == NULL){
        return;
    }
    if(iter_ptr->next == NULL){
        iter_ptr = NULL;
        return;
    }
    iter_ptr = iter_ptr->next;
}

/** Dont modify this function for this lab. Leave it as is */
std::optional<std::pair<int *, float *>> hash_list::get_iter_value() {

    if(iter_ptr == NULL){
        return {};
    }

    if(iter_ptr == NULL)
    {
        return {};
    }
    int* ptrkey = &(iter_ptr->key);
    float* ptrvalue = &(iter_ptr->value);


    return std::make_pair(ptrkey, ptrvalue);
}

/** Dont modify this function for this lab. Leave it as is */
bool hash_list::iter_at_end() {
    if(iter_ptr == NULL){
        return true;
    }
    return false;
}
