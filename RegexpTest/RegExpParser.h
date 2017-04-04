#pragma once
#include <memory>
#include <istream>
#include "RegExp.h"
using namespace std;

namespace regexp {
	class RegExpParser
	{
	public:
		static unique_ptr<RegExp> parse(istream& s);
	};
}//namespace regexp 
