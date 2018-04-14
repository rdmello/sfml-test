
#include <iostream>
#include <chrono>
#include <SFML/Window.hpp>

void mainloop(sf::Window& w)
{
  w.create(sf::VideoMode(1600, 1200), "Test Game");

  while( w.isOpen() )
  {
    sf::Event event;

    while( w.pollEvent(event) )
    {
      if (event.type == sf::Event::Closed)
      {
        w.close();
      }
    }
  }
}

int main(int argc, char** argv)
{
  std::cout << "Initializing..." << std::endl;


  /* Try drawing a simple window */
  sf::Window window;
  mainloop(window); 
  
  std::cout << "Exiting, thanks for playing!" << std::endl;

  return 0;
}
