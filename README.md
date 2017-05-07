# AniVis
Plugin to animate node visibility in DAZ Studio 4.5+

Current version is "beta" code not "production".

## Terms
Licensed under Mozilla Public License Version 2.0 (MPL).

Free for personal and commercial use. 

Any work products you create using AniVis are entirely your own so far as AniVis Contributors are concerned.

There is NO WARRANTY, USE AT YOUR OWN RISK.


## Supported Platform(s)
Currently available for the Windows 64-bit platform.

## To Install
Click the "release" link, then download the AnaVis####.zip file and extract the contents.  

Copy the dll file into the DAZ Studio plugins directory (e.g. C:\Program Files\DAZ 3D\DAZStudio4\plugins).

Restart DAZ Studio if it was already running.

Access Help/About Installed Plugins and verify that the list includes AniVis with "green" status.

## To Build
Obtain and fully install (with all pre-requisites) the DAZ Studio SDK (4.5+).

Ensure you are able to successfully build a sample plugin.

Download the source from this repository (clone or download and extract the zip).


On Windows:

Open the sln file in Visual Studio 2012 or later and build the plugin.


Elsewhere:

Create a project for your toolset and make source code mods as needed for your compiler.

## To Use
Select one or more nodes in the scene.

Click the menu item Edit / Add AnaVis Property.

Select a node and move in the Timeline to the frame where you want it to disappear.

Locate the AnimateVisibility properrty under Parameters and toggle it to Off.

Move the prior frame and toggle it to On.

Note that you can also toggle back and forth in multiple frames e.g. to blink.

Also note that nodes do not need to be top-level, e.g. you can make a character's head disappear... 

## Trademarks
DAZ Studio is a trademark of DAZ 3D, Inc.

Visual Studio and Windows are registered trademarks of Microsoft Corp.
