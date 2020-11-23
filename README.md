# Native iOS and Android ratings and review windows for Defold

This is small native extension for [Defold engine](http://www.defold.com) which allows to use [native iOS Ratings and Reviews window](https://developer.apple.com/ios/human-interface-guidelines/system-capabilities/ratings-and-reviews/) and [Google Play In-App Review API](https://developer.android.com/guide/playcore/in-app-review).

_Your app should be in store otherwise method `requestReview()` won't work._

## Installation

You can use the DefReview extension in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/).
Open your game.project file and in the dependencies field under project add:

>https://github.com/defold/extension-review/archive/master.zip

## Example
![screenshot iOS](/example/example_image.png)
![Screenshot android](https://user-images.githubusercontent.com/2209596/95632078-26a1d400-0a85-11eb-8d34-e25ec25d8b29.png)

```lua
if (defreview and defreview.isSupported()) then
  defreview.requestReview()
else
  --do something else
end
```

## LUA Api
#### defreview.isSupported()
Check if the feature supported.

Available only on iOS 10.3+.

Android 5.0+ (API 21+) and the Google Play Store has to be installed.

#### defreview.requestReview()
Show review window.



If you have any issues, questions or suggestions please [create an issue](https://github.com/AGulev/DefVideoAds/issues) or contact me: me@agulev.com
