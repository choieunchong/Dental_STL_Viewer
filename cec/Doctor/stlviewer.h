#ifndef STLVIEWER_H
#define STLVIEWER_H

#include <QWidget>

namespace Ui {
class STLViewer;
}

class STLViewer : public QWidget
{
    Q_OBJECT

public:
    explicit STLViewer(QWidget *parent = nullptr);
    ~STLViewer();

private:
    Ui::STLViewer *ui;
};

#endif // STLVIEWER_H
