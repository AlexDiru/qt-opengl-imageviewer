#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle("OpenGL Image Viewer");

	connect(ui.loadImageButton, SIGNAL(clicked(bool)), this, SLOT(LoadImage()));
	connect(ui.rotateLeftButton, SIGNAL(clicked(bool)), this, SLOT(RotateLeft()));
	connect(ui.rotateRightButton, SIGNAL(clicked(bool)), this, SLOT(RotateRight()));
	connect(ui.zoomInButton, SIGNAL(clicked(bool)), this, SLOT(ZoomIn()));
	connect(ui.zoomOutButton, SIGNAL(clicked(bool)), this, SLOT(ZoomOut()));
}
