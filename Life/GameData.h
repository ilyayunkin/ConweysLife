/** @file
  * @author Yunkin Ilya.
  */
#ifndef ColorLinesGameData_H
#define ColorLinesGameData_H

#include <QObject>

#include "Life.h"
#include "COMMON/MAP/ColorLinesTileMap.h"

enum
{
    /// Количество тайлов в строке или столбце.
    DIMENSION = 9,
};

class LifeGameData: public QObject
{
    Q_OBJECT

    int fieldSide;
    bool lose;
    bool started;
    bool staticState; ///<  Система застабилизировалась
    /// Последний успешно проделанный путь между тайлами.
public:
    QList<ColorLinesTile *> path;

    ColorLinesTileMap tileMap;
    /// Выделенный тайл с фишкой.
    ColorLinesTile *selection;
    QString statistics;

    explicit LifeGameData(Life *game, unsigned fieldSide = 0);
private:
    Life *game;
    LifeGameData();
    explicit LifeGameData(LifeGameData&);
    LifeGameData &operator =(const LifeGameData&);
    int countNei(ColorLinesTile *tile);

public slots:
public:
    void start();
    void update();
    void tileClicked(int col, int row);

    bool isLose();
    bool isStarted();
    int getRowCount() const;
    int getColCount() const;
};

#endif // ColorLinesGameData_H
