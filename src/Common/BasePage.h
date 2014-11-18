
#pragma once

#include <QWidget>

class BasePage : public QWidget
{
   Q_OBJECT
public:
   BasePage(QWidget* pParent = 0);
   ~BasePage();
};