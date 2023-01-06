#ifndef MAINSERVCER_H
#define MAINSERVCER_H

#include <QWidget>

namespace Ui {
class MainServcer;
}

class MainServcer : public QWidget
{
    Q_OBJECT

public:
    explicit MainServcer(QWidget *parent = nullptr);
    ~MainServcer();

private:
    Ui::MainServcer *ui;
};

#endif // MAINSERVCER_H
