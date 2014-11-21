
#pragma once

#include "Common.h"

#include <QWidget>

class COMMON_EXPORT BasePage : public QWidget
{
   Q_OBJECT
public:
   BasePage(QWidget* pParent = 0);
   ~BasePage();
};