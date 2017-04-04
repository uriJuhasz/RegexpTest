#pragma once
#include "CharSet.h"
namespace regexp {
	class RegExp
	{
	public:
		RegExp();
		virtual ~RegExp();
	};

	class EmptyRE final : public RegExp {};

	class EpsilonRE final : public RegExp {};
	class CharSetRE final : public RegExp {
	public:
		CharSetRE(CharSet c) : c(c) {}
		const CharSet c;
	};

	class SeqRE final : public RegExp {
	public:
		SeqRE(const RegExp& e0, const RegExp& e1) : e0(e0), e1(e1) {}
		const RegExp& e0;
		const RegExp& e1;
	};
	class OrRE final : public RegExp {
	public:
		OrRE(const RegExp& e0, const RegExp& e1) : e0(e0), e1(e1) {}
		const RegExp& e0;
		const RegExp& e1;
	};
	class StarRE final : public RegExp {
	public:
		StarRE(const RegExp& e) : e(e) {}
		const RegExp& e;
	};

}//namespace regexp