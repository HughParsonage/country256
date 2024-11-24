#include "country256.h"

#define nCountries 255

#define DIAG_UTF8 4
#define DIAG_ISO2 1
#define DIAG_ISO3 2
#define DIAG_MIXR 3

// Code in raw vector, in order of ISO3

// cc <- as.data.table(countries::country_reference_list)
// cc[simple %ein% "Namibia", ISO2 := "NA"]
// i is the code
// dput(cc[nzchar(ISO3)][order(ISO3)][, i := .I][, .(i, ISO2, ISO3, simple)][order(ISO2)]$i + 0)

// this is just the ISO2 countries in alphabetical order
const char * ISO2[nCountries] =
  {"??",
   "AD", "AE", "AF", "AG", "AI", "AL", "AM", "AO", "AQ", "AR",
   "AS", "AT", "AU", "AW", "AX", "AZ", "BA", "BB", "BD", "BE", "BF",
   "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BQ", "BR", "BS",
   "BT", "BV", "BW", "BY", "BZ", "CA", "CC", "CD", "CF", "CG", "CH",
   "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CW", "CX",
   "CY", "CZ", "DE", "DJ", "DK", "DM", "DO", "DZ", "EC", "EE", "EG",
   "EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FO", "FR", "GA",
   "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP",
   "GQ", "GR", "GS", "GT", "GU", "GW", "GY", "HK", "HM", "HN", "HR",
   "HT", "HU", "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR", "IS",
   "IT", "JE", "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM", "KN",
   "KP", "KR", "KW", "KY", "KZ", "LA", "LB", "LC", "LI", "LK", "LR",
   "LS", "LT", "LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG",
   "MH", "MK", "ML", "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT",
   "MU", "MV", "MW", "MX", "MY", "MZ", "NA", "NC", "NE", "NF", "NG",
   "NI", "NL", "NO", "NP", "NR", "NU", "NZ", "OM", "PA", "PE", "PF",
   "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY",
   "QA", "RE", "RO", "RS", "RU", "RW", "SA", "SB", "SC", "SD", "SE",
   "SG", "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "SS",
   "ST", "SV", "SX", "SY", "SZ", "TC", "TD", "TF", "TG", "TH", "TJ",
   "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ", "UA",
   "UG", "UM", "US", "UY", "UZ", "VA", "VC", "VE", "VG", "VI", "VN",
   "VU", "WF", "WS", "YE", "YT", "ZA", "ZM", "ZW",
   "ZZ", "ZZ", "ZZ", "ZZ", "ZZ"};

// This is the map back to the ISO3 ordering
unsigned char ISO2r[nCountries] =
  {0, 7, 8, 2, 14, 4, 6, 10, 3, 12, 9, 11, 16, 15, 1, 5, 17, 27,
   34, 23, 19, 22, 24, 25, 18, 20, 28, 31, 35, 32, 21, 33, 26, 36,
   37, 38, 29, 30, 40, 41, 47, 39, 48, 42, 45, 49, 43, 46, 44, 50,
   53, 54, 52, 55, 56, 58, 59, 60, 61, 63, 62, 64, 65, 66, 71, 67,
   69, 68, 70, 72, 73, 74, 75, 78, 77, 76, 79, 80, 91, 81, 94, 82,
   83, 84, 92, 87, 85, 86, 89, 90, 196, 93, 95, 88, 96, 97, 98,
   99, 100, 101, 102, 103, 107, 111, 104, 105, 106, 109, 108, 110,
   112, 114, 113, 115, 116, 118, 119, 120, 121, 51, 122, 182, 123,
   124, 57, 117, 125, 126, 129, 130, 131, 127, 132, 133, 134, 135,
   128, 138, 139, 140, 149, 137, 141, 144, 145, 146, 148, 150, 136,
   151, 155, 153, 154, 147, 156, 142, 157, 143, 158, 152, 160, 161,
   162, 163, 164, 165, 167, 168, 169, 170, 166, 171, 172, 174, 176,
   186, 179, 177, 173, 180, 204, 175, 181, 185, 183, 178, 184, 187,
   188, 189, 205, 190, 191, 192, 199, 214, 193, 211, 195, 197, 210,
   198, 209, 200, 202, 194, 203, 208, 206, 207, 201, 213, 215, 212,
   216, 217, 13, 218, 219, 220, 221, 223, 222, 226, 224, 227, 225,
   228, 229, 230, 232, 231, 233, 235, 234, 236, 237, 238, 239, 240,
   241, 242, 243, 244, 245, 246, 159, 247, 248, 249};


