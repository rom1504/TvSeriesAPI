#ifndef SEASON_H
#define SEASON_H

#include <QObject>
#include <QAbstractItemModel>
//#include <QtQml>
//#include <QQmlEngine>


#include "episode.h"
#include "model/signallist.h"
#include "adapter/signallistadapter.h"

class Series;

class Season : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number NOTIFY numberChanged)
    Q_PROPERTY(Image* banner READ banner NOTIFY bannerChanged)
    Q_PROPERTY(Image* poster READ poster NOTIFY posterChanged)
    Q_PROPERTY(QAbstractItemModel * seasonModel READ seasonModel NOTIFY seasonModelChanged)
    Q_PROPERTY(bool seen READ seen WRITE setSeen NOTIFY seenChanged)
    Q_PROPERTY(double seenRatio READ seenRatio NOTIFY seenRatioChanged)
    Q_PROPERTY(int episodeCount READ episodeCount NOTIFY episodeCountChanged)
    Q_PROPERTY(int episodeSeenCount READ episodeSeenCount NOTIFY episodeSeenCountChanged)
    Q_PROPERTY(QDate firstAired READ firstAired NOTIFY firstAiredChanged)
    Q_PROPERTY(double airedRatio READ airedRatio NOTIFY airedRatioChanged)
    Q_PROPERTY(int episodeAiredCount READ episodeAiredCount NOTIFY episodeAiredCountChanged)
    Q_PROPERTY(QAbstractItemModel * seasonUpcomingModel READ seasonUpcomingModel NOTIFY seasonUpcomingModelChanged)

public:
    explicit Season(int number,Image* banner,Image* poster,Series *parent);
    void addEpisode(Episode * episode);
    int number() const;
    Image* banner() const;
    Image* poster() const;
    QAbstractItemModel *seasonModel();
    QAbstractItemModel *seasonUpcomingModel();
    bool seen() const;
    int episodeSeenCount() const;
    int episodeCount() const;
    double seenRatio() const;
    QDate firstAired() const;
    double airedRatio() const;
    int episodeAiredCount() const;
    Series * series() const;

    void setSeen(bool seen);
    void setBanner(Image* banner);
    void setPoster(Image* poster);

    SignalList<Episode *> * episodes();

    Episode* findEpisode(int episodeNumber);

private:
    SignalListAdapter<Episode *> *seasonModelT();

signals:
    void numberChanged();
    void bannerChanged();
    void posterChanged();
    void seasonModelChanged();
    void seenChanged();
    void seenRatioChanged();
    void episodeCountChanged();
    void episodeSeenCountChanged();
    void firstAiredChanged();
    void airedRatioChanged();
    void episodeAiredCountChanged();
    void seasonUpcomingModelChanged();

public slots:
    Episode *getEpisode(int row) const;

private:
    int mNumber;
    Image* mBanner;
    Image* mPoster;
    SignalList<Episode *> mEpisodes;
    Series* mSeries;

};
Q_DECLARE_METATYPE (Season*)

#endif // SEASON_H
