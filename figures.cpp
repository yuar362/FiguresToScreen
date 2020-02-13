#include <array>

#include "figures.h"

class Circle : public IFigure {
public:
    Circle(const Coordinates& point) : center(point) {}

    void Represent(IRepresenter& representer) const override {
        representer.RepresentCircle(center, radius);
    }
private:
    Coordinates center;
    unsigned int radius = 30;
};

class Rectangle : public IFigure {
public:
    Rectangle(const Coordinates& point) : left_top(point) {}

    void Represent(IRepresenter& representer) const override {
        representer.RepresentRectangle(left_top, width, height);
    }
private:
    Coordinates left_top;
    unsigned int width = 60;
    unsigned int height = 30;
};

class Square : public IFigure {
public:
    Square(const Coordinates& point) : left_top(point) {}

    void Represent(IRepresenter& representer) const override {
        representer.RepresentRectangle(left_top, length, length);
    }
private:
    Coordinates left_top;
    unsigned int length = 30;
};

class Triangle : public IFigure {
public:
    Triangle(const Coordinates& point) :
        vertices{{{point.first - 15, point.second + 10},
                 {point.first, point.second - 15},
                 {point.first + 15, point.second + 10}}} {}

    void Represent(IRepresenter& representer) const override {
        for(size_t i = 0; i < 2; ++i)
            representer.RepresentLine(vertices[i], vertices[i+1]);
        representer.RepresentLine(vertices[2], vertices[0]);
    }
private:
    std::array<Coordinates, 3> vertices;
};

std::unique_ptr<IFigure> GetFigure(FigureTypes type, const Coordinates& point) {
    switch(type) {
    case FigureTypes::Circle:
        return std::make_unique<Circle>(Circle(point));
    case FigureTypes::Rectangle:
        return std::make_unique<Rectangle>(Rectangle(point));
    case FigureTypes::Square:
        return std::make_unique<Square>(Square(point));
    case FigureTypes::Triangle:
        return std::make_unique<Triangle>(Triangle(point));
    default:
        return nullptr;
    }
}

