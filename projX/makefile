CXX        := g++-4.8
CXX        := g++
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOV       := gcov
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunSolution
	rm -f RunSolution.tmp
	rm -f TestSolution
	rm -f TestSolution.tmp

config:
	git config -l

scrub:
	make  clean
	rm -f  Solution.log
	rm -rf solution-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

submit:
	cat Solution.h Solution.c++ RunSolution.c++ | sed -e "1,$$ s/\#include \"Solution.h\"//" > Submission.cpp

RunSolution: Solution.h Solution.c++ RunSolution.c++ submit
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Solution.c++ RunSolution.c++ -o RunSolution

release: Solution.h Solution.c++ TestSolution.c++ submit
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Solution.c++ TestSolution.c++ -o TestSolution $(LDFLAGS)
	./TestSolution

debug: Solution.h Solution.c++ TestSolution.c++ submit
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) -g -DDBG Solution.c++ TestSolution.c++ -o TestSolution $(LDFLAGS)
	./TestSolution


check: TestSolution
	$(VALGRIND) ./TestSolution                                        >  TestSolution.tmp 2>&1
	$(GCOV) -b Solution.c++     | grep -A 5 "File 'Solution.c++'"     >> TestSolution.tmp
	$(GCOV) -b TestSolution.c++ | grep -A 5 "File 'TestSolution.c++'" >> TestSolution.tmp
	cat TestSolution.tmp
