# Install packages if not already installed
install_dependency() {
	if dpkg -s "$1" &>/dev/null; then
		PKG_EXIST=$(dpkg -s "$1" | grep "install ok installed")
		if [[ -n "$PKG_EXIST" ]]; then
			return
		fi
	fi
	sudo apt install "$1" -y
}

install_dependency libsdl2-dev
install_dependency libsdl2-ttf-dev
install_dependency libsdl2-image-dev
