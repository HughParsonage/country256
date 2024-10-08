library(country256)
library(tinytest)
# Placeholder with simple test
expect_equal(1 + 1, 2)

expect_equal(decode_country256(encode_country256("AUS")), "AUS")

expect_equal(decode_country256(encode_country256(c("AU", "AF", "AUS", "CA"))),
             c("AUS", "AFG", "AUS", "CAN"))
