import QtQuick 2.0

Item {
    default property alias content: itemsContent.children
    required property int columns;
    required property int rows;
    property int spacing: 0

    function updateLayout(){
        console.assert(columns > 0, "'columns' must be superior to 0");
        console.assert(rows > 0, "'rows' must be superior to 0");

        let m_left = anchors.leftMargin;
        let m_right = anchors.rightMargin;
        let m_top = anchors.topMargin;
        let m_bottom = anchors.bottomMargin;

        let wi = (width  - m_left - m_right  - (columns-1)*spacing )/columns;
        let hi = (height - m_top  - m_bottom - (rows-1)*spacing    )/rows;

        //console.log("wi:"+wi+" hi:"+hi);


        for (let i = 0; i < itemsContent.children.length; ++i)
        {
            let child = itemsContent.children[i];
            if( child instanceof PowerGridItem ){}else{
                console.warn("child at i:"+i+" not a PowerGridItem object, required parameters may be missing")
                child.width = child.height = -1;
                continue;
            }

            console.assert(child.pos_x > 0);
            console.assert(child.pos_y > 0);
            console.assert(child.size_x > 0);
            console.assert(child.size_y > 0);

            console.assert(child.pos_x+child.size_x <= columns );
            console.assert(child.pos_y+child.size_y <= rows );

            child.width  = child.size_x*wi + (child.size_x-1)*spacing;
            child.height = child.size_y*hi + (child.size_y-1)*spacing;
            child.x = x+m_left + child.pos_x*wi + (child.pos_x)*spacing
            child.y = y+m_top  + child.pos_y*hi + (child.pos_y)*spacing

            console.log(
                "px:"+child.pos_x +" py"+child.pos_y+"\n"+
                "sx:"+child.size_x+" sy"+child.size_y+"\n"+
                "x:"+child.x+ " y:"+child.y+"\n"+
                "width:"+child.width+" height:"+child.height+"\n\n"
            );
        }
    }

    Component.onCompleted: updateLayout();
    onWidthChanged: updateLayout();
    onHeightChanged: updateLayout();
    onXChanged: updateLayout();
    onYChanged: updateLayout();

    Item{
        id:itemsContent
    }
}
