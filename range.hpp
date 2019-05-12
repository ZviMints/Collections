#ifndef RANGE_HPP
#define RANGE_HPP

#include <iostream>

namespace itertools {
template <typename T> class range {
        private:
        T a; // begin Point
        T b; // End Point
        public:
        range(const T& begin,const T& end) : a(begin), b(end) {}
        struct iterator {
        iterator(const T& p) : type(p) {} 
        iterator& operator++(){ ++type; return *this; } 
        T& operator*() { return type; } 
        bool operator!=(const iterator& iter) { return type != iter.type; }
       
        private:
        T type; 
       
     }; // End Struct Iterator
        
        iterator begin() { return iterator(a); }
        iterator end() { return iterator(b); }
    };
} // End Namespace 'itertools'

#endif