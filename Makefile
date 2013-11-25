OPTS = -Wall -g

alu:	alu.o
	g++ $(OPTS) -o alu alu.o

4bitalu:	4bitalu.o
	g++ $(OPTS) -o 4bitalu 4bitalu.o

alu.o:	alu.cpp blogic.H
	g++ $(OPTS) -c alu.cpp

4bitalu.o:	4bitalu.cpp blogic.H
	g++ $(OPTS) -c 4bitalu.cpp

clean:
	rm -f alu 4bitalu alu.o