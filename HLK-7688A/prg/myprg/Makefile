include $(TOPDIR)/rules.mk

PKG_NAME:=myprg
PKG_VERSION:=1.0
PKG_RELEASE:=1

# Указываем, что исходники локальные
PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/myprg
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=My custom project
  DEPENDS:=+libi2c +libstdcpp   # Укажите нужные зависимости
endef

# Копируем ваш проект в директорию сборки (не нужно, есть директория src)
#define Build/Prepare
#	mkdir -p $(PKG_BUILD_DIR)
#	$(CP) /абсолютный/путь/до/вашего/проекта/* $(PKG_BUILD_DIR)/
#endef

# Вызываем ваш родной Makefile
define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
	$(TARGET_CONFIGURE_OPTS) \
	CFLAGS="$(TARGET_CFLAGS) $(EXTRA_CFLAGS) -I$(PKG_BUILD_DIR)/u8g2/csrc -ffunction-sections -fdata-sections -I$(PKG_BUILD_DIR)/u8g2/sys/linux-i2c/. " \
	LDFLAGS="$(TARGET_LDFLAGS) $(EXTRA_LDFLAGS) -Wl,--gc-sections"
endef

# Установка бинарника в пакет
define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/myprg $(1)/usr/bin/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
