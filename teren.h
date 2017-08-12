#ifndef TEREN_H
#define TEREN_H
#include <QGraphicsView>

#include <QWidget>

lass teren : public QGraphicsView
{
    Q_OBJECT
public:
    explicit teren(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // TEREN_H
