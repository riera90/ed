# this Makefile was generated automaticly by generic-makefile

.PHONY : target
target : banner run
	
	
.PHONY : run
run : ./output/bin.out
	@echo "\tExecuting binary.\n"
	@time "./output/bin.out" 
	
	
./output/bin.out : ./src/main.cpp  ./tmp/libproject.a
	@echo "\tCompiling binary."
	@mkdir -p ./output
	@g++ ./src/main.cpp -Wpedantic -g -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/Monomio  -o ./output/bin.out ./tmp/libproject.a 


./tmp/libproject.a : ./tmp/Entity/Monomio/Monomio.o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o ./tmp/Controller/Monomio/operadoresExternosMonomios.o 
	@echo "\tBuilding project library."
	@ar -rsc ./tmp/libproject.a ./tmp/Entity/Monomio/Monomio.o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o ./tmp/Controller/Monomio/operadoresExternosMonomios.o 


./tmp/Entity/Monomio/Monomio.o : ./src/Entity/Monomio/Monomio.cpp ./src/Entity/Monomio/Monomio.hpp
	@echo "\tPrecompiling object for ./src/Entity/Monomio/Monomio.cpp."
	@mkdir -p ./tmp/Entity/Monomio
	@g++ -c ./src/Entity/Monomio/Monomio.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/Monomio  -o ./tmp/Entity/Monomio/Monomio.o;


./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o : ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.hpp
	@echo "\tPrecompiling object for ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp."
	@mkdir -p ./tmp/Auxiliar/AuxiliarFunctions
	@g++ -c ./src/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/Monomio  -o ./tmp/Auxiliar/AuxiliarFunctions/funcionesAuxiliares.o;


./tmp/Controller/Monomio/operadoresExternosMonomios.o : ./src/Controller/Monomio/operadoresExternosMonomios.cpp ./src/Controller/Monomio/operadoresExternosMonomios.hpp
	@echo "\tPrecompiling object for ./src/Controller/Monomio/operadoresExternosMonomios.cpp."
	@mkdir -p ./tmp/Controller/Monomio
	@g++ -c ./src/Controller/Monomio/operadoresExternosMonomios.cpp -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/Monomio  -o ./tmp/Controller/Monomio/operadoresExternosMonomios.o;


.PHONY: gdb
gdb : clean ./output/bin.out
	@echo "\tLaunching gdb.\n"
	@gdb ./output/bin.out


.PHONY : googletest
googletest : banner ./output/monomioUnittest.out 
	@echo "\n\tRunning ./output/monomioUnittest.out"
	./output/monomioUnittest.out

./output/monomioUnittest.out : ./tmp/libgtest.a ./tmp/libproject.a ./gtests/monomioUnittest.cpp
	@mkdir -p ./output
	@echo "\tBuilding googletest ./gtests/monomioUnittest.cpp."
	@g++ -isystem ./make-files/googletest/googletest/include -pthread -I ./src -I ./src/Entity -I ./src/Entity/Monomio -I ./src/Auxiliar -I ./src/Auxiliar/AuxiliarFunctions -I ./src/Controller -I ./src/Controller/Monomio  -Wpedantic -g ./gtests/monomioUnittest.cpp ./tmp/libproject.a ./tmp/libgtest.a -o ./output/monomioUnittest.out


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
