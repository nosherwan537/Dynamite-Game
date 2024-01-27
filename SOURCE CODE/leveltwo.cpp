#include "levelone.h"
#include"leveltwo.h"
#include"levelthree.h"
#include<cctype>
#include<cstdlib>
#include <SFML/Audio.hpp>

std::string riddles() { //function for riddles
	srand(time(NULL)); //random seed
	int num; //integer for random number

	num = rand() % 10;
	std::string riddle; //string for riddle
	switch (num) {
	case 0:
		riddle = "What has a head and a tail, but no body?\n  A Coin \n B Book\n";
		break;
	case 1:
		riddle = "What has a face and two hands,\n but no arms or legs?\n A Clock \nB Tree\n";
		break;
	case 2:
		riddle = "What has a thumb and four fingers,\n but is not a hand?\nA Glove\nB Banana\n";
		break;
	case 3:
		riddle = "What has a neck, but no head?\n A Bottle\nB Snake";
		break;
	case 4:
		riddle = "What has a foot, but no legs?\nA Bed\nB Shoe";
		break;
	case 5:
		riddle = "What has a tongue, but cannot talk?\nA Shoe\n B Dog\n";
		break;
	case 6:
		riddle = "What has a ring, but no finger?\nA Phone\n B Ring";
		break;
	case 7:
		riddle = "What has a face, but no eyes\n, nose, or mouth?\nA Clock\n B Mirror\n";
		break;
	case 8:
		riddle = "What has a mouth,\n but cannot eat?\nA River\nB Lion\n";
		break;
	case 9:
		riddle = "What has a bed, but never sleeps?\n Flowerbed\nB Bear\n";
		break;
	}
	return riddle;

}
void level2(sf::RenderWindow& window) { //function for level 2
	sf::SoundBuffer buffer; //sound buffer for boss intro
	if (!buffer.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\boss-intro.mp3")) {
		std::cout << "Error loading sound file" << std::endl;
	}


	sf::Sound sound; //sound for boss intro
	sound.setBuffer(buffer); //setting buffer for boss intro

	bool Spressed = true; //boolean for S key
	bool Apressed = false; //boolean for A key
	bool code = true; //boolean for code
	bool Bpressed = false; //boolean for B key
	bool Escpressed = true; //boolean for escape key
	bool start = true; //boolean for start
	bool restart = true; //boolean for restart
	int first = 0; //integer for first (turns of correct answers)
	int esc = 0; //integer for escape
	int tries = 0; //integer for tries
	//texture setting
	sf::Texture map;
	if (!map.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\map2.jpg")) {
		std::cout << "Error loading map2.jpg" << std::endl;
	}
	sf::Texture life;
	if (!life.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\heart.png")) {
		std::cout << "Error loading heart.png" << std::endl;
	}
	sf::Texture progress;
	if (!progress.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\progress.png")) {
		std::cout << "Error loading progress.png" << std::endl;
	}
	sf::Texture boy;
	if (!boy.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\boyfr.png")) {
		std::cout << "Error loading boy.jpg" << std::endl;
	}
	sf::Texture enemy;
	if (!enemy.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\guards1.png")) {
		std::cout << "Error loading enemy.png" << std::endl;
	}

	sf::Font font;
	if (!font.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\arial.ttf")) {
		std::cout << "Error loading font.ttf" << std::endl;
	}
	sf::Texture newpower;
	if (!newpower.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\newpow.png")) {
		std::cout << "Error loading newpow.png" << std::endl;
	}

	sound.play(); //playing boss intro sound
	sf::Text text; //text for level 2
	text.setFont(font); //setting font for text
	//set string
	text.setString(" WELCOME TO LEVEL 2!\n YOU ENTERED ENEMY SPACE SHIP \n AND GOT TRAPPED \n NOW TRY TO ESCAPE \n PRESS S TO BEGIN\n");
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	sf::Text text2;
	text2.setFont(font);
	text2.setString("Inventory contains power\n");
	text2.setCharacterSize(20); //setting character size
	text2.setPosition(540, 520);
	text2.setFillColor(sf::Color::White); //setting color
	text2.setStyle(sf::Text::Bold); //setting style





	//draw rectangle to extreme right
	sf::RectangleShape rect(sf::Vector2f(345, 140));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(0, 0);
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Black);
	//put text in rectangle
	text.setPosition(0, 0);





	// Sprite setting
	sf::Sprite
		background(map);
	background.setScale( //scaling background
		static_cast<float>(window.getSize().x) / background.getGlobalBounds().width,
		static_cast<float>(window.getSize().y) / background.getGlobalBounds().height
	);

	background.setPosition(0, 0); //setting position of background
	sf::Sprite 
		heart(life); //sprite for heart
	heart.setScale(0.05f, 0.05f);
	heart.setPosition(600, 0);
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
	player.setPosition(240, 150);
	sf::Sprite
		enemy1(enemy); //sprite for enemy
	enemy1.setScale(0.15f, 0.15f);
	enemy1.setPosition(500, 350);
	sf::Sprite
		enemy2(enemy); //sprite for enemy
	enemy2.setScale(0.15f, 0.15f);
	enemy2.setPosition(600, 300);
	sf::Sprite
		enemy3(enemy); //sprite for enemy
	enemy3.setScale(0.15f, 0.15f);
	enemy3.setPosition(650, 300);
	sf::Sprite
		enemy4(enemy); //sprite for enemy
	enemy4.setScale(0.15f, 0.15f);
	enemy4.setPosition(700, 350);
	sf::Sprite
		power2(newpower); //sprite for new power which is acquired
	power2.setScale(0.2f, 0.2f);
	power2.setPosition(470, 150);


	sf::Sprite
		progressBar(progress); //sprite for progress
	progressBar.setScale(0.3f, 0.3f);
	progressBar.setPosition(800, 0);
	progressBar.setRotation(90);

	sf::Sprite
		doodle(boy); //sprite for doodle
	doodle.setScale(0.15f, 0.15f);
	doodle.setPosition(700, 50);



	while (window.isOpen()) { //while window is open



		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) { 
				// Close the window
				window.close();
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Spressed == true) { //if S key pressed
			if (code == true) { //for riddle
				std::string riddle = riddles();
				text.setString("SOLVE RIDDLE\n" + riddle);
			}
			if (code == false) { //for code
				sound.play();
				text.setString("CRACK CODE TO ACQUIRE SPECIAL POWER \nHERE IS A STRING\n\n string code=\"PHP IS OLD WE EMPLOY REACT USERS\"\nHINT: code.subtr(0,1);\n code.subtr(7,1);\ncode.subtr(11,1);\ncode.subtr(14,1);\ncode.subtr(21,1);\n A : POWER B: OWER\n");

			}
			//can only press A and B key now
			Apressed = true;
			Bpressed = true;
			Escpressed = false;
			restart = true;
			Spressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Apressed == true) //if A is pressed
		{
			restart = true; //can't restart
			if (first == 0) { //if first turn

				player.setPosition(200, 300); //set player position
				//set string
				text.setString("CONGRATS\n YOU GOT IT RIGHT\n NOW KILL ENEMY \n PRESS S \n");
				rect.setFillColor(sf::Color::White); //set rectangle color
				//can only press S key now
				Bpressed = false;
				Spressed = true;
				Apressed = false;
				esc = 1; //set escape to 1
				first++; //increment first
			}
			if (first == 1 && Apressed == true) { //if second turn

				text.setString("CONGRATS\n YOU GOT IT RIGHT\n NOW ACQUIRE POWER \n KILL ENEMIES\n");
				player.setPosition(500, 400);
				player.setColor(sf::Color::Blue);
				enemy1.setColor(sf::Color::Transparent);
				//can only press S
				Bpressed = false;
				Spressed = true;
				Apressed = false;
				esc = 2;

				first++;
			}
			if (first == 2 && Apressed == true) { //third turn

				text.setString("CONGRATS\n YOU GOT IT RIGHT\n AND KILLED ENEMIES\n NOW YOU HAVE TO CRACK THE CODE\n");
				player.setPosition(600, 400);
				player.setColor(sf::Color::Blue);
				enemy2.setColor(sf::Color::Transparent);
				enemy3.setColor(sf::Color::Transparent);
				enemy4.setColor(sf::Color::Transparent);

				player.setColor(sf::Color::White);
				enemy1.setColor(sf::Color::Transparent);
				esc = 3;
				//can only press S
				Bpressed = false;
				Spressed = true;
				Apressed = false;
				code = false;
				first++;



			}
			if (first == 3 && Apressed == true) { //fourth turn

				esc = 4;  //set escape to 4
				first++; //increment first
				text.setString("CONGRATS\n YOU GOT IT RIGHT\n AND CRACKED THE CODE\n NOW YOU CAN GET POWER AND ESCAPE\n");
				player.setPosition(470, 160);
				//can only press S
				Bpressed = false;
				Spressed = true;
				Apressed = false;
				code = true;



			}
			if (first == 4 && Apressed == true) {
				text.setString("CONGRATS\n YOU GOT IT RIGHT\n YOU GET POWER\n TIME FOR SHOWDOWN\n");
				player.setPosition(470, 160);
				power2.setColor(sf::Color::Transparent);
				text2.setString("Inventory contains\n 1.Power \n 2.Dynamite power\n");
				Bpressed = false;
				Spressed = false;
				Apressed = false;
				//can only press enter
				start = false;


			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && Bpressed == true)  //if B pressed
		{



			restart = true; //can't restart

				

			text.setString("OOPS! YOU GOT WRONG\n TRY AGAIN\n PRESS ESCAPE\n");
			rect.setFillColor(sf::Color::White);
			//can only press escape
			Apressed = false;
			Escpressed = true;
			Spressed = false;



		}
		//if escape pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Bpressed == true && Escpressed == true) {
			//can only press S
			Spressed = true;
			Apressed = false;
			Bpressed = false;


			if (esc < 5) { //if escape is less than 5 (There are 5 checkpoints in this level)


				if (tries < 3) { //if tries are less than 3


					if (tries == 0) {

						heart.setColor(sf::Color::Transparent);



					}
					else if (tries == 1) {
						heart1.setColor(sf::Color::Transparent);

					}
					else if (tries == 2) {
						sound.play();
						heart2.setColor(sf::Color::Transparent);

					}
					tries++; //increment tries
				}

				if (esc == 0 && tries < 3) { //for first checkpoint

					text.setString("PRESS S");
					player.setPosition(240, 150);
					enemy1.setPosition(500, 350);
					player.setRotation(0);
					rect.setFillColor(sf::Color::White);



				}
				else if (esc == 1 && tries < 3) { //for second checkpoint
					text.setString("PRESS S");
					player.setPosition(200, 300);
					enemy1.setPosition(500, 350);
					player.setRotation(0);
					rect.setFillColor(sf::Color::White);


				}

				else if (esc == 2 && tries < 3) { //for third checkpoint
					text.setString("PRESS S");
					player.setPosition(500, 400);
					player.setColor(sf::Color::Blue);
					enemy1.setColor(sf::Color::Transparent);


				}
				else if (esc == 3 && tries < 3) { //for fourth checkpoint
					text.setString("PRESS S");
					player.setPosition(600, 400);
					enemy1.setPosition(500, 350);
					player.setRotation(0);
					rect.setFillColor(sf::Color::White);



				}

				else if (esc == 4 && tries < 3) { //for fifth checkpoint
					text.setString("PRESS S");
					player.setPosition(470, 160);

					player.setRotation(0);
					rect.setFillColor(sf::Color::White);
				}

				else {
					//you lost , can restart
					text.setString("YOU LOST ALL YOUR LIVES\nPRESS LEFT SHIFT TO RESTART LEVEL 2\n");

					restart = false;
					Spressed = false;
					Apressed = false;
					Bpressed = false;


				}

			}



		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && restart == false) {
			//restart level 2 and reset everything
			player.setPosition(240, 150);
			player.setColor(sf::Color::White);
			enemy1.setColor(sf::Color::White);
			enemy1.setPosition(500, 350);
			text.setString(" WELCOME TO LEVEL 2!\n YOU ENTERED ENEMY SPACE SHIP \n AND GOT TRAPPED \n NOW TRY TO ESCAPE \n PRESS S TO BEGIN\n");
			rect.setFillColor(sf::Color::White);
			sound.play();
			esc = 0;
			first = 0;
			tries = 0;
			heart.setColor(sf::Color::White);
			heart1.setColor(sf::Color::White);
			heart2.setColor(sf::Color::White);
			Apressed = false;
			Bpressed = false;
			Spressed = true;
			code = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && start == false) { //if enter pressed
			sound.stop(); //stop boss intro sound
			level3(window); //go to level 3
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

		window.draw(enemy1);
		window.draw(enemy2);
		window.draw(enemy3);
		window.draw(enemy4);
		window.draw(doodle);
		window.draw(power2);
		// Draw the rectangle
		window.draw(rect);
		window.draw(text);
		window.draw(text2);






		// Display things on screen
		window.display();
	}



}

