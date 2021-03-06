import bb.cascades 1.0

// creates one page with a label

Page {
    
    function updateScore(scoreChange){
         
         console.log(scoreChange);
         //update the rope position
         ropeContainer.translationX += parseInt(scoreChange);
    }
    
    Container {
        
        layout: DockLayout {
        }
        ImageView {
            imageSource: "bg.png"
        }
        WebView {
            url: "http://10.0.2.1/app.html"
            
            onMessageReceived: {
                 updateScore(message.data);
            }
            preferredHeight: 200.0
            settings.background: Color.Transparent 
        }
        Container {
            id: ropeContainer
            //background: Color.Blue
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            layout: DockLayout {
            }
            ImageView {
                imageSource: "rope.png"
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
            }
            Container {
                
                //background: Color.Yellow
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                leftPadding: 150.0
                rightPadding: 150.0
                ImageView {
                    imageSource: "don.png"
                }
                Container {
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                }
                ImageView {
                    imageSource: "luca.png"
                }
            }
        }
    }
}
