#
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=uboot-fl2440
PKG_VERSION:=2010.09
PKG_RELEASE:=1

PKG_SOURCE:=u-boot-2010.03-fl2440.tar.bz2
PKG_SOURCE_SUBDIR:=u-boot-2010.09-fl2440
PKG_BUILD_DIR=$(KERNEL_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)
PKG_SOURCE_URL:=git://github.com/iAlios/fl2440-uboot-2010.09.git
PKG_SOURCE_PROTO:=git
# last commit id
PKG_SOURCE_VERSION:=7877290e987a95dc834e686a059ab5ceb04fb714
#PKG_TARGETS:=bin

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  TITLE:=for fl2440(iAlios)
  CATEGORY:=Device
  SUBMENU:=
  SECTION:=boot
  DEPENDS:=@TARGET_s3c24xx @BROKEN
  URL:=http://www.denx.de/wiki/U-Boot
endef

define Package/$(PKG_NAME)/description
  U-Boot for FL2440 Boards, by iAlios.
  https://github.com/iAlios/fl2440-uboot-2010.09
endef

define Build/Prepare
	$(PKG_UNPACK)
	$(Build/Patch)
	$(FIND) $(PKG_BUILD_DIR) -name .svn | $(XARGS) rm -rf
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) fl2440_config
	$(MAKE) -C $(PKG_BUILD_DIR) CROSS_COMPILE=$(TARGET_CROSS)
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(BIN_DIR)
	dd if=$(PKG_BUILD_DIR)/u-boot.bin of=$(BIN_DIR)/$(PKG_NAME).bin bs=128k conv=sync
endef


$(eval $(call BuildPackage,$(PKG_NAME)))
