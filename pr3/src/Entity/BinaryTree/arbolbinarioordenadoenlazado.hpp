#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				this->_info = info;
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				this->_info = n._info;
				this->_derecho = n._derecho;
				this->_izquierdo = n._izquierdo;
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
                return this->_info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return this->_izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
                return this->_derecho;
			}

			bool esHoja() const
			{
				if (this->_izquierdo == NULL && this->_derecho == NULL)
					return true;

				return true;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				if (this->esHoja()) {
					operador.aplicar(this->_info);
					return;
				}

				operador.aplicar(this->_info);
				this->_izquierdo->recorridoPreOrden(operador);
				this->_derecho->recorridoPreOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if (this->esHoja()) {
					operador.aplicar(this->_info);
					return;
				}

				this->_izquierdo->recorridoInOrden(operador);
				operador.aplicar(this->_info);
				this->_derecho->recorridoInOrden(operador);
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if (this->esHoja()) {
					operador.aplicar(this->_info);
					return;
				}

				operador.aplicar(this->_info);
				this->_izquierdo->recorridoPostOrden(operador);
				this->_derecho->recorridoPostOrden(operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				this->_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				this->_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				this->_derecho = n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
			    if (this == &n)
			        return * new NodoArbolBinario();

				this->_info = n._info;
				this->_derecho = n._derecho;
				this->_izquierdo = n._izquierdo;

				return *this;
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/




	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			this->_raiz = NULL;
			this->_actual = NULL;
			this->_padre = NULL;
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			this->_padre = a._padre;
			this->_actual = a._actual;
			this->_raiz = a._raiz;
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			if (this == &a)
				return * new NodoArbolBinario();

			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;
		}

		bool insertar(const G &x)
		{
			if (this->buscar(x))
				return false;

			this->_actual = this->_raiz;
			this->_padre = this->_raiz;

			while (this->existeActual())
			{
				if (this->actual() == x)
					return false;

				this->_padre = this->_actual;

				if (this->_actual->getIzquierdo()->getInfo() < x) {
					this->_actual = this->_actual->getIzquierdo();
				} else {
					this->_actual = this->_actual->getDerecho();
				}
			}


			this->_actual = new NodoArbolBinario(x);
			if (this->_padre->getInfo() > x)
				this->_padre->setIzquierdo(this->_actual);
			else
				this->_padre->setDerecho(this->_actual);

			return true;
		}

		void borrarArbol()
		{
			this->_raiz = NULL;
			this->_actual = NULL;
			this->_padre = NULL;
		}

		bool borrar()
		{
			if (!this->existeActual())
				return false;

			this->_actual == NULL;
			return true;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x)
		{
			this->_actual = this->_raiz;
			this->_padre = this->_raiz;

			while (this->existeActual())
			{
				if (this->actual() == x)
					return true;

				this->_padre = this->_actual;

				if (this->_actual->getIzquierdo()->getInfo() < x) {
					this->_actual = this->_actual->getIzquierdo();
				} else {
					this->_actual = this->_actual->getDerecho();
				}
			}

			return false;
		}

		bool estaVacio() const
		{
			if (this->_raiz == NULL)
				return true;
			return false;
		}

		G raiz() const
		{
			return this->_raiz->getInfo();
		}

		bool existeActual() const
		{
			if (this->_actual == NULL)
				return false;
			return true;
		}

		G actual() const
		{
			return this->_actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
