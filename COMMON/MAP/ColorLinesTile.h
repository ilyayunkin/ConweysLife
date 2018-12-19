/** @file
  * @author Yunkin Ilya.
  */
#ifndef COLORLINESTILE_H
#define COLORLINESTILE_H

#include <QList>
#include <QColor>
#include <QPoint>

/// Класс для представления в памяти тайла (вадрата игрового поля),
/// который может быть свободным или нести одну цветную фишку.
class ColorLinesTile
{
    /// Тайл слева.
    ColorLinesTile *left;
    /// Тайл справа.
    ColorLinesTile *right;
    /// Тайл сверху.
    ColorLinesTile *top;
    /// Тайл снизу.
    ColorLinesTile *bottom;

public:
    /// Используемые в игре цвета
    enum Color
    {
        RED,
        GREEN,
        BLUE,
        BLACK,
        YELLOW,
        MAGENTA,
        CYAN,

        COUNT,
        NONE = COUNT ///< Тайл чист
    };

    explicit ColorLinesTile(Color color = NONE);
    ColorLinesTile *getLeftTile() const;
    ColorLinesTile *getLeftTile(int index) const;
    ColorLinesTile *getRightTile() const;
    ColorLinesTile *getRightTile(int index) const;
    ColorLinesTile *getTopTile() const;
    ColorLinesTile *getTopTile(int index) const;
    ColorLinesTile *getBottomTile() const;
    ColorLinesTile *getBottomTile(int index) const;

    ColorLinesTile *getTile(int col, int row) const;
    /**
     * @brief Возвращает позицию тайла tile относительно тайла,
     * для которого вызван метод.
     * @return Объект точки, где x() - номер колонки, y() - номер строки.
     */
    QPoint getTileCoordinate(const ColorLinesTile *tile) const;

    void setLeftTile(ColorLinesTile *tile);
    void setRightTile(ColorLinesTile *tile);
    void setTopTile(ColorLinesTile *tile);
    void setBottomTile(ColorLinesTile *tile);

    Color getColor() const;
    /**
     * @brief Возвращает значение, предназначенное для отрисовки тайла.
     * @warning Запрещено вызывать для свободных тайлов.
     */
    QColor getQColor() const;

    /// Устанавливает цвет фишки color,
    /// что может соответствовать снятию фишки, если значение равно NONE
    void setColor(Color color);

    /// Возвращает список тайлов при движении вправо и вниз,
    /// включая тайл, для которого метод вызван.
    QList<ColorLinesTile *>getTileList() const;
    QList<ColorLinesTile *>getHorizontalColorList() const;
    QList<ColorLinesTile *>getVerticalColorList() const;
    QList<ColorLinesTile *>getDiagonal1ColorList() const;
    QList<ColorLinesTile *>getDiagonal2ColorList() const;
private:
    /// Цвет фишки, стоящей на тайле.
    Color color;
};


#endif // COLORLINESTILE_H
