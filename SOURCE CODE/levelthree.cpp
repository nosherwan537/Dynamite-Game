#include"levelthree.h"
#include"endscreen.h"
#include<cctype>
#include<cstdlib>
#include <SFML/Audio.hpp>
//add comments in whole code

void level3(sf::RenderWindow& window) { //function for level 3

	sf::SoundBuffer buffer; //sound buffer
	if (!buffer.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\evil-laugh.mp3")) { //loading sound file
		std::cout << "Error loading sound file" << std::endl; //error message
	}


	sf::Sound sound; //sound
	sound.setBuffer(buffer); //setting buffer

	sf::SoundBuffer buffer1; //sound buffer
	if (!buffer1.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\lightning-tiger.mp3")) { //loading sound file
		std::cout << "Error loading sound file" << std::endl; //error message
	}


	sf::Sound sound1; //sound
	sound1.setBuffer(buffer1); //setting buffer
	bool S1pressed = true; //bool for S
	bool Num4pressed = false; //bool for 4
	bool Num5pressed = false; //bool for 5
	bool Num6pressed = false; //bool for 6
	bool Num0pressed = false; //bool for 0
	bool Num1pressed = false; //bool for 1
	bool Num2pressed = false; //bool for 2
	bool Num3pressed = false; //bool for 3
	bool Num7pressed = false; //bool for 7
	bool Num8pressed = false; //bool for 8
	bool Num9pressed = false; //bool for 9
	bool Enterpressed = true; //bool for enter

	bool turn = true; //bool for checking turn of S being pressed

	bool Esc1pressed = true; //bool for escape
	bool restart1 = true; //bool for restarting level
	int first1 = 0; //int for keeping record of correct turns 
	int esc1 = 0; //int for keeping record of escape
	int tries1 = 0; //int for keeping record of tries


	sf::Texture map3; //texture
	if (!map3.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\map3.jpg")) { //loading texture
		std::cout << "Error loading map3.jpg" << std::endl; //error message
	}
	sf::Texture life3; //texture
	if (!life3.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\heart.png")) { //loading texture
		std::cout << "Error loading heart.png" << std::endl; //error message
	}
	sf::Texture progress3; //texture
	if (!progress3.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\progress.png")) { //loading texture
		std::cout << "Error loading progress.png" << std::endl; //error message
	}
	sf::Texture boy3; //texture
	if (!boy3.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\boyfr.png")) { //loading texture
		std::cout << "Error loading boyfr.jpg" << std::endl; //error message
	}
	sf::Texture boss; //texture
	if (!boss.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\bossfr.png")) { //loading texture
		std::cout << "Error loading enemy.png" << std::endl; //error message
	}

	sf::Font font; //font
	if (!font.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\arial.ttf")) { //loading font
		std::cout << "Error loading font.ttf" << std::endl; //error message
	}
	sf::Texture newpower;
	if (!newpower.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\newpow.png")) { //loading texture
		std::cout << "Error loading newpow.png" << std::endl; //error message
	}
	sf::Texture bosspower;
	if (!bosspower.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\bosspow.png")) { //loading texture
		std::cout << "Error loading bosspow.png" << std::endl; //error message
	}
	sf::Texture power;
	if (!power.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\power.png")) { //loading texture
		std::cout << "Error loading power.png" << std::endl; //error message
	}
	sf::Texture progress;
	if (!progress.loadFromFile("C:\\THE DYNAMITE\\Dynamite\\assets\\progress.png")) { //loading texture
		std::cout << "Error loading progress.png" << std::endl; //error message
	}
	sound1.play(); //playing sound
	sf::Text text; //text
	text.setFont(font); //setting font
	text.setString(" WELCOME TO LEVEL 3!\n YOU ENTERED HAVE ENTERED THE BOSS CHAMBER \n NOW YOU HAVE TO FIGHT HIM TO ESCAPE \n  PRESS S TO BEGIN\n\n\n LET THE FIGHT BEGIN!!!!!!!\n"); //setting string
	text.setCharacterSize(12); //setting character size
	text.setFillColor(sf::Color::Black); //setting color
	text.setStyle(sf::Text::Bold); //setting style







	//draw rectangle to extreme right
	sf::RectangleShape rect(sf::Vector2f(345, 140)); //rectangle
	rect.setFillColor(sf::Color::White); //setting color
	rect.setPosition(0, 0); //setting position
	rect.setOutlineThickness(2); //setting outline thickness
	rect.setOutlineColor(sf::Color::Black); //setting outline color
	//put text in rectangle
	text.setPosition(0, 0); //setting position
	sf::Text text3;
	text3.setFont(font);
	text3.setString("Inventory contains\n 1.Power\n 2.Dynamite power\n");
	text3.setCharacterSize(20); //setting character size
	text3.setPosition(540, 520);
	text3.setFillColor(sf::Color::White); //setting color
	text3.setStyle(sf::Text::Bold); //setting style





	// Sprite
	sf::Sprite
		background(map3); //background
	background.setScale(
		static_cast<float>(window.getSize().x) / background.getGlobalBounds().width,
		static_cast<float>(window.getSize().y) / background.getGlobalBounds().height
	); //setting scale

	background.setPosition(0, 0); //setting position
	sf::Sprite //sprite
		heart(life3); //heart
	heart.setScale(0.05f, 0.05f); //setting scale
	heart.setPosition(600, 0); //setting position
	sf::Sprite //sprite
		heart1(life3); //heart
	heart1.setScale(0.05f, 0.05f); //setting scale
	heart1.setPosition(635, 0); //setting position
	sf::Sprite //sprite
		heart2(life3); //heart
	heart2.setScale(0.05f, 0.05f); //setting scale
	heart2.setPosition(670, 0); //setting position


	sf::Sprite	//sprite
		player(boy3); //player
	player.setScale(0.15f, 0.15f);
	player.setPosition(240, 485);
	sf::Sprite //sprite
		enemy1(boss); //enemy
	enemy1.setScale(0.25f, 0.25f);
	enemy1.setPosition(500, 460);
	sf::Sprite //sprite
		progressBar(progress); //progress bar
	progressBar.setScale(0.3f, 0.3f);
	progressBar.setPosition(800, 0);
	progressBar.setRotation(90);
	sf::Sprite //sprite
		Bosspwr1(bosspower); //bosspower
	Bosspwr1.setScale(0.1f, 0.1f);
	Bosspwr1.setPosition(470, 460);
	sf::Sprite //sprite
		Bosspwr2(bosspower); //bosspower
	Bosspwr2.setScale(0.1f, 0.1f);
	Bosspwr2.setPosition(500, 450);
	sf::Sprite //sprite
		Bosspwr3(bosspower); //bosspower
	Bosspwr3.setScale(0.1f, 0.1f);
	Bosspwr3.setPosition(530, 460);

	sf::Sprite //sprite
		Newpwr(newpower); //newpower
	Newpwr.setScale(0.1f, 0.1f);
	Newpwr.setPosition(230, 460);

	sf::Sprite //sprite
		Pwr(power); //power
	Pwr.setScale(0.07f, 0.07f);
	Pwr.setPosition(210, 485);
	sf::Sprite //sprite
		Pwr1(power); //power
	Pwr1.setScale(0.07f, 0.07f);
	Pwr1.setPosition(270, 485);


	sf::Sprite //sprite
		doodle(boy3); //doodle
	doodle.setScale(0.15f, 0.15f);
	doodle.setPosition(705, 0);



	float movementspeed = 290.0f; //movement speed for boy power


	float BOSSmovementspeed = -290.0f; //movement speed for boss power




	while (window.isOpen()) { //while window is open



		sf::Event event; //event
		while (window.pollEvent(event)) {	//polling event
			if (event.type == sf::Event::Closed) { //if event is closed
				// Close the window
				window.close();
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && S1pressed == true) { //if S is pressed

			if (turn == true) {  //if turn is true (game continues)
				text.setString("\nChoose a Number from 0-9");
				//all number options available now to press 
				Num4pressed = true; 
				Num5pressed = true;
				Num6pressed = true;
				Num0pressed = true;
				Num1pressed = true;
				Num2pressed = true;
				Num3pressed = true;
				Num7pressed = true;
				Num8pressed = true;
				Num9pressed = true;
				Esc1pressed = false;
				restart1 = true; //can't restart level
				S1pressed = false;
			}
			if (turn == false) { //if turn is false (game ends)
				text.setString("YOU WON  \n JUST PRESS ENTER"); //setting string
				Enterpressed = false; //can press enter now only
				//all options not available now to press
				S1pressed = false;
				Num4pressed = false;
				Num5pressed = false;
				Num6pressed = false;
				Num0pressed = false;
				Num1pressed = false;
				Num2pressed = false;
				Num3pressed = false;
				Num7pressed = false;
				Num8pressed = false;
				Num9pressed = false;
				Esc1pressed = false;
				restart1 = true; //can't restart level

				


			}
			
			
		}
		//if 4 or 7 or 9 is pressed
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) && Num4pressed == true && Num7pressed == true && Num9pressed == true) 
		{


			restart1 = true; //can't restart level
			if (first1 == 0) { //if first correct turn



				//set transparent color

				text.setString("CONGRATS\n YOU GOT IT RIGHT \n PRESS S \n"); //setting string
				rect.setFillColor(sf::Color::White); //setting color
				//move power to hit boss and then get transparent
				Pwr.move(movementspeed, 0);
				if (Pwr.getPosition().x >= 500) {
					Pwr.setColor(sf::Color::Transparent);
				}
				//can press only S now
				Num5pressed = false; 
				S1pressed = true;
				Num4pressed = false;
				Num6pressed = false;
				Num0pressed = false;
				Num1pressed = false;
				Num2pressed = false;
				Num3pressed = false;
				Num7pressed = false;
				Num8pressed = false;
				Num9pressed = false;
				first1++; //increase first by 1
			}
			if (first1 == 1 && Num4pressed == true && Num7pressed == true && Num9pressed == true) {
				text.setString("CONGRATS\n YOU GOT IT RIGHT\n PRESS S \n"); //setting string
				Pwr1.move(movementspeed, 0); //move power to hit boss and then get transparent
				if (Pwr1.getPosition().x >= 500) {
					Pwr1.setColor(sf::Color::Transparent);
				}
				//can press only S now
				Num5pressed = false;
				S1pressed = true;
				Num4pressed = false;
				Num6pressed = false;
				Num0pressed = false;
				Num1pressed = false;
				Num2pressed = false;
				Num3pressed = false;
				Num7pressed = false;
				Num8pressed = false;
				Num9pressed = false;

				first1++; //increase first by 1
			}
			if (first1 == 2 && Num4pressed == true && Num7pressed == true && Num9pressed == true) {
				text.setString("CONGRATS\n YOU GOT IT RIGHT\n YOU WON!!!!!\n PRESS S \n");//setting string
				//move last power(grenade) to hit boss and then get transparent
				Newpwr.move(movementspeed, 0); 
				if (Newpwr.getPosition().x >= 500) {
					Newpwr.setColor(sf::Color::Transparent);
				} 
				//boss and powers get transparent
				Bosspwr1.setColor(sf::Color::Transparent);
				Bosspwr2.setColor(sf::Color::Transparent);
				Bosspwr3.setColor(sf::Color::Transparent);
				enemy1.setColor(sf::Color::Transparent);
				//can press only S now
				Num5pressed = false;
				S1pressed = true;
				Num4pressed = false;
				Num6pressed = false;
				Num0pressed = false;
				Num1pressed = false;
				Num2pressed = false;
				Num3pressed = false;
				Num7pressed = false;
				Num8pressed = false;
				Num9pressed = false;
				turn = false; //turn is false
				first1++; //increase first by 1



			}

		}
		//if 5 or 8 or 6 or 2 or 3 or 0 or 1 is pressed
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) && Num0pressed == true && Num1pressed == true && Num2pressed == true && Num3pressed == true && Num5pressed == true && Num8pressed == true && Num6pressed == true) 
		{



			restart1 = true; //can't restart level

			

			text.setString("OOPS! YOU GOT WRONG\n TRY AGAIN\n PRESS ESCAPE\n"); //setting string
			rect.setFillColor(sf::Color::White);



			//can only press escape now
			Num4pressed = false;
			Num7pressed = false;
			Num9pressed = false;
			Esc1pressed = true;
			S1pressed = false;



		}
		//if escape is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Num0pressed == true && Num1pressed == true && Num2pressed == true && Num3pressed == true && Num5pressed == true && Num8pressed == true && Num6pressed == true && Esc1pressed == true) {
			//can only press S now
			S1pressed = true;
			Num4pressed = false;
			Num5pressed = false;
			Num6pressed = false;
			Num0pressed = false;
			Num1pressed = false;
			Num2pressed = false;
			Num3pressed = false;
			Num7pressed = false;
			Num8pressed = false;
			Num9pressed = false;
			//you have three chances
			if (esc1 < 2) { //if escape is less than 2 , restore from last  checkpoint
				if (esc1 == 0) {
					Bosspwr1.move(BOSSmovementspeed, 0);
					if (Bosspwr1.getPosition().x <= 240) {
						Bosspwr1.setColor(sf::Color::Transparent);
					}
					heart.setColor(sf::Color::Transparent);

					text.setString("PRESS S");


					rect.setFillColor(sf::Color::White);



				}
				else if (esc1 == 1) {
					Bosspwr1.move(BOSSmovementspeed, 0);
					if (Bosspwr1.getPosition().x <= 240) {
						Bosspwr1.setColor(sf::Color::Transparent);
					}
					heart1.setColor(sf::Color::Transparent);

					text.setString("PRESS S");

					rect.setFillColor(sf::Color::White);


				}
				esc1++; //increase escape by 1

			}
			else{ //if escape is 2 , you lose
					
				    heart2.setColor(sf::Color::Transparent);
					player.setColor(sf::Color::Transparent);
					Newpwr.setColor(sf::Color::Transparent);
					Pwr.setColor(sf::Color::Transparent);
					Pwr1.setColor(sf::Color::Transparent);
					text.setString("YOU LOST ALL YOUR LIVES\nPRESS LEFT SHIFT TO RESTART LEVEL 3\n");
					sound.play(); //play sound
					restart1 = false; //can restart level	
					S1pressed = false;
					Num4pressed = false;
					Num5pressed = false;
					Num6pressed = false;
					Num0pressed = false;
					Num1pressed = false;
					Num2pressed = false;
					Num3pressed = false;
					Num7pressed = false;
					Num8pressed = false;
					Num9pressed = false;


			}



		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && restart1 == false) { //if left shift is pressed and restart is false
			//restart level and reset everything 
			player.setPosition(240, 485);
			player.setColor(sf::Color::White);
			enemy1.setColor(sf::Color::White);
			enemy1.setPosition(500, 460);
			text.setString(" WELCOME TO LEVEL 3!\n YOU ENTERED HAVE ENTERED THE BOSS CHAMBER \n NOW YOU HAVE TO FIGHT HIM TO ESCAPE \n  PRESS S TO BEGIN\n\n\n LET THE FIGHT BEGIN!!!!!!!\n");
			rect.setFillColor(sf::Color::White);
			esc1 = 0;
			first1 = 0;
			tries1 = 0;
			heart.setColor(sf::Color::White);
			heart1.setColor(sf::Color::White);
			heart2.setColor(sf::Color::White);
			Bosspwr1.setColor(sf::Color::White);
			Bosspwr2.setColor(sf::Color::White);
			Bosspwr3.setColor(sf::Color::White);
			Newpwr.setColor(sf::Color::White);
			Pwr.setColor(sf::Color::White);
			Pwr1.setColor(sf::Color::White);
			//can press S only
			Num4pressed = false;
			Num5pressed = false;
			Num6pressed = false;
			Num0pressed = false;
			Num1pressed = false;
			Num2pressed = false;
			Num3pressed = false;
			Num7pressed = false;
			Num8pressed = false;
			Num9pressed = false;
			S1pressed = true;
			turn = true;
			Bosspwr1.setPosition(470, 460);
			Bosspwr2.setPosition(500, 450);
			Bosspwr3.setPosition(530, 460);
			Newpwr.setPosition(230, 460);
			Pwr.setPosition(210, 485);
			Pwr1.setPosition(270, 485);
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Enterpressed == false) { //if enter is pressed and enterpressed is false
			sound1.stop(); //stop sound
			endscreen(window); //go to end screen as game has ended

		}

		// Clear the window
		window.clear();

		// Draw the background and all sprites
		window.draw(background);

		window.draw(heart);
		window.draw(heart1);
		window.draw(heart2);
		window.draw(player);

		window.draw(enemy1);
		window.draw(progressBar);
		window.draw(doodle);
		window.draw(Bosspwr1);
		window.draw(Bosspwr2);
		window.draw(Bosspwr3);
		window.draw(Newpwr);
		window.draw(Pwr);
		window.draw(Pwr1);




		// Draw the rectangle
		window.draw(rect);
		window.draw(text);
		window.draw(text3);





		// Display things on screen
		window.display();
	}

}

