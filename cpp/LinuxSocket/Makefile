chatServer:socket.o serverSocket.o 
	$(CXX) -o chatServer -std=c++11 -pthread socket.o serverSocket.o

chatClient:clientSocket.o socket.o
	$(CXX) -o chatClient -std=c++11 -pthread socket.o clientSocket.o

clientSocket.o:clientSocket.cpp socket.o

serverSocket.o:serverSocket.cpp socket.o

socket.o:socket.cpp

clean:
	rm chatServer chatClient *.o