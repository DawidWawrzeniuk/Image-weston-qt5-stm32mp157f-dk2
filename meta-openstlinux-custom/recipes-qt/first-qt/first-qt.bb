SUMMARY = "Simple Qt test app"
LICENSE = "CLOSED"

inherit qmake5 pkgconfig

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI = " \
    file://main.cpp \
    file://First_QT.pro \
    file://logo.png \
    file://qml/main.qml \
"

S = "${WORKDIR}"

DEPENDS += "qtbase qtwayland qtimageformats qtdeclarative qtquickcontrols2 qtquickcontrols"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 First_QT ${D}${bindir}/First_QT

    install -d ${D}/usr/share/first-qt/
    install -m 0644 ${WORKDIR}/logo.png ${D}/usr/share/first-qt/

    install -d ${D}/usr/share/first-qt/qml/
    install -m 0644 ${WORKDIR}/qml/main.qml ${D}/usr/share/first-qt/qml/
}

