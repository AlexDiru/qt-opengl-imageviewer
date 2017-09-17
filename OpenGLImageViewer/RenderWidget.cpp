#include "RenderWidget.h"

#include <thread>
#include <QTimer>

RenderWidget::RenderWidget(QWidget *parent)
	: QOpenGLWidget(parent), updateTimer(std::make_unique<QTimer>(this))
{
	auto const updateFn = [this]() { update(); };
	connect(updateTimer.get(), &QTimer::timeout, this, updateFn);
	updateTimer->start(10);
}

RenderWidget::~RenderWidget()
{

}

void RenderWidget::initializeGL()
{
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void RenderWidget::paintGL()
{
	//For non ^2 images
	float textureX = float(ImageWidth) / ImageUpperWidth;
	float textureY = float(ImageHeight) / ImageUpperHeight;

	if (autoRotateZ)
		ZRotation += 0.5f;

	glClearColor(0, 0, 0, 1);

	glPushMatrix();
	glTranslatef(XTranslation, 0, ZTranslation);
	glRotatef(ZRotation, 0.0f, 0, 1);

	glBindTexture(GL_TEXTURE_2D, TextureID);
	glEnable(GL_TEXTURE_2D);

	float hRatio = (float)ImageWidth / ImageHeight;
	float wRatio = (float)ImageHeight / ImageWidth;

	float ImageWidthNormalised, ImageHeightNormalised;

	if (ImageHeight > ImageWidth) {
		ImageHeightNormalised = 1;
		ImageWidthNormalised = (float)ImageWidth / ImageHeight;
	}
	else if (ImageWidth > ImageHeight) {
		ImageWidthNormalised = 1;
		ImageHeightNormalised = (float)ImageHeight / ImageWidth;
	} 
	else {
		ImageWidthNormalised = ImageHeightNormalised = 1;
	}

	//Swap because wrong way round...
	float t = ImageWidthNormalised;
	ImageWidthNormalised = ImageHeightNormalised;
	ImageHeightNormalised = t;

	glBegin(GL_QUADS);
	glTexCoord2f(0, textureY);
	glVertex3f(-ImageWidthNormalised /2, ImageHeightNormalised /2, 0.0f);

	glTexCoord2f(0, 0);
	glVertex3f(ImageWidthNormalised / 2, ImageHeightNormalised / 2, 0.0f);

	glTexCoord2f(textureX, 0);
	glVertex3f(ImageWidthNormalised / 2, -ImageHeightNormalised / 2, 0.0f);

	glTexCoord2f(textureX, textureY);
	glVertex3f(-ImageWidthNormalised / 2, -ImageHeightNormalised / 2, 0.0f);
	glEnd();

	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void RenderWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 0.01, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}