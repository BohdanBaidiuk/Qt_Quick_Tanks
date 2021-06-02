import QtQuick 2.12
import QtQuick.Window 2.15
import Object 1.0
Window {
    id:root
    width: 640
    height: 480
    visible: true

    Object {
        id: poly
        anchors {
            fill: parent
            bottomMargin: 20
        }
    }
}
