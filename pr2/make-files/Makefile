# this Makefile was generated automaticly by generic-makefile

.PHONY : target
target : banner run
	
	
.PHONY : run
run : ./output/bin.out
	@echo "\tExecuting binary.\n"
	@time "./output/bin.out" hi!
	
	
./output/bin.out : ./src/main.cpp  ./tmp/libproject.a
	@echo "\tCompiling binary."
	@mkdir -p ./output
	@g++ ./src/main.cpp -Wpedantic -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./output/bin.out ./tmp/libproject.a 


./tmp/libproject.a : ./tmp/Entity/Monomio/Monomio.o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o ./tmp/Auxiliar/AuxiliarFunctions/auxiliarFunctions.o ./tmp/Controller/MonomioController/operadoresExternosMonomios.o ./tmp/Controller/PolinomioController/operadoresExternosPolinomios.o ./tmp/Polinomio/Polinomio.o 
	@echo "\tBuilding project library."
	@ar -rsc ./tmp/libproject.a ./tmp/Entity/Monomio/Monomio.o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o ./tmp/Auxiliar/AuxiliarFunctions/auxiliarFunctions.o ./tmp/Controller/MonomioController/operadoresExternosMonomios.o ./tmp/Controller/PolinomioController/operadoresExternosPolinomios.o ./tmp/Polinomio/Polinomio.o 


./tmp/Entity/Monomio/Monomio.o : ./src/Entity/Monomio/Monomio.cpp ./src/Entity/Monomio/Monomio.hpp
	@echo "\tPrecompiling object for ./src/Entity/Monomio/Monomio.cpp."
	@mkdir -p ./tmp/Entity/Monomio
	@g++ -c ./src/Entity/Monomio/Monomio.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Entity/Monomio/Monomio.o;


./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o : ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.hpp
	@echo "\tPrecompiling object for ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp."
	@mkdir -p ./tmp/Auxiliar/AuxiliarFunctions
	@g++ -c ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o;


./tmp/Auxiliar/AuxiliarFunctions/auxiliarFunctions.o : ./src/Auxiliar/AuxiliarFunctions/auxiliarFunctions.cpp ./src/Auxiliar/AuxiliarFunctions/auxiliarFunctions.hpp
	@echo "\tPrecompiling object for ./src/Auxiliar/AuxiliarFunctions/auxiliarFunctions.cpp."
	@mkdir -p ./tmp/Auxiliar/AuxiliarFunctions
	@g++ -c ./src/Auxiliar/AuxiliarFunctions/auxiliarFunctions.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Auxiliar/AuxiliarFunctions/auxiliarFunctions.o;


./tmp/Controller/MonomioController/operadoresExternosMonomios.o : ./src/Controller/MonomioController/operadoresExternosMonomios.cpp ./src/Controller/MonomioController/operadoresExternosMonomios.hpp
	@echo "\tPrecompiling object for ./src/Controller/MonomioController/operadoresExternosMonomios.cpp."
	@mkdir -p ./tmp/Controller/MonomioController
	@g++ -c ./src/Controller/MonomioController/operadoresExternosMonomios.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Controller/MonomioController/operadoresExternosMonomios.o;


./tmp/Controller/PolinomioController/operadoresExternosPolinomios.o : ./src/Controller/PolinomioController/operadoresExternosPolinomios.cpp ./src/Controller/PolinomioController/operadoresExternosPolinomios.hpp
	@echo "\tPrecompiling object for ./src/Controller/PolinomioController/operadoresExternosPolinomios.cpp."
	@mkdir -p ./tmp/Controller/PolinomioController
	@g++ -c ./src/Controller/PolinomioController/operadoresExternosPolinomios.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Controller/PolinomioController/operadoresExternosPolinomios.o;


./tmp/Polinomio/Polinomio.o : ./src/Polinomio/Polinomio.cpp ./src/Polinomio/Polinomio.hpp
	@echo "\tPrecompiling object for ./src/Polinomio/Polinomio.cpp."
	@mkdir -p ./tmp/Polinomio
	@g++ -c ./src/Polinomio/Polinomio.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -o ./tmp/Polinomio/Polinomio.o;


.PHONY : googletest
googletest : banner ./output/MonomioUnittest.out ./output/PolinomioUnittest.out 
	@echo "\n\tRunning ./output/MonomioUnittest.out"
	./output/MonomioUnittest.out
	@echo "\n\tRunning ./output/PolinomioUnittest.out"
	./output/PolinomioUnittest.out

./output/MonomioUnittest.out : ./tmp/libgtest.a ./tmp/libproject.a ./gtests/MonomioUnittest.cpp
	@mkdir -p ./output
	@echo "\tBuilding googletest ./gtests/MonomioUnittest.cpp."
	@g++ -isystem ./make-files/googletest/googletest/include -pthread -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -Wpedantic ./gtests/MonomioUnittest.cpp ./tmp/libproject.a ./tmp/libgtest.a -o ./output/MonomioUnittest.out


./output/PolinomioUnittest.out : ./tmp/libgtest.a ./tmp/libproject.a ./gtests/PolinomioUnittest.cpp
	@mkdir -p ./output
	@echo "\tBuilding googletest ./gtests/PolinomioUnittest.cpp."
	@g++ -isystem ./make-files/googletest/googletest/include -pthread -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/MonomioController -I ./src/Controller/PolinomioController -I ./src/Polinomio  -Wpedantic ./gtests/PolinomioUnittest.cpp ./tmp/libproject.a ./tmp/libgtest.a -o ./output/PolinomioUnittest.out


./tmp/libgtest.a : ./tmp/gtest_main.o ./tmp/gtest-all.o
	@echo "\tCompiling googletest library."
	@ar -rc ./tmp/libgtest.a ./tmp/gtest-all.o ./tmp/gtest_main.o


./tmp/gtest_main.o : ./make-files/googletest/googletest/src/gtest_main.cc
	@echo "\tPrecompiling googletest object for ./make-files/googletest/googletest/src/gtest_main.cc."
	@mkdir -p ./tmp
	@g++ -isystem ./make-files/googletest/googletest/include -I ./make-files/googletest/googletest -pthread -c ./make-files/googletest/googletest/src/gtest_main.cc -o ./tmp/gtest_main.o

./tmp/gtest-all.o : ./make-files/googletest/googletest/src/gtest-all.cc
	@echo "\tPrecompiling googletest object for ./make-files/googletest/googletest/src/gtest-all.cc"
	@mkdir -p ./tmp
	@g++ -isystem ./make-files/googletest/googletest/include -I ./make-files/googletest/googletest -pthread -c ./make-files/googletest/googletest/src/gtest-all.cc -o ./tmp/gtest-all.o


.PHONY : banner
banner :
	@cat ./make-files/fancy_banner_short.txt


.PHONY : help
help:
	@cat ./make-files/banner.txt
	@cat ./make-files/help.txt


.PHONY : clean
clean:
	@echo "\tRemoving temporal files"
	@rm -rf ./tmp
	@echo "\tRemoving binary files"
	@rm ./output/*.out

#    __
# __( o)>
# \ <_ ) r90