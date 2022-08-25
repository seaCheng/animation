﻿#include "sacleButtonView.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

ScaleButtonView::ScaleButtonView(QWidget *parent)
    : QFrame(parent)
{
    initial();
    setConnect();
}

void ScaleButtonView::setConnect()
{
    connect(enlargeBtn, &QPushButton::clicked, [&](){

        if(qScale >= 2.0)
        {
           return;
        }

        qScale = qScale + 0.25;

        lNum->setText(QString("%1 %").arg((int) (qScale * 100)));
        emit s_scaleFreash(qScale);

    });

    connect(zoomOutBtn, &QPushButton::clicked, [&](){

        if(qScale <= 0.5)
        {
           return;
        }

        qScale = qScale - 0.25;

        lNum->setText(QString("%1 %").arg((int) (qScale * 100)));
        emit s_scaleFreash(qScale);

    });
}

void ScaleButtonView::initial()
{
    setObjectName("ScaleButtonView");

    setFixedSize(50, 130);
    enlargeBtn = new QPushButton;
    enlargeBtn->setObjectName("enlargeBtn");
    enlargeBtn->setFixedSize(40, 40);

    zoomOutBtn = new QPushButton;
    zoomOutBtn->setObjectName("zoomOutBtn");
    zoomOutBtn->setFixedSize(40, 40);

    QLabel *lScale = new QLabel;
    lScale->setObjectName("lScale");

    lNum = new QLabel;
    lNum->setObjectName("lNum");
    lNum->setText("100%");
    lNum->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QVBoxLayout * lay = new QVBoxLayout;
    lay->setContentsMargins(0,0,0,0);
    lay->setSpacing(2);

    lay->addWidget(lNum);
    lay->addWidget(lScale);
    lay->addStretch(5);
    lay->addWidget(enlargeBtn);
    lay->addWidget(zoomOutBtn);

    setLayout(lay);

}
