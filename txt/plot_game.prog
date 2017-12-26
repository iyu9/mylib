//-------------------------------------------
//Note: Plot according to interpreter format
//-------------------------------------------

class Splash:
 Image imgSplashLogo = CENTER(256,256)
 -ChangeScene(TransitionTime)
 
class Title:
 Image imgBg
 Image imgGameLogo
 Image imgButton

 Button[] btnMenu = {
   "Start",
   "Load",
   "Gallary",
   "Option",
   "Exit",
 }

 -OnClick()
 -OnMouseOver()

 -InitScene()
 -ChangeScene(TransitionTime, btnClicked)

class Option:
 Image imgBg
 Image imgButton
 Image imgSlider

 Button btnClose

 Slider sldBgmVolume
 Slider sldSeVolume
 Slider sldVoiceVolume

 -Save()
 -ChangeScene(TransitionTime)

class Adv:
 Image imgSpeaker
 Image imgNextArrow
 Image imgAdvFrames
 Image imgView

 -OnClick()
 -NextMessage()
 -ChangeScene(TransitionTime);

class ConfirmPopup:
 +Show()
 +Hide()
