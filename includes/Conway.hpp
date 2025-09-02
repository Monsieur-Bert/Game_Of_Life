#ifndef CONWAY_HPP
# define CONWAY_HPP

#include <unordered_set>
#include <unordered_map>
#include <Cell.hpp>
#include <gameOfLife.hpp>

struct CellHash
{
	size_t operator()(const Cell& c) const;
};

using CellSet = std::unordered_set<Cell, CellHash>;

class Conway
{
	public:
		/*Canonical Form*/
		Conway(void);
		Conway(Conway const &src);
		~Conway(void);
		Conway &operator=(Conway const &rhs);

		/*Constructor Overloading*/
		Conway(int width, int height);

		/*Getters Members*/
		int				getWidth() const;
		int				getHeight() const;
		const CellSet	&getGrid() const;

		/*Public Members*/
		void	addCell(int x, int y);
		void	iteration();

	private:
		int		_width;
		int		_height;
		CellSet	_grid;
};

#endif // CONWAY_HPP