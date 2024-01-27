// main.cpp

#include "environment.h" // Include  environment header file
#include"levelone.h" // Include  level 1 header file
#include"leveltwo.h" // Include  level 2 header file
#include"levelthree.h" // Include  level 3 header file
#include"endscreen.h" // Include  endscreen header file


int main() { // Main function
    enviro(); // Call your environment function
    sf::RenderWindow window(sf::VideoMode(800, 600), "THE DYNAMITE");

    //Fix Framerate to 60
    window.setFramerateLimit(60);


    return 0;
}
