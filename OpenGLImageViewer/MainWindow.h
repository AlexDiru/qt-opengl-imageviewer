#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <qkeyevent>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	void LoadImage() {
		auto fileName = QFileDialog::getOpenFileName(this, "Open Image File", "").toStdString();
		ui.openGLWidget->SetImage(fileName);
	}

	void RotateLeft() {
		ui.openGLWidget->RotateCounterClockwise();
	}

	void RotateRight() {
		ui.openGLWidget->RotateClockwise();
	}

	void ZoomIn() {
		ui.openGLWidget->ZoomIn();
	}

	void ZoomOut() {
		ui.openGLWidget->ZoomOut();
	}

	void PanLeft() {
		ui.openGLWidget->PanLeft();
	}

	void PanRight() {
		ui.openGLWidget->PanRight();
	}

	void keyPressEvent(QKeyEvent *event) override
	{
		if (event->key() == Qt::Key::Key_W)
			ZoomIn();
		else if (event->key() == Qt::Key::Key_S)
			ZoomOut();
		else if (event->key() == Qt::Key::Key_A)
			PanLeft();
		else if (event->key() == Qt::Key::Key_D)
			PanRight();
	}

private:
	Ui::MainWindowClass ui;
};
