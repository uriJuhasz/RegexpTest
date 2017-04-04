#include "CharSet.h"


namespace regexp {

	CharSet::CharSet()
	{
	}
	
	CharSet::~CharSet()
	{
	}

	bool CharSet::has(Char c) const
	{
		return set[c];
	}

	CharSet CharSet::makeNone()
	{
		return CharSet();
	}
	CharSet CharSet::makeAll()
	{
		BSet s;
		s.set();
		return CharSet(s);
	}
	CharSet CharSet::make(Char c)
	{
		BSet s;
		s.set(c);
		return CharSet(s);
	}
	CharSet CharSet::makeRange(Char c0,Char c1)
	{
		BSet s;
		for (auto i=c0;i<=c1;i++)
			s.set(i);
		return CharSet(s);
	}

	CharSet operator+(const CharSet& a, const CharSet& b) {
		return CharSet(a.set | b.set);
	}
	CharSet operator-(const CharSet& a, const CharSet& b) {
		return CharSet(a.set & ~b.set);
	}
	CharSet operator*(const CharSet& a, const CharSet& b) {
		return CharSet(a.set & b.set);
	}

}//namespace regexp