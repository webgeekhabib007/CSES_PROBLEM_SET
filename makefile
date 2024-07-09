CXX? = $(Shell which g++)
CXXFLAGS = -Wall -g --std=c++17


App: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o App

run: App
	./App