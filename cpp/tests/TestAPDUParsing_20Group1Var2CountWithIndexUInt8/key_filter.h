#ifndef _key_filter_h_
#define _key_filter_h_

#include <QtWidgets>

class key_filter : public QObject
{
	Q_OBJECT
public:
	explicit key_filter(QObject *parent = 0);

protected:
	bool eventFilter(QObject *obj, QEvent *event);

signals:
	void sig_key_1();
	void sig_key_2();
	void sig_key_3();
	void sig_key_4();

	void sig_key_5();
	void sig_key_6();
	void sig_key_7();
	void sig_key_8();

	void sig_ctrlkey(int);

	void sig_key_up();
	void sig_key_down();
	void sig_key_pgDown();
	void sig_key_pgUp();
	void sig_key_left();
	void sig_key_right();
	void sig_key_home();
	void sig_key_end();
	void sig_key_enter();
	void sig_key_esc();
	void sig_key_asterisk();

	void sig_key_f1();
	void sig_key_f2();
	void sig_key_f3();
	void sig_key_f8();
};

#endif  
