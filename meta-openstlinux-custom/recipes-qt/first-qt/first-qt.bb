SUMMARY = "Simple Qt test app"
LICENSE = "CLOSED"

inherit qmake5 pkgconfig

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI = " \
    file://main.cpp \
    file://First_QT.pro \
    file://logo.png \
"

S = "${WORKDIR}"

DEPENDS += " \
    qtbase \
    qtwayland \
    qtimageformats \
"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 First_QT ${D}${bindir}/First_QT

    install -d ${D}/usr/share/first-qt/
    install -m 0644 ${WORKDIR}/logo.png \
        ${D}/usr/share/first-qt/
}
