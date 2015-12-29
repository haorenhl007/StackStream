import QtQuick 2.5
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.2
import QtQuick.Window 2.2
import StackStream 1.0

ApplicationWindow {
    id: thirtyBitImageItemMainWindow
    objectName: "thirtyBitImageItemMainWindow"
    visible: false
    width: 1024
    height: 768
    title: qsTr("Thirty Bit Image Item Viewer")

    menuBar: MenuBar {
        id: foobar
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Open")
                onTriggered: fileDialog.open()
            }

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    FileDialog {
        id: fileDialog
        visible: false
        modality: Qt.WindowModal
        sidebarVisible: true
        selectMultiple: false
        onAccepted: {
            if(thirtyBitImageItem.image == null) {
                thirtyBitImageItem.image = Qt.createQmlObject('import StackStream 1.0; SSImage {}', thirtyBitImageItem, 'FAKEPATH')
            }
            thirtyBitImageItem.image.read(fileUrls[0]);
        }
    }

    ShaderEffect {
        id: tileBackground
        anchors.fill: parent

        property real tileSize: 16
        property color color1: Qt.rgba(0.9, 0.9, 0.9, 1);
        property color color2: Qt.rgba(0.85, 0.85, 0.85, 1);

        property size pixelSize: Qt.size(width / tileSize, height / tileSize);

        fragmentShader:
            "
            uniform lowp vec4 color1;
            uniform lowp vec4 color2;
            uniform highp vec2 pixelSize;
            varying highp vec2 qt_TexCoord0;
            void main() {
                highp vec2 tc = sign(sin(3.14152 * qt_TexCoord0 * pixelSize));
                if (tc.x != tc.y)
                    gl_FragColor = color1;
                else
                    gl_FragColor = color2;
            }
            "
    }

    ThirtyBitImageItem {
        id: thirtyBitImageItem
        objectName: "thirtyBitImageItem"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: (implicitWidth / implicitHeight) * height
        anchors.margins: 10

//        layer.enabled: true
    }
}