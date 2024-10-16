compilar : src/main.cpp
	g++ src/main.cpp -Iinclude -o bin/programa

ejecutar: bin/programa
	./bin/programa