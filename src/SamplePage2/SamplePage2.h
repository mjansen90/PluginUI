
#pragma once

#include "SamplePage2_global.h"

#include "BasePage.h"

#include <QWidget>

class Ui_SamplePage2;

class SAMPLEPAGE2_EXPORT SamplePage2 : public BasePage
{
   Q_OBJECT
   Q_INTERFACES(BasePage)
public:
   SamplePage2(QWidget* pParent = 0);

   virtual void Initialize();
   virtual QString Description() const;

private:
   Ui_SamplePage2* m_pUI;
};