const char * ISO3[nCountries] =
  {"???",
   "ABW", "AFG", "AGO", "AIA", "ALA", "ALB", "AND", "ARE", "ARG",
   "ARM", "ASM", "ATA", "ATF", "ATG", "AUS", "AUT", "AZE", "BDI",
   "BEL", "BEN", "BES", "BFA", "BGD", "BGR", "BHR", "BHS", "BIH",
   "BLM", "BLR", "BLZ", "BMU", "BOL", "BRA", "BRB", "BRN", "BTN",
   "BVT", "BWA", "CAF", "CAN", "CCK", "CHE", "CHL", "CHN", "CIV",
   "CMR", "COD", "COG", "COK", "COL", "COM", "CPV", "CRI", "CUB",
   "CUW", "CXR", "CYM", "CYP", "CZE", "DEU", "DJI", "DMA", "DNK",
   "DOM", "DZA", "ECU", "EGY", "ERI", "ESH", "ESP", "EST", "ETH",
   "FIN", "FJI", "FLK", "FRA", "FRO", "FSM", "GAB", "GBR", "GEO",
   "GGY", "GHA", "GIB", "GIN", "GLP", "GMB", "GNB", "GNQ", "GRC",
   "GRD", "GRL", "GTM", "GUF", "GUM", "GUY", "HKG", "HMD", "HND",
   "HRV", "HTI", "HUN", "IDN", "IMN", "IND", "IOT", "IRL", "IRN",
   "IRQ", "ISL", "ISR", "ITA", "JAM", "JEY", "JOR", "JPN", "KAZ",
   "KEN", "KGZ", "KHM", "KIR", "KNA", "KOR", "KWT", "LAO", "LBN",
   "LBR", "LBY", "LCA", "LIE", "LKA", "LSO", "LTU", "LUX", "LVA",
   "MAC", "MAF", "MAR", "MCO", "MDA", "MDG", "MDV", "MEX", "MHL",
   "MKD", "MLI", "MLT", "MMR", "MNE", "MNG", "MNP", "MOZ", "MRT",
   "MSR", "MTQ", "MUS", "MWI", "MYS", "MYT", "NAM", "NCL", "NER",
   "NFK", "NGA", "NIC", "NIU", "NLD", "NOR", "NPL", "NRU", "NZL",
   "OMN", "PAK", "PAN", "PCN", "PER", "PHL", "PLW", "PNG", "POL",
   "PRI", "PRK", "PRT", "PRY", "PSE", "PYF", "QAT", "REU", "ROU",
   "RUS", "RWA", "SAU", "SDN", "SEN", "SGP", "SGS", "SHN", "SJM",
   "SLB", "SLE", "SLV", "SMR", "SOM", "SPM", "SRB", "SSD", "STP",
   "SUR", "SVK", "SVN", "SWE", "SWZ", "SXM", "SYC", "SYR", "TCA",
   "TCD", "TGO", "THA", "TJK", "TKL", "TKM", "TLS", "TON", "TTO",
   "TUN", "TUR", "TUV", "TWN", "TZA", "UGA", "UKR", "UMI", "URY",
   "USA", "UZB", "VAT", "VCT", "VEN", "VGB", "VIR", "VNM", "VUT",
   "WLF", "WSM", "YEM", "ZAF", "ZMB", "ZWE",
   "ZZZ", "ZZZ", "ZZZ", "ZZZ", "ZZZ"};

