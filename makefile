bin/programa : src/main.cpp include/*.hpp
	g++ src/main.cpp -Iinclude -o bin/programa

ejecutar: bin/programa
	./bin/programa

clean : bin/programa
	rm bin/programa