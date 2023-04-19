# Install packages if not already installed
ifnot_install() {
  if dpkg -s "$1" &>/dev/null; then
    PKG_EXIST=$(dpkg -s "$1" | grep "install ok installed")
    if [[ -n "$PKG_EXIST" ]]; then
      return
    fi
  fi
  sudo apt install "$1" -y
}

ifnot_install libsdl2-dev
ifnot_install libsdl2-ttf-dev
ifnot_install libsdl2-image-dev