#include "s21_math_test.h"

static const double fmod_array[84][2] = {{1.0 / 0.0, 1},
                                         {1.0 / 0.0, -1},
                                         {1.0 / 0.0, 0},
                                         {1.0 / 0.0, 1.0 / 0.0},
                                         {1.0 / 0.0, -1.0 / 0.0},
                                         {1.0 / 0.0, 0.0 / 0.0},
                                         {1.0 / 0.0, -0.0 / 0.0},
                                         {0.0 / 0.0, 0},
                                         {0.0 / 0.0, 1},
                                         {0.0 / 0.0, -1},
                                         {0.0 / 0.0, 1.0 / 0.0},
                                         {0.0 / 0.0, -1.0 / 0.0},
                                         {0.0 / 0.0, 0.0 / 0.0},
                                         {-0.0 / 0.0, 1.0 / 0.0},
                                         {-1, 3},

                                         {0.5, 1.0 / 0.0},
                                         {0.5, -1.0 / 0.0},
                                         {5, 1.0 / 0.0},
                                         {5, -1.0 / 0.0},
                                         {-1, -5},
                                         {-1, 0.3},
                                         {-1, -0.6},
                                         {1, -0.7},
                                         {1, 0.0 / 0.0},
                                         {1, -0.0 / 0.0},
                                         {2, 0.0 / 0.0},
                                         {0, 0.0 / 0.0},
                                         {2, 0.0 / 0.0},
                                         {-1, 0.0 / 0.0},
                                         {-1, -0.0 / 0.0},
                                         {0, 1.0 / 0.0},
                                         {-1, 1.0 / 0.0},
                                         {12, 1.0 / 0.0},
                                         {1, -1.0 / 0.0},
                                         {-1, -1.0 / 0.0},

                                         {0, -1.0 / 0.0},
                                         {0.0 / 0.0, -1.0 / 0.0},
                                         {0, 3},
                                         {0, -5},
                                         {0, 0.2},
                                         {0, -0.2},
                                         {0, 1.0 / 0.0},
                                         {0, 1.0 / 0.0},
                                         {-1.0 / 0.0, 1},
                                         {-1.0 / 0.0, -1},

                                         {-1.0 / 0.0, 0},
                                         {-1.0 / 0.0, 1.0 / 0.0},
                                         {0.005, 0.5},
                                         {0.005, -0.5},
                                         {-1.0 / 0.0, -1.0 / 0.0},
                                         {0.005, -2},
                                         {0.005, 2},
                                         {-0.005, 0.5},
                                         {-0.005, 1.0 / 0.0},
                                         {0.005, 1.0 / 0.0},

                                         {-0.005, -1.0 / 0.0},
                                         {0.005, -1.0 / 0.0},
                                         {4.005, 1.0 / 0.0},
                                         {-4.005, -1.0 / 0.0},
                                         {0.997, 2},
                                         {0.997, 0.997},
                                         {
                                             0.997,
                                             -3.9,
                                         },
                                         {0.997, -345.23},
                                         {11.50001, -2.3},
                                         {11.50001, 2.3},

                                         {11.50001, -234},
                                         {11.50001, 0.0003},
                                         {125165161222, 213.3},
                                         {125165161222, -213.3},
                                         {125165161222, 0.00053},
                                         {125165161222, -21131.3},
                                         {-1400, 2},
                                         {-1400, 2.3},
                                         {-1400, -5},
                                         {-1400, -4},

                                         {-1400, 3},
                                         {-1400, -5.3},
                                         {-1400, 0.5},
                                         {4, 4},
                                         {9, 0.5},
                                         {25, -0.5},
                                         {8, 0.3333},
                                         {-8, 0.3333},
                                         {4, 2.3}

};

START_TEST(test_fmod) {
  double test_number_base = fmod_array[_i][0];
  double test_number_exp = fmod_array[_i][1];

  long double otvet_real = fmod(test_number_base, test_number_exp);
  long double otvet_my = s21_fmod(test_number_base, test_number_exp);

  if (isnan(otvet_real)) {
    ck_assert_ldouble_nan(otvet_my);
  } else if (isinf(otvet_real)) {
    ck_assert_ldouble_eq(otvet_my, otvet_real);
  } else {
    ck_assert_ldouble_eq_tol(otvet_my, otvet_real, TEST_EPS);
  }
}
END_TEST

Suite *suite_fmod(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("FMOD");
  tc_core = tcase_create("Core");
  tcase_add_loop_test(tc_core, test_fmod, 0, 84);
  suite_add_tcase(s, tc_core);
  return s;
}