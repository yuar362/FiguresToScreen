#ifndef FIGURES_H
#define FIGURES_H

#include <memory>

#include "representer.h"

enum class FigureTypes {
    Circle = 0,
    Rectangle = 1,
    Square = 2,
    Triangle = 3,
    Total = 4
};

class IFigure {
public:
    virtual void Represent(IRepresenter& representer) const = 0;
    virtual ~IFigure(){};
};

std::unique_ptr<IFigure> GetFigure(FigureTypes type, const Coordinates& point);

#endif // FIGURES_H
