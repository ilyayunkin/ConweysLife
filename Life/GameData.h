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
    /// Минимальная длина линии одного цвета.
    MIN_LINE = 5,
};

class LifeGameData: public QObject
{
    Q_OBJECT

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

    explicit LifeGameData(Life *game);
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
};

#endif // ColorLinesGameData_H
