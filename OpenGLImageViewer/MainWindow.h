#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>

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

private:
	Ui::MainWindowClass ui;
};
