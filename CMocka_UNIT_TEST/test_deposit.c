// COMPILE: gcc test_deposit.c -I. -Wl,--wrap=deposit -lcmocka && ./a.out 

#include <stdlib.h>
#include <string.h>

// Mandatory headers needed by CMocka                                                                                                                                                         
#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

// The real function "deposit()" must satisfy these requirements
// 1. Only accept deposits greater than 100
// 2. We can deposit in any bank other than Nordea Bank
// However the real deposit() function doesn't exist, so we mock it
int deposit(int money, const char* bank);

// This is our wrapper, for the purpose of testing only
int __wrap_deposit(int money, const char* bank)
{
  // Always ensure input parameters are what's expected                                                                                                                                       
  check_expected(money);
  check_expected_ptr(bank);

  bool is_valid_account = mock_type(bool);
  if (!is_valid_account) { return EXIT_FAILURE; }

  int minimum_money = mock_type(int);
  if (minimum_money <= 100) { return EXIT_FAILURE; }

  char* bank_name = mock_ptr_type(char*);
  if (strcmp(bank_name, "Nordea") == 0) { return EXIT_FAILURE; }

  return EXIT_SUCCESS;
}


double production_code(int money, const char* bank)
{
  double ret = 0;

  if (bank) {
    ret = deposit(money, bank);
  }

  return ret;
}


// Test functions                                                                                                                                                                             
static void test_successful_deposit(void** state)
{
  (void)state;  //unused variable                                                                                                                                                             

  // These expects must match the order of declaration of "check_expected"                                                                                                                    
  // in __wrap_deposit()                                                                                                                                                                      
  int deposit_money = 200;
  const char* deposit_bank = "Citibank";

  expect_value(__wrap_deposit, money, deposit_money);
  expect_string(__wrap_deposit, bank, deposit_bank);

  // These will_return's must match the order of declaration of "mock_type"s                                                                                                                  
  // in __wrap_deposit()                                                                                                                                                                      
  will_return(__wrap_deposit, true);  // assume account is valid                                                                                                                              
  will_return(__wrap_deposit, deposit_money);
  will_return(__wrap_deposit, deposit_bank);

  // Test the production code                                                                                                                                                                 
  int ret = production_code(deposit_money, deposit_bank);


  assert_int_equal(ret, EXIT_SUCCESS);
}

static void test_failed_deposit(void** state)
{
  (void)state;  //unused variable                                                                                                                                                             

  // These expects must match the order of declaration of "check_expected"                                                                                                                    
  // in __wrap_deposit()                                                                                                                                                                      
  int deposit_money = 200;
  const char* deposit_bank = "Citibank";

  expect_value(__wrap_deposit, money, deposit_money);
  expect_string(__wrap_deposit, bank, deposit_bank);

  // These will_return's must match the order of declaration of "mock_type"s                                                                                                                  
  // in __wrap_deposit()                                                                                                                                                                      
  will_return(__wrap_deposit, false);  // assume account is invalid                                                                                                                           

  // Test the production code                                                                                                                                                                 
  int ret = production_code(deposit_money, deposit_bank);

  assert_int_equal(ret, EXIT_FAILURE);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_successful_deposit),
    cmocka_unit_test(test_failed_deposit),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
