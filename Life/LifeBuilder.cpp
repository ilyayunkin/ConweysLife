/** @file
  * @author Yunkin Ilya.
  */
#include "LifeBuilder.h"

#include "Life.h"
#include "COMMON/GUI/ColorLinesWidget.h"

#include <QVBoxLayout>
#include <QPushButton>

void ColorLinesBuilder::createGame(AbstractColorLinesGame *&game,
                                   QWidget *&widget)
{    
    Life *newGame = new Life;
    game = newGame;
    widget = new QWidget;

    QVBoxLayout *mainLayout = new QVBoxLayout(widget);

    {
        QPushButton *startButton = new QPushButton("Start");
        mainLayout->addWidget(startButton);
        QObject::connect(startButton, SIGNAL(clicked(bool)),
                         newGame, SLOT(start()));
        QObject::connect(startButton, SIGNAL(clicked(bool)),
                         startButton, SLOT(hide()));
        QObject::connect(newGame, SIGNAL(gameReStarted()),
                         startButton, SLOT(show()));
    }
    {
        /// Виджет игрового поля
        ColorLinesWidget *linesWidget = new ColorLinesWidget(game);

        linesWidget->setElementType(ColorLinesWidget::RECTANGLE);
        linesWidget->setElementWidth(0.6);
        mainLayout->addWidget(linesWidget);

        mainLayout->setMargin(0);
    }
}

QString ColorLinesBuilder::getName() const
{
    return "Conwey's Life";
}

QIcon ColorLinesBuilder::getIcon() const
{
    return QIcon(":/icons/icons/lines_ico.png");
}
