all: main
	rm *.o
main: block blockchain node transaction blocklist  ./MAIN/main.cpp
	g++ -Wall -o programme block.o blockchain.o node.o transaction.o blocklist.o ./MAIN/main.cpp -lpthread
block: ./Class/block.cpp
	g++ -Wall -c -o block.o ./Class/block.cpp -lpthread
blockchain: ./Class/blockchain.cpp
	g++ -Wall -c -o blockchain.o ./Class/blockchain.cpp -lpthread
node: ./Class/node.cpp
	g++ -Wall -c -o node.o ./Class/node.cpp -lpthread
transaction: ./Class/transaction.cpp
	g++ -Wall -c -o transaction.o ./Class/transaction.cpp -lpthread
blocklist : ./Class/blocklist.cpp
	g++ -Wall -c -o blocklist.o ./Class/blocklist.cpp -lpthread
