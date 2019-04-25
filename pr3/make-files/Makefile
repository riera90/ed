# this Makefile was generated automatically by generic-makefile

.PHONY : target
target : banner run
	
	
.PHONY : run
run : ./output/tree.out
	@echo "\tExecuting binary.\n"
	@time "./output/tree.out" hi!
	
	
./output/tree.out : ./app/src/main.cpp  ./tmp/libproject.a
	@echo "\tCompiling binary."
	@mkdir -p ./output
	@g++ ./app/src/main.cpp -Wpedantic -g -ansi -I ./app/include -I ./app -I ./app/src -I ./app/src/Entity -I ./app/src/Generator -I ./app/include -I ./app/include/ed -I ./app/include/ed/Entity -I ./app/include/ed/Generator  -o ./output/tree.out ./tmp/libproject.a 


./tmp/libproject.a : ./tmp/src/Entity/persona.o ./tmp/src/Generator/generarpersona.o 
	@echo "\tBuilding project library."
	@ar -rsc ./tmp/libproject.a ./tmp/src/Entity/persona.o ./tmp/src/Generator/generarpersona.o 


./tmp/src/Entity/persona.o : ./app/src/Entity/persona.cpp 
	@echo "\tPrecompiling object for ./app/src/Entity/persona.cpp."
	@mkdir -p ./tmp/src/Entity
	@g++ -c ./app/src/Entity/persona.cpp -I ./app -I ./app/src -I ./app/src/Entity -I ./app/src/Generator -I ./app/include -I ./app/include/ed -I ./app/include/ed/Entity -I ./app/include/ed/Generator  -o ./tmp/src/Entity/persona.o;


./tmp/src/Generator/generarpersona.o : ./app/src/Generator/generarpersona.cpp 
	@echo "\tPrecompiling object for ./app/src/Generator/generarpersona.cpp."
	@mkdir -p ./tmp/src/Generator
	@g++ -c ./app/src/Generator/generarpersona.cpp -I ./app -I ./app/src -I ./app/src/Entity -I ./app/src/Generator -I ./app/include -I ./app/include/ed -I ./app/include/ed/Entity -I ./app/include/ed/Generator  -o ./tmp/src/Generator/generarpersona.o;


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
