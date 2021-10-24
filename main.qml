import QtQuick 2.12
import QtQuick.Window 2.15
import Scene 1.0

Window {
    id:root
    width: 640
    height: 480
    visible: true


    Rectangle{
        anchors.fill: parent
        Scene {
            id: ellipse
            anchors.fill: parent
            focus: true
        }
    }
}
