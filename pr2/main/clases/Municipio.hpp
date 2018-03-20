#ifndef _MUNICIPIO_H_
#define _MUNICIPIO_H_


class Municipio{
	private:
		int postal_code_;		//!< código postal del Municipio
		std::string name_;	//!< nombre del Municipio
		int mens_;					//!< número de hombres del Municipio
		int womens_;				//!< número de mujeres del Municipio
		//! \name Funciones o métodos públicos de la clase Municipio
	public:
		//! \name Constructores de la clase Municipio
		/*!
			\brief     Constructor parametrizado con valores por defecto
			\attention Función sobrecargada
			\note      Función inline
			\param     nombre: valor por defecto ""
			\param     codigoPostal: valor por defecto 0.0
			\param     hombres: valor por defecto 0.0
			\param     mujeres: valor por defecto 0.0
			\pre       Ninguna
			\post      Ninguna
			\sa        set_name(), set_postal_code(),set_mans(), set_womans()
		*/
		inline Municipio(std::string nombre = "",
											int codigoPostal = 0,
											int hombres = 0,
											int mujeres = 0){
				this->set_postal_code(codigoPostal);
				this->set_name(nombre);
				this->set_mans(hombres);
				this->set_womans(mujeres);
		}

			/*!
				\brief     Constructor de "copia"
				\attention Función sobrecargada
				\note      Función inline
				\warning   Se requiere que las funciones de acceso tengan el modificador const
				\param     objeto de la clase Municipio que proporciona los valores iniciales
				\pre       Ninguna
				\post      Ninguna
				\sa        set_name(), set_postal_code(), set_mans(), set_womans(),
				\n		   get_name(), get_postal_code(), get_mans(), get_womens()
			*/
		inline Municipio(Municipio const &objeto){
			this->set_postal_code(objeto.get_postal_code());
			this->set_name(objeto.get_name());
			this->set_mans(objeto.get_mans());
			this->set_womans(objeto.get_womens());
		}

		//! \name Observadores: funciones de consulta de Municipio
		/*!
			\brief   Función que devuelve el nombre
			\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Nombre del municipio
			\pre     Ninguna
			\post    Ninguna
			\sa      get_postal_code(), get_mans(), get_womens(), get_habitants()
		*/
		inline std::string get_name()const{
			return this->name_;
		}

		/*!
			\brief   Función que devuelve el código postal
			\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Código postal del municipio (tipo int)
			\pre     Ninguna
			\post    Ninguna
			\sa      get_name(), get_mans(), get_womens(), get_habitants()
		*/
		inline int get_postal_code()const{
				return this->postal_code_;
		}

		/*!
			\brief   Función que devuelve el número total de hombres
			\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Número total de hombres del municipio (tipo int)
			\pre     Ninguna
			\post    Ninguna
			\sa      get_postal_code(), get_name(), get_womens(), get_habitants()
			*/
		inline int get_mans() const{
			return this->mens_;
		}


		/*!
			\brief   Función que devuelve el número total de mujeres
			\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Número total de mujeres del municipio (tipo int)
			\pre     Ninguna
			\post    Ninguna
			\sa      get_postal_code(), get_name(), get_mans(), get_habitants()
		*/
		inline int get_womens() const{
			return this->womens_;
		}

		/*!
			\brief   Función que devuelve el número total de habitantes
			\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\note 	 El número total de habitantes es un atributo "derivado" que se calcula mediante la suma del número de hombres y el número de mujeres
			\return  Número total de habitantes del municipio (tipo int)
			\pre     Ninguna
			\post    valorDevuelto == get_mans() + get_womens()
			\sa      get_postal_code(), get_name(), get_mans(), get_womens()
		*/
		inline int get_habitants() const{
			return this->get_mans() + this->get_womens();
		}


		//! \name Funciones de modificación de Municipio

		/*!
			\brief Función que asigna un nuevo valor al código postal
			\note    Función inline
			\param v: nuevo valor del código postal
			\pre   Ninguna
			\post  El valor del código postal debe ser "v"
			\sa    set_name, set_mans, set_womans
		*/
		inline void set_postal_code(int v){
			this->postal_code_ = v;
		}


		/*!
			\brief Función que asigna un nuevo valor al nombre
			\note    Función inline
			\param v: nuevo valor del nombre
			\pre   Ninguna
			\post  El valor del nombre debe ser "v"
			\sa    set_postal_code
		*/
		inline void set_name(std::string const &v){
			this->name_ = v;
		}

		/*!
			\brief Función que asigna un nuevo valor al número total de hombres
			\note    Función inline
			\param v: nuevo valor del número total de hombres
			\pre   Ninguna
			\post  El valor del número total de hombres debe ser "v"
			\sa    set_name, set_postal_code, set_womans
		*/
		inline void set_mans(int v){
			this->mens_ = v;
		}

