This module allow you to set the window attached to the HWND handle to be placed at the lowest z-index available aka *bottom-most*

It's the inverse of top-most.

Electron indeed have a top-most property but do not have a bottom-most one.

This native module is a wrapper around [SetWindowPosition](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633545(v=vs.85).aspx) Win32 API function.

I'm open to any contribution about other OS.

## Installation

```shell
npm i -S electron-bottom-most                     # install the module
npm i -g electron-rebuild                         # this module msut be installed in order to recompile this module to your current electron version

electron-rebuild -f -w electron-bottom-most       # rebuild the module to match your electron version
```

## Usage
Look at the index.html, index.js and package.json file to integrate it into your Electron application

Basically it consists of 2 steps

* Include the module in your .js file:
```js
import { SetBottomMost } from 'electron-bottom-most';
 - or -
const { SetBottomMost } = require('electron-bottom-most');
```
* Create your Electron BrowserWindow
```js
let mainWindow = new BrowserWindow({
    height: 800,
    width: 800,
    useContentSize: true,
    transparent: !isDev,
    frame: isDev,
    focusable: isDev,
    show: false
});

// load it
mainWindow.loadURL(__dirname + "/index.html");

//show it
mainWindow.show();

// get the native HWND handle
let handle = mainWindow.getNativeWindowHandle();

// set bottom most!
SetBottomMost(handle);

```

## Todo
- [ ] Make it safe please


## Authors

* **Armaldio** - [Armaldio](https://github.com/armaldio)

See also the list of [contributors](https://github.com/armaldio/electron-bottom-most/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
