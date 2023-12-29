build:
	rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe
	
run:
	./application.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./application.exe


build_tests:
	rm -f tests.exe
	g++ -g -std=c++11 -Wall tests.cpp -o tests.exe

build_tests2:
	rm -f testsg.exe
	g++ testg.cpp -o testsg.exe -lgtest -lgtest_main -lpthread

run_tests2:
	./testsg.exe	

run_tests:
	./tests.exe
	
valgrind_tests:
	valgrind --tool=memcheck --leak-check=yes ./tests.exe
	
valgrind_tests2:
	valgrind --tool=memcheck --leak-check=yes ./testsg.exe
