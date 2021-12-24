/*
parser.h

Copyright (C) 2020-2021 Yassin Achengli <0619883460@uma.es>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

======================================================================
*/

#ifndef PAIRTEX
#define PAIRTEX
#include <string>
#include <iostream>
#include <cmath>

#define E 2.718281828
namespace tex {
	struct Binary{
		double a,b;
		std::string op;
	};
	
	typedef Binary Bin;
	typedef unsigned int uint;
	
	class Bifunc {
		private:
			Bin data;
			Bifunc *childa;
			Bifunc *childb;
		public: 
			/*constructors and destructors*/
			Bifunc(const std::string &form);
			Bifunc(const Bin &d);
			Bifunc(const Bifunc &o);
			~Bifunc(const);
			
			/*methods */
			void appendBin(const Bifunc &o,tex::uint p); // get all the childs and put it as primary child
			Bifunc* getChild() const; // get the pos child in order 
			double eval()const;
			double eval(const double a, const double b) const;			
	};
	/*call makes switch to select the function called*/
	double call(const Bin &s);
	bool checkFunction (const std::string &fun);
	Bifunc * strFunc(const std::string &o);
	bool clear(const std::string &text, const std::string &patterns);
	bool checkPhar(const std::string &p);
}

#endif
