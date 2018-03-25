#include "Provincia_base.hpp"
#include "Provincia_controler.hpp"
#include "Provincia_handler.hpp"

class Provincia : public Provincia_handler{
	public:
		Provincia(std::string name="", int code=0)
		: Provincia_handler(name, code){};
};
