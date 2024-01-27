#include"environment.h"
#include"levelone.h"
void enviro() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "THE DYNAMITE");

    // Set the initial game state to Loading
    GameState gameState = Loading;

    // Create loading screen elements
    sf::Font font;
    if (!font.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
        // Handle the error (e.g., return from the function or display an error message)
    }


    // Texture
    sf::Texture loadscreen;
    if (!loadscreen.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\loadscreen.jpeg")) {
        std::cout << "Error loading background.png" << std::endl;
        // Handle the error (e.g., return from the function or display an error message)
    }
    sf::Texture menuscreen;
    if (!menuscreen.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\map.jpg")) {
        std::cout << "Error loading map.jpg" << std::endl;
        // Handle the error (e.g., return from the function or display an error message)
    }
    //texture
    sf::Texture playbutton;
    if (!playbutton.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\play button.png")) {
		std::cout << "Error loading background.png" << std::endl;
		// Handle the error (e.g., return from the function or display an error message)
	}
    // Sprite


    sf::Sprite
        background(loadscreen);
    background.setScale(
        static_cast<float>(window.getSize().x) / background.getGlobalBounds().width,
        static_cast<float>(window.getSize().y) / background.getGlobalBounds().height
    );
    sf::Sprite
       menu(menuscreen);
    menu.setScale(
        static_cast<float>(window.getSize().x) / menu.getGlobalBounds().width,
        static_cast<float>(window.getSize().y) / menu.getGlobalBounds().height
    );

    sf::Sprite play(playbutton);
    play.setScale(0.5, 0.5);
    play.setPosition((window.getSize().x - play.getGlobalBounds().width) / 2,
        		(window.getSize().y - play.getGlobalBounds().height) / 2);

   



    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Logic based on the current game state
        switch (gameState) {
        case Loading:
            // Simulate loading process (replace with your actual loading logic)
            // For demonstration purposes, we'll just wait for a short time
            window.clear();
            window.draw(background);
            window.display();

            sf::sleep(sf::seconds(5));

            // Transition to the Menu state after loading
            gameState = Menu;
            break;

        case Menu:
            //add color to window
            window.draw(menu);
            window.draw(play);
            window.display();
            //make game load when i press play texture
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (play.getGlobalBounds().contains(mousePosF)) {

                    level1(window);
                }
            }
        
            break;
        }
    }
}


