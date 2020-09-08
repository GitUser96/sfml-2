#include "Player.h"

void main()
{
					//$whoami
	int arr[ROWS][COLUMNS];
	// Reading from File
	ifstream inputFile;
	inputFile.open("Board.txt");
	if (inputFile.is_open())
	{
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				if (!inputFile.eof())
					inputFile >> arr[i][j];
		inputFile.close();
	}
	else
		cout << "Error loading Board.txt ..." << endl;

	// SFML
	RenderWindow window;
	window.create(VideoMode(800, 800), "Simple Maze");

	Player p(35, 1, 1, "CuteFace.png");
	Texture bricksTexture, grassTexture;
	bricksTexture.loadFromFile("Bricks.png");
	grassTexture.loadFromFile("Grass.png");
	RectangleShape board[ROWS][COLUMNS];
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j].setSize(Vector2f(70, 70));
			board[i][j].setPosition(50 + 70 * j, 50 + 70 * i);
			if (arr[i][j] < 0)
			{
				board[i][j].setTexture(&bricksTexture);
				board[i][j].setFillColor(Color::Yellow);
			}
			else
			{
				board[i][j].setTexture(&grassTexture);
				board[i][j].setFillColor(Color::Green);
			}
		}
	Event e;
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			else if (e.type == Event::KeyPressed)
				p.moveOnWindow(e, arr);
		}
		window.clear();
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				window.draw(board[i][j]);
		// window.draw(p.getPlayer());
		p.drawOnWindow(window);
		window.display();
	}
}