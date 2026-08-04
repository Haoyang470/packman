#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QPainter>
#include <QPaintEvent>

class CannonField : public QWidget
{
public:
    CannonField(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setBrush(Qt::blue);
        painter.drawEllipse(20, 20, 30, 30);
    }
};


class GameBoard : public QWidget
{
public:
    GameBoard(QWidget *parent = nullptr) : QWidget(parent)
    {
        QPushButton *quit = new QPushButton("Quit");
        quit->setFont(QFont("Times", 18, QFont::Bold));
        connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

        CannonField *cannonField = new CannonField;

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(quit);
        layout->addWidget(cannonField);
        setLayout(layout);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameBoard board;
    board.setGeometry(100, 100, 300, 200);
    board.show();

    return a.exec();
}
