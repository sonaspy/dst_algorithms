demo : main.o print.o 
	clang++ -o demo main.o print.o

main.o : main.cpp print.cc
	clang++ -c main.cpp

print.o : print.cc
	clang++ -c print.cc

clean : 
	rm -f demo main.o print.o