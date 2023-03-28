#ifndef HOMEPOP_H
#define HOMEPOP_H

#include <QQuickItem>
#include <QObject>
class HomePop : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mode READ get_mode WRITE set_mode NOTIFY mode_changed)
    Q_PROPERTY(bool is_connected READ is_connected() WRITE set_connection NOTIFY connection_changed)

    public:
    explicit HomePop(QObject *parent = nullptr);
    QString get_mode();
    bool is_connected();
    void set_mode(QString);
    void set_connection(bool);

    signals:
    void mode_changed();
    void connection_changed();



    public slots:
    void show_home();
    void position_changed(int x, int y);

   private:
    QString m_mode;
    bool m_is_connected;
};

#endif // HOMEPOP_H
