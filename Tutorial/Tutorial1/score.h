#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = nullptr);
    void Increase();
    int GetScore() const;
private:
    int score;
};

#endif // SCORE_H
