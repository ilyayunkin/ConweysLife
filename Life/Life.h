/** @file
  * @author Yunkin Ilya.
  */
#ifndef JUSTANOTHERLINES_H
#define JUSTANOTHERLINES_H

#include "../COMMON/INTERFACES/AbstractColorLinesGame.h"

#include <QSharedPointer>

class Life;

class LifeGameData;

/// Реализация игры "Жизнь"
class Life : public AbstractColorLinesGame
{
    Q_OBJECT
    /// Приватная реализация
    QSharedPointer<LifeGameData> data;
public:
    explicit Life(QObject *parent = 0);
    int getRowCount() const;
    int getColCount() const;
    const QString &getStatistics() const;
    ColorLinesTile *getRootTile() const;
    ColorLinesTile *getSelectedTile() const;
    QList<ColorLinesTile *> const&getPath() const;

    /// Обрабатывает случай поражения.
    void lose();

private slots:
    void update();

public slots:
    void tileClicked(int col, int row);
    void start();
};

#endif // JUSTANOTHERLINES_H
