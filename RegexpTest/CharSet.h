#pragma once
#include <bitset>
using namespace std;

namespace regexp{
	typedef char Char;

	
	class CharSet final
	{
	public:
		~CharSet();

		bool has(Char c) const;

		static CharSet make(Char c);
		static CharSet makeAll();
		static CharSet makeNone();
		static CharSet makeRange(Char c0,Char c1);
	private:
		typedef bitset<256> BSet;
		CharSet();
		CharSet(const BSet& set) : set(set) {}
		const BSet set;
		friend CharSet operator+(const CharSet& a, const CharSet& b);
		friend CharSet operator-(const CharSet& a, const CharSet& b);
		friend CharSet operator*(const CharSet& a, const CharSet& b);
	};

CharSet operator+(const CharSet& a, const CharSet& b);
CharSet operator-(const CharSet& a, const CharSet& b);
CharSet operator*(const CharSet& a, const CharSet& b);
}//namespace regexp

