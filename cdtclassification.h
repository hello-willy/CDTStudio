#ifndef CDTCLASSIFICATION_H
#define CDTCLASSIFICATION_H

#include <QtCore>
#include <QMap>
#include <QVariant>
#include "cdtprojecttreeitem.h"

class CDTClassification:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString shapefilePath READ shapefilePath WRITE setShapefilePath NOTIFY shapefilePathChanged)
    Q_PROPERTY(QString method READ method)
public:
    explicit CDTClassification(QObject* parent=0);

    friend QDataStream &operator<<(QDataStream &out, const CDTClassification &classification);
    friend QDataStream &operator>>(QDataStream &in, CDTClassification &classification);

    QString name()const;
    QString shapefilePath() const;
    QString method()const;

    void setName(const QString& name);
    void setShapefilePath(const QString &shpPath);
    void setMethodParams(const QString& methodName,const QMap<QString,QVariant> &params);

signals:
    void nameChanged();
    void shapefilePathChanged();
    void methodParamsChanged();

public slots:
    void updateTreeModel(CDTProjectTreeItem* parent);

private:
    QString m_name;
    QString m_shapefilePath;
    QString m_method;
    QMap<QString,QVariant> m_params;
};

QDataStream &operator<<(QDataStream &out, const CDTClassification &classification);
QDataStream &operator>>(QDataStream &in, CDTClassification &classification);

#endif // CDTCLASSIFICATION_H