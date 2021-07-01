#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <time.h>  
#include<iostream>
#include <string>
#include <fstream> 

using namespace std;
using namespace sf;

int cheak(int **pole, int X, int Y) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (pole[i][j] == 0) {
				return 1;
			}
		}
	}
	return 0;
}
int check(int** pole, int X, int Y) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (pole[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}
void create(int** pole, int X, int Y) {
	int random;
	int x_1, x_2, y_1, y_2;
	int num;
	while (cheak(pole, X, Y)) {
		do {
			x_1 = rand() % (X);
			y_1 = rand() % (Y);
		}while (pole[x_1][y_1] != 0);
		do {
			x_2 = rand() % (X);
			y_2 = rand() % (Y);
		}while (pole[x_2][y_2] != 0);

		if (pole[x_1][y_1] != 0) {
			continue;
		}
		if (pole[x_2][y_2] != 0) {
			continue;
		}
		if (x_1 == x_2 && y_1 == y_2) {
			continue;
		}
		num = rand() % 3 + 1;
		pole[x_1][y_1] = num; 
		pole[x_2][y_2] = num;
		for (int i = 0; i < X; i++) {
			cout << "|";
			for (int j = 0; j < Y; j++) {
				cout << pole[i][j] << "|";
			}
			cout << endl;
		}
		cout << endl;
	}
}
void win_or_losing(int**pole, int& x_1, int& x_2, int& y_1, int& y_2, int& v_x, int& v_y, Music* music) {
	int ran;
	if (pole[x_1][y_1] == pole[x_2][y_2]) {
		cout << "won" << endl;
		pole[x_2][y_2] = 0;
		pole[x_1][y_1] = 0;
		ran = rand() % 11;
		music[ran].play();
	}
	else {
		cout << "losing" << endl;
	}
	x_1 = 0;
	x_2 = 0;
	y_1 = 0;
	y_2 = 0;
	v_x = 99;
	v_y = 99;
}

int main()
{
	int X;
	int Y;
	cin >> X;
	cin >> Y;
	int player_x = 0;
	int player_y = 0;
	int game_x_1 = 0;
	int game_y_1 = 0;
	int game_x_2 = 0;
	int game_y_2 = 0;
	int vision_x = 0;
	int vision_y = 0;
	float timer = 0;;
	int num = 0;
	srand(time(NULL));
	int** pole = new int*[X];
	for (int i = 0; i < X; i++) {
		pole[i] = new int[Y];
		for (int j = 0; j < Y; j++) {
			pole[i][j] = 0;
		}
	}
	create(pole, X, Y);
	for (int i = 0; i < X; i++) {
		cout << "|";
		for (int j = 0; j < Y; j++) {
			cout << pole[i][j] << "|";
		}
		cout << endl;
	}
	
	RenderWindow window(VideoMode(Y*150 + (Y-1)*10, X * 150 + (X - 1) * 10), "Game");

	Texture t1,t2,t3, noname, ram;
	t1.loadFromFile("Для игры/1.jpg"); 
	t3.loadFromFile("Для игры/3.jpg");
	t2.loadFromFile("Для игры/2.jpg");
	noname.loadFromFile("Для игры/4.jpg");
	ram.loadFromFile("Для игры/44.jpg");
	Music* music = new Music[12];
	music[0].openFromFile("Для игры/boy-next-door.ogg");
	music[1].openFromFile("Для игры/dungeon-master.ogg");
	music[2].openFromFile("Для игры/fisting-is-300-.ogg");
	music[3].openFromFile("Для игры/fucking-slaves-get-your-ass-back-here.ogg");
	music[4].openFromFile("Для игры/fuck-you1.ogg");
	music[5].openFromFile("Для игры/iam-cumming.ogg");
	music[6].openFromFile("Для игры/now-loading.ogg");
	music[7].openFromFile("Для игры/oh-shit-iam-sorry.ogg");
	music[8].openFromFile("Для игры/spank.ogg");
	music[9].openFromFile("Для игры/stick-your-finger-in-my-ass.ogg");
	music[10].openFromFile("Для игры/woo.ogg");
	music[11].openFromFile("Для игры/swallow-my-cu.ogg");

	Sprite player;
	player.setTexture(ram);
	Sprite** s = new Sprite*[X];
	Clock clock;
	for (int i = 0; i < X; i++) {
		s[i] = new Sprite[Y];
	}
	
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			s[i][j].setTexture(noname);
		}
	}

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			window.clear();
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed || check(pole, X, Y)) {
				cout << time << endl;
				cout << num << endl;
				window.close();
			}
			else if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Left) && player_y > 0) {//player_y-- влево
					player_y--;
					window.clear();
				}
				if (Keyboard::isKeyPressed(Keyboard::Right) && player_y < Y - 1) {//player_y++ вправо
					player_y++;
					window.clear();
				}
				if (Keyboard::isKeyPressed(Keyboard::Down) && player_x < X - 1) {//player_x++ вниз
					player_x++;
					window.clear();
				}
				if (Keyboard::isKeyPressed(Keyboard::Up) && player_x > 0) { //player_x-- вверх
					player_x--;
					window.clear();
				}
				if (pole[player_x][player_y] != 0) {
					if (Keyboard::isKeyPressed(Keyboard::Enter) && game_x_1 == 0 && game_y_1 == 0) { // выбор
						game_x_1 = player_x;
						game_y_1 = player_y;
						vision_x = game_x_1;
						vision_y = game_y_1;
						num++;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Enter) && game_x_2 == 0 && game_y_2 == 0) {
						if (game_x_1 != player_x || game_y_1 != player_y) {
							game_x_2 = player_x;
							game_y_2 = player_y;
							num++;
							win_or_losing(pole, game_x_1, game_x_2, game_y_1, game_y_2, vision_x, vision_y, music);
							window.clear();
							window.display();
						}
					}
				}
			}
		}
		
		// Отрисовка окна	
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if (pole[i][j] != 0) {
					if (vision_x == i && vision_y == j) {
						if (pole[vision_x][vision_y] == 1) {
							s[vision_x][vision_y].setTexture(t1);
							s[vision_x][vision_y].setPosition(vision_y * 160, vision_x * 160);
							window.draw(s[vision_x][vision_y]);
						}
						else if (pole[vision_x][vision_y] == 2) {
							s[vision_x][vision_y].setTexture(t2);
							s[vision_x][vision_y].setPosition(vision_y * 160, vision_x * 160);
							window.draw(s[vision_x][vision_y]);
						}
						else if (pole[vision_x][vision_y] == 3) {
							s[vision_x][vision_y].setTexture(t3);
							s[vision_x][vision_y].setPosition(vision_y * 160, vision_x * 160);
							window.draw(s[vision_x][vision_y]);
						}
					}
					else if (player_x == i && player_y == j) {
						player.setPosition(j * 160, i * 160);
						window.draw(player);
						continue;
					}
					else {
						s[i][j].setTexture(noname);
						s[i][j].setPosition(j * 160, i * 160);
						window.draw(s[i][j]);
					}
				}
			}
		}
		
		window.display();
	}
	return 0;
}