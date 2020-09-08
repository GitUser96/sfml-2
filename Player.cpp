#include "Player.h"

Player::Player(float radius, int initialRow, int initialColumn, string fileName)
{
	circle.setRadius(radius);
	circle.setPosition(50 + 70 * initialColumn, 50 + 70 * initialRow);
	texture.loadFromFile(fileName);
	circle.setTexture(&texture);
	row = initialRow;
	column = initialColumn;
}
void Player::moveOnWindow(Event e, int arr[][COLUMNS])
{
	switch (e.key.code)
	{
	case Keyboard::Up:
		if (arr[row - 1][column] >= 0)
		{
			circle.move(0, -70);
			row--;
		}
		break;
	case Keyboard::Down:
		if (arr[row + 1][column] >= 0)
		{
			circle.move(0, 70);
			row++;
		}
		break;
	case Keyboard::Right:
		if (arr[row][column + 1] >= 0)
		{
			circle.move(70, 0);
			column++;
		}
		break;
	case Keyboard::Left:
		if (arr[row][column - 1] >= 0)
		{
			circle.move(-70, 0);
			column--;
		}
		break;
	}
}
void Player::drawOnWindow(RenderWindow& window)
{
	window.draw(circle);
}
CircleShape Player::getPlayer()
{
	return circle;
}