enum iso3 {
  ABW, AFG, AGO, AIA, ALA, ALB, AND, ARE, ARG, ARM, ASM, ATA, ATF, ATG, AUS, AUT,
  AZE, BDI, BEL, BEN, BES, BFA, BGD, BGR, BHR, BHS, BIH, BLM, BLR, BLZ, BMU, BOL,
  BRA, BRB, BRN, BTN, BVT, BWA, CAF, CAN, CCK, CHE, CHL, CHN, CIV, CMR, COD, COG,
  COK, COL, COM, CPV, CRI, CUB, CUW, CXR, CYM, CYP, CZE, DEU, DJI, DMA, DNK, DOM,
  DZA, ECU, EGY, ERI, ESH, ESP, EST, ETH, FIN, FJI, FLK, FRA, FRO, FSM, GAB, GBR,
  GEO, GGY, GHA, GIB, GIN, GLP, GMB, GNB, GNQ, GRC, GRD, GRL, GTM, GUF, GUM, GUY,
  HKG, HMD, HND, HRV, HTI, HUN, IDN, IMN, IND, IOT, IRL, IRN, IRQ, ISL, ISR, ITA,
  JAM, JEY, JOR, JPN, KAZ, KEN, KGZ, KHM, KIR, KNA, KOR, KWT, LAO, LBN, LBR, LBY,
  LCA, LIE, LKA, LSO, LTU, LUX, LVA, MAC, MAF, MAR, MCO, MDA, MDG, MDV, MEX, MHL,
  MKD, MLI, MLT, MMR, MNE, MNG, MNP, MOZ, MRT, MSR, MTQ, MUS, MWI, MYS, MYT, NAM,
  NCL, NER, NFK, NGA, NIC, NIU, NLD, NOR, NPL, NRU, NZL, OMN, PAK, PAN, PCN, PER,
  PHL, PLW, PNG, POL, PRI, PRK, PRT, PRY, PSE, PYF, QAT, REU, ROU, RUS, RWA, SAU,
  SDN, SEN, SGP, SGS, SHN, SJM, SLB, SLE, SLV, SMR, SOM, SPM, SRB, SSD, STP, SUR,
  SVK, SVN, SWE, SWZ, SXM, SYC, SYR, TCA, TCD, TGO, THA, TJK, TKL, TKM, TLS, TON,
  TTO, TUN, TUR, TUV, TWN, TZA, UGA, UKR, UMI, URY, USA, UZB, VAT, VCT, VEN, VGB,
  VIR, VNM, VUT, WLF, WSM, YEM, ZAF, ZMB, ZWE
};




int find_str_in_strX(const char * x, const char * X[nCountries]) {
  for (int j = 0; j < nCountries; ++j) {
    if (x[0] == X[j][0] &&
        x[1] == X[j][1] &&
        /// ISO2 should be null terminated here
        x[2] == X[j][2]) {
      return j;
    }
  }
  return 0;
}

int find_str_in_sorted_strX(const char * x, const char * X[nCountries]) {
  int low = 1;
  int upp = nCountries - 1;
  // should only require 9 passes at max
  for (int k = 0; k < 10; ++k) {
    if (low > upp) {
      return 0;
    }
    int mid = (low + upp) / 2;
    int cmp = strcmp(X[mid], x);

    if (cmp == 0) {
      return mid;
    } else if (cmp < 0) {
      low = mid + 1;
    } else {
      upp = mid - 1;
    }
  }
  return 0;
}

void lengths_of_strings(uint32_t Table[4], const SEXP *xp, R_xlen_t N) {
  for (R_xlen_t i = 0; i < N; ++i) {
    int xi = length(xp[i]);
    if (xi <= 3) {
      Table[xi - 1]++;
    } else {
      Table[3]++;
    }
  }
}

// typedef enum {
//   CE_NATIVE = 0,
//   CE_UTF8   = 1,
//   CE_LATIN1 = 2,
//   CE_BYTES  = 3,
//   CE_SYMBOL = 5,
//   CE_ANY    = 99
// } cetype_t;

bool any_nonASCII(const SEXP *xp, R_xlen_t N) {
  bool any_ = false;
  for (R_xlen_t i = 0; i < N; ++i) {
    switch(getCharCE(xp[i])) {
    case CE_NATIVE:
      continue;
    default:
      any_ = true;
    }
  }
  return any_;
}

SEXP C_any_nonASCII(SEXP x) {
  return ScalarLogical(any_nonASCII(STRING_PTR_RO(x), xlength(x)));
}

SEXP C_diagnose_strsxp(SEXP x) {
  // determine if 3 or 2 char (or both)
  // or requires conversion
  if (!isString(x)) {
    error("`x` was type '%s' but must be type character", type2char(TYPEOF(x)));
  }
  R_xlen_t N = xlength(x);
  const SEXP *xp = STRING_PTR_RO(x);
  uint32_t LensTable[4] = {0};
  lengths_of_strings(LensTable, xp, N);
  if (LensTable[3]) {
    if (any_nonASCII(xp, N)) {
      return ScalarInteger(DIAG_UTF8);
    }
  }


  return R_NilValue;
}



