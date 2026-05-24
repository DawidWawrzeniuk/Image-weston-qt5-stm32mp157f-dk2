SUMMARY = "Simple C app"
LICENSE = "CLOSED"

SRC_URI = "file://myapp.c"

S = "${WORKDIR}"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/myapp.c -o myapp
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 myapp ${D}${bindir}/myapp
}
