#!/bin/sh

set -e -u

toupper()
{
	echo $(tr 'a-z' 'A-Z' <<< "$1")
}

update_sublibrary()
{
	local sublibrary="$1"
	local upperpath=$(toupper "${sublibrary}")
	local libdir=libs/"${sublibrary}"

	update_cmake \
		"${libdir}"/CMakeLists.txt \
		FCPPT_"${upperpath}"_FILES \
		"${@:2}" \
		"${libdir}"
}

LIBS=(
	boost
	catch
	core
	filesystem
	log
	options
	parse
)

for lib in ${LIBS[@]} ; do
	update_sublibrary $lib
done

update_cmake \
	doc/CMakeLists.txt \
	FCPPT_DOC_FILES \
	libs/boost/include \
	libs/catch/include \
	libs/core/include \
	libs/filesystem/include \
	libs/log/include \
	libs/options/include \
	libs/parse/include \
	examples \
	-e ".*" \
	doc
