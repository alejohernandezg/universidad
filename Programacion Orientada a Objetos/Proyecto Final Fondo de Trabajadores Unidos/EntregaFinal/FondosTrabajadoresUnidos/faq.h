#ifndef FAQ_H
#define FAQ_H

#include <QWidget>
#include "menuusuario.h"
namespace Ui {
class faq;
}

class faq : public QWidget
{
    Q_OBJECT

public:
    explicit faq(QWidget *parent = 0);
    ~faq();

private slots:
    void on_pushButton_clicked();

private:
    Ui::faq *ui;
};

#endif // FAQ_H
