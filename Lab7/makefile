all: buildMain buildTest

buildMain:
	g++ -o main src/main.cpp src/MarriageAgency.cpp src/People.cpp

buildTest:
	g++ --coverage src/test.cpp src/MarriageAgency.cpp src/People.cpp -o test
	./test
	gcov MarriageAgency.cpp 
	gcov People.cpp
	