

standardize_country <- function(x) {
  x <- iconv(x, from = "UTF-8", to = "ASCII//TRANSLIT")
}

encode_country256 <- function(x, na_treatment = "__auto__") {
  .Call("C_EncodeCountry256", x, na_treatment, PACKAGE = "country256")
}

decode_country256 <- function(x, to = "iso3", na_treatment = "__auto__") {
  .Call("C_DecodeCountry256", x, match(to, c("", "iso2", "iso3")), na_treatment, PACKAGE = "country256")
}




any_nonASCII <- function(x) {
  .Call("C_any_nonASCII", x, PACKAGE = "country256")
}
