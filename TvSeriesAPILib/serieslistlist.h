#ifndef SERIESLISTLIST_H
#define SERIESLISTLIST_H

#include <QObject>
#include <QAbstractItemModel>
#include "serieslist.h"
#include "model/signallist.h"
#include "API/trakttvapi.h"

class SeriesListList : public QObject
{
    Q_OBJECT

public:
    explicit SeriesListList(TraktTvAPI * traktTvAPI, QObject *parent);

signals:

public slots:
    QAbstractItemModel * seriesListListModel();

private:
    SignalList<SeriesList*> mSeriesListList;
    TheTvDBAPI * mTheTvDBAPI;
    TraktTvAPI * mTraktTvAPI;
};

#endif // SERIESLISTLIST_H
