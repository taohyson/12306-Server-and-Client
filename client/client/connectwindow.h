#include "ui_connect.h"
#include "client.h"

class ConnectWindow: public QWidget{
	Q_OBJECT
private:
	Ui::connect ui;
	Client *client;
private slots:
	void connectToServer();
public:
	ConnectWindow(Client *client);
	~ConnectWindow();
};