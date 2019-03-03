start /wait %QtResourceGeneratorPath% submodules\protomorph-bg-icons game-icons.qrc --pmbgSvg --prefix gameicons --file-extensions *.svg
start %RCC% -compress 4 game-icons.qrc