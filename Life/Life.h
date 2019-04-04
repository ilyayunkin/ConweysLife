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
    int getRowCount() const override;
    int getColCount() const override;
    const QString &getStatistics() const override;
    ColorLinesTile *getRootTile() const override;
    ColorLinesTile *getSelectedTile() const override;
    QList<ColorLinesTile *> const&getPath() const override;

    /// Обрабатывает случай поражения.
    void lose();

private slots:
    void update();

public slots:
    void tileClicked(int col, int row) override;
    void start();
signals:
    /// Сигнализирует о начале новой игры.
    void gameReStarted();
};

#endif // JUSTANOTHERLINES_H
