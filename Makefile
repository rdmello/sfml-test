
main.run: main.cpp
	g++ -Wall -Werror -std=c++11 main.cpp -o main.run -I ../SFML-2.4.2/include -L ../SFML-2.4.2/build/lib/ -lsfml-window-s -lsfml-system-s -lX11 -lXrandr -lGL -lpthread -ludev

clean:
	rm -f ./*.run

