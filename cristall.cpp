#include "cristall.h"
#include "ui_cristall.h"

Cristall::Cristall(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cristall)
{
    ui->setupUi(this);
    connect(ui->addFile, SIGNAL(triggered()), this, SLOT(slotAddFile()));
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(slotExit()));
    connect(ui->FiX, SIGNAL(textChanged(QString)), this, SLOT(slotChangeAngle()));
    connect(ui->FiY, SIGNAL(textChanged(QString)), this, SLOT(slotChangeAngle()));
    connect(ui->FiZ, SIGNAL(textChanged(QString)), this, SLOT(slotChangeAngle()));

    canvas = new Frame(this);
    ui->canvasLayout->addWidget(canvas);
}

Cristall::~Cristall()
{
    canvas->deleteLater();
    delete ui;
}

void Cristall::slotAddFile()
{
    QString path = QFileDialog::getOpenFileName(0, "Выберете файл!", "", "*.vtk");
    if (path == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Вы не выбрали файл!");
        return;
    }
    else
    {
        QFileInfo info(path);
        ui->uiPath->setText(info.baseName());
        canvas->upload(path);
    }
}

void Cristall::slotExit()
{
    this->close();
}


void Cristall::slotChangeAngle()
{
    canvas->setFiX(ui->FiX->text().toDouble());
    canvas->setFiY(ui->FiY->text().toDouble());
    canvas->setFiZ(ui->FiZ->text().toDouble());
}

void Cristall::on_goStepX_clicked()
{
    canvas->rotateX();
}

void Cristall::on_goStepY_clicked()
{
    canvas->rotateY();
}

void Cristall::on_goStepZ_clicked()
{
    canvas->rotateZ();
}

void Cristall::on_goScaleX_clicked()
{
    canvas->scaleX(ui->scaleX->text().toDouble());
}

void Cristall::on_goScaleY_clicked()
{
    canvas->scaleY(ui->scaleY->text().toDouble());
}

void Cristall::on_goScaleZ_clicked()
{
    canvas->scaleZ(ui->scaleZ->text().toDouble());
}

void Cristall::on_goX_clicked()
{
    canvas->moveToCoord(ui->posX->text().toDouble(), 0, 0);
}

void Cristall::on_goY_clicked()
{
    canvas->moveToCoord(0, ui->posY->text().toDouble(), 0);
}

void Cristall::on_goZ_clicked()
{
    canvas->moveToCoord(0, 0, ui->posZ->text().toDouble());
}

void Cristall::on_goReflectX_clicked()
{
    canvas->reflectX();
}

void Cristall::on_goReflectY_clicked()
{
    canvas->reflectY();
}

void Cristall::on_goReflectZ_clicked()
{
    canvas->reflectZ();
}
