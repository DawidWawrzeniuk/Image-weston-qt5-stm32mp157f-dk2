import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Fusion 2.15

Rectangle {
    width: 480
    height: 320
    color: "black"

    Text {
        anchors.centerIn: parent
        text: "Hello QML on STM32MP1!"
        color: "white"
        font.pixelSize: 28
    }

    Button {
        text: "Kliknij mnie"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        onClicked: console.log("Klik!")
    }
}
