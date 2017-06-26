# DefReview

This is small native extension for [Defold engine](http://www.defold.com) which allows to use [native iOS Ratings and Reviews window](https://developer.apple.com/ios/human-interface-guidelines/interaction/ratings-and-reviews/).

## Installation

You can use the DefReview extension in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/).
Open your game.project file and in the dependencies field under project add:

>https://github.com/AGulev/defreview/archive/master.zip
## Example
```lua
if (defreview and defreview.isSupported()) then
  defreview.requestReview()
else
  --do something else
end
```

## LUA Api
#### defreview.isSupported()
Is feature supprorted (It's avaliable only on iOS 10.3+)
#### defreview.requestReview()
Show window.



If you have any questions or suggestions contact me: me@agulev.com
