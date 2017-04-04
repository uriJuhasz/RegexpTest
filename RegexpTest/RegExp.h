#pragma once
#include "CharSet.h"
#include <memory>

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
		SeqRE(unique_ptr<RegExp> e0, unique_ptr<RegExp> e1) : e0(move(e0)), e1(move(e1)) {}
		const unique_ptr<RegExp> e0;
		const unique_ptr<RegExp> e1;
	};
	class OrRE final : public RegExp {
	public:
		OrRE(unique_ptr<RegExp> e0, unique_ptr<RegExp> e1) : e0(move(e0)), e1(move(e1)) {}
		const unique_ptr<RegExp> e0;
		const unique_ptr<RegExp> e1;
	};
	class StarRE final : public RegExp {
	public:
		StarRE(unique_ptr<RegExp> e) : e(move(e)) {}
		const unique_ptr<RegExp> e;
	};

}//namespace regexp