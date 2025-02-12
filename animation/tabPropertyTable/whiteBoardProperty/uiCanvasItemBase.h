﻿#ifndef UICANVASITEMBASE_H
#define UICANVASITEMBASE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsObject>
#include <QPaintEvent>

enum ItemResizeDirection
{
    d_none,
    d_upLeft,
    d_topMiddle,
    d_upRight,
    d_leftMiddle,
    d_rightMiddle,
    d_bottomLeft,
    d_bottomRight,
    d_bottomMiddle
};
Q_DECLARE_METATYPE(ItemResizeDirection)

class UICanvasItemBase : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    enum ItemOperator
    {
        t_none,
        t_move,
        t_resize,
        t_rotate
    };

    void setResizeAble(bool bResize)
    {
        m_resize = bResize;
    }

    void setRectSize(QSize size)
    {
        m_size = size;
    }

    QSize getRectSize()
    {
        return m_size;
    }


    UICanvasItemBase(QMenu *conMenu, QGraphicsItem* parentItem = nullptr);
    ~UICanvasItemBase() override;

    // 设置改变大小相关属性
    void setItemResizeable(bool resizeable);
    void setItemResizeRatio(bool resizeRation, qreal rationValue);

    //刷新鼠标
    void refreashCursor(QPointF pos, QRectF outLintRect);

    virtual void sizeRefreash();
private:
    // 初始化Icon
    void initIcon(void);

    static QImage m_rotateIcon;

    QPixmap m_rotatePixmap;

    // 设置是否能够更改尺寸
    bool m_isResizeable = true;
    bool m_isRatioScale = true;
    qreal m_ratioValue = 1.0;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) final;
    QPainterPath shape() const override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

    // 自定义元素绘制
    virtual void customPaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    QSize m_size = QSize(50,50);
    ItemOperator m_itemOper = t_none;

    // 获取自定义绘制所需要的矩形
    virtual QRectF getCustomRect(void) const;

    double lengthPos(const QPointF &p1, const QPointF &p2);

protected:
    // 处理Item上的类型
    virtual void mouseMoveMoveOperator(const QPointF& scenePos, const QPointF& loacalPos);
    virtual void mouseMoveResizeOperator(const QPointF& scenePos, const QPointF& loacalPos, const QPointF& lPos);
    virtual void mouseMoveRotateOperator(const QPointF& scenePos, const QPointF& loacalPos);

    QPointF m_pos;              // 本地所坐标点击的点
    QPointF m_pressedPos;       // 场景坐标点击的点
    QPointF m_startPos;         // Item再场景坐标的起始坐标
    QTransform m_transform;     // 变换矩阵
    qreal m_rotate = 0.0;       // 当前旋转角度

    QPointF pTopRota;
    QPointF pTopMiddle;
    QPointF pRightMiddle;
    QPointF pLeftMiddle;
    QPointF pBottomMiddle;

    int m_nInterval = 1;
    int m_nEllipseWidth = 6;    // 半径

signals:
    void onClickedCopyItem(void);

private:

    // 画笔设置
    QColor m_cPenColor;
    int m_nPenWidth = 1;
    // 画刷设置
    QColor m_cBrushColor;
    ItemResizeDirection itemDiretion = d_none;

    bool m_resize = true;

    QMenu *myContextMenu;

};
#endif

