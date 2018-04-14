
#include <iostream>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void draw_graphics(sf::RenderWindow& window)
{
  // Draw black background
  window.clear(sf::Color::Black);

  // display (does this use a double-buffer system?)
  window.display();
}

void print_framerate(std::chrono::high_resolution_clock::time_point start)
{
  using clock = std::chrono::high_resolution_clock;
  
  clock::duration elapsed = clock::now() - start;
  std::chrono::microseconds us_elapsed
    = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);

  std::cout << "Frame rate: " << 1.0e6 / us_elapsed.count() 
            << " fps" << std::endl;
}

void mainloop(sf::RenderWindow& w)
{
  w.create(sf::VideoMode(1600, 1200), "Test Game");
  sf::Event event;

  while( w.isOpen() )
  {
    // time each iteration of the main loop
    std::chrono::high_resolution_clock::time_point timestart 
      = std::chrono::high_resolution_clock::now();

    // close Window if close event is detected
    while( w.pollEvent(event) )
    {
      if (event.type == sf::Event::Closed) w.close();
    }

    draw_graphics(w);

    print_framerate(timestart);
  }
}

int main(int argc, char** argv)
{
  std::cout << "Initializing..." << std::endl;

  /* Try drawing a simple window */
  sf::RenderWindow window;
  mainloop(window); 
  
  std::cout << "Exiting, thanks for playing!" << std::endl;

  return 0;
}
