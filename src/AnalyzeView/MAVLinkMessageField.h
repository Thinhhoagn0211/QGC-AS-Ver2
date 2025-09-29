#pragma once

#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>
#include <QtCore/QPointF>
#include <QtCore/QString>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QLineSeries>

Q_DECLARE_LOGGING_CATEGORY(MAVLinkMessageFieldLog)

class QGCMAVLinkMessage;
class MAVLinkChartController;

class QGCMAVLinkMessageField : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString label READ label CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(QString value READ value NOTIFY valueChanged)
    Q_PROPERTY(bool selectable READ selectable NOTIFY selectableChanged)
    Q_PROPERTY(int chartIndex READ chartIndex CONSTANT)
    Q_PROPERTY(const QtCharts::QAbstractSeries* series READ series NOTIFY seriesChanged)

public:
    QGCMAVLinkMessageField(const QString &name, const QString &type, QGCMAVLinkMessage *parent = nullptr);
    ~QGCMAVLinkMessageField();

    QString name() const { return _name; }
    QString label() const;
    QString type() const { return _type; }
    QString value() const { return _value; }
    bool selectable() const { return _selectable; }
    bool selected() const { return !!_pSeries; }
    const QtCharts::QAbstractSeries* series() const { return _pSeries; }
    const QList<QPointF>* values() const { return &_values; }
    qreal rangeMin() const { return _rangeMin; }
    qreal rangeMax() const { return _rangeMax; }
    int chartIndex() const;

    void setSelectable(bool sel);
    void updateValue(const QString &newValue, qreal v);

    void addSeries(MAVLinkChartController *chartController, QtCharts::QAbstractSeries *series);
    void delSeries();
    void updateSeries();

signals:
    void seriesChanged();
    void selectableChanged();
    void valueChanged();

private:
    QString _type;
    QString _name;
    QGCMAVLinkMessage *_msg = nullptr;

    QString _value;
    bool _selectable = true;
    int _dataIndex = 0;
    qreal _rangeMin = 0;
    qreal _rangeMax = 0;
    QList<QPointF> _values;

    QtCharts::QAbstractSeries *_pSeries = nullptr;
    MAVLinkChartController *_chartController = nullptr;
};