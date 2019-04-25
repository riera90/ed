#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include <ed/Entity/arbolbinarioordenado.hpp>
#include <ed/Entity/operadornodo.hpp>

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

				return false; // fuck this return 5 hours wasted here
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador.aplicar(this->_info);

				if (this->esHoja())
					return;

				if (this->_izquierdo->getIzquierdo() != NULL)
					this->_izquierdo->recorridoInOrden(operador);

				if (this->_izquierdo->getDerecho() != NULL)
					this->_derecho->recorridoInOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if (this->esHoja()) {
					operador.aplicar(this->_info);
					return;
				}

				if (this->_izquierdo->getIzquierdo() != NULL)
					this->_izquierdo->recorridoInOrden(operador);

				if (this->_izquierdo->getDerecho() != NULL)
					this->_derecho->recorridoInOrden(operador);

				operador.aplicar(this->_info);
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const {
				if (this->esHoja()) {
					operador.aplicar(this->_info);
					return;
				}

				if (this->getIzquierdo() != NULL)
					this->_izquierdo->recorridoInOrden(operador);

				operador.aplicar(this->_info);

				if (this->getDerecho() != NULL)
					this->_derecho->recorridoInOrden(operador);

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
			if (this->_raiz == NULL) {
				this->_raiz = new NodoArbolBinario(x);
				return true;
			}

			if (this->buscar(x))
				return false;

			auto* nodo = new NodoArbolBinario(x);

			if (this->_padre->getInfo() > x) {

				this->_padre->setIzquierdo(nodo);
			}
			else {
				this->_padre->setDerecho(nodo);
			}

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
			// TODO finish this function

			if (!this->existeActual())
				return false;

			AlmacenarNodo<G> almacenador;

			this->_actual->recorridoPostOrden(almacenador);

			if (this->_padre->getInfo() > this->_actual->getInfo())
			    this->_padre->setIzquierdo(NULL);

            else
                this->_padre->setDerecho(NULL);

			std::vector<G> nodes = almacenador.vectorNodos();

            for (int i = 1; i < nodes.size(); ++i) {
                this->insertar(nodes[i]);
            }

			return true;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			if (this->_raiz == NULL)
				return;

			this->_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			if (this->_raiz == NULL)
				return;

			this->_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			if (this->_raiz == NULL)
				return;

			this->_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x)
		{
			if (this->_raiz == NULL)
				return false;

			this->_actual = this->_raiz;
			this->_padre = NULL;

			while (this->_actual != NULL && this->actual() != x)
			{
				if (this->_actual->getInfo() > x) {
					this->_padre = this->_actual;
					this->_actual = this->_padre->getIzquierdo();
				} else {
					this->_padre = this->_actual;
					this->_actual = this->_padre->getDerecho();
				}
			}
			if (this->_actual == NULL) {
				return false;
			}
			return true;

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
