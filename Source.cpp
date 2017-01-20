#include <SFML\Graphics.hpp>
#include <iostream>
#include <time.h>
#include <random>

using namespace std;


int const cols = 20;
int const rows = 20;
int width = 800;
int height = 800;
double sizx = (width / cols);
double sizy = (height / rows);

sf::RenderWindow window(sf::VideoMode(width, height), "A-STAR");




class Spot {
public:

	void drawRect() {
		sf::RectangleShape rect(sf::Vector2f(sizx, sizy));
		rect.setPosition((pos_x), (pos_y));
		rect.setOutlineThickness(0.5);
		rect.setOutlineColor(sf::Color::Black);
		//if (start == true) { rect.setFillColor(sf::Color::Blue); }
		if (end == true) { rect.setFillColor(sf::Color::Red); }
		if (open == true) { rect.setFillColor(sf::Color::Green); }
		if (closed == true) { rect.setFillColor(sf::Color::Yellow); }

		window.draw(rect);
	}
	void isClosed(bool is) {
		closed = is;
	}
	void isOpen(bool is) {
		open = is;
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
	
	bool getIsOpen() {
		return open;
	}
	bool getIsClosed() {
		return closed;
	}
	int getPos_x() {
		//cout << "pos_x = " << pos_x << endl;
		return pos_x;
	}
	int getPos_y() { return pos_y; }
	
	int f = 0;
	int g = 0;
	int h = 0;
private:
	int pos_x;
	int pos_y;

	bool start = false;
	bool end = false;
	bool open = false;
	bool closed = false;

};


int main()
{
	srand(time(NULL));
	Spot grid[cols][rows];
	int startX = 0;
	int startY = 0;
	int endX = cols-1;
	int endY = rows-1;
	bool testisobstacle = false;
	bool testisobstacleE = false;
	vector<Spot> openSet;
	vector<Spot> closedSet;

	grid[startX][startY].setPos_x(startX);
	grid[startX][startY].setPos_y(startY);
	grid[startX][startY].isStart(true);

	grid[endX][endY].setPos_x(endX);
	grid[endX][endY].setPos_y(endY);
	grid[endX][endY].isEnd(true);



	
	openSet.push_back(grid[startX][startY]);


	
	/*---------------------------------------------------------------   DRAW  --------------------------------------------------------*/
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		for (unsigned int i = 0; i < closedSet.size(); i++)
		{
			closedSet[i].isClosed(true);
		}
		for (unsigned int i = 0; i < openSet.size(); i++)
		{
			openSet[i].isOpen(true);
		}

		if (openSet.size() > 0) {
			int winner = 0;
			for (int i = 0; i < openSet.size(); i++) {
				if (openSet[i].f < openSet[winner].f)
				{
					winner = i;
				}
			}

			auto current = openSet[winner];

			if (current.getPos_x() == grid[endX][endY].getPos_x() && current.getPos_y() == grid[endX][endY].getPos_y()) {
				cout << "Here it is!" << endl;
			}
			closedSet.push_back(current);
			openSet.erase(openSet.begin()+winner);
			
	}
		else {
			// no solution
		}

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				grid[i][j].setPos_x(i);
				grid[i][j].setPos_y(j);
				grid[i][j].drawRect();
			}

		}
		window.display();
	}

	return 0;
}
