#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T16:59:14
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bambam2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include

SOURCES += \
        main.cpp \
    maindialog.cpp \
    game.cpp \
    keypresseventfilter.cpp \
    randomizer.cpp \
    screenmanager.cpp \
    settings/dialog/widgets/dataproviderssettingswidget.cpp \
    settings/dialog/widgets/generalsettingswidget.cpp \
    settings/dialog/widgets/scalingpolicysettingswidget.cpp \
    settings/settings_common.cpp \
    settings/settingscontroller.cpp \
    settings/settingshelpers.cpp \
    translationmanager.cpp \
    xmlreader.cpp \
    dirparser.cpp \
    xmlfileparser.cpp \
#    data_providers/svgitemprovider.cpp \
    data_providers/strategies/charbasedretrievestrategy.cpp \
    data_providers/strategies/randomretrievestrategy.cpp \
    data_providers/strategies/strategyselector.cpp \
    data_providers/textdataprovider.cpp \
    data_providers/providerselector.cpp \
    data_providers/graphics/decorators/graphicsitemdecorator.cpp \
    data_providers/graphics/factories/graphicsitemfactory.cpp \
    data_providers/graphics/decorators/imagedecorator.cpp \
    data_providers/graphics/direct/mimebasedprovider.cpp \
    data_providers/graphics/direct/textitemprovider.cpp \
    data_providers/graphics/decorators/scaledecorator.cpp \
    data_providers/graphics/policies/fittosizepolicy.cpp \
    data_providers/graphics/policies/noscalepolicy.cpp \
    data_providers/graphics/factories/scalingpolicyfactory.cpp \
    data_providers/configbaseddataprovider.cpp \
    gameelementdata.cpp \
    data_providers/graphics/policies/scalingpolicy_common.cpp \
    data_providers/graphics/direct/circleitemprovider.cpp \
    data_providers/dataproviderfactory.cpp \
    settings/settingsreader.cpp \
    settings/settingswriter.cpp \
    settings/gamesettings.cpp \
    settings/dialog/settingsdialog.cpp \
    settings/dialog/widgets/movewidget.cpp

HEADERS += \
    maindialog.hpp \
    game.hpp \
    keypresseventfilter.hpp \
    randomizer.hpp \
    screenmanager.hpp \
    settings/dialog/idataprovidersettings.hpp \
    settings/dialog/igeneralsettings.hpp \
    settings/dialog/iscalingpolicysettings.hpp \
    settings/dialog/widgets/dataproviderssettingswidget.hpp \
    settings/dialog/widgets/generalsettingswidget.hpp \
    settings/dialog/widgets/scalingpolicysettingswidget.hpp \
    settings/isettingsreader.hpp \
    settings/isettingswriter.hpp \
    settings/settingscontroller.hpp \
    settings/settingshelpers.hpp \
    translationmanager.hpp \
    xmlreader.hpp \
    dirparser.hpp \
    xmlfileparser.hpp \
    include/ikeyboardgrabber.hpp \
    include/iretrievestrategy.hpp \
    include/iparser.hpp \
    include/pimpl.hpp \
    include/typedefs.hpp \
#    data_providers/svgitemprovider.hpp \
    data_providers/strategies/charbasedretrievestrategy.hpp \
    data_providers/strategies/randomretrievestrategy.hpp \
    data_providers/strategies/strategyselector.hpp \
    include/iimageprovider.hpp \
    data_providers/textdataprovider.hpp \
    include/igameelementdata.hpp \
    include/iscalingpolicy.hpp \
    data_providers/providerselector.hpp \
    include/idataprovider.hpp \
    data_providers/graphics/factories/graphicsitemfactory.hpp \
    data_providers/graphics/decorators/graphicsitemdecorator.hpp \
    data_providers/graphics/decorators/imagedecorator.hpp \
    data_providers/graphics/direct/mimebasedprovider.hpp \
    data_providers/graphics/direct/textitemprovider.hpp \
    data_providers/graphics/decorators/scaledecorator.hpp \
    data_providers/graphics/policies/fittosizepolicy.hpp \
    data_providers/graphics/policies/noscalepolicy.hpp \
    data_providers/graphics/factories/scalingpolicyfactory.hpp \
    data_providers/configbaseddataprovider.hpp \
    include/gameelementdata.hpp \
    data_providers/graphics/policies/scalingpolicy_common.hpp \
    data_providers/graphics/direct/circleitemprovider.hpp \
    data_providers/dataproviderfactory.hpp \
    settings/settingsreader.hpp \
    settings/settingswriter.hpp \
    settings/gamesettings.hpp \
    settings/settings_common.hpp \
    settings/dialog/settingsdialog.hpp \
    settings/dialog/widgets/movewidget.hpp

