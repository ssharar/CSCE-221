#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QWidget>
#include <QPainter>

#include <vector>
#include <algorithm>
using namespace std;

// change the 0 following line to 1 to work on part 3 of PA3
#define PA3_PART3 0

#if PA3_PART3
#include "../SparseMatrix/sparsematrix.h"
#include <QFileDialog>
#include <QString>
#endif

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);

private:
    QColor interpolateColor(double v, double minVal, double maxVal, QColor minColor, QColor maxColor);

private:

#if PA3_PART3
private:
    SparseMatrix *mat;

    struct Button {
      // design a reasonable button class
    };
    Button loadButton;

private:
    // use QFileDialog for matrix loading
    void loadMatrix();
    // visualize the matrix
    void drawMatrix(QPainter &p, const SparseMatrix *m);

    bool isMouseOverButton(int x, int y, const Button &b);
    void drawButton(QPainter &p, const Button &b);
#else
    void drawBox(QPainter &p);
    void drawArray(QPainter &p, const vector<int> &v, int idx);
#endif

signals:

public slots:

};

#endif // WINDOW_H
