start /wait %QtResourceGeneratorPath% submodules\icons game-icons.qrc --pmbgSvg --prefix gameicons --file-extensions *.svg
start %RCC% -compress 4 game-icons.qrc