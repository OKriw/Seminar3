all:
	g++ main.cpp Client.cpp Client.h Mgr.cpp Mgr.h Task.cpp Task.h Timer.cpp Timer.h
clean:
	rm  *.out