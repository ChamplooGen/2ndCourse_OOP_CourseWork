#include "Base.h"

int Base::makeX(int len, int deg) const
{
	return (len*cos(rad(deg)));
}

int Base::makeY(int len, int deg) const
{
	return (len*sin(rad(deg)));
}