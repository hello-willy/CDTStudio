#include "cdtproject.h"
#include "cdtprojecttreeitem.h"
#include <QMenu>

CDTProject::CDTProject(QObject *parent):
    QObject(parent),
    actionAddImage(new QAction(tr("Add Image"),this))
{
    connect(actionAddImage,SIGNAL(triggered()),this,SLOT(addImageLayer()));
}

void CDTProject::addImageLayer()
{
    CDTImageLayer *image = new CDTImageLayer();
    image->setName("name");
    image->setPath("path");
    addImageLayer(image);


}

void CDTProject::addImageLayer(CDTImageLayer *image)
{
    images.push_back(image);
}

void CDTProject::addImageLayer(const QString name, const QString path)
{
    CDTImageLayer *image = new CDTImageLayer();
    image->setName(name);
    image->setPath(path);
    addImageLayer(image);
}

void CDTProject::setName(const QString &n)
{
    name = n;
}

void CDTProject::setPath(const QString &p)
{
    path = p;
}

void CDTProject::onContextMenu(QWidget* parent)
{
    QMenu* menu =new QMenu(parent);
    menu->addAction(actionAddImage);
    menu->exec(QCursor::pos());
}


QDataStream &operator <<(QDataStream &out,const CDTProject &project)
{
    out<<project.images.size();
    foreach (CDTImageLayer* image, project.images) {
        out<<*image;
    }
    out<<project.isFileExsit<<project.name<<project.path;
    return out;
}


QDataStream &operator >>(QDataStream &in, CDTProject &project)
{
    int count;
    in>>count;
    for (int i=0;i<count;++i)
    {
        CDTImageLayer* image = new CDTImageLayer();
        in>>*image;
        project.images.push_back(image);
    }
    in>>project.isFileExsit>>project.name>>project.path;
    return in;
}
