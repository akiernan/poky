# Not clear why we need this and upstream doesn't, probably our outdated autotools
dropbear_fix_perms() {
	ln ${S}/src/install-sh ${S}/src/config.sub ${S}
}
do_unpack[postfuncs] += "dropbear_fix_perms"
