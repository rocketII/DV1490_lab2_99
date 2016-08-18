#ifndef ICDDL_H
#define ICDDL_H

enum direction { NEXT, PREV };
template <typename T>
class ICircularDoubleDirectedList
{
public:
	virtual ~ICircularDoubleDirectedList() {};
	virtual void add(T& item) = 0;
	virtual bool remove(T& item) = 0; // requires == operator of item
	virtual int size() const = 0;
	virtual T& currentItem() = 0;
	virtual void changeDirection() = 0;
	virtual void move() = 0;
};

#endif