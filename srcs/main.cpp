#include <gameOfLife.hpp>
#include <Conway.hpp>

void	debugPrint(Conway const &game)
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
	Conway game(40, 20);

	// test add blinker
	game.addCell(20,10);
	game.addCell(21,10);
	game.addCell(22,10);

	for(int gen = 0; gen < 3; ++gen)
	{
		std::cout << "Generation " << gen << ":\n";
		debugPrint(game);
		game.iteration();
	}

	return 0;
}