unix {
 QT += x11extras
 LIBS = -lX11
 SOURCES += x11keyboardgrabber.cpp
 HEADERS += x11keyboardgrabber.hpp
}

# svrepo.com, http://www.openclipart.org/,
# https://dumielauxepices.net/, https://free.clipartof.com

DISTFILES += \
    data/animals/aardvark.xml \
    data/animals/alligator.xml \
    data/animals/alpaca.xml \
    data/animals/alpaca2.xml \
    data/animals/antilope.xml \
    data/animals/ape.xml \
    data/animals/badger.xml \
    data/animals/bat.xml \
    data/animals/bear.xml \
    data/animals/beaver.xml \
    data/animals/bison.xml \
    data/animals/camel.xml \
    data/animals/cat.xml \
    data/animals/chicken.xml \
    data/animals/cobra.xml \
    data/animals/cow.xml \
    data/animals/crawfish.xml \
    data/animals/deer.xml \
    data/animals/dog.xml \
    data/animals/dolphin.xml \
    data/animals/donkey.xml \
    data/animals/dragonfly.xml \
    data/animals/duck.xml \
    data/animals/eagle.xml \
    data/animals/earthworm.xml \
    data/animals/emu.xml \
    data/animals/flamingo.xml \
    data/animals/frog.xml \
    data/animals/giraffe.xml \
    data/animals/goat.xml \
    data/animals/goose.xml \
    data/animals/gorilla.xml \
    data/animals/hamster.xml \
    data/animals/hippopotamus.xml \
    data/animals/horse.xml \
    data/animals/hyena.xml \
    data/animals/kangaroo.xml \
    data/animals/koala.xml \
    data/animals/ladybug.xml \
    data/animals/lama.xml \
    data/animals/leopard.xml \
    data/animals/mole.xml \
    data/animals/monkey.xml \
    data/animals/moth.xml \
    data/animals/mouse.xml \
    data/animals/orca.xml \
    data/animals/owl.xml \
    data/animals/panda.xml \
    data/animals/parrot.xml \
    data/animals/pellican.xml \
    data/animals/penguin.xml \
    data/animals/pigeon.xml \
    data/animals/rabbit.xml \
    data/animals/racoon.xml \
    data/animals/reindeer.xml \
    data/animals/rhinoceros.xml \
    data/animals/rooster.xml \
    data/animals/sealion.xml \
    data/animals/seal.xml \
    data/animals/shark.xml \
    data/animals/sheep.xml \
    data/animals/skunk.xml \
    data/animals/sloth.xml \
    data/animals/snake.xml \
    data/animals/spider.xml \
    data/animals/squirrel.xml \
    data/animals/stork.xml \
    data/animals/swallow.xml \
    data/animals/swan.xml \
    data/animals/swan2.xml \
    data/animals/tiger.xml \
    data/animals/toucan.xml \
    data/animals/turkey.xml \
    data/animals/turtle.xml \
    data/animals/vulture.xml \
    data/animals/wasp.xml \
    data/animals/whale.xml \
    data/animals/wolf.xml \
    data/animals/yak.xml \
    data/animals/zebra.xml

# Solution taken from:
# https://dragly.org/2013/11/05/copying-data-files-to-the-build-directory-when-working-with-qmake/
copydata.commands = $(COPY_DIR) $$PWD/data $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
