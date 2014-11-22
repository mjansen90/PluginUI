
#include "SamplePage.h"

#include "ui_SamplePage.h"

// Constructor
SamplePage::SamplePage(QWidget* pParent) :
   BasePage(pParent),
   m_pUI(new Ui_SamplePage)
{
   m_pUI->setupUi(this);
}

void SamplePage::Initialize()
{
   m_pUI->m_pLabel->setText("I am the sample page!");
}

QString SamplePage::Description() const
{
   return "SamplePage";
}

Q_EXPORT_PLUGIN2(SamplePage, SamplePage)
