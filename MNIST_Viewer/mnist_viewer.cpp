#include "mnist_viewer.h"
#include "qpushbutton.h"
#include <qfiledialog.h>
#include <iostream>
#include <fstream>
#include <QtCore\qstring.h>
#include <string>
using namespace std;

static QString sq(const std::string &_str) {
	return QString(_str.c_str());
};

static std::string qs(const QString &_qstr) {
	return std::string(_qstr.toLocal8Bit().constData());
};

int ReverseInt(int i) {
	unsigned char ch1, ch2, ch3, ch4;
	ch1 = i & 255;
	ch2 = (i >> 8) & 255;
	ch3 = (i >> 16) & 255;
	ch4 = (i >> 24) & 255;
	return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
int ReadMNIST(std::string _file, int DataOfAnImage, vector<vector<double>> &arr) {
	ifstream file(_file, ios::binary);
	int number_of_images = 0;
	if (file.is_open()) {
		int magic_number = 0;
		
		int n_rows = 0;
		int n_cols = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		if (number_of_images > 0) {
			arr.clear();
			arr.resize(number_of_images, vector<double>(784));
		}
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = ReverseInt(n_rows);
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = ReverseInt(n_cols);
		for (int i = 0; i<number_of_images; ++i) {
			for (int r = 0; r<n_rows; ++r) {
				for (int c = 0; c<n_cols; ++c) {
					unsigned char temp = 0;
					file.read((char*)&temp, sizeof(temp));
					arr[i][(n_rows*r) + c] = (double)temp;
				}
			}
		}
	}
	return number_of_images;
}
MNIST_Viewer::MNIST_Viewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_ar.resize(1, vector<double>(784));
	connect(ui.pushButton,&QPushButton::clicked, this, &MNIST_Viewer::BrowseFiles);// , Qt::QueuedConnection);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &MNIST_Viewer::KeyPressed);// , Qt::QueuedConnection);
	connect(ui.verticalSlider, &QSlider::valueChanged, this, &MNIST_Viewer::SliderMoved);// , Qt::QueuedConnection);
	QSlider *slider = ui.verticalSlider;
	slider->setMinimum(1);
	slider->setMaximum(1);
	slider->setSliderPosition(1);

	// The smaller of two natural steps that an abstract sliders provides 
	// and typically corresponds to the user pressing an arrow key.
	slider->setSingleStep(1);
	Update_view(1);
}

MNIST_Viewer::~MNIST_Viewer()
{

}
void MNIST_Viewer::BrowseFiles() {
	QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"), "/path/to/file/", tr("MNIST image files (*.*)"));
	if (fileNames.size() > 0) {
		m_ar.clear();
		std::string filePath = qs(fileNames[0]);
		ui.lineEdit->setText(fileNames[0]);
		m_ar.resize(1, vector<double>(784));
		auto number_of_images=  ReadMNIST(filePath, 784, m_ar);
		ui.lineEdit_2->setText("1");
		ui.lineEdit_3->setText(QString::number(number_of_images));
		QSlider *slider = ui.verticalSlider;
		slider->setMinimum(1);
		slider->setMaximum(number_of_images);
		slider->setSliderPosition(1);

		// The smaller of two natural steps that an abstract sliders provides 
		// and typically corresponds to the user pressing an arrow key.
		slider->setSingleStep(1);
		Update_view(1);
	}
}

void CreateScene(std::vector<double> &_v, QGraphicsScene *_scene) {

	for (int r = 0; r < 28; r++) {
		for (int c = 0; c < 28; c++) {
			QPolygonF polygon;
			int max_x = (c + 1) * 10;
			int max_y = (r + 1) * 10;
			int min_x = (c) * 10;
			int min_y = (r)* 10;
			polygon << QPointF(min_x, min_y) << QPointF(min_x, max_y)
				<< QPointF(max_x, max_y)
				<< QPointF(max_x, min_y);

			QPen p;
			int color = _v[c + (r * 28)] ;
			if (color != 0) 				{
				int i = 0;
}
			p.setColor(QColor(color, color, color));
			p.setWidth(0);
			QBrush b;
			b = QBrush(QColor(color, color, color));
			_scene->addPolygon(polygon, p, b);
		}
	}
}

void MNIST_Viewer::Update_view(int _image) {
	QGraphicsScene* scene = new QGraphicsScene(ui.graphicsView->parent());
	AddGrid(scene, _image-1);
	ui.graphicsView->setScene(scene);
}

void MNIST_Viewer::AddGrid(QGraphicsScene *_scene,int _index) {
	if (_index >= m_ar.size())
		return;
	auto &image = m_ar[_index];
	CreateScene(image, _scene);
}

void MNIST_Viewer::KeyPressed(const QString &_text) {

	try {
		int val_int= _text.toInt();
		if (val_int > 0 && val_int <= ui.lineEdit_3->text().toInt()) {
			ui.verticalSlider->setValue(val_int);
			Update_view(val_int);
		}
	}
	catch (...) {

	}
}

void MNIST_Viewer::SliderMoved(int _value) {
	ui.lineEdit_2->setText(QString::number(_value));
	//Update_view(_value);
}