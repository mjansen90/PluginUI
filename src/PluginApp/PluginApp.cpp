
#include "PluginApp.h"

#include "ui_PluginApp.h"

#include "SamplePage/SamplePage.h"

// Constructor
PluginApp::PluginApp(QWidget* pParent) :
   QMainWindow(pParent),
   m_pUI(new Ui_PluginUI)
{
   m_pUI->setupUi(this);
   m_pUI->m_pTabWidget->addTab(new SamplePage(this), "Sample");
}

// Destructor
PluginApp::~PluginApp()
{
}