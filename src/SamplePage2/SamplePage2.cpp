
#include "SamplePage2.h"

#include "ui_SamplePage2.h"

// Constructor
SamplePage2::SamplePage2(QWidget* pParent) :
   BasePage(pParent),
   m_pUI(new Ui_SamplePage2)
{
   m_pUI->setupUi(this);
}

void SamplePage2::Initialize()
{
   m_pUI->m_pLabel->setText("I am the second sample page!");
}

QString SamplePage2::Description() const
{
   return "SamplePage2";
}

Q_EXPORT_PLUGIN2(SamplePage2, SamplePage2)
