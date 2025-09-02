#include <Cell.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Constructor*/
Cell::Cell() : _x(0), _y(0) {}

/*Copy Constructor*/
Cell::Cell(Cell const &src)
{
	_x = src._x;
	_y = src._y;
}

/*Default Destructor*/
Cell::~Cell() {}

/*Copy assignment operator*/
Cell	&Cell::operator=(Cell const &rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
	}
	return (*this);
}


// ************************************************************************** //
//                        | Constructor Overloading |                         //
// ************************************************************************** //

Cell::Cell(int x, int y) : _x(x), _y(y) {}

// ************************************************************************** //
//                           | Getters Members  |                             //
// ************************************************************************** //

int	Cell::getX(void) const { return (_x);}
int	Cell::getY(void) const { return (_y);}

// ************************************************************************** //
//                           | Public Members |                               //
// ************************************************************************** //

/**
 * Look and stock statement of cell's neigbors
 */
std::vector<Cell>	Cell::neighbors() const
{
	static const int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},
								   {0,-1},        {0,1},
								   {1,-1}, {1,0}, {1,1}};
	
	std::vector<Cell>	neighbors;
	neighbors.reserve(8);
	for (int i = 0; i < 8; i++)
		neighbors.push_back(Cell(_x + dirs[i][0], _y + dirs[i][1]));

	return (neighbors);
}

// ************************************************************************** //
//                         | Operators Overloading |                          //
// ************************************************************************** //

bool Cell::operator==(const Cell &other) const
{
	return ((_x == other._x) && (_y == other._y));
}
