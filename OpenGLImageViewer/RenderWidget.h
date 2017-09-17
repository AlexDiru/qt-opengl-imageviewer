#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <QtWidgets/qmessagebox.h>
#include <memory>

#include "SOIL/SOIL.h"
#include "SOILHelper.h"

class RenderWidget : public QOpenGLWidget
{
private:
	GLuint TextureID;
	unsigned char *Image;

	int ImageWidth;
	int ImageHeight;
	int ImageUpperWidth;
	int ImageUpperHeight;

	float ZRotation{ 90 };
	float XTranslation{ 0 };
	float ZTranslation{ 2 };

	bool autoRotateZ{ true };

	const std::unique_ptr<QTimer> updateTimer;

	static bool FEquals(float a, float b) {
		return fabs(a - b) < FLT_EPSILON;
	}

public:
	RenderWidget(QWidget *parent = 0);
	~RenderWidget();

	void RotateClockwise() {
		ZRotation -= 90;
		update();
	}

	void RotateCounterClockwise() {
		ZRotation += 90;
		update();
	}

	void ZoomIn() {
		ZTranslation += 0.1;
		update();
	}

	void ZoomOut() {
		ZTranslation -= 0.1;
		update();
	}

	void PanLeft() {
		XTranslation += 0.1;
		update();
	}

	void PanRight() {
		XTranslation -= 0.1;
		update();
	}

	void SetImage(const std::string& file) {
		int width, height;
		TextureID = SOILHelper::LoadImage(file, ImageWidth, ImageHeight, ImageUpperWidth, ImageUpperHeight);

		if (TextureID == 0) {
			QMessageBox messageBox;
			messageBox.critical(0, "Error", "Failed to load image");
			messageBox.setFixedSize(500, 200);
			return;
		}

		update();
	}

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
};