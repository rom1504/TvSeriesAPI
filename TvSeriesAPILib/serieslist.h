#ifndef SERIESLIST_H
#define SERIESLIST_H

#include <QObject>
#include <QStringListModel>

#include "series.h"
#include "model/signallist.h"
#include "API/thetvdbapi.h"

class SeriesList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel * seriesListFilteredModel READ seriesListFilteredModel NOTIFY seriesListFilteredModelChanged)
    Q_PROPERTY(QAbstractItemModel * seriesListModel READ seriesListModel NOTIFY seriesListModelChanged)
    Q_PROPERTY(QAbstractItemModel * seriesListUpcomingModel READ seriesListUpcomingModel NOTIFY seriesListUpcomingModelChanged)
    Q_PROPERTY(int seriesCount READ seriesCount NOTIFY seriesCountChanged)
    Q_PROPERTY(QAbstractItemModel * autocompleteModel READ autocompleteModel NOTIFY autocompleteModelChanged)
    Q_PROPERTY(QString genre READ genre WRITE setGenre NOTIFY genreChanged)

public:
    explicit SeriesList(TheTvDBAPI* theTvDBAPI, SeriesList* filterBySeriesList,QObject *parent); // set filterBySeriesList to nullptr if you don't want to filter
    explicit SeriesList(TheTvDBAPI* theTvDBAPI, bool /* not sorted */,SeriesList* filterBySeriesList, QObject *parent);
    int addSeries(Series * series);
    SignalList<Series *> *series();
    void saveSeries(QString fileName="") const;
    int seriesCount() const;
    QString genre() const;
    bool added(int id) const;
    void loadSeries(QString fileName="");


    void setGenre(QString genre);

    QAbstractItemModel * seriesListFilteredModel();
    QAbstractItemModel * seriesListModel();
    QAbstractItemModel * seriesListUpcomingModel();
    QAbstractItemModel * autocompleteModel();

private:
    SignalListAdapter<Series*> * seriesListModelT();
    void removeSeries(Series* series);

signals:
    void seriesListFilteredModelChanged();
    void seriesListModelChanged();
    void seriesListUpcomingModelChanged();
    void searchCompleted(QAbstractItemModel * searchListModel,int resultsCount);
    void seriesAdded(int addIndex);
    void seriesCountChanged();
    void autocompleteModelChanged();
    void genreChanged();

public slots:
    Series *getSeries(int row) const;
    void completeAddSaveSeries(Series* series);
    void removeSaveSeries(Series *series);
    void searchSeries(const QString &seriesName);
    void updateAutocompleteModel(const QString &beginSeriesName);

private:
    QStringListModel * mAutocompleteModel;
    SignalList<Series*> mSeries;
    QString mSaveFileName;
    QSet<int> mIds;
    QString mGenre;
    SeriesList* mFilterBySeriesList;
    TheTvDBAPI* mTheTvDBAPI;
};
Q_DECLARE_METATYPE (SeriesList*)

#endif // SERIESLIST_H
