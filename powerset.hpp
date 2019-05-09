
#ifndef POWERSET_HPP
#define POWERSET_HPP

#include <iostream>
#include <vector> 
#include <cmath>

namespace itertools {
template <typename T> class powerset {
        
        private:
        T _object; // Range (1,5) for example

        public:        
        powerset(const T& _object) :_object(_object) {} 
        
    struct iterator {
        iterator(T& _object,int n, int N) : it_begin(_object.begin()), n(n), N(N) {}
        iterator& operator++(){  ++N; return *this; } 
        std::string operator*() { 
        std::string ans;
        ans += "{";
        for(int j=0; j<n; j++)
        {
            if( N & (1<<j)) {
                decltype(*(_object.begin())) at_j = At(j);
                if((at_j >= 'a' && at_j <= 'z') ||( at_j >= 'A' && at_j <='Z'))
                    ans += at_j;
                else 
                    ans += std::to_string(at_j);
                ans += ",";
            }
        }
        ans = ans.substr(0,ans.find_last_of(","));
        ans += "}";
        return ans;
        } 
        
        bool operator!=(const iterator& iter) { return N != iter.N; }
        
        private:
        decltype(_object.begin()) it_begin;
        int n; // Size of the total _ _ _ _ 
        int N; // pow of n

       decltype(*(_object.begin())) At(int j) {
        decltype(_object.begin()) temp = it_begin;
            for(int i=0; i<j; i++)
             ++temp;
             return *temp;
        }


     }; // End Struct Iterator
        
        iterator begin() { return iterator(_object,findSize(),0); }
        iterator end() { return iterator(_object,findSize(),pow(2,findSize())); }
       
        int findSize() {
            int counter = 0;
            for(auto p : _object) counter++;
            return counter;
        }
    };
} // End Namespace 'itertools'

#endif