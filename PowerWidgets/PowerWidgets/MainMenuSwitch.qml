import QtQuick 2.0
import QtQuick.Controls 2.15


Item{
    id:root
    width: 600
    height: 400

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent
        width: parent.width
        height: parent.height

        Rectangle{
            color: "#959090"
            x:100
            y:100
            width: root.width-200
            height: root.height-200
            //anchors.fill: parent
            //anchors.margins: 10

            PowerGrid{
                //anchors.fill: parent
                x:20
                y:20
                width: root.width-80
                height: root.height-80

                columns: 4
                rows:4
                spacing: 5

                PowerGridItem{
                    pos_x:0
                    pos_y:0
                    size_x:2
                    size_y:2
                    Rectangle{
                        anchors.fill:parent
                        color:"red"
                    }
                }
                PowerGridItem{
                    pos_x:2
                    pos_y:0
                    size_x:2
                    size_y:1
                    Rectangle{
                        anchors.fill:parent
                        color:"blue"
                    }
                }
                PowerGridItem{
                    pos_x:2
                    pos_y:1
                    size_x:1
                    size_y:1
                    Rectangle{
                        anchors.fill:parent
                        color:"green"
                    }
                }
                PowerGridItem{
                    pos_x:0
                    pos_y:2
                    size_x:4
                    size_y:1
                    Rectangle{
                        anchors.fill:parent
                        color:"purple"
                    }
                }
                PowerGridItem{
                    pos_x:0.5
                    pos_y:3
                    size_x:3.1
                    size_y:0.5
                    Rectangle{
                        anchors.fill:parent
                        color:"yellow"
                    }
                }

                PowerGridItem{
                    pos_x:0
                    pos_y:3.5
                    size_x:1
                    size_y:0.5
                    Rectangle{
                        anchors.fill:parent
                        color:"black"
                    }
                }
                PowerGridItem{
                    pos_x:1
                    pos_y:3.5
                    size_x:1
                    size_y:0.5
                    Rectangle{
                        anchors.fill:parent
                        color:"black"
                    }
                }
                PowerGridItem{
                    pos_x:2
                    pos_y:3.5
                    size_x:1
                    size_y:0.5
                    Rectangle{
                        anchors.fill:parent
                        color:"black"
                    }
                }
                PowerGridItem{
                    pos_x:3
                    pos_y:3.5
                    size_x:1
                    size_y:0.5
                    Rectangle{
                        anchors.fill:parent
                        color:"black"
                    }
                }
            }
        }

    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
