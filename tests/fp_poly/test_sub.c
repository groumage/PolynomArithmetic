#include "../../lib/include/fp_poly.h"

#define BUFFER_SIZE 32768

static void remove_last_newline(char* str)
{
    size_t length;
    
    length = strlen(str);
    if (length > 0 && str[length - 1] == '\n')
        str[length - 1] = '\0';
}

static fp_poly_t *init_and_assert(uint8_t* coeff, size_t len_coeff, uint8_t* list_coeff, size_t len_list_coeff, size_t expected_index_coeff)
{
    fp_poly_t *p = fp_poly_init_array(coeff, len_coeff);
    assert (p != NULL);
    list_t *coeff_p = list_create_from_array(list_coeff, len_list_coeff);
    assert (coeff_p != NULL);
    assert (fp_poly_assert_sizet(p, expected_index_coeff, coeff_p) == FP_POLY_E_SUCCESS);
    assert (list_destroy(coeff_p) == LIST_E_SUCCESS);
    return p;
}

static void sub_polynom(fp_poly_t *p, fp_poly_t *q, fp_field_t *f, size_t expected_index_coeff, uint8_t *expected_coeff, uint8_t len_expected_coeff)
{
    fp_poly_t *res;
    assert (fp_poly_sub(&res, p, q, f) == FP_POLY_E_SUCCESS);
    list_t *coeff_into_list = list_create_from_array(expected_coeff, len_expected_coeff);
    assert (fp_poly_assert_sizet(res, expected_index_coeff, coeff_into_list) == FP_POLY_E_SUCCESS);
    assert (list_destroy(coeff_into_list) == LIST_E_SUCCESS);
    fp_poly_free(res);
}

static void hello_world_tests()
{
    fp_poly_t *p1 = init_and_assert((uint8_t[]) {2, 2, 0, 2}, 4, (uint8_t[]) {2, 2, 2}, 3, 11); // p1 = 2 + 2*x + 2*x^3
    fp_poly_t *p2 = init_and_assert((uint8_t[]) {1, 1, 0, 1}, 4, (uint8_t[]) {1, 1, 1}, 3, 11); // p2 = 1 + x + x^3
    fp_poly_t *p3 = init_and_assert((uint8_t[]) {2, 2, 0, 2}, 4, (uint8_t[]) {2, 2, 2}, 3, 11); // p3 = 2 + 2*x + 2*x^3
    sub_polynom(p1, p2, NULL, 11, (uint8_t[]) {1, 1, 1}, 3);
    sub_polynom(p1, p3, NULL, 1, (uint8_t[]) {0}, 1);
    assert (fp_poly_free(p1) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free(p2) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free(p3) == FP_POLY_E_SUCCESS);
}

static void pari_gp_tests(char *filename)
{
    fp_poly_t *res;
    fp_poly_t *poly[3];
    char line[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");

    fgets(line, sizeof(line), file);
    fp_field_t *field = fp_poly_init_prime_field(atoi(line));
    for (size_t i = 0; i < 3; i++)
    {
        fgets(line, sizeof(line), file);
        remove_last_newline(line);
        poly[i] = fp_poly_parse(line);
    }
    assert (fp_poly_sub(&res, poly[0], poly[1], field) == FP_POLY_E_SUCCESS);
    assert (fp_poly_assert_equality(poly[2], res) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free(res) == FP_POLY_E_SUCCESS);
    for (size_t i = 0; i < 3; i++)
        assert (fp_poly_free(poly[i]) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free_field(field) == FP_POLY_E_SUCCESS);

    fgets(line, sizeof(line), file);
    field = fp_poly_init_prime_field(atoi(line));
    for (size_t i = 0; i < 3; i++)
    {
        fgets(line, sizeof(line), file);
        remove_last_newline(line);
        poly[i] = fp_poly_parse(line);
    }
    assert (fp_poly_sub(&res, poly[0], poly[1], field) == FP_POLY_E_SUCCESS);
    assert (fp_poly_assert_equality(poly[2], res) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free(res) == FP_POLY_E_SUCCESS);
    for (size_t i = 0; i < 3; i++)
        assert (fp_poly_free(poly[i]) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free_field(field) == FP_POLY_E_SUCCESS);
    fclose(file);
}

void test_error()
{
    fp_poly_t *p = fp_poly_init_array((uint8_t[]) {1, 1, 0, 1}, 4);
    fp_poly_t *q = fp_poly_init_array((uint8_t[]) {1, 0, 1, 1}, 4);
    fp_poly_t *res;
    list_t *mem;
    list_node_t *mem_node;
    assert (fp_poly_sub(&res, NULL, q, NULL) == FP_POLY_E_POLYNOM_IS_NULL);
    assert (fp_poly_sub(&res, p, NULL, NULL) == FP_POLY_E_POLYNOM_IS_NULL);
    mem = p->coeff;
    p->coeff = NULL;
    assert (fp_poly_sub(&res, p, q, NULL) == FP_POLY_E_LIST_COEFFICIENT_IS_NULL);
    p->coeff = mem;
    mem_node = p->coeff->head;
    p->coeff->head = NULL;
    assert (fp_poly_sub(&res, p, q, NULL) == FP_POLY_E_POLYNOM_MANIPULATION);
    p->coeff->head = mem_node;
    mem = q->coeff;
    q->coeff = NULL;
    assert (fp_poly_sub(&res, p, q, NULL) == FP_POLY_E_LIST_COEFFICIENT_IS_NULL);
    q->coeff = mem;
    mem_node = q->coeff->head;
    q->coeff->head = NULL;
    assert (fp_poly_sub(&res, p, q, NULL) == FP_POLY_E_POLYNOM_MANIPULATION);
    q->coeff->head = mem_node;
    p->coeff->head->coeff = 150;
    q->coeff->head->coeff = 200;
    assert (fp_poly_sub(&res, p, q, NULL) == FP_POLY_E_POLYNOM_MANIPULATION);
    assert (fp_poly_free(p) == FP_POLY_E_SUCCESS);
    assert (fp_poly_free(q) == FP_POLY_E_SUCCESS);
}

int main()
{
    hello_world_tests();
    test_error();
    pari_gp_tests("../../../tests/fp_poly/input_test/test_sub.txt");
    return 0;
}