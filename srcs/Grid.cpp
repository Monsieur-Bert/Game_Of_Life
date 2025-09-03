#include <Grid.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Constructor*/
Grid::Grid() {}

/*Copy Constructor*/
Grid::Grid(Grid const &src)
{
	_width = src._width;
	_height = src._height;
	_grid = src._grid;
}

/*Default Destructor*/
Grid::~Grid() {}

/*Copy assignment operator*/
Grid	&Grid::operator=(Grid const &rhs)
{
	if (this != &rhs)
	{
		_width = rhs._width;
		_height = rhs._height;
		_grid = rhs._grid;
	}
	return (*this);
}


// ************************************************************************** //
//                        | Constructor Overloading |                         //
// ************************************************************************** //

Grid::Grid(int width, int height) : _width(width), _height(height) {}

// ************************************************************************** //
//                           | Getters Members  |                             //
// ************************************************************************** //

int				Grid::getWidth() const { return (_width); }
int				Grid::getHeight() const { return (_height); }
const CellSet	&Grid::getGrid() const { return (_grid); }


// ************************************************************************** //
//                            | Public Members |                              //
// ************************************************************************** //

void	Grid::addCell(int x, int y)
{
	_grid.insert(Cell(x, y));
}

/**
 * Compute the next generation of Cells.
 */
void	Grid::iteration()
{
	std::unordered_map<Cell, int, CellHash>	neighborCount;
	for(const Cell& c : _grid) {
		for(const Cell& n : c.neighbors()) {
			neighborCount[n]++;
		}
	}

	CellSet next;
	for(const auto& [cell, count] : neighborCount) {
		if(count == 3 || (count == 2 && _grid.count(cell)))
			next.insert(cell);
	}
	_grid = std::move(next);
}

// ************************************************************************** //
//                         | Operators Overloading |                          //
// ************************************************************************** //

/**
 * Tranform our coordonate into a integer.
 * @return A functor hash as size_t.
 */
size_t CellHash::operator()(const Cell& c) const
{
	return (std::hash<int>()(c.getX()) ^ (std::hash<int>()(c.getY()) << 1));
}