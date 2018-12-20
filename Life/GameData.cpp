/** @file
  * @author Yunkin Ilya.
  */
#include "GameData.h"

#include <time.h>

LifeGameData::LifeGameData(Life *game)
    : lose(false),
      started(false),
      staticState(false),
      tileMap(DIMENSION, DIMENSION),
      selection(0),
      game(game)
{
}

static bool isNotFree(ColorLinesTile *tile)
{
   return (tile != 0) && tile->getColor() != ColorLinesTile::NONE;
}

int LifeGameData::countNei(ColorLinesTile *tile)
{
    int nei = 0;
    ColorLinesTile *l = tile->getLeftTile();
    ColorLinesTile *r = tile->getRightTile();

    nei+= isNotFree(tile->getBottomTile()) ? 1 :0;
    nei+= isNotFree(tile->getTopTile()) ? 1 :0;
    if(l != 0)
    {
        nei+= isNotFree(l) ? 1 :0;
        nei+= isNotFree(l->getBottomTile()) ? 1 :0;
        nei+= isNotFree(l->getTopTile()) ? 1 :0;
    }
    if(r != 0)
    {
        nei+= isNotFree(r) ? 1 :0;
        nei+= isNotFree(r->getBottomTile()) ? 1 :0;
        nei+= isNotFree(r->getTopTile()) ? 1 :0;
    }
    return nei;
}

void LifeGameData::update()
{
    bool changed = false;

    QList<ColorLinesTile *> toSet;
    QList<ColorLinesTile *> toFree;

    for(int row = 0; row < DIMENSION; row++){
        ColorLinesTile *left = tileMap.topLeft->getTile(0, row);
        ColorLinesTile *tile = left;
        while(tile != 0){
            int neiCount = countNei(tile);
            if(tile->getColor() == ColorLinesTile::NONE){
                if(neiCount == 3){
                    toSet.push_back(tile);
                    changed = true;
                }
            }else
            {
                if(neiCount == 3 || neiCount == 2){
                }else{
                    toFree.push_back(tile);
                    changed = true;
                }
            }
            tile = tile->getRightTile();
        }
    }

    foreach(ColorLinesTile *t, toSet)
    {
        tileMap.set(t, ColorLinesTile::GREEN);
    }
    foreach(ColorLinesTile *t, toFree)
    {
        tileMap.free(t);
    }

    if(!changed){
        staticState = true;
    }
}

void LifeGameData::start()
{
    started = true;
}

void LifeGameData::tileClicked(int col, int row)
{
    ColorLinesTile *tile = tileMap.topLeft->getTile(col, row);
    if(!started){
        if(tile->getColor() == ColorLinesTile::NONE){
            tileMap.set(tile, ColorLinesTile::GREEN);
        }else
        {
            tileMap.free(tile);
        }
    }
}

bool LifeGameData::isLose()
{
    bool emptyMap = tileMap.ownedList.isEmpty();
    return emptyMap || staticState;
}
bool LifeGameData::isStarted()
{
    return started;
}
