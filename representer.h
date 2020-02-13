#ifndef REPRESENTER_H
#define REPRESENTER_H

using Coordinates = std::pair<int, int>;

class IRepresenter {
public:
    virtual void RepresentLine(const Coordinates& first_point,
                          const Coordinates& last_point) = 0;
    virtual void RepresentCircle(const Coordinates& center, unsigned int radius) = 0;
    virtual void RepresentRectangle(const Coordinates& left_top,
                               unsigned int width, unsigned int height) = 0;
    virtual ~IRepresenter(){}
};
#endif // REPRESENTER_H
