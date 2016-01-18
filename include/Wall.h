#include "Constants.h"
#include "Colors.h"

class Wall
{
public:
    Wall();
    void setColor(unsigned number, Color color);
    Color getColor(unsigned number);
    void lock();
    void unlock();
    bool isLocked() const;
private:
    bool locked;
    Color colors[numberOfCells];
};
