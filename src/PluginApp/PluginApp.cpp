
#include "PluginApp.h"

#include "ui_PluginApp.h"

#include "Common/BasePage.h"

#include <QDir>
#include <QPluginLoader>

// Constructor
PluginApp::PluginApp(QWidget* pParent) :
   QMainWindow(pParent),
   m_pUI(new Ui_PluginUI)
{
   m_pUI->setupUi(this);

   m_pUI->m_pActionAddTabs->setEnabled(false);
   m_pUI->m_pActionInitializePages->setEnabled(false);

   connect(m_pUI->m_pActionAddTabs, SIGNAL(triggered()), this, SLOT(OnActionAddTabs()));
   connect(m_pUI->m_pActionInitializePages, SIGNAL(triggered()), this, SLOT(OnActionInitPages()));
   connect(m_pUI->m_pActionLoadPlugins, SIGNAL(triggered()), this, SLOT(OnActionLoadPlugins()));
}

// Destructor
PluginApp::~PluginApp()
{
}

void PluginApp::InitPages()
{
   QMap<QString, BasePage*>::const_iterator it = m_PageMap.begin();
   QMap<QString, BasePage*>::const_iterator itEnd = m_PageMap.end();
   for (; it != itEnd; ++it)
   {
      (*it)->Initialize();
   }
}

void PluginApp::LoadPlugins()
{
   QDir pluginsDir(qApp->applicationDirPath());
   qWarning("Plugin Dir %s", pluginsDir.absolutePath().toAscii().constData());
   pluginsDir.cdUp();
   pluginsDir.cdUp();
   pluginsDir.cd("plugins");
   foreach (QString file, pluginsDir.entryList(QDir::Files))
   {
      QPluginLoader loader(pluginsDir.absoluteFilePath(file));
      if (QObject* pPlugin = loader.instance())
      {
         if (BasePage* pPage = qobject_cast<BasePage*>(pPlugin))
         {
            if (!m_PageMap.contains(pPage->Description()))
            {
               qWarning("Loaded %s", pPage->Description().toAscii().constData());
               m_PageMap[pPage->Description()] = pPage;
            }
            else
            {
               qWarning("%s plugin already loaded!", pPage->Description().toAscii().constData());
            }
         }
         else
         {
            qWarning("%s is not a BasePage", file.toAscii().constData());
         }
      }
      else
      {
         qWarning("%s is not a Qt Plugin", file.toAscii().constData());
      }
   }

   m_pUI->m_pActionAddTabs->setEnabled(!m_PageMap.empty());
}

void PluginApp::AddTabs()
{
   QMap<QString, BasePage*>::const_iterator it = m_PageMap.begin();
   QMap<QString, BasePage*>::const_iterator itEnd = m_PageMap.end();
   for (; it != itEnd; ++it)
   {
      if (m_pUI->m_pTabWidget->indexOf(it.value()) == -1)
      {
         m_pUI->m_pTabWidget->addTab(it.value(), it.key());
      }
      else
      {
         qWarning("%s tab already added!", it.key().toAscii().constData());
      }
   }

   m_pUI->m_pActionInitializePages->setEnabled(m_pUI->m_pTabWidget->count() > 0);
}

void PluginApp::OnActionAddTabs()
{
   AddTabs();
}

void PluginApp::OnActionInitPages()
{
   InitPages();
}

void PluginApp::OnActionLoadPlugins()
{
   LoadPlugins();
}