
#pragma once

#include <QWidget>

class Page : public QWidget
{
   Q_OBJECT
public:
   Page(QWidget* pParent = 0);
   ~Page();
};