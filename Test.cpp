/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;
#include "range.hpp"
#include "chain.hpp"
#include "product.hpp"
#include "zip.hpp"
#include "powerset.hpp"
#include <random>
#include <chrono>
#include "badkan.hpp"

#define COMMA ,
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		
	int i_begin = 5;
	int i_end = 10;
	char c_begin = 'a';
	char c_end = 'z';

	auto r1 = range(i_begin,i_end);
	auto r1_start = r1.begin();
	auto r1_end = r1.end();

	auto r2 = range(c_begin,c_end);
	auto r2_start = r2.begin();
	auto r2_end = r2.begin();

	auto c1 = chain(string("hello"),r2);
	auto c1_start = c1.begin();
	auto c1_end = c1.end();

	auto z1 = zip(r1,r2);
	auto z1_start = z1.begin();
	auto z1_end = z1.end();

	auto p1 = product(r1,r2);
	auto p1_start = p1.begin();
	auto p1_end = p1.end();


	auto ps = powerset(r1);
	auto ps_start = ps.begin();
	auto ps_end = ps.end();

	
	auto ps2 = powerset(string("PlzlOO"));
	auto ps2_start = ps2.begin();
	auto ps2_end = ps2.end();
	
	
	testcase.setname("Range Test"); // Range TEST
	int counter = 0;
	for(int p : r1 ) {
	testcase.CHECK_OUTPUT(p, std::to_string(i_begin + counter++));    
	}

	counter = 0;
	std::string ans = "abcdefghijklmnopqrstuvwxy";
	std::string curr = "";
	for(char p : r2 ) {
	curr += p;  
	}
	testcase.CHECK_OUTPUT(curr, ans);  

	testcase.setname("Chain Test"); // Chain TEST
	
	counter = 0;
	ans = "helloabcdefghijklmnopqrstuvwxy";
	curr = "";
	for(char p : c1 ) {
	curr += p;  
	}
	testcase.CHECK_OUTPUT(curr, ans);  

	testcase.setname("Zip Test"); // Zip TEST
	
	counter = 0;
	int counter2 = 0;
	for(auto p : z1 ) {
	testcase.CHECK_OUTPUT(p, std::to_string(*r1.begin() + counter++) + "," + (char)(*r2.begin() + counter2++));  
	}


	testcase.setname("Product Test"); // Product TEST
	
	counter = 0;
	counter2 = 0;
	for(auto p : p1 ) {
	testcase.CHECK_OUTPUT(p, std::to_string(*r1.begin() + counter) + "," + (char)(*r2.begin() + counter2));  
	if(*r2.begin() + counter2 + 1!= *r2.end()) { counter2++; }
	else { counter++; counter2 =0; }
	}

	testcase.setname("Product Test"); // Powerset TEST
	
	counter = 0;
	ans = "{}{5}{6}{5,6}{7}{5,7}{6,7}{5,6,7}{8}{5,8}{6,8}{5,6,8}{7,8}{5,7,8}{6,7,8}{5,6,7,8}{9}{5,9}{6,9}{5,6,9}{7,9}{5,7,9}{6,7,9}{5,6,7,9}{8,9}{5,8,9}{6,8,9}{5,6,8,9}{7,8,9}{5,7,8,9}{6,7,8,9}{5,6,7,8,9}";
	curr = "";
	for(auto p : ps ) {
	curr += p;  
	}
	testcase.CHECK_OUTPUT(curr, ans);  

	
	counter = 0;
	ans = "{}{P}{l}{P,l}{z}{P,z}{l,z}{P,l,z}{l}{P,l}{l,l}{P,l,l}{z,l}{P,z,l}{l,z,l}{P,l,z,l}{O}{P,O}{l,O}{P,l,O}{z,O}{P,z,O}{l,z,O}{P,l,z,O}{l,O}{P,l,O}{l,l,O}{P,l,l,O}{z,l,O}{P,z,l,O}{l,z,l,O}{P,l,z,l,O}{O}{P,O}{l,O}{P,l,O}{z,O}{P,z,O}{l,z,O}{P,l,z,O}{l,O}{P,l,O}{l,l,O}{P,l,l,O}{z,l,O}{P,z,l,O}{l,z,l,O}{P,l,z,l,O}{O,O}{P,O,O}{l,O,O}{P,l,O,O}{z,O,O}{P,z,O,O}{l,z,O,O}{P,l,z,O,O}{l,O,O}{P,l,O,O}{l,l,O,O}{P,l,l,O,O}{z,l,O,O}{P,z,l,O,O}{l,z,l,O,O}{P,l,z,l,O,O}";
	curr = "";
	for(auto p : ps2 ) {
	curr += p;  
	}
	testcase.CHECK_OUTPUT(curr, ans);  

   ;
   	grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

