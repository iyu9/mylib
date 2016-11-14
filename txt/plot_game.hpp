//-------------------------------------------
//Note: Plot according to interpreter format
//-------------------------------------------

class Splash:
 Image CircleSplashLogo = CENTER(256,256)
 +ChangeScene(3.0f)
 
class Title:
 Image imgBg = (width, height)
 Image imgGameLogo = CENTER_UPPER
 Image imgButton = RIGHT

 Button btnMenu = {
   "Start",
   "Load",
   "Gallary",
   "Option",
   "Exit",
 }

 -OnClick()
 -OnMouseOver()

 -Init()
 -ChangeScene()

class Option:
 Image imgBg = (width, height)
 Image imgButton
