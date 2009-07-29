/**
 * \file express_tests.h
 * \date Jul 4, 2009
 * \author anton
 * \details
 */
#ifndef EXPRESS_TESTS_H_
#define EXPRESS_TESTS_H_

typedef struct _EXPRESS_TEST_DESCRIPTOR {
	const char *name;
	int (*exec)();
} EXPRESS_TEST_DESCRIPTOR;

#define DECLARE_EXPRESS_TEST(name, exec) \
    static int exec(); \
    static const EXPRESS_TEST_DESCRIPTOR _descriptor = { name, exec }; \
    static const EXPRESS_TEST_DESCRIPTOR *_pdescriptor __attribute__ ((section(".express_tests"))) = &_descriptor;

int express_tests_execute();

#endif /* EXPRESS_TESTS_H_ */
