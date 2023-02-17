#include <QApplication>
#include <QQuickView>

int main(int argc, char* argv[])
{

    QGuiApplication app(argc, argv);

    QQuickView* view = new QQuickView;

    view->setSource(QUrl("qrc:/PowerWidgets/MainMenuSwitch.qml"));
    view->show();
    return app.exec();
}
