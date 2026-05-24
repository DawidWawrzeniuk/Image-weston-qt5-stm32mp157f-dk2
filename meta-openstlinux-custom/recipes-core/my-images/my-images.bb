SUMMARY = "Add custom image to rootfs"
LICENSE = "CLOSED"

SRC_URI = "file://logo.png"

S = "${WORKDIR}"

do_install() {
    install -d ${D}/home/root/images
    install -m 0644 ${WORKDIR}/logo.png ${D}/home/root/images/
}
