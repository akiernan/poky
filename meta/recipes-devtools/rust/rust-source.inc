require rust-config.inc

RUST_VERSION ?= "${@d.getVar('PV').split('-')[0]}"

SRC_URI += "${RUST_DIST_SERVER}/dist/rustc-${RUST_VERSION}-src.tar.xz;name=rust \
            file://zlib-off64_t.patch;patchdir=${RUSTSRC} \
            file://0001-Revert-Map-source-absolute-paths-to-OUT_DIR-as-relat.patch;patchdir=${RUSTSRC} \
            file://rv32-rustix-libc-backend.patch;patchdir=${RUSTSRC} \
            file://rv32-cargo-rustix-0.38.19-fix.patch;patchdir=${RUSTSRC} \
            file://cargo-path.patch;patchdir=${RUSTSRC} \
            file://repro-issue-fix-with-v175.patch;patchdir=${RUSTSRC} \
"
SRC_URI[rust.sha256sum] = "66126989782cbf77fa3aff121bbb108429f2d46fe19328c3de231553de711b90"

RUSTSRC = "${WORKDIR}/rustc-${RUST_VERSION}-src"

UPSTREAM_CHECK_URI = "https://forge.rust-lang.org/infra/other-installation-methods.html"
UPSTREAM_CHECK_REGEX = "rustc-(?P<pver>\d+(\.\d+)+)-src"
