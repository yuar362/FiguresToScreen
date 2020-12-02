#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

using Coordinates = std::pair<int, int>;

class Representer {
public:
    Representer(QWidget* widget) : painter(widget) {}

    void RepresentLine(const Coordinates& first_point,
                  const Coordinates& last_point) {
        painter.drawLine(first_point.first, first_point.second,
                         last_point.first, last_point.second);
    }

    void RepresentCircle(const Coordinates& center, unsigned int radius) {
        painter.drawEllipse(center.first - radius, center.second - radius, 2*radius, 2*radius);
    }

    void RepresentRectangle(const Coordinates &left_top,
                       unsigned int width, unsigned int height) {
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

    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event) {
    if (mouse_event->button() == Qt::LeftButton) {

    }
    else if (mouse_event->button() == Qt::RightButton) {

    }

    QMainWindow::mousePressEvent(mouse_event);
}
