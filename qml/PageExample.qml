

import QtQuick.Controls.Styles 1.4
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import IT.Hello.DataBase 1.0
import IT.Hello.Model 1.0



import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.XmlListModel 2.0

MyPage {
    id: pageExample

    title: qsTr("Example")

    //DataBase {id: database}
//    Model {id: myModel}

    RowLayout {
            id: rowLayout
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 5

            spacing: 10

            Text {text: qsTr("Имя")}
            TextField {id: fnameField}
            Button {
                text: qsTr("Добавить")
                onClicked: {
                    mydatabase.inserIntoTable(fnameField.text , "NULL", "NULL")
                   myModel.updateModel() // И обновляем модель данных с новой записью

                }
            }
    }
    TableView {
        id: tableView
        anchors.top: rowLayout.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5






        TableViewColumn {
            role: "time"    // Эти роли совпадают с названиями ролей в C++ модели
            title: "Dictionaries"
        }


        model: myModel
    }


}
