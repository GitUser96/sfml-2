#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
const int ROWS = 10, COLUMNS = 10;

class Player
{
private:
	CircleShape circle;
	Texture texture;
	int row;
	int column;
public:
	Player(float radius, int initialRow, int initialColumn, string fileName);
	void moveOnWindow(Event e, int arr[][COLUMNS]);
	void drawOnWindow(RenderWindow& window);
	CircleShape getPlayer();
};