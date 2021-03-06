#ifndef TRANSLATION_MANAGER_H
#define TRANSLATION_MANAGER_H

// Qt
#include <QString>
#include <QScopedPointer>

namespace presentation
{
    class TranslationManager
    {
    public:
        TranslationManager();
        ~TranslationManager();

        QStringList avalibleLocales();
        QString currentLocale();

        void setCurrentLocale(const QString& locale);

        void loadLocales();
        void initLocales();

    private:
        class Impl;
        QScopedPointer<Impl> const d;
    };
}

#endif // TRANSLATION_MANAGER_H
