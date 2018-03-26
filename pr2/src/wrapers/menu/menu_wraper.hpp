#ifndef _WRAPER_MENU_HPP_
#define _WRAPER_MENU_HPP_

#include "Provincia.hpp"
#include "Municipio.hpp"


void comprobarProvinciaVacia(Provincia &provincia);
void cargarProvincia(Provincia &provincia);
void grabarProvincia(Provincia &provincia);
void consultarDatosDeProvincia(Provincia &provincia);
void mostrarMunicipiosDeProvincia(Provincia &provincia);
void modificarDatosDeProvincia(Provincia &provincia);
void borrarTodosLosMunicipiosDeProvincia(Provincia &provincia);
void consultarMunicipioDeProvincia(Provincia &provincia);
void insertarMunicipioEnProvincia(Provincia &provincia);
void borrarMunicipioDeProvincia(Provincia &provincia);

#endif