SEXP C_EncodeCountry256(SEXP x, SEXP TreatNA) {
  if (!isString(x)) {
    error("`x` was type '%s' but must be type character", type2char(TYPEOF(x)));
  }
  R_xlen_t N = xlength(x);
  const SEXP * xp = STRING_PTR_RO(x);
  SEXP ans = PROTECT(allocVector(RAWSXP, N));
  unsigned char *restrict ansp = RAW(ans);
  uint32_t Lengths[4] = {0};
  lengths_of_strings(Lengths, xp, N);
  bool is_principally_iso2 = Lengths[1] >= (N / 2 + N / 8);
  bool is_possibly_iso2 = Lengths[1] >= (N / 4);
  bool only_iso2 = Lengths[1] == N;
  bool only_iso3 = Lengths[2] == N;
  bool only_iso2or3 = (Lengths[1] + Lengths[2]) == N;

  if (only_iso2) {
    for (R_xlen_t i = 0; i < N; ++i) {
      if (xp[i] == NA_STRING) {
        ansp[i] = ISO2r[find_str_in_sorted_strX("NA", ISO2)];
        continue;
      }
      int abc = find_str_in_strX(CHAR(xp[i]), ISO2);
      ansp[i] = ISO2r[abc];
    }
    UNPROTECT(1);
    return ans;
  }
  if (only_iso3) {
    for (R_xlen_t i = 0; i < N; ++i) {
      if (xp[i] == NA_STRING) {
        ansp[i] = find_str_in_sorted_strX("NA", ISO2);
        continue;
      }
      ansp[i] = find_str_in_sorted_strX(CHAR(xp[i]), ISO3);
    }
    UNPROTECT(1);
    return ans;
  }
  if (only_iso2or3) {
    for (R_xlen_t i = 0; i < N; ++i) {
      if (xp[i] == NA_STRING) {
        ansp[i] = is_principally_iso2 ? find_str_in_sorted_strX("NA", ISO2) : 0;
        continue;
      }
      switch(length(xp[i])) {
      case 2:
        ansp[i] = ISO2r[find_str_in_sorted_strX(CHAR(xp[i]), ISO2)];
        break;
      case 3:
        ansp[i] = find_str_in_sorted_strX(CHAR(xp[i]), ISO3);
        break;
      default:
        ansp[i] = 0;
      }
    }
    UNPROTECT(1);
    return ans;
  }


  for (R_xlen_t i = 0; i < N; ++i) {
    if (xp[i] == NA_STRING) {
      // check whether vector contains 2 or 3 length objects
      if (is_possibly_iso2) {
        ansp[i] = 160; // NAM
        continue;
      }
      switch(length(xp[i])) {
      case 2:
        ansp[i] = find_str_in_sorted_strX(CHAR(xp[i]), ISO2);
        break;
      case 3:
        ansp[i] = find_str_in_sorted_strX(CHAR(xp[i]), ISO3);
        break;
      default:
        ansp[i] = 0;
      }
    }

  }
  UNPROTECT(1);
  return ans;
}

SEXP C_DecodeCountry256(SEXP x, SEXP To, SEXP TreatNA) {
  if (TYPEOF(x) != RAWSXP) {
    error("`x` was type '%s' but must be type raw", type2char(TYPEOF(x)));
  }
  int to = asInteger(To);
  R_xlen_t N = xlength(x);
  SEXP ans = PROTECT(allocVector(STRSXP, N));
  const unsigned char * xp = RAW(x);
  switch(to) {
  case 2:
    for (R_xlen_t i = 0; i < N; ++i) {
      unsigned int xpi = xp[i];
      if (xpi >= nCountries) {
        continue;
      }
      const char * cpi = ISO2[xpi];
      SET_STRING_ELT(ans, i, mkCharCE(cpi, CE_UTF8));
    }
    break;
  case 3:
    for (R_xlen_t i = 0; i < N; ++i) {
      unsigned int xpi = xp[i];
      if (xpi >= nCountries) {
        continue;
      }
      const char * cpi = ISO3[xpi];
      SET_STRING_ELT(ans, i, mkCharCE(cpi, CE_UTF8));
    }
    break;
  }

  UNPROTECT(1);
  return ans;
}

void print256_raw(SEXP x, SEXP ii) {
  int i_ = asInteger(ii);
  if (i_ < 1) {
    error("(print256_raw): i was not of positive integer value so will not be printed");
  }
  R_xlen_t N = xlength(x);
  unsigned char * xp = RAW(x);
  if (i_ > N) {
    i_ = N;
  }
  Rprintf("country256(len=%lld): ", (long long)N);

  for (int i = 0; i < i_; ++i) {
    Rprintf("%s ", ISO3[(int)xp[i]]);
  }
}

SEXP C_print256(SEXP x, SEXP ii) {
  switch(TYPEOF(x)) {
  case RAWSXP:
    print256_raw(x, ii);
  }
  return R_NilValue;
}



