
// BLARG_BOOST substitute. For full blarg_boost library see http://blarg_boost.org

#ifndef BLARG_BOOST_STATIC_ASSERT_HPP
#define BLARG_BOOST_STATIC_ASSERT_HPP

#if defined (_MSC_VER) && _MSC_VER <= 1200
	// MSVC6 can't handle the ##line concatenation
	#define BLARG_BOOST_STATIC_ASSERT( expr ) struct { int n [1 / ((expr) ? 1 : 0)]; }

#else
	#define BLARG_BOOST_STATIC_ASSERT3( expr, line ) \
				typedef int blarg_boost_static_assert_##line [1 / ((expr) ? 1 : 0)]

	#define BLARG_BOOST_STATIC_ASSERT2( expr, line ) BLARG_BOOST_STATIC_ASSERT3( expr, line )

	#define BLARG_BOOST_STATIC_ASSERT( expr ) BLARG_BOOST_STATIC_ASSERT2( expr, __LINE__ )

#endif

#endif

