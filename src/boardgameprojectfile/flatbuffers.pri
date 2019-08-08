# This pri file assumes that special variables are declared.
# FLATBUFFERS_INCLUDE_DIR - directory where flatbuffers include files are located
# FLATBUFFERS_LIB_DIR - directory where flatbuffers libs are located
# FLATC_SCHEME_FILES - list of flatbuffers schema files used to generate headers

# Example: FLATBUFFERS_INCLUDE_DIR=D:/MSYS2_Commander/msys64/mingw64/include FLATBUFFERS_LIB_DIR=D:/MSYS2_Commander/msys64/mingw64/lib
#
# FLATC_SCHEME_FILES += \
#    $$PWD/bgame.fbs

INCLUDEPATH += $$FLATBUFFERS_INCLUDE_DIR
LIBS += -L$$FLATBUFFERS_LIB_DIR

LIBS += -lflatbuffers

FLATC_COMMAND = flatc -c
for (FBS_FILE, FLATC_SCHEME_FILES) {
    system($$FLATC_COMMAND $$FBS_FILE)

    GENERATED_HEADER_DIR = $$dirname(FBS_FILE)

    FBS_FILE_BASENAME=$$basename(FBS_FILE)
    FBS_FILE_BASENAME_SPLITTED += $$split(FBS_FILE_BASENAME, .))
    FBS_FILE_NAME = $$first(FBS_FILE_BASENAME_SPLITTED)

    GENERATED_HEADER = $${GENERATED_HEADER_DIR}/$${FBS_FILE_NAME}_generated.h

    message($$GENERATED_HEADER)

    HEADERS += $$GENERATED_HEADER
}

OTHER_FILES += FLATC_SCHEME_FILES
