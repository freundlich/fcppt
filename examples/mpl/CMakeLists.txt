function(
	add_fcppt_mpl_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		mpl/${EXAMPLE_NAME}
		${ARGN}
		LINK_LIBS
			fcppt_core_interface
	)
endfunction()

add_fcppt_mpl_example(
	lambda
)

add_subdirectory(
	list
)

add_fcppt_mpl_example(
	variant
)
