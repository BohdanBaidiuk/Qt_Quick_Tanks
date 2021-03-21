#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>


class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = nullptr);

    void increase();
    int getScore() const;
    void setScore(int value);

private:
    int score = 0;
};

#endif // SCORE_H
