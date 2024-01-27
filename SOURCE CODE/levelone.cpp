// levelone.cpp

#include "levelone.h"
#include"leveltwo.h"
#include "environment.h"
#include<cctype>
#include<cstdlib>
using namespace std;
std::string riddles1() { //function for riddles
	srand(time(NULL)); //random seed
	int num; //integer for random number

	num = rand() % 4; //random number between 0 and 3
	std::string riddle1; //string for riddle
	switch (num) { //switch case for riddle
	case 0:
		riddle1 = "What has a head and a tail, but no body?\n  A BOOK \n B COIN\n";
		break;
	case 1:
		riddle1 = "What has a face and two hands,\n but no arms or legs?\n A TREE \nB CLOCK\n";
		break;
	case 2:
		riddle1 = "What has a thumb and four fingers,\n but is not a hand?\nB Glove\nA Banana\n";
		break;
	case 3:
		riddle1 = "What has a neck, but no head?\n A SNAKE\nB BOTTLE";
		break;
	}
	return riddle1;
}

void level1(sf::RenderWindow& window) { //function for level 1
	bool isdown = true; //boolean for down key
	bool start = true; //boolean for start
	bool isESC = true; //boolean for escape key
	bool isright = true; //boolean for right key
	bool isA = false; //boolean for A key
	bool isB = false; //boolean for A key
	int tries = 0;	//integer for tries
	bool restart = true; //boolean for restart
    //texture
    sf::Texture map; //texture for map
    if (!map.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\map1.jpg")) {
        std::cout << "Error loading map1.jpg" << std::endl;
    }
	sf::Texture life; //texture for life
	if (!life.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\heart.png")) {
		std::cout << "Error loading heart.png" << std::endl;
	}
	sf::Texture progress; //texture for progress
	if (!progress.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\progress.png")) {
		std::cout << "Error loading progress.png" << std::endl;
	}
	sf::Texture boy; //texture for boy
	if (!boy.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\boyfr.png")) {
		std::cout << "Error loading boy.jpg" << std::endl;
	}
	sf::Texture enemy; //texture for enemy
	if (!enemy.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\guards1.png")) {
		std::cout << "Error loading enemy.png" << std::endl;
	}
	sf::Texture power; //texture for power
	if (!power.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\power.png")) {
		std::cout << "Error loading power.png" << std::endl;
	}
	sf::Font font; //font for text
	if (!font.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\arial.ttf")) {
		std::cout << "Error loading font.ttf" << std::endl;
	}
	sf::Text text; //text 
	text.setFont(font);
	text.setString(" WELCOME TO LEVEL 1!\n PRESS DOWN KEY TO ACQUIRE POWER\n AND ESCAPE \n RIGHT TO MOVE TO ENEMIES AND FIGHT\n");
	text.setCharacterSize(12); //setting character size
	text.setFillColor(sf::Color::Black); //setting color
	text.setStyle(sf::Text::Bold); //setting style
	
	sf::Text text1;
	text1.setFont(font);
	text1.setString("Inventory is empty\n");
	text1.setCharacterSize(20); //setting character size
	text1.setPosition(540,570);	
	text1.setFillColor(sf::Color::Black); //setting color
	text1.setStyle(sf::Text::Bold); //setting style

	
	
	


	//draw rectangle to extreme right
	sf::RectangleShape rect(sf::Vector2f(300, 80));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(0, 0);
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Black);
	//put text in rectangle
	text.setPosition(0, 0);
	





	// Sprite
	sf::Sprite
     background(map);
	background.setScale( //scaling background
		static_cast<float>(window.getSize().x) / background.getGlobalBounds().width,
		static_cast<float>(window.getSize().y) / background.getGlobalBounds().height
	);
	
	background.setPosition(0, 0); //setting position of background
		sf::Sprite 
		heart(life); //sprite for heart
		heart.setScale(0.05f, 0.05f); //scaling heart
		heart.setPosition(600, 0); //setting position of heart
		sf::Sprite
			heart1(life); //sprite for heart
		heart1.setScale(0.05f, 0.05f);
		heart1.setPosition(635, 0);
		sf::Sprite
			heart2(life); //sprite for heart
		heart2.setScale(0.05f, 0.05f);
		heart2.setPosition(670, 0);

	
	sf::Sprite
		player(boy); //sprite for player
	player.setScale(0.15f, 0.15f);
	player.setPosition(240, 300);
	sf::Sprite
		enemy1(enemy); //sprite for enemy
	enemy1.setScale(0.15f, 0.15f);
	enemy1.setPosition(500, 350);

	sf::Sprite
		progressBar(progress); //sprite for progress
	progressBar.setScale(0.3f, 0.3f);
	progressBar.setPosition(800, 0);
	progressBar.setRotation(90);

	sf::Sprite
		doodle(boy); //sprite for doodle
	doodle.setScale(0.15f, 0.15f);
	doodle.setPosition(700, 100);

	sf::Sprite
		power1(power); //sprite for power
	power1.setScale(0.15f, 0.15f);
	power1.setPosition(240, 500);
	int i = 0;
	
    // Game loop
    while (window.isOpen()) { //while window is open
		


		sf::Event event; //event for closing window
		while (window.pollEvent(event)) { //polling event
			if (event.type == sf::Event::Closed) { 
				// Close the window
				window.close(); 
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isright == true) //if right key pressed
		{
			//get enemy position
			sf::Vector2f enemyPos = enemy1.getPosition();
			//move player to enemy position

			player.setPosition(enemyPos.x, enemyPos.y + 50);
			player.setRotation(90);
			//can only press escape key now
			isright = false;
			isESC = false;
			isA = false;
			isB = false;
			isdown = false;
			text.setString("YOU DIED AS YOU DIDN'T HAVE POWER\nPRESS ESCAPE TO RETRY\n");
			rect.setFillColor(sf::Color::White);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && isdown==true) //down key pressed
		{
			//generate riddle
			std::string riddle = riddles1();
			text.setString("SOLVE RIDDLE TO ACQUIRE POWER\n" + riddle);
			//can only press A and B key now
			isA = true;
			isB = true;
			isdown = false;
			isright = false;
			isESC = true;


		}
		
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && isESC==false ) { //escape key pressed
				if (tries < 2) { //if tries are less than 2
					if (tries == 0) {
						heart.setColor(sf::Color::Transparent);
					}
					else if (tries == 1) {
						heart1.setColor(sf::Color::Transparent);
					}




					tries++; //increment tries
					player.setPosition(240, 300); //set player position
					enemy1.setPosition(500, 350); //set enemy position
					player.setRotation(0); //set player rotation
					isESC = true; 
					//can press down or right key now
					isright = true; 
					isdown = true; 
					isA = false;
					isB = false;

					text.setString(" WELCOME TO LEVEL 1!\n PRESS DOWN KEY TO ACQUIRE POWER\n AND ESCAPE \n RIGHT TO MOVE TO ENEMIES AND FIGHT\n");
					rect.setFillColor(sf::Color::White);
				}
				else { //if tries are greater than 2
					//all turns expired
					heart2.setColor(sf::Color::Transparent);
					text.setString("YOU LOST ALL YOUR LIVES\nPRESS LEFT SHIFT TO RESTART LEVEL 1\n");
					restart = false;

					
				}

			}
		
		
		

		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)&&isB==true) { //if B key pressed
			 sf::Vector2f powerPos = power1.getPosition(); //get power position
			 player.setPosition(powerPos.x, powerPos.y + 10); //move player to power position
			 power1.setColor(sf::Color::Transparent); //make power transparent
			 //can only press enter key now
			 isB = false; 
			 isA = false;
			 isESC = true;
			 isright = false;
			 isdown = false;
			 start = false;

			 //clear old text in rectangle
			 rect.setFillColor(sf::Color::Transparent);
			 //put new text in rectangle
			 text.setString("YOU ACQUIRED POWER . CONGRATS\n YOU PROCEED TO NEXT LEVEL\nPRESS ENTER TO PROCEED\n");
			 text1.setString("Inventory contains power\n");
			 rect.setFillColor(sf::Color::White);

		 }
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isA==true) { //if A key pressed
			 player.setPosition(240, 300); //set player position
			 enemy1.setPosition(500, 350); //set enemy position
			 player.setRotation(0); //set player rotation
			 //can only press escape key now
			 isA = false;
			 isB = false;
			 isESC = false;
			 isright = false;
			 isdown = false;

			 text.setString(" OOPS!\nWRONG ANSWER\PRESS ESCAPE TO \n TRY AGAIN\n");
			 rect.setFillColor(sf::Color::White);
			 
		 }
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && restart == false) { //if left shift pressed
			 //reset everything and restart level
			 player.setPosition(240, 300);
			 player.setRotation(0);
			 text.setString("WELCOME TO LEVEL 1!\n PRESS DOWN KEY TO ACQUIRE POWER\n AND ESCAPE \n RIGHT TO MOVE TO ENEMIES AND FIGHT\n ");
			 rect.setFillColor(sf::Color::White);
		
			restart= true; 
			isright = true;
			isdown = true;
			isA = false;
			isB = false;
			isESC = true;


			 
		
			
			 tries = 0;
			 heart.setColor(sf::Color::White);
			 heart1.setColor(sf::Color::White);
			 heart2.setColor(sf::Color::White);

		 }

		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && start == false) { //if enter key pressed
			 //go to level 2
			level2(window);
		 }
		 
		 

		// Clear the window
		window.clear();

		// Draw the background and all sprites
		window.draw(background);
		window.draw(progressBar);
		window.draw(heart);
		window.draw(heart1);
		window.draw(heart2);
		window.draw(player);
		window.draw(power1);
		window.draw(enemy1);
		window.draw(doodle);
		
		// Draw the rectangle
		window.draw(rect);
		window.draw(text1);
		window.draw(text);

	

		

		// Display things on screen
		window.display();
	}


}


