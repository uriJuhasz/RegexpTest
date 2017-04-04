#include "RegExpParser.h"

/*
The parser is a recursive descent parser implementing the following grammar
<RE>    ::=     <union> | <simple-RE>
<union>     ::= <RE> "|" <simple-RE>                              {OrRE}
<simple-RE>     ::=     <concatenation> | <basic-RE>
<concatenation>     ::= <simple-RE> <basic-RE>                    {SeqRE}
<basic-RE>  ::= <star> | <plus> | <elementary-RE>
<star>  ::= <elementary-RE> "*"                                   {StarRE}
<plus>  ::= <elementary-RE> "+"                                   {xx*}
<elementary-RE>     ::= <group> | <any> | <eos> | <char> | <set>
<group>     ::=     "(" <RE> ")"
<any>   ::=     "."                                               {CharSetRE(all)}
//<eos>   ::=     "$"
<char>  ::=     any non metacharacter | "\" metacharacter         {CharSetRE(x)}
<set>   ::=     <positive-set> | <negative-set>
<positive-set>  ::=     "[" <set-items> "]"                       {CharSetRE(xs)}
<negative-set>  ::=     "[^" <set-items> "]"                      {CharSetRE(~xs)}

<set-items>     ::=     <set-item> | <set-item> <set-items>
<set-items>     ::=     <range> | <char>                          
<range>     ::=     <char> "-" <char>                             {CharSet(c0-c1)}
*/


namespace regexp {

	unique_ptr<RegExp> RegExpParser::parse(istream& s) {
		return RegExpParserImp(s).parse();
	}

	class RegExpParserImp {
	public:
		RegExpParserImp(istream& s)
			: s(s)
		{
		}
		unique_ptr<RegExp> parse() {
			return parseRE();
		}

		unique_ptr<RegExp> parseRE() {
			auto r = parseSRE();
			while (tryParse('|'))
				r = make_unique<OrRE>(move(r), move(parseRE()));

		}
		unique_ptr<RegExp> parseSRE();
		bool tryParse(Char c);

		istream& s;
	};


}//namespace regexp 
