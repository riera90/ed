#ifndef __AUXILIAR_FUNCTIONS__
#define __AUXILIAR_FUNCTIONS__

#define FLOAT_NEAR_PRESICION 0.03

#include <cmath>
#include <string>
#include <regex>

namespace ed
{

	bool near(const float &n1, const float &n2);
	bool isInt(std::string s);
	bool isFloat(std::string s);

}

#endif
