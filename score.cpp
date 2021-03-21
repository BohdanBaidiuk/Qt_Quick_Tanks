#include "score.h"

#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() const
{
    return score;
}

void Score::setScore(int value)
{
    score = value;
}
