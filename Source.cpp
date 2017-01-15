#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;


int const cols = 10;
int const rows = 10;
//double grid[cols][rows];
// Just for loggin
int openSet[];
int closedSet[];
int width = 800;
int height = 800;
double sizx = (width / cols);
double sizy = (height / rows);
sf::RenderWindow window(sf::VideoMode(width, height), "A-STAR");
int start[cols][rows];
int end[cols][rows];


class Spot {
public:

	void drawRect() {
		sf::RectangleShape rect(sf::Vector2f(sizx, sizy));
		//sf::CircleShape rect(50.f);
		rect.setPosition((pos_x), (pos_y));
		rect.setOutlineThickness(0.5);
		rect.setOutlineColor(sf::Color::Black);
		if (start == true) { rect.setFillColor(sf::Color::Blue); }
		if (end == true) { rect.setFillColor(sf::Color::Red); }
		window.draw(rect);
	}
	
	void isStart(bool is) {
		start = is;
	}
	void isEnd(bool ise) {
		end = ise;
	}
	
	void setPos_x(int iterator) {
		pos_x = sizx*iterator;
	}
	void setPos_y(int jterator) {
		pos_y = sizy*jterator;
	}

	int getPos_x() {
		//cout << "pos_x = " << pos_x << endl;
		return pos_x;
	}
private:
	int pos_x;
	int pos_y;
	int f = 0;
	int g = 0;
	int h = 0;
	bool start = false;
	bool end = false;

};
int main()
{
	Spot grid[cols][rows];

	
	sf::CircleShape shape(100.f);
	sf::RectangleShape rect(sf::Vector2f(sizx, sizy));
	sf::RectangleShape rect2(sf::Vector2f(sizx, sizy));
	//rect.setPosition((sizx* 7)-5, (sizy * 0));
	//rect2.setPosition((sizx * 6)-10, (sizy * 0));
	//rect.setOutlineColor(sf::Color::Black);
	//rect2.setOutlineColor(sf::Color::Black);
	//rect2.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{

				grid[i][j].setPos_x(i);
				grid[i][j].setPos_y(j);
				grid[i][j].drawRect();
				if (i == 0 && j == 0) { grid[i][j].isStart(true); }
				if (i == cols-1 && j == rows-1) { grid[i][j].isEnd(true); }
			}
		}

		//window.clear();
		//	window.draw(shape);
		//window.draw(rect);
		//window.draw(rect2);
		window.display();
	}

	return 0;
}