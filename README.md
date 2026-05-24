## 🔧 Required tools

Before building and flashing the system, download the required ST tools and files:

### 1. STM32CubeProgrammer

Download and install the official STM32CubeProgrammer tool from STMicroelectronics:

- https://wiki.st.com/stm32mpu/wiki/STM32CubeProgrammer  
- https://www.st.com/en/development-tools/stm32cubeprog.html

This tool is used for:
- flashing images to SD card / eMMC
- connecting to STM32MP1 board via USB / UART
- updating bootloader and partitions

---

### 2. OpenSTLinux distribution package

Download the official OpenSTLinux distribution for STM32MP1:

https://wiki.st.com/stm32mpu/wiki/OpenSTLinux_distribution

This package contains:
- Yocto build system
- ST BSP layers
- reference images and configuration files
- flashlayout and deployment scripts

---

## 📦 Project usage

After downloading the required tools and OpenSTLinux package:

```bash
cd build-openstlinuxweston-stm32mp1
source ../layers/meta-st/scripts/envsetup.sh
bitbake st-image-weston
```

---

## 📁 Output images

Generated images are located in:

```
tmp-glibc/deploy/images/stm32mp1/
```

---

## 📥 Repository setup

After flashing the image, clone this repository:

```bash
git clone https://github.com/DawidWawrzeniuk/Image-weston-qt5-stm32mp157f-dk2.git
```

Copy it into your layers directory:

```bash
cp -r Image-weston-qt5-stm32mp157f-dk2/layers/* ../layers/
```

---

## 📦 Available layers after setup

After copying the repository, the following layers will be available in the `layers` directory:

- `meta-openembedded` – community OpenEmbedded layers  
- `openembedded-core` – Yocto core system  
- `meta-st` – STMicroelectronics BSP layer  
- `meta-openstlinux` – ST OpenSTLinux configuration layer  
- `meta-openstlinux-custom` – custom project layer (user modifications)  
- `Image-weston-qt5-stm32mp157f-dk2` – project-specific layer containing custom recipes
