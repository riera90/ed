#include "auxiliarFunctions.hpp"


bool ed::near(const float &n1, const float &n2)
{
	return FLOAT_NEAR_PRESICION > abs(n1 - n2);
}
