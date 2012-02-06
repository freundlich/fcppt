namespace fcppt
{
namespace math
{
/**
\brief Contains \link fcppt::math::box::basic box::basic \endlink and helper functions, classes and types for it
*/
namespace box
{
}
}
}

/**
\defgroup fcpptmathbox fcppt::math::box
\ingroup fcpptmath
\brief A class representing axis-aligned rectangles, boxes, hypercubes, ...

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptmathbox_motivation</li>
	<li>\ref fcpptmathbox_declaring_boxes</li>
	<li>\ref fcpptmathbox_constructors_and_getters</li>
	<li>\ref fcpptmathbox_coordinate_systems</li>
	<li>\ref fcpptmathbox_null_boxes_and_comparisons</li>
	<li>\ref fcpptmathbox_operators</li>
	<li>\ref fcpptmathbox_headers</li>
</ol>

</td>
</tr>
</table>

\section fcpptmathbox_motivation Motivation

In your code, you might need a class representing a rectangle, for example, to
specify the position and size of a window on the screen. Or, you might want to
store the bounding box of an object in your 3D world. To do that,
fcppt::math::box::basic was invented.

Note that this class only represents axis-aligned boxes, so they do not have a
rotation. It's more of a wrapper around a <code>(vector,dim)</code> pair than a
fully-fledged geometry primitive class.

\section fcpptmathbox_declaring_boxes Declaring boxes

fcppt::math::box::basic is declared like this:

\code
template<typename T,typename N>
class basic;
\endcode

Notice that you do not have to specify a storage type. A box always stores the
dimension and the position <em>statically</em>.

\section fcpptmathbox_constructors_and_getters Constructors and getters

To construct a box, you have to specify the position and the size:

\code
typedef
fcppt::math::box::basic<int,2>
int_box;

int_box my_box(
	int_box::vector(
		0,
		0),
	int_box::dim(
		1,
		2));
\endcode

A box has getters and setters for the position and size, but it also has
specialized getters and setters for the dimensions 2 and 3. You can, for
example, query the x coordinate of a box using <code>my_box.left()</code>. This
is for convenience only.

\section fcpptmathbox_coordinate_systems Coordinate systems

All your calculations and positions assume a certain <em>coordinate
system</em>. In the two-dimensional computer graphics world, for example, the
coordinate system origin is at the <em>top left</em>, with the x axis extending
<em>rightwards</em> and the y axis extending <em>downwards</em>. In this
coordinate system, the "top" coordinate must be smaller than the bottom
coordinate (and the left coordinate smaller than the right coordinate).

fcppt::math::box::basic doesn't enforce those constraints, and thus is useful
in arbitrary coordinate systems. However, some of the getter functions are
suggestive: There's fcppt::math::box::basic::top which returns the y coordinate
of the box's position. This, of course, assumes that the top coordinate is
really given by the position, not the position plus the size.

However, those functions are just there for convenience, so just don't use them
if your coordinate system isn't compatible with them.

\section fcpptmathbox_null_boxes_and_comparisons Null boxes and comparisons

To get a box with all zeroes, use the static member function <code>::%null()</code>:

\code
int main()
{
	typedef
	fcppt::math::box::basic<float,2>
	box2f;

	box2f n = box2f::null();
}
\endcode

To compare two boxes, you <em>can</em> use the comparison operator(s):

\code
int main()
{
	typedef
	fcppt::math::box::basic<float,2>::type
	box2f;

	box2f x(box2f::vector(1.0f,2.0f),box2f::size(1.0f,1.0f));
	box2f y(box2f::vector(1.0f,2.0f),box2f::size(10.0f,10.0f));

	std::cout << (x == y) << "\n";
}
\endcode

This will use the float comparison operator. However, since floating point
values are inherently inaccurate, an exact comparison is almost <em>never</em>
what you want to do. Instead, you should use a different method for comparsion.
fcppt::math::box provides the \link fcppt::math::box::componentwise_equal
componentwise_equal \endlink method which takes two boxes and an epsilon. If
one of the components of the difference is larger than the given epsilon, this
function returns <code>false</code>. Apart from that, there are currently no
other metrics defined for a box (you are, of course, free to implement your
own).

\section fcpptmathbox_operators Operators

fcppt::math::box::basic defines no operators other than <code>operator==</code>
and <code>operator!=</code> for comparison (see above) and
<code>operator<<</code> to output a box to the standard output.

\section fcpptmathbox_headers Header files

fcppt::math::box is spread out across various header files. There's one
header per free function. fcppt::math::box::basic itself is split into
various headers, too. Here's an exhaustive list:

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>basic_fwd.hpp</code></td>
<td>Contains \link fcppt::math::box::basic basic's \endlink declaration. Include this if you pass a box by reference, for example.</td>
</tr>
<tr>
<td><code>basic_decl.hpp</code></td>
<td>Contains \link fcppt::math::box::basic basic's \endlink definition.</td>
</tr>
<tr>
<td><code>basic_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::math::box::basic basic's \endlink member functions.</td>
</tr>
<tr>
<td><code>basic.hpp</code></td>
<td>Includes <code>basic_fwd.hpp</code>, <code>basic_decl.hpp</code> and <code>basic_impl.hpp</code></td>
</tr>
<tr>
<td><code>output.hpp</code></td>
<td>Contains an <code>operator<<</code> for the standard input streams (wide and narrow) which outputs boxs in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
</table>
*/
