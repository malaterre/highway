#include "hwy/highway.h"
#include "hwy/contrib/math/math-inl.h"

#include <cstdio>
#include <cmath>

int main()
{
#if 1
	//const double value = 9.8046570862201476e-17;
	//const double value = 5.526720574244119e-20;
	const double value = 5.5968112995194757e-20;
	hwy::N_EMU128::Simd<double, 2u, 0> a;
       	hwy::N_EMU128::Vec128<double, 2u> b = hwy::N_EMU128::Set(a, value);
	hwy::N_EMU128::Vec128<double, 2> ret = hwy::N_EMU128::Log1p(a, b);
	const double actual = hwy::N_EMU128::GetLane(ret);
	const double expected = std::log1p( value );
	std::printf("%.17g vs %.17g\n", actual, expected );
#else
	//const double value = 0.28195148706436157; // clang-16
	const double value = 6.0400722645681526e-08;
	hwy::N_EMU128::Simd<float, 4u, 0> a;
       	hwy::N_EMU128::Vec128<float, 4u> b = hwy::N_EMU128::Set(a, value);
	hwy::N_EMU128::Vec128<float, 4> ret = hwy::N_EMU128::Log1p(a, b);
	const double actual = hwy::N_EMU128::GetLane(ret);
	const double expected = std::log1p( value );
	std::printf("%.17g vs %.17g\n", actual, expected );
#endif
	return 0;
}
