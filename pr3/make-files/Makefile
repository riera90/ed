# this Makefile was generated automatically by generic-makefile

.PHONY : target
target : banner run
	
	
.PHONY : run
run : ./output/tree.out
	@echo "\tExecuting binary.\n"
	@time "./output/tree.out" hi!
	
	
./output/tree.out : ./src/main.cpp  ./tmp/libproject.a
	@echo "\tCompiling binary."
	@mkdir -p ./output
	@g++ ./src/main.cpp -Wpedantic -g -ansi -g -I ./src -I ./src/Entity -I ./src/Entity/Person -I ./src/Entity/Node -I ./src/Entity/BinaryTree -I ./src/Generator  -o ./output/tree.out ./tmp/libproject.a 


./tmp/libproject.a : ./tmp/Entity/Person/persona.o ./tmp/Generator/generarpersona.o 
	@echo "\tBuilding project library."
	@ar -rsc ./tmp/libproject.a ./tmp/Entity/Person/persona.o ./tmp/Generator/generarpersona.o 


./tmp/Entity/Person/persona.o : ./src/Entity/Person/persona.cpp ./src/Entity/Person/persona.hpp
	@echo "\tPrecompiling object for ./src/Entity/Person/persona.cpp."
	@mkdir -p ./tmp/Entity/Person
	@g++ -c ./src/Entity/Person/persona.cpp -I ./src -I ./src/Entity -I ./src/Entity/Person -I ./src/Entity/Node -I ./src/Entity/BinaryTree -I ./src/Generator  -o ./tmp/Entity/Person/persona.o;


./tmp/Generator/generarpersona.o : ./src/Generator/generarpersona.cpp ./src/Generator/generarpersona.hpp
	@echo "\tPrecompiling object for ./src/Generator/generarpersona.cpp."
	@mkdir -p ./tmp/Generator
	@g++ -c ./src/Generator/generarpersona.cpp -I ./src -I ./src/Entity -I ./src/Entity/Person -I ./src/Entity/Node -I ./src/Entity/BinaryTree -I ./src/Generator  -o ./tmp/Generator/generarpersona.o;


.PHONY: gdb
gdb : clean ./output/tree.out
	@echo "\tLaunching gdb.\n"
	@gdb ./output/tree.out


.PHONY : googletest
googletest : banner  

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
	@if [ -d "./tmp" ]; then rm -rf ./tmp; fi
	@echo "\tRemoving binary files"
	@if [ -d "./output/*.out" ]; then rm ./output/*.out; fi


.PHONY : init-gest
init-gest:
	@echo "\tClonning googletest to make-files"
	@if [ -d "make-files/googletest" ]; then \
		echo "googletest is already cloned"; \
	else \
		git clone https://github.com/google/googletest.git make-files/googletest; \
		rm ./make-files/googletest/googletest/.git -rf; \
	fi;


.PHONY : rm-gest
rm-gest:
	@echo "\tRemoving googletest repository"
	@if [ -d "make-files/googletest" ]; then \
		rm make-files/googletest -rf; \
	fi;

#    __
# __( o)>
# \ <_ ) r90
