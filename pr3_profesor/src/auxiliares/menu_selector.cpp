#include "menu_selector.hpp"

void print_menu(){
	std::cout<<CYAN<<"\t1) "<<RESET<<UWHITE<<"Añadir medicion.\t"<<RESET;
	std::cout<<"\t11) .\n";
	std::cout<<CYAN<<"\t2) "<<RESET<<UWHITE<<"Modificar medicion.\t"<<RESET;
	std::cout<<"\t12) .\n";
	std::cout<<CYAN<<"\t3) "<<RESET<<UWHITE<<"Cargar desde fichero."<<RESET;
	std::cout<<"\t13) .\n";
	std::cout<<CYAN<<"\t4) "<<RESET<<UWHITE<<"Guardar en fichero.\t"<<RESET;
	std::cout<<"\t14) .\n";
	std::cout<<CYAN<<"\t5) "<<RESET<<UWHITE<<"Borrar raiz.\t\t"<<RESET;
	std::cout<<"\t15) .\n";
	std::cout<<CYAN<<"\t6) "<<RESET<<UWHITE<<"Borrar todo.\t\t"<<RESET;
	std::cout<<"\t16) .\n";
	std::cout<<CYAN<<"\t7) "<<RESET<<UWHITE<<"Buscar medicion por fecha."<<RESET;
	std::cout<<"\t17) .\n";
	std::cout<<CYAN<<"\t8) "<<RESET<<UWHITE<<"Imprimir mediciones.\t"<<RESET;
	std::cout<<"\t18) .\n";
	std::cout<<CYAN<<"\t9) "<<RESET<<UWHITE<<"Imprimir raiz.\t"<<RESET;
	std::cout<<"\t19) .\n";
	std::cout<<CYAN<<"\t10) "<<RESET<<UWHITE<<"Numero de Mediciones."<<RESET;
	std::cout<<CYAN<<"\t20) "<<RESET<<UWHITE<<"Salir del programa.\n"<<RESET;
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
				ed::Medicion medicion=new ed::Medicion;
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
					std::cout <<UWHITE<< "\tNo hay medicion que modificar\n\n";
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
				std::string filename;
				std::cout<<"ruta a cargar "<<CYAN<<"[./output/Palma_del_Rio.txt.csv]"<<RESET<<":\n\t->";
				std::getline(std::cin, filename);
				if(filename=="")filename="./output/Palma_del_Rio.txt.csv";
				grabarMonticuloEnFichero(filename,heap);
				std::cout<<UWHITE<<"Volcado completado"<<"\n\n";
				pause();
				break;
			}

			case 5:{// Borrar raiz
				setup();
				std::cin.ignore();
				if (heap.isEmpty())std::cout << "\tEl monticulo esta vacio\n\n";
				else{
					heap.remove();
					std::cout <<UWHITE<<"\tRaiz borrada con exito!\n\n";
				}
				pause();
				break;
			}

			case 6:{// Borrar todo
				setup();
				std::cin.ignore();
				for (; !(heap.isEmpty()); heap.remove())
				std::cout <<UWHITE<< "\tMontuculo borrado con exito!" << '\n';
				pause();
				break;
			}

			case 7:{// Buscar medicion por fecha TODO
				setup();
				std::cin.ignore();
				pause();
				break;
			}

			case 8:{// Imprimir mediciones
				setup();
				std::cin.ignore();
				std::cout<<CYAN;
				ed::MonticuloMediciones aux(heap);
				for (; !(aux.isEmpty()); aux.remove()) {
					if (aux.size()%30==0) {
						pause();
						std::cout<<CLEAR_SCREEN;
						std::cout<<CYAN;
					}
					aux.top().escribirMedicion();
				}
				std::cout<<RESET;
				pause();
				break;
			}

			case 9:{// Imprimir raiz
				setup();
				if (heap.isEmpty())std::cout << "\tEl monticulo esta vacio\n\n";
				else{
					std::cin.ignore();
					std::cout<<IBLUE;
					heap.top().escribirMedicion();
					std::cout<<RESET;
				}
				pause();
				break;
			}

			case 10:{// Numero de Mediciones
				setup();
				std::cin.ignore();
				std::cout <<UWHITE<< "\thay "<<RESET<<IBLUE<<heap.size()<<RESET<<UWHITE<<" mediciones en el monticulo\n\n";
				pause();
				break;
			}

			case 20:{// exit
				setup();
				std::cin.ignore();
				std::cout <<UWHITE<< "exiting!" <<RESET<< '\n';
				break;
			}

			default:{// default
				setup();
				std::cin.ignore();
				std::cout <<UWHITE<< "\nIntroduzca un valor valido, \""<<RESET<<ITALIC<<BBLUE<<option<<RESET<<UWHITE<<"\" no es un valor apto."<< '\n';
				pause();
				break;
			}
		}
	}
}
