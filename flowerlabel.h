#ifndef FLOWERLABEL_H
#define FLOWERLABEL_H

#include <QLabel>
#include <QEvent>

class FlowerLabel : public QLabel
{
    Q_OBJECT
public:
    FlowerLabel(QWidget *parent = nullptr);
protected:
    bool	eventFilter(QObject *watched, QEvent *event);

signals:
    void click();
};

#endif // FLOWERLABEL_H
