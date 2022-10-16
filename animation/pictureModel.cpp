﻿// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "pictureModel.h"
#include "pictureItem.h"
#include "mvvm/interfaces/undostackinterface.h"
#include "mvvm/model/modelutils.h"
#include "mvvm/factories/modeldocumentfactory.h"


#include <QDebug>
#include<QRandomGenerator>
#include <QPixmap>

using namespace ModelView;

PictureModel::PictureModel() : SessionModel("PictureModel")
{
    registerItem<PictureItem>();
    populateModel();
    setUndoRedoEnabled(true);
}

//! Inserts new item of given type at given position.

PictureItem * PictureModel::insertConnectableItem(const std::string& itemType, double xpos, double ypos, const QPixmap & pix)
{
    PictureItem * item;
    Utils::BeginMacros(this, "insertConnectableItem");

    if ( item = dynamic_cast<PictureItem*>(insertItem<PictureItem>()); item) {

        item->setQpixmap(pix);
        item->setX(xpos);
        item->setY(ypos);

    }else
    {
        qDebug()<<"insert failed....";
    }


    Utils::EndMacros(this);

    return item;
}

void PictureModel::insertConnectItemImg(QPixmap pix)
{
    PictureItem * item;
    Utils::BeginMacros(this, "insertConnectItemImg");

    if ( item = dynamic_cast<PictureItem*>(insertItem<PictureItem>()); item) {

        item->setQpixmap(pix);

    }else
    {
        qDebug()<<"insert failed....";
    }


    Utils::EndMacros(this);
}

void PictureModel::insertConnectItems(QStringList lst)
{
    Utils::BeginMacros(this, "insertConnectableItems");
    for(auto file : lst)
    {
        PictureItem * item;
        if ( item = dynamic_cast<PictureItem*>(insertItem<PictureItem>()); item) {

            QImage pix = QImage(file);

            //qDebug()<<"pix x:"<<pix.width()<<" pix y"<<pix.height();
            QPixmap pi;
            pi.convertFromImage(pix);
            item->setX(pix.width());
            item->setY(pix.height());
            item->setQpixmap(pi);


        }else
        {
            qDebug()<<"insert failed....";
        }

    }

    Utils::EndMacros(this);
}

void PictureModel::insertEmptyPicture()
{
    QImage img(300,300,QImage::Format_ARGB32);
    img.fill(QColor(255,255,255,0));
    PictureItem * item;
    Utils::BeginMacros(this, "insertEmptyPicture");

    if ( item = dynamic_cast<PictureItem*>(insertItem<PictureItem>()); item) {

        item->setQpixmap(QPixmap::fromImage(img));
        item->setX(0);
        item->setY(0);

    }else
    {
        qDebug()<<"insert failed....";
    }


    Utils::EndMacros(this);

    ;

}

void PictureModel::insertConnectItems(const std::vector<QPixmap> lst)
{
    Utils::BeginMacros(this, "insertConnectableItemVec");
    for(auto file : lst)
    {
        PictureItem * item;
        if ( item = dynamic_cast<PictureItem*>(insertItem<PictureItem>()); item) {

            item->setX(file.toImage().width());
            item->setY(file.toImage().height());
            item->setQpixmap(file);

        }else
        {
            qDebug()<<"insert failed....";
        }

    }

    Utils::EndMacros(this);
}

void PictureModel::eraseConnectItem(ModelView::SessionItem * item)
{
    Utils::DeleteItemFromModel(item);
}

void PictureModel::eraseConnectItems(const std::vector<ModelView::SessionItem *> lst)
{
    Utils::BeginMacros(this, "eraseConnectItems");
    for(auto item : lst)
    {

        Utils::DeleteItemFromModel(item);
    }

    Utils::EndMacros(this);
}

void PictureModel::loadFromFile(const std::string& name)
{
    if (name.empty())
        return;
    auto document = ModelView::CreateJsonDocument({this});
    document->load(name);
}

void PictureModel::saveToFile(const std::string& name)
{
    if (name.empty())
        return;
    auto document = ModelView::CreateJsonDocument({this});
    document->save(name);
}

//! Populates the model with an exemplary hierarchical structure representing an initial node editor
//! content.

void PictureModel::populateModel()
{
    //
}

