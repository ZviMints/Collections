
#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <iostream>

namespace itertools {
template <typename T1, typename T2> class chain {
        private:
        T1 a; // range(5,8) for Example
        T2 b; // range(9,10) for Example
        
        public:
        chain(const T1& r1,const T2& r2) : a(r1), b(r2) {}

       struct iterator {        
        iterator(T1& a, T2& b) 
        : t1_begin(a.begin()), t1_end(a.end()),
          t2_begin(b.begin()), t2_end(b.end()) {} 
        
        iterator(T1& a, T2& b, bool) 
        : t1_begin(a.end()), t1_end(a.end()),
          t2_begin(b.end()), t2_end(b.end()) {} 
          
        iterator& operator++() { 
        if(t1_begin != t1_end) ++ t1_begin;
        else ++ t2_begin;
        return *this; 
        }

        auto operator*() { 
        if(t1_begin != t1_end) return *t1_begin;
        else return *t2_begin;
        } 

        bool operator!=(const iterator& iter) {
            if(t1_begin != iter.t1_begin || t2_begin != iter.t2_begin) return true;
            else return false;
            // == (Negation)
            // t1_begin == iter.t1_begin && t2_begin == iter.t2_begin
        }
       
        private:
        decltype(a.begin()) t1_begin;
        decltype(a.end()) t1_end;

        decltype(b.begin()) t2_begin;
        decltype(b.end()) t2_end;
       
     }; // End Struct Iterator
        
        iterator begin() { return iterator(a,b); }
        iterator end() { return iterator(a,b,false); }
    };
}

#endif