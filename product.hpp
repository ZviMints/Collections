#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>

namespace itertools {

template <typename T1, typename T2> class product {
        private:
        T1 a; // range(5,8) for Example
        T2 b; // range(9,10) for Example
        
        public:
        product(const T1& r1,const T2& r2) : a(r1), b(r2) {}

    class iterator {  
      
      template <typename V, typename K>
      class MyPair {
      V v;
      K k;
      public:
      MyPair(const V& v, const K& k) : v(v), k(k) {}
      MyPair() {}

      friend std::ostream& operator<<(std::ostream& os,const MyPair<V,K>& pair)
      {
        return os << pair.v << "," << pair.k;
      }
      }; // End Class MyPair
        decltype(a.begin()) t1_begin;
        decltype(a.end()) t1_end;

        decltype(b.begin()) running_pointer;
        decltype(b.begin()) t2_begin;
        decltype(b.end()) t2_end;
       
        public:      
        iterator(T1& a, T2& b) 
        : t1_begin(a.begin()), t1_end(a.end()),
          running_pointer(b.begin()), t2_begin(b.begin()), t2_end(b.end()) {} 
        
        iterator(T1& a, T2& b, bool) 
        : t1_begin(a.end()), t1_end(a.end()),
          running_pointer(b.end()), t2_begin(b.end()), t2_end(b.end()) {} 
          
        iterator& operator++() {
        ++running_pointer;
        if(!(running_pointer != t2_end)) 
        {
            ++ t1_begin;
            running_pointer = t2_begin;
        }
        return *this; 
        }

        MyPair<decltype(*t1_begin),decltype(*t2_begin)> operator*() { 
        return MyPair<decltype(*t1_begin),decltype(*running_pointer)> (*t1_begin,*running_pointer);
        } 

        bool operator != (const iterator& iter) {
            if( t1_begin != iter.t1_begin ) return true;
            else return false;
            // == (Negation)
            // t1_begin == iter.t1_begin || t2_begin == iter.t2_begin
        }  
     }; // End class Iterator
        
        iterator begin() { return iterator(a,b); }
        iterator end() { return iterator(a,b,false); }

    };
} // end namespace


#endif