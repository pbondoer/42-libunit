# libunit @ 42

![Where are the
tests?](https://www.commitstrip.com/wp-content/uploads/2017/02/Strip-Ou-sont-les-tests-unitaires-english650-final.jpg)

*Source: http://www.commitstrip.com/en/2017/02/08/where-are-the-tests/*

This is a small library developed at 42 to help with the task of unit testing.
It's tiny and doesn't have a lot of features, but it gets the job done.

# API Documentation
Your testing executable will run a list of **test suites**, which will run
**individual tests**. There are two kinds of tests: **simple**, which return 0
or -1 based on success, and **out**, which will capture `stdout` and check for a
predefined output.

* `unit_add_suite` adds a suite to a list.
* `unit_add_test` adds a test to a suite.
* `unit_add_test_output` adds an stdout test to a suite.
* `unit_run_all` executes the suite list.

There are also some functions to call from within your tests:

* `unit_assert_output` checks stdout output.
* `TEST_SUCCESS` and `TEST_ERROR` contain the return variables for results.

Here's a basic example:
```c
#include "testproject.h"
#include "libunit.h"
#include <signal.h>

int				main(int argc, char **argv)
{
	static t_unit_list *list = NULL;

	(void)argc;
	unit_add_suite(&list, "Basic tests", basic_tests());
	// Add more suites as needed
	return (unit_run_all(list, argv[0]));
}

t_unit_suite	*basic_tests(void)
{
	static t_unit_suite *suite = NULL;

	if (suite)
		return (suite);
	unit_add_test(&suite, "Simple test", &simple_test, 0);
	// Your tests can also write to stdout!
	unit_add_test_output(&suite, "Stdout test", &another_test, 0);
	// You can also add tests that are expected to fail
	unit_add_test(&suite, "Segfault test", &segv_test, SIGSEGV);
	return (suite);
}

// a simple equality test
int				simple_test(void)
{
	if (ft_strlen(test) == strlen(test))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

// p here is a pointer to the stdout/stdin pipe
int				stdout_test(int *p)
{
	ft_putstr("abc");
	return (unit_assert_output(p, "abc"));
}

// this test is meant to fail
int				segv_test(void)
{
	ft_strlen(NULL);
	return (TEST_SUCCESS);
}
```

By default, all tests time out after 10 seconds. If you would like to change
this, check out [`libunit.h`](https://github.com/pbondoer/42-libunit/blob/master/includes/libunit.h)
and edit the `TEST_TIMEOUT` define.

## License
This project is licensed under the [GNU General Public License
3.0](https://www.gnu.org/licenses/gpl-3.0.txt) or later.
