#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"WindowSize.h"
#include"Movement.h"
#include"Food.h"
#include"Snake.h"
#include"Collision.h"
#include"Level.h"
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>
#include <thread>


int main()
{
	sf::RenderWindow app_window(sf::VideoMode(WIDTH, HEIGHT+30, 64), "THE SNAKE GAME");
	snake snake_body;
	food snake_food;

	sf::RectangleShape *segm_shape;
	segm_shape = new sf::RectangleShape[(WIDTH*HEIGHT)/(EDGE*EDGE)];
	for (int i = 0; i < ((WIDTH*HEIGHT) / (EDGE*EDGE)); i++)
	{
		segm_shape[i] = sf::RectangleShape(sf::Vector2f(EDGE, EDGE));
		segm_shape[i].setFillColor(sf::Color::Black);
	}
	
	segm_shape[0].setPosition(200, 200);

	sf::CircleShape food_shape(snake_food.get_edge()/2);

	sf::RectangleShape *gridX;
	gridX = new sf::RectangleShape[HEIGHT / EDGE];
	sf::RectangleShape *gridY;
	gridY = new sf::RectangleShape[WIDTH / EDGE];

	sf::Color bleu(0, 200, 0);
	bleu.a = 100;


	for (int i = 1; i < HEIGHT / EDGE; i++)
	{
		gridX[i] = sf::RectangleShape(sf::Vector2f(WIDTH, 1));
		gridX[i].setPosition(0, EDGE*i);
		gridX[i].setFillColor(bleu);
	}
	for (int i = 1; i < WIDTH / EDGE; i++)
	{
		gridY[i] = sf::RectangleShape(sf::Vector2f(1, HEIGHT));
		gridY[i].setPosition(EDGE*i, 0);
		gridY[i].setFillColor(bleu);
	}


	sf::Text score_t;
	sf::Text score_eq;
	sf::Text inst1;
	sf::Text inst2;
	sf::Text paused;

	sf::Music music;
	music.openFromFile("dotto.wav");
	
	sf::SoundBuffer buffer1;
	if(!buffer1.loadFromFile("score2.wav"))
		return -1;
	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("fail2.wav"))
		return -1;
	sf::Sound point;
	point.setBuffer(buffer1);
	sf::Sound fail;
	fail.setBuffer(buffer2);
	
	food_shape.setFillColor(sf::Color::Red);

	snake_food.spawn();

	int score=0;
	int TIME = 300;
	std::string score_equals = "Score:";
	std::string inst1_s = "Esc = quit     P = pause";
	std::string inst2_s = "1-9 = set speed";
	std::string paused_s = "PAUSED";
	sf::Font font;
	sf::Font fontl;
	font.loadFromFile("WarWound.otf");
	fontl.loadFromFile("WarWound.otf");
	score_t.setFont(font);
	score_eq.setFont(fontl);
	inst1.setFont(fontl);
	inst2.setFont(fontl);
	paused.setFont(font);
	paused.setScale(5, 5);
	paused.setPosition(WIDTH / 2 - 235, HEIGHT / 2 - 90);
	score_t.setPosition(WIDTH / 2+30, HEIGHT-5);
	score_eq.setPosition(WIDTH/2-70, HEIGHT-5);
	inst1.setPosition(50, HEIGHT - 5);
	inst2.setPosition(WIDTH-270, HEIGHT - 5);
	score_t.setColor(sf::Color::Black);
	score_eq.setColor(sf::Color::Black);
	inst1.setColor(sf::Color::Black);
	inst2.setColor(sf::Color::Black);
	paused.setColor(sf::Color::Red);

	bool safe=true, game_paused=false;

	while (app_window.isOpen())
	{
		sf::Event event;
		if (music.getStatus() != sf::Music::Playing)
		{
			music.play();
		}
		safe = true;
		while (app_window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				app_window.close();
				return 0;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left && snake_body._head->dir!='R' && safe==true)
			{

				snake_body._head->dir = 'L';
				safe = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right && snake_body._head->dir != 'L' && safe == true)
			{

				snake_body._head->dir = 'R';
				safe = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && snake_body._head->dir != 'D' && safe == true)
			{

				snake_body._head->dir = 'U';
				safe = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && snake_body._head->dir != 'U' && safe == true)
			{

				snake_body._head->dir = 'D';
				safe = false;
			}
			
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			{
				if (game_paused == false)
					game_paused = true;
				else
					game_paused = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
				TIME = set_level(1);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num2))
				TIME = set_level(2);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num3))
				TIME = set_level(3);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num4))
				TIME = set_level(4);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num5))
				TIME = set_level(5);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num6))
				TIME = set_level(6);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num7))
				TIME = set_level(7);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num8))
				TIME = set_level(8);
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Num9))
				TIME = set_level(9);
		}
		if (game_paused == false)
		{
			move(snake_body._head);
			follow(snake_body._head);
			if (food_col(snake_body, snake_food) == true)
			{
				point.play();
				score += 1;
			}
			if (tail_col(snake_body._head) == true)
			{
				snake_body.remove_tail();
				snake_body.set_length(1);
				fail.play();
				score = 0;
			}
		}
	

		std::stringstream ss;
		
		score_eq.setString(score_equals);
		ss << score;
		score_t.setString(ss.str());

		inst1.setString(inst1_s);
		inst2.setString(inst2_s);

		paused.setString(paused_s);

		segm *x = snake_body._head;
		for (int i = 0; i < snake_body.get_length(); i++)
		{
			segm_shape[i].setPosition(x->posX, x->posY);
			x = x->next;
		}

		
		food_shape.setPosition(snake_food.get_pos_x(), snake_food.get_pos_y());
		app_window.clear(sf::Color::White);
		app_window.draw(score_t);
		app_window.draw(score_eq);
		app_window.draw(inst1);
		app_window.draw(inst2);
		app_window.draw(food_shape);
		for (int i = 0; i < snake_body.get_length(); i++)
		{
			app_window.draw(segm_shape[i]);
		}
		for (int i = 1; i < HEIGHT / EDGE; i++)
		{
			app_window.draw(gridX[i]);
		}
		for (int i = 1; i < WIDTH / EDGE; i++)
		{
			app_window.draw(gridY[i]);
		}
		if(game_paused==true)
			app_window.draw(paused);

		app_window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(TIME));
	}
	
	delete[] segm_shape;
	delete[] gridX;
	delete[] gridY;
	return 0;
}