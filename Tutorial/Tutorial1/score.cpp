#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent), score(0)
{
    // draw the text
    setPlainText(QString("Score : ") + QString::number(score));;
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::Increase()
{
    score++;
}

int Score::GetScore() const
{
    return score;
}
