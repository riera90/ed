#include "menu_selector.hpp"

void print_menu(){
	std::cout<<"\t1) Añadir medicion.\t";
	std::cout<<"\t11) .\n";
	std::cout<<"\t2) Modificar medicion.\t";
	std::cout<<"\t12) .\n";
	std::cout<<"\t3) Cargar desde fichero.";
	std::cout<<"\t13) .\n";
	std::cout<<"\t4) Guardar en fichero.\t";
	std::cout<<"\t14) .\n";
	std::cout<<"\t5) Borrar raiz.\t\t";
	std::cout<<"\t15) .\n";
	std::cout<<"\t6) Borrar todo.\t\t";
	std::cout<<"\t16) .\n";
	std::cout<<"\t7) Buscar medicion por fecha.";
	std::cout<<"\t17) .\n";
	std::cout<<"\t8) Imprimir mediciones.\t";
	std::cout<<"\t18) .\n";
	std::cout<<"\t9) Imprimir raiz.\t";
	std::cout<<"\t19) .\n";
	std::cout<<"\t10) Numero de Mediciones.";
	std::cout<<"\t20) Salir del programa.\n";
	std::cout<<'\n';
}


void menu_selector(ed::MonticuloMediciones &heap){
	std::string option="0";
	while (option!="20") {
		std::cout<<CLEAR_SCREEN;
		print_menu();
		std::cin>>option;
		switch (atoi(option.c_str())) {

			case 1:{// Añadir medicion
				setup();
				std::cin.ignore();
				ed::Medicion medicion;
				medicion.leerMedicion();
				heap.insert(medicion);
				pause();
				break;
			}

			case 2:{// Modificar medicion
				setup();
				std::cin.ignore();
				if (!heap.isEmpty()) {
					ed::Medicion medicion;
					medicion.leerMedicion();
					heap.modify(medicion);
				}else{
					std::cout << "No hay medicion que modificar" << '\n';
				}
				pause();
				break;
			}

			case 3:{// Cargar desde fichero
				setup();
				std::cin.ignore();
				std::string filename;
				std::cout<<"ruta a cargar "<<CYAN<<"[./output/Palma_del_Rio.txt.csv]"<<RESET<<":\n\t->";
				std::getline(std::cin, filename);
				if(filename=="")filename="./output/Palma_del_Rio.txt.csv";
				cargarMonticuloDeFichero(filename,heap);
				pause();
				break;
			}

			case 4:{// Guardar en fichero
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 5:{// Borrar raiz
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 6:{// Borrar todo
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 7:{// Buscar medicion por fecha
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 8:{// Imprimir mediciones
				setup();
				std::cin.ignore();
				std::cout<<IBLUE;
				ed::MonticuloMediciones aux(heap);
				for (; !(aux.isEmpty()); aux.remove()) {
					aux.top().escribirMedicion();
				}
				std::cout<<RESET;
				pause();
				break;
			}

			case 9:{// Imprimir raiz
				setup();
				std::cin.ignore();
				std::cout<<IBLUE;
				heap.top().escribirMedicion();
				std::cout<<RESET;
				pause();
				break;
			}

			case 10:{// Numero de Mediciones
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 19:{// Imprimir mediciones
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 20:{// Numero de Mediciones
				setup();
				std::cin.ignore();
				std::cout << "exiting!" << '\n';
				break;
			}

			default:{// default
				setup();
				std::cin.ignore();
				std::cout << "\nIntroduzca un valor valido, \""<<ITALIC<<BBLUE<<option<<RESET<<"\" no es un valor apto."<< '\n';
				pause();
				break;
			}
		}
	}
}
