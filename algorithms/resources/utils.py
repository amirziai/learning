def run_tests(tests, function):
    """
    Runs provided test cases and reports failure or success
    :param tests: list of tests in (dict, expected value) format
    :param function: function to run the tests against
    :return: None
    """
    success = 0
    for test, expected in tests:
        actual = function(**test)
        if actual == expected:
            success += 1
        else:
            error_message = x = """
            error in : {}
            expected : {}
            actual   : {}
            """.format(test, expected, actual)
            print(error_message)
            
    if success == len(tests):
        print('✓ All tests successful')
