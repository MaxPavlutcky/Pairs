#ifndef CELL_HPP
#define CELL_HPP

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int key READ key NOTIFY keyChanged)
    Q_PROPERTY(bool isOpen READ isOpen NOTIFY isOpenChanged)
public:
    explicit Cell(QObject *parent = 0);

    int key() const { return m_key; }
    bool isOpen() const { return m_open;}
    void setKey(int key);

signals:
    void keyChanged(int key);
    void isOpenChanged (bool open);
    void cellOpened(Cell *cell);

public slots:
   void open();
   void close ();
private:
    int m_key;
    bool m_open;
};

#endif // CELL_HPP
