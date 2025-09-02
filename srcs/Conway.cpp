#include <Conway.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Constructor*/
Conway::Conway() {}

/*Copy Constructor*/
Conway::Conway(Conway const &src)
{
	_width = src._width;
	_height = src._height;
	_grid = src._grid;
}

/*Default Destructor*/
Conway::~Conway() {}

/*Copy assignment operator*/
Conway	&Conway::operator=(Conway const &rhs)
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

Conway::Conway(int width, int height) : _width(width), _height(height) {}

// ************************************************************************** //
//                           | Getters Members  |                             //
// ************************************************************************** //

int				Conway::getWidth() const { return (_width); }
int				Conway::getHeight() const { return (_height); }
const CellSet	&Conway::getGrid() const { return (_grid); }


// ************************************************************************** //
//                            | Public Members |                              //
// ************************************************************************** //

void	Conway::addCell(int x, int y)
{
	_grid.insert(Cell(x, y));
}

/**
 * Compute the next generation of Cells.
 */
void	Conway::iteration()
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