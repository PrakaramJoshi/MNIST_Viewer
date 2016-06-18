#ifndef MNIST_VIEWER_H
#define MNIST_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_mnist_viewer.h"
#include <vector>

class MNIST_Viewer : public QMainWindow
{
	Q_OBJECT
	std::vector<std::vector<double>> m_ar;
	
public:
	MNIST_Viewer(QWidget *parent = 0);

	~MNIST_Viewer();

private:
	Ui::MNIST_ViewerClass ui;

	void AddGrid(QGraphicsScene *_scene, int _index);

	void Update_view(int _image);

	public slots:

	void BrowseFiles();

	void SliderMoved(int _value);

	void KeyPressed(const QString &_text);

};

#endif // MNIST_VIEWER_H
