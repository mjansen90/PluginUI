
#pragma once

#include "SamplePage_global.h"

#include "BasePage.h"

#include <QWidget>

class Ui_SamplePage;

class SAMPLEPAGE_EXPORT SamplePage : public BasePage
{
   Q_OBJECT
   Q_INTERFACES(BasePage)
public:
   SamplePage(QWidget* pParent = 0);

   virtual void Initialize();
   virtual QString Description() const;

private:
   Ui_SamplePage* m_pUI;
};