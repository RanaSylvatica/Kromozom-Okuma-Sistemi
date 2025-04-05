all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/genDugum.cpp -o ./lib/genDugum.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/genBagliListe.cpp -o ./lib/genBagliListe.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/genDugum.o ./lib/Dugum.o ./lib/genBagliListe.o ./lib/BagliListe.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program