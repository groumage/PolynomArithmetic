add_executable(parse test_parse.c)
target_include_directories(parse PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(parse PRIVATE fp_poly)
add_test(NAME parse COMMAND parse)
set_property(TEST parse PROPERTY LABELS "parse")
add_test(NAME parse_memory COMMAND valgrind ./parse)
set_tests_properties(parse_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(parse_memory PROPERTIES LABELS "parse;memory")

#add_executable(aux test_util.c)
#target_include_directories(aux PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
#target_link_libraries(aux PRIVATE fp_poly)
#add_test(NAME aux COMMAND aux)
#add_test(NAME util_memory COMMAND valgrind ./util)
#set_tests_properties(util_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")

add_executable(init test_init_and_free.c)
target_include_directories(init PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(init PRIVATE fp_poly)
add_test(NAME init COMMAND init)
set_tests_properties(init PROPERTIES LABELS "init")
add_test(NAME init_memory COMMAND valgrind ./init)
set_tests_properties(init_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(init_memory PROPERTIES LABELS "init;memory")

add_executable(assert test_assert.c)
target_include_directories(assert PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(assert PRIVATE fp_poly)
add_test(NAME assert COMMAND assert)
set_tests_properties(assert PROPERTIES LABELS "assert")
add_test(NAME assert_memory COMMAND valgrind ./assert)
set_tests_properties(assert_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(assert_memory PROPERTIES LABELS "assert;memory")

add_executable(print test_print.c)
target_include_directories(print PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(print PRIVATE fp_poly)
add_test(NAME print COMMAND print)
set_tests_properties(print PROPERTIES LABELS "print")
add_test(NAME print_memory COMMAND valgrind ./print)
set_tests_properties(print_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(print_memory PROPERTIES LABELS "print;memory")

add_executable(static test_static.c)
target_include_directories(static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(static PRIVATE fp_poly)
add_test(NAME static COMMAND static)
set_tests_properties(static PROPERTIES LABELS "static")
add_test(NAME static_memory COMMAND valgrind ./static)
set_tests_properties(static_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(static_memory PROPERTIES LABELS "static;memory")

add_executable(addition test_add.c)
target_include_directories(addition PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(addition PRIVATE fp_poly)
add_test(NAME addition COMMAND ./addition)
set_tests_properties(addition PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME addition_memory COMMAND valgrind ./addition)
set_tests_properties(addition_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(addition_memory PROPERTIES LABELS "nominal;memory")

add_executable(substraction test_sub.c)
target_include_directories(substraction PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(substraction PRIVATE fp_poly)
add_test(NAME substraction COMMAND substraction)
set_tests_properties(substraction PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME substraction_memory COMMAND valgrind ./substraction)
set_tests_properties(substraction_memory PROPERTIES TIMEOUT 10 PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(substraction_memory PROPERTIES LABELS "nominal;memory")

add_executable(multiplication test_mul.c)
target_include_directories(multiplication PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(multiplication PRIVATE fp_poly)
add_test(NAME multiplication COMMAND multiplication)
set_tests_properties(multiplication PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME multiplication_memory COMMAND valgrind ./multiplication)
set_tests_properties(multiplication_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(multiplication_memory PROPERTIES LABELS "nominal;memory")

add_executable(division test_div.c)
target_include_directories(division PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(division PRIVATE fp_poly)
add_test(NAME division COMMAND division)
set_tests_properties(division PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME division_memory COMMAND valgrind ./division)
set_tests_properties(division_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(division_memory PROPERTIES LABELS "nominal;memory")

add_executable(gcd test_gcd.c)
target_include_directories(gcd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(gcd PRIVATE fp_poly)
add_test(NAME gcd COMMAND gcd)
set_tests_properties(gcd PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME gcd_memory COMMAND valgrind ./gcd)
set_tests_properties(gcd_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(gcd_memory PROPERTIES LABELS "nominal;memory")

add_executable(multiplication_fq test_mul_fq.c)
target_include_directories(multiplication_fq PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(multiplication_fq PRIVATE fp_poly)
add_test(NAME multiplication_fq COMMAND multiplication_fq)
set_tests_properties(multiplication_fq PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME multiplication_fq_memory COMMAND valgrind ./multiplication_fq)
set_tests_properties(multiplication_fq_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(multiplication_fq_memory PROPERTIES LABELS "nominal;memory")

add_executable(gcd_ext test_gcd_ext.c)
target_include_directories(gcd_ext PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(gcd_ext PRIVATE fp_poly)
add_test(NAME gcd_ext COMMAND gcd_ext)
set_tests_properties(gcd_ext PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME gcd_ext_memory COMMAND valgrind ./gcd_ext)
set_tests_properties(gcd_ext_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(gcd_ext_memory PROPERTIES LABELS "nominal;memory")

add_executable(irred_generation test_irred_generation.c)
target_include_directories(irred_generation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(irred_generation PRIVATE fp_poly)
add_test(NAME irred_generation_short COMMAND irred_generation 1)
set_tests_properties(irred_generation_short PROPERTIES TIMEOUT 10 LABELS "nominal;short-irreducible")
add_test(NAME irred_generation_long COMMAND irred_generation 0)
set_tests_properties(irred_generation_long PROPERTIES LABELS "nominal;long-irreducible")
add_test(NAME irred_generation_short_memory COMMAND valgrind ./irred_generation 1)
set_tests_properties(irred_generation_short_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(irred_generation_short_memory PROPERTIES LABELS "nominal;short-irreducible;memory")
add_test(NAME irred_generation_long_memory COMMAND valgrind ./irred_generation 0)
set_tests_properties(irred_generation_long_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(irred_generation_long_memory PROPERTIES LABELS "nominal;long-irreducible;memory")

add_test(NAME irred_generation_verify COMMAND sh -c "gp -q verify_input_poly.gp;" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(irred_generation_verify PROPERTIES LABELS "nominal")

add_executable(irred_check test_irred_check.c)
target_include_directories(irred_check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fp_poly/include)
target_link_libraries(irred_check PRIVATE fp_poly)
add_test(NAME irred_check COMMAND irred_check)
set_tests_properties(irred_check PROPERTIES TIMEOUT 10 LABELS "nominal")
add_test(NAME irred_check_memory COMMAND valgrind ./irred_check)
set_tests_properties(irred_check_memory PROPERTIES PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors.*")
set_tests_properties(irred_check_memory PROPERTIES LABELS "nominal;memory")