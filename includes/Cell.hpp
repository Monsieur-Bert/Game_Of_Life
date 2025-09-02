#ifndef Cell_HPP
# define Cell_HPP

#include <vector>
#include <gameOfLife.hpp>

class Cell
{
	public:
		/*Canonical Form*/
		Cell(void);
		Cell(Cell const &src);
		~Cell(void);
		Cell &operator=(Cell const &rhs);

		/*Constructor Overloading*/
		Cell(int x, int y);

		/*Getters Members*/
		int	getX(void) const;
		int	getY(void) const;

		/*Operators Overloading*/
		bool operator==(const Cell &other) const;

		/*Public Members*/
		std::vector<Cell> neighbors() const;

	private:
		int	_x;
		int	_y;

};

#endif // Cell_HPP