		/*!
			\brief Función que asigna un nuevo valor al número total de mujeres
			\note    Función inline
			\param v: nuevo valor del número total de mujeres
			\pre   Ninguna
			\post  El valor del número total de mujeres debe ser "v"
			\sa    set_name, set_postal_code, set_mans
		*/
		inline void set_womans(int v){
			this->womens_ = v;
		}


		//! \name Operadores

		/*!
			\brief     Operador de asignación
			\attention Se sobrecarga el operador de asignación "="
			\note      Función inline
			\warning   Se requiere que las funciones de acceso tengan el modificador const
			\param     objeto de la clase Municipio pasado como referencia constante
			\pre       El Municipio "objeto" debe ser diferente del municipio actual
			\post      Ninguna
			\sa        set_postal_code, set_name, set_mans, set_womans,
			\n		   get_postal_code, get_name, get_mans, get_womens
		*/
		inline Municipio & operator=(Municipio const &objeto){
			// Se comprueba que no sean el mismo objeto
			if (this != &objeto){
				this->set_postal_code(objeto.get_postal_code());
				this->set_name(objeto.get_name());
				this->set_mans(objeto.get_mans());
				this->set_womans(objeto.get_womens());
			}
			return *this;
		}



		/*!
			\brief     Operador de igualdad: compara si los dos municipios tiene el mismo nombre
			\attention Se sobrecarga el operador de igualdad "="
			\note      Función inline
			\param     objeto de la clase Municipio pasado como referencia constante
			\return	   true: si los municipios son iguales; false, en caso contrario
			\pre       Ninguna
			\post      Ninguna
			\sa        get_name, operator<
		*/
		inline bool operator == (Municipio const &objeto) const{
			return ( this->get_name() == objeto.get_name() );
		}

		/*!
			\brief     Operador relacional "menor que": compara los nombres de los municipios
			\attention Se sobrecarga el operador de igualdad "<"
			\note      Función inline
			\param     objeto de la clase Municipio pasado como referencia constante
			\return	   true: si los municipios son iguales; false, en caso contrario
			\pre       Ninguna
			\post      Ninguna
			\sa        get_name, operator=
		*/
		inline bool operator < (Municipio const &objeto) const{
			return ( this->get_name() < objeto.get_name() );
		}



		//! \name Funciones lectura y escritura de la clase Municipio

		/*!
			\brief   Asigna a un Municipio las conombres "x" e "y" leídas desde el teclado
			\pre     Ninguna
			\post    Deben ser numéricos los atributos de los atributos código postal, hombre y mujeres
			\sa      set_postal_code, set_name, set_mans, set_womans, escribirMunicipio
		*/
		void write_Municipio();

		/*!
			\brief Escribe por pantalla los valores de los atributos de un Municipio
			\note  Formato: código postal, nombre, habitantes, hombres, mujeres
			\pre   Ninguna
			\post  Ninguna
			\sa    get_postal_code, get_name, get_mans, get_womens, get_habitants
		*/
		void read_Municipio() const;

}; // Fin de la definición de la clase Municipio

//! \name Funciones auxiliares del espacio de nombres ed

/*!
	\brief     Función de comparación relacional "menor que": compara el número de habitantes de los municipios
	\note      Función inline
	\param     objeto1 de la clase Municipio pasado como referencia constante
	\param     objeto2 de la clase Municipio pasado como referencia constante
	\return	   true: el objeto1 tiene menos habitatnes que objeto2; false, en caso contrario
	\pre       Ninguna
	\post      Ninguna
	\sa        operator<
*/
bool compare_haitants (Municipio const &objeto1, Municipio const &objeto2) ;

/*!
	\brief     Sobrecarga del operador de salida o escritura "<<"
	\n Se escriben los datos teniendo en cuenta el formato: CP Nombre; hombres; mujeres;
	\param     stream: flujo de salida
	\param     objeto de la clase Municipio pasado como referencia "constante"
	\pre       Ninguna
	\post      Ningguna
	\sa        operator>>()
*/
std::ostream &operator<<(std::ostream &stream, Municipio const &objeto);

/*!
	\brief     Sobrecarga del operador de entrada o lectura ">>"
	\n  Se lee un minicipio con el formato: CP Nombre; hombres; mujeres;
	\attention Función amiga de la clase Municipio
	\param     stream: flujo de salida
	\param     objeto de la clase Municipio pasado como referencia
	\pre       Ninguna
	\post      Ninguna
	\sa        operator<<()
*/
std::istream &operator>>(std::istream &stream, Municipio &objeto);


#endif //_MUNICIPIO_HPP_
