#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "mydevice.h"
#include "database.h"
#include "model.h"
#include "createdictionary.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<DataBase>("IT.Hello.DataBase", 1, 0, "DataBase");
    qmlRegisterType<Model>("IT.Hello.Model", 1, 0, "Model");
    qmlRegisterType<MyDevice>("mydevice", 1, 0, "MyDevice");

    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));




   // QQmlApplicationEngine engine;

    // Инициализируем базу данных
    DataBase database;
    //CreateDictionarry dict("Dictionary");
    // Объявляем и инициализируем модель представления данных
    Model *model = new Model();
    /* Поскольку Мы отнаследовались от QSqlQueryModel, то
     * для выборки данных нам необходимо выполнить SQL-запрос,
     * в котором мы выберем все необходимы поля из нужной нам таблицы
     * */
    model->setQuery("SELECT id, " TABLE_FNAME ", " TABLE_SNAME ", " TABLE_NIK " FROM " TABLE);

    /* А это уже знакомо из уроков по сигналам и слотам в QML
     * Помещаем полученную модель в контекст QML, чтобы была возможность
     * обращаться к модели по имени "myModel"
     * */
    engine.rootContext()->setContextProperty("myModel", model);
    engine.rootContext()->setContextProperty("mydatabase", &database);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

