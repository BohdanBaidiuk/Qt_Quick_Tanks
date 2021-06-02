#ifndef OBJECT_H
#define OBJECT_H

#include <QQuickItem>
#include <utility>

class Object : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
public:
    explicit Object(QQuickItem *parent = nullptr);

    int width() const;
    void setWidth(int newWidth);

    int height() const;
    void setHeight(int newHeight);

signals:
    void widthChanged();

    void heightChanged();

private:
    std::pair<int,int> coordinate;
    int m_width;
    int m_height;
    // QQuickItem interface
protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);
};

#endif // OBJECT_H
