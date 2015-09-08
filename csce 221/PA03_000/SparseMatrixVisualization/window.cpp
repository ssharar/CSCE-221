#include "window.h"
#include <time.h>

Window::Window() {
  setWindowTitle("Random Array Visualization");
  resize(800, 600);

  // create the button here
}

QColor Window::interpolateColor(double v, double minVal, double maxVal,
                                QColor minColor, QColor maxColor) {
     double ratio = (maxVal-v)/(maxVal-minVal);
     double h = minColor.hsvHueF() * ratio + maxColor.hsvHueF() * (1.0 - ratio);
     return QColor::fromHsvF(h, 1.0, 1.0);
}

#if !PA3_PART3
void Window::drawBox(QPainter &painter) {
    // compute the drawing region
    int w = width();
    int h = height();

    double edgeRatio = 0.15;
    double contentRatio = 1.0 - edgeRatio*2.0;

    int left = edgeRatio * w, top = edgeRatio * h;
    int cw = contentRatio * w, ch = contentRatio * h;

    // setup pen and brush
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(QColor(200, 225, 255), Qt::SolidPattern));

    painter.drawRect(left, top, cw, ch);
}

void Window::drawArray(QPainter &painter, const vector<int> &v, int idx) {
    // compute the drawing region
    int w = width();
    int h = height();

    double edgeRatio = 0.15;
    double contentRatio = 1.0 - edgeRatio*2.0;

    int left = edgeRatio * w, top = edgeRatio * h;
    int cw = contentRatio * w, ch = contentRatio * h;

    // find out the maximum and minmum number in the vector
    int maxval = *(std::max_element(v.begin(), v.end()));
    int minval = *(std::min_element(v.begin(), v.end()));

    // compute the y coordinates of the 0-line
    int zeropos = top + ch;
    double stepHeight = ch / double(maxval);
    if( minval < 0 ) {
        zeropos = maxval / double(maxval - minval) * ch + top;
        stepHeight = ch / double(maxval - minval);
    }

    // compute the width of a vertical bar
    double binWidth = cw / double(v.size());

    // setup the pen
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

    // draw all the bins
    for(int i=0;i<(int)v.size();++i) {

        // take the value of the i-th bin
        int bv = v[i];

        // compute the height of this bin
        int binHeight = abs(-bv) * stepHeight;

        // compute the x-coordiantes of left side of this bin
        int bleft = i * binWidth + left;

        // compute the y-coordinates of the top of this bin
        int btop;
        if( bv >= 0 ) {
          btop = zeropos - binHeight;
        }
        else {
          btop = zeropos;
        }

        // choose a color for this bar
        QColor barColor = interpolateColor(v[i], minval, maxval, Qt::blue, Qt::red);

        // use a special brush for the bar with largest value
        if( i==idx ) painter.setBrush(QBrush(Qt::black, Qt::Dense5Pattern));
        else painter.setBrush(QBrush(barColor, Qt::SolidPattern));

        // draw the bar as a rectangle
        painter.drawRect(bleft, btop, binWidth, binHeight);
    }
}

#else

void Window::drawButton(QPainter &painter, const Button &b) {
    // implement this function, place the button reasonably
}

void Window::drawMatrix(QPainter &painter, const SparseMatrix *m) {
    // implement this function, use of interpolateColor to compute color for
    // matrix elements
}

void Window::loadMatrix() {
    // implement this function, make use of QFileDialog
}

bool Window::isMouseOverButton(int x, int y, const Button &b) {
    // implement this function, detect if the given coordiantes lie side the
    // button region
}

#endif

void Window::paintEvent(QPaintEvent *)
{
    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage
    QPainter painter(this);

    //The setRenderHint() call enables antialiasing, telling QPainter to use different
    //color intensities on the edges to reduce the visual distortion that normally
    //occurs when the edges of a shape are converted into pixels
    painter.setRenderHint(QPainter::Antialiasing, true);

    // clear the canvas
    painter.fillRect(0, 0, width(), height(), Qt::white);

#if PA3_PART3
    // draw the button
    drawButton(painter, loadButton);

    // draw the matrix
    drawMatrix(painter, mat);
#else
    // draw the background box
    drawBox(painter);

    // draw a random array
    vector<int> v(64);
    for(int i=0;i<64;++i) v[i] = rand() % 256;
    drawArray(painter, v, std::max_element(v.begin(), v.end()) - v.begin());
#endif
}

void Window::mousePressEvent(QMouseEvent *e) {
#if PA3_PART3
    if( isMouseOverButton(e->pos().x(), e->pos().y(), loadButton) ) loadMatrix();
#endif
    repaint();
    e->accept();
}
