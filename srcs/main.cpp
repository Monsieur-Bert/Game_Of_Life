#include <gameOfLife.hpp>
#include <Grid.hpp>
#include <Renderer.hpp>

void	debugPrint(Grid const &game)
{
	for (int y = 0; y < game.getHeight(); ++y)
	{
		for (int x = 0; x < game.getWidth(); ++x)
		{
			if (game.getGrid().count(Cell(x, y)))
				std::cout << "0";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}


int main() {
	Grid game(G_WIGHT, G_HEIGHT);

	// Cliper
	// game.addCell(10, 10);
	// game.addCell(10, 0);
	// game.addCell(9, 10);

	// Glider
	game.addCell(1,0);
	game.addCell(2,1);
	game.addCell(0,2);
	game.addCell(1,2);
	game.addCell(2,2);

	Renderer renderer(W_WIDTH, W_HEIGHT, CELL_SIZE);

	while (true) {
		game.iteration();
		renderer.render(game);
		// debugPrint(game);
	}

	return (0);
}