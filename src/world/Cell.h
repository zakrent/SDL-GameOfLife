#ifndef GOL_CELL
#define GOL_CELL

namespace world{
	class Cell{
		bool alive;
	public:
		bool getAlive(){return alive;}
		void setAlive(bool _alive){alive = _alive;}
		Cell(bool _alive) : alive(_alive){}
	};
}

#endif
