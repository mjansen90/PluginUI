
#pragma once

#include "Common.h"
#include <QtPlugin>
#include <QWidget>

class COMMON_EXPORT BasePage : public QWidget
{
   Q_OBJECT
public:
   BasePage(QWidget* pParent = 0) {}
   virtual ~BasePage() {}

   virtual void Initialize() = 0;
   virtual QString Description() const = 0;
};

Q_DECLARE_INTERFACE(BasePage, "com.jansen.BasePage")