
# Necessary Eigen libraries, e. g. Eigen_LIBS = iostreams math_c99 regex
# XXX: this will not play nice with the win case as-is

exists( custom.pro ):include( custom.pro )
exists( custom.pri ):include( custom.pri )

Eigen_LIBS = "C:/DEV/lib/eigen"

win32 {
	!equals($$(Eigen_DIR), ""):exists( "$$(Eigen_DIR)" ) {
		# Eigen_DIR environment variable is set, use it:
		Eigen_DIR = "$$(Eigen_DIR)"
	} else:isEmpty( Eigen_DIR ) {
		# Eigen_DIR QMake variable is not set at all (in custom.pro), use a hardcoded default:
                Eigen_DIR = "C:/DEV/lib/eigen"
    }

    Eigen_INCDIR = "$${Eigen_DIR}"

    INCLUDEPATH += "$${Eigen_INCDIR}"
    HEADERS += "$${Eigen_INCDIR}"

}
