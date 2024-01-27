#include "endscreen.h"
#include "levelthree.h"
#include <iostream>
#include "levelone.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void endscreen(sf::RenderWindow& window) { //function for endscreen

    bool Enter1pressed = false; //boolean for enter key

    sf::SoundBuffer buffer3; //sound buffer for bird sound
    if (!buffer3.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\birdsound.wav")) {
        std::cout << "Error loading sound file" << std::endl;
    }


    sf::Sound sound3; //sound for bird sound
    sound3.setBuffer(buffer3); //setting buffer for bird sound




     
    sf::Texture endscreen; //texture for endscreen
    if (!endscreen.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\endscreen.jpg")) {
        std::cout << "Error loading endscreen.jpg" << std::endl;
    }
    sf::Font font; //font for text
    if (!font.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\avenir.ttf")) {
        std::cout << "Error loading font.ttf" << std::endl;
    }

    sf::Sprite background(endscreen); //sprite for endscreen
    background.setScale( //scaling background
        static_cast<float>(window.getSize().x) / background.getGlobalBounds().width,
        static_cast<float>(window.getSize().y) / background.getGlobalBounds().height
    );
    background.setPosition(0, 0); //setting position of background

    sound3.play(); //playing bird sound

    sf::Text text; //text for endscreen
    text.setFont(font); //setting font for text
    //credits and thankyou message
    text.setString("THANK YOU!!! \n HAVE A NICE DAY\n I KNOW YOU LIKED OUR GAME\n\nTHE GAME WAS MADE BY\nNOSHERWAN TAHIR\nMUHAMMAD SOHAIB AKHTAR \n\nTHE PEACE ON EARTH HAS BEEN RESTORED\n THE ALIEN KING ALONG WITH HIS EMPIRE LEFT THE PLANET EARTH \n AFTER GETTING DEFEATED BY THE BOY\n\n\n PRESS ESCAPE TO RESTART GAME\n\n\nPRESS ENTER TO CLOSE\n");
    text.setCharacterSize(20); //setting character size
    text.setFillColor(sf::Color::Black); //setting color
    text.setStyle(sf::Text::Bold); //setting style
    text.setStyle(sf::Text::Italic); //setting style
    text.setPosition(20, 0); //setting position of text

    float textSpeed = 10.0f; //setting speed of text

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) { //while window is open
        sf::Event event; //event for closing window
        while (window.pollEvent(event)) { //polling event
            if (event.type == sf::Event::Closed) { //if event is closed
                window.close(); //close window
            }
        }

        // Update text position for downward animation
        float deltaTime = clock.restart().asSeconds();
        sf::Vector2f textPosition = text.getPosition();
        text.setPosition(textPosition.x, textPosition.y + textSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Enter1pressed == false) {
            window.close();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            sound3.stop();
            level1(window);
		}

        // Clear the window
        window.clear();
        // Draw background and text
        window.draw(background);
        window.draw(text);
        // Display things on screen
        window.display();
    }
}
