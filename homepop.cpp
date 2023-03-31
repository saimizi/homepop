extern "C" {
	#include <jswmlib.h>
}

#include "homepop.h"

HomePop::HomePop(QObject *parent): QObject(parent)
{
    this->m_is_connected = false;
    this->m_mode = QString("800x480");
    qDebug()<<"Created"<<Qt::endl;
}

QString HomePop::get_mode() {
    return this->m_mode;
}

void HomePop::set_mode(QString m)
{
    if (!this->m_mode.compare(m, Qt::CaseSensitivity::CaseSensitive)){
        this->m_mode = m;
        emit this->mode_changed();
    }
}

bool HomePop::is_connected ()
{
    return this->m_is_connected;
}

void HomePop::set_connection(bool connected)
{
    if (this->m_is_connected != connected) {
        this->m_is_connected = connected;
        emit this->connection_changed();
    }
}

void HomePop::show_home()
{
    qDebug()<<"ShowHome!"<<Qt::endl;
}

void HomePop::position_changed(int x, int y)
{
	qDebug()<<"Notify JSWM position changed." << Qt::endl;

	/*
	 * Since the size is not changed, w and h are set to 0
	 */
	jswmcon_set_role_relative_pos(NULL, "INFO", x, y, 0, 0);

}

