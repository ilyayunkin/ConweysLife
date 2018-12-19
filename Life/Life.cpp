/** @file
  * @author Yunkin Ilya.
  */
#include "Life.h"

#include <time.h>
#include <assert.h>

#include <QMessageBox>
#include <QTimer>
#include <QApplication>

#include "COMMON/MAP/ColorLinesTileMap.h"

#include "GameData.h"

Life::Life(QObject *parent)
    : AbstractColorLinesGame(parent),
      data(new LifeGameData(this))
{    
    QTimer *t = new QTimer(this);
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(update()));
    t->start(1000);
}

void Life::start()
{
    data->start();
}

void Life::lose()
{
    assert(!data.isNull());

    QMessageBox::StandardButton b =
            QMessageBox::question(0, tr("Game over!"), tr("Do you want to replay?"));
    if(b == QMessageBox::Yes)
    {
        data = QSharedPointer<LifeGameData>(new LifeGameData(this));
    }else{
        emit quitToMenu();
    }
}

int Life::getRowCount() const
{
    return DIMENSION;
}

int Life::getColCount() const
{
    return DIMENSION;
}

const QString &Life::getStatistics() const
{
    assert(!data.isNull());
    return data->statistics;
}

ColorLinesTile *Life::getRootTile() const
{
    assert(!data.isNull());
    return data->tileMap.topLeft;
}

ColorLinesTile *Life::getSelectedTile() const
{
    assert(!data.isNull());
    return data->selection;
}

QList<ColorLinesTile *> const&Life::getPath() const
{
    assert(!data.isNull());
    return data->path;
}

void Life::tileClicked(int col, int row)
{
    assert(!data.isNull());
    data->tileClicked(col, row);
}

void Life::update()
{
    assert(!data.isNull());
    if(data->isStarted()){
        if(data->isLose()){
            lose();
        }else{
            data->update();
        }
    }
}

