
main.run: main.cpp
	g++ -Wall -Werror -std=c++11 main.cpp -o main.run -I ../SFML-2.4.2/include -L ../SFML-2.4.2/build/lib/ -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lX11 -lXrandr -lGL -lpthread -ludev -ljpeg

clean:
	rm -f ./*.run

