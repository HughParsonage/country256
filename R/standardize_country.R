#' Encode country as 8-bit
#' @param x A character vector to encode/decode.
#' @param na_treatment A method of treating NA values.
#' @param to Either \code{"iso2"} or \code{"iso3"}, designating the code
#' the encoded values should be decoded to. Essentially, whether to decode to
#' 2-character or 3-character strings.
#' @return
#' For encode, a raw vector; for decode, a (standardized) character vector.
#'
#' @details
#' Since \code{"NA"} is the correct 2-character ISO-3166 encoding for Namibia,
#' such strings should not necessarily be interpreted as \code{NA_character_},
#' yet in some contexts, this may be the appropriate choice.  The parameter
#' \code{na_treatment} is concerned with this choice. In this version,
#' \code{"__auto__"} treats any such string as Namibia if all the other strings
#' are length-2
#' @export

encode_country256 <- function(x, na_treatment = "__auto__") {
  ans <- .Call("C_EncodeCountry256", x, na_treatment, PACKAGE = "country256")
  class(ans) <- "country256"
  ans
}

#' @rdname encode_country256
#' @export
decode_country256 <- function(x, to = "iso3", na_treatment = "__auto__") {
  .Call("C_DecodeCountry256", x, match(to, c("", "iso2", "iso3")), na_treatment, PACKAGE = "country256")
}

print.country256 <- function(x, i = min(getOption("country256.max.length", 6L), length(x)),
                             to = getOption("country256.standard", "ISO3"), ...) {
  invisible(.Call("C_print256", x, i, PACKAGE = "country256"))
}




any_nonASCII <- function(x) {
  .Call("C_any_nonASCII", x, PACKAGE = "country256")
}

standardize_country <- function(x) {
  x <- iconv(x, from = "UTF-8", to = "ASCII//TRANSLIT")
}
