#include <QMouseEvent>
#include <ctime>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class Representer : public IRepresenter {
public:
    Representer(QWidget* widget) : painter(widget) {}

    void RepresentLine(const Coordinates& first_point,
                  const Coordinates& last_point) override {
        painter.drawLine(first_point.first, first_point.second,
                         last_point.first, last_point.second);
    }

    void RepresentCircle(const Coordinates& center, unsigned int radius) override {
        painter.drawEllipse(center.first, center.second, radius, radius);
    }

    void RepresentRectangle(const Coordinates &left_top,
                       unsigned int width, unsigned int height) override {
        painter.drawRect(left_top.first, left_top.second,
                         width, height);
    }

private:
    QPainter painter;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent* paint_event) {
    Representer painter(this);
    for(const auto& fig : figures)
        fig->Represent(painter);
    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event) {
    if (mouse_event->button() == Qt::LeftButton) {
        std::srand(std::time(nullptr));
        auto random = rand() % static_cast<int>(FigureTypes::Total);
        FigureTypes type = static_cast<FigureTypes>(random);
        auto figure = GetFigure(type, {mouse_event->pos().x(), mouse_event->pos().y()});
        if(figure) {
            figures.push_back(std::move(figure));
            repaint();
        }
    }

    QMainWindow::mousePressEvent(mouse_event);
}
