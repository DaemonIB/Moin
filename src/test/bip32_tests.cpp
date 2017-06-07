// Copyright (c) 2013 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/test/unit_test.hpp>

#include "base58.h"
#include "key.h"
#include "uint256.h"
#include "util.h"

#include <string>
#include <vector>

struct TestDerivation {
    std::string pub;
    std::string prv;
    unsigned int nChild;
};

struct TestVector {
    std::string strHexMaster;
    std::vector<TestDerivation> vDerive;

    TestVector(std::string strHexMasterIn) : strHexMaster(strHexMasterIn) {}

    TestVector& operator()(std::string pub, std::string prv, unsigned int nChild) {
        vDerive.push_back(TestDerivation());
        TestDerivation &der = vDerive.back();
        der.pub = pub;
        der.prv = prv;
        der.nChild = nChild;
        return *this;
    }
};

TestVector test1 =
  TestVector("000102030405060708090a0b0c0d0e0f")
    ("moipXY9njTPCnsVVA2bHEdgfQwwmMFsLjrCpiPTs21a47Vy3QPRawHL3BEqgg1YcYzVLT9tZKD2AY32n9Uq3aWGUfaum4RbWYNs6wfeU1LaZH5W",
     "moivYMcZoUdupxqBPGetGoBK4Kui52RzWPo9TmqTPY8vGo8PjJFiT8aFkRRrL5X2wm4YeuY8QurZJokEc7v6W68jyUFCCwdg5NQHFWQTzSr3ufh",
     0x80000000)
    ("moipXaRCjAgft8cUJdizSPZJHz3sg5Rh7vgqPztkz6xB5hAKmfimMWs8JPC6TH7KJJPsTNB8BSZbGg6s7soBXXzrjUNVG4PmTgmKTbn2JyeaFvK",
     "moivYPsyoBwNvDxAXsnbUZ3wwN1pPqzLtUHA9PGMMdX3EzKg6aYtsN7LsZnG7LsNMUSWMxRpnDBRhAb7Kswp9gQvmYKiGpJpKL7AxX3KRcKAJHv",
     1)
    ("moipXcbKvxEZGqVY95mSAeTAtiwXjTQo7xR8LKZbaNiz2KxY1DDu5KHSFx6KsMZtiF7DR5oAxs1hPGbLiBXzzsAkR8CRZGEcwKmb6LJobtQaaVe",
     "moivYS46zyVGJvqENKq3CowpY6uUTDyStW1T5hwBwuHrBd7tL842bAXeq8gVXQ4RxQDYp3BWb2mrmsYXTpU3H2CuYhp9nbGYP5t2dKMgxYi73eY",
     0x80000002)
    ("moipXfCbyV4QyiLx1FZXRErYFiyfxcHKPW17froGpi29CCKyR4R1t57sAPeFRNkjA7YXmbtuaEzJmDAKAWgHhxiHUaMG9ACm2GqGp2Dwh9fpo9r",
     "moivYUfP3WK81ogeEVd8TQMBu6wcgNqyA3bSRFAsCEb1MVVKjyF9PvN5jaER5SH3vdj3KWCuBVinCHNRh2Cns386foFp9Cq6Y27yEb6ub8v7rqt",
     2)
    ("moipXhRzovBNAC1w5j3F7W4d9E8z3Ra426KK7Lga5fYcWdtanA3NwqpEMy7B6hk7ZuhGEv25iFUFox4Riw2HoG9VCApX3wkwrTj6pi8nqpXqieW",
     "moivYWtmswS5CHMdJy6r9fZGnc6vmC8hndudrj4ATC7Ufw3w74sWTh4Sw9hLkkgWPJ8UPJLboQxM76pbAD7F4TfSsBqrYSvC66wgPZa56hh3GR2",
     1000000000)
    ("moipXj9mHbncHKQ8c4phE3dMSw8yqf9Mqb8Lub58KwvkiiH5VHSmUG4td5GEjXf4RAmyicJdDbQ4M9m2KMRJu7eL3RydvVB2ewJjdfki5sNdZwT",
     "moivYYcYMd3KKQjpqJtJGD816K6vZRi1c8ifeySihUVct1SRpCGtz7K7CFrQPcTiJDFYzhjramwHx9MiAP7cbXgAz9VPswgRD1hPfu8RqjPgPsy",
     0);

TestVector test2 =
  TestVector("fffcf9f6f3f0edeae7e4e1dedbd8d5d2cfccc9c6c3c0bdbab7b4b1aeaba8a5a29f9c999693908d8a8784817e7b7875726f6c696663605d5a5754514e4b484542")
    ("moipXY9njTPCnsVV9e6cLnkws9fXbT1mRUTePyFbJxJt5t5uhNSn7S6yc91H27dbGErJMi8MDsgKw7Y2sGZGhhBdoVuhvMnyNsMmG3KaHE6XCpX",
     "moivYMcZoUdupxqBNtADNxFbWXdUKDaRC23y9MdBgUskFBFG2HGudHMCBKbSg9J68GcdtxHZACK1aunRheeCYWXSaqZxfMhvDiK1pm2hMR8LBCk",
     0)
    ("moipXbRY1B5AGtKZfuguUa8pvx53xQm28Swvx8zxUmLLAHwsPLtkghT3kyaXbabV4Krja2cX66g5LCP12Ryxaqt496ZzCQXeHDW9PXSEiRSFpZb",
     "moivYQtK5CKsJyfFu9kWWjdUaL2zgBKftzYFhXNYrHuCKb7DiFitCYhGLAAhFeZtmLTUJcXP4Cik25CZ4AH26o2VX4jMfY7ycCUkxAwFihHKmDA",
     0xFFFFFFFF)
    ("moipXcabFn6genVfqmu5u28UQHkcM9yvfw7d3J5VQAF6p2iFqe8DJasMy3N8Cxqbp4TqMYY4jwXgdQobh6rJMkNAsF2cjV9hdwmAFuhqZBwQZeW",
     "moivYS3NKoMPgsqN51xgwBd83fiZ4vYaSUhwngT5mgoxyKscAYxLpS7aYDxHs13sVbBxCqrGqDvP55hfVQ1nqAdd6NAv6GMKNiD1jxGnV9EMvfL",
     1)
    ("moipXfPZfo5cpRnrwPaDxgH3NEgqggrRn82tMjaMFDuS7v4hWTzNc6Q4rwkW3m2jbwA7wizcaacvGY7Rmu7KGeo88aVXKmMYrVCNBgNnokNbFda",
     "moivYUrLjpLKrX8ZAddpzqmh1cenQTR5YfdD77wwckUJHDE3qNpW7weHS8LfhoFVXJPeWoCyaWzmUdNsp6nwt4A16qzDE2t8DpBQDkhWxpefX5w",
     0xFFFFFFFE)
    ("moipXgZbam1yRpkaELophA6ajkP2bRKnq6fPPSJEmwbqxgKwxpKJhmL5PU7bgRAEoJgZuAeFP5gdK9SHRYGhxXudqwBybfg3QnHn3uTNLdBSbjN",
     "moivYW2NenGgTv6GTasRjKbEP8LyKBtSbeFi8pfq9UAi7yVJHj9SDcaHxehmLVyt9imw4NVftLmkrzxTdDtKQ14VngfP3yRSN2D2ZLi32a5v4Wg",
     2)
    ("moipXhvdYCEUx14oybziREEGiVkzzUru5RaU3bv8BixLbUBY31essQFqa34bkpEWvt3GRDrUf1C3CrTGuyLCndbYAC3ZEqW8M9aWjCeZ1Evntma",
     "moivYXPQcDVBz6QWCr4KTPivMsiwiFRYqyAnnzHiZFXCkmLtMvV1PFW49DemQuetJjs16gMQB6QaK6o9fmmq8KRiqfQ6rpvwRSLkFi3b7DguLtS",
     0);

void RunTest(const TestVector &test) {
    std::vector<unsigned char> seed = ParseHex(test.strHexMaster);
    CExtKey key;
    CExtPubKey pubkey;
    key.SetMaster(&seed[0], seed.size());
    pubkey = key.Neutered();
    BOOST_FOREACH(const TestDerivation &derive, test.vDerive) {
        unsigned char data[74];
        key.Encode(data);
        pubkey.Encode(data);
        // Test private key
        CBitcoinExtKey b58key;
        b58key.SetKey(key);
        BOOST_CHECK(b58key.ToString() == derive.prv);
        // Test public key
        CBitcoinExtPubKey b58pubkey;
        b58pubkey.SetKey(pubkey);
        BOOST_CHECK(b58pubkey.ToString() == derive.pub);
        // Derive new keys
        CExtKey keyNew;
        BOOST_CHECK(key.Derive(keyNew, derive.nChild));
        CExtPubKey pubkeyNew = keyNew.Neutered();
        if (!(derive.nChild & 0x80000000)) {
            // Compare with public derivation
            CExtPubKey pubkeyNew2;
            BOOST_CHECK(pubkey.Derive(pubkeyNew2, derive.nChild));
            BOOST_CHECK(pubkeyNew == pubkeyNew2);
        }
        key = keyNew;
        pubkey = pubkeyNew;
    }
}


BOOST_AUTO_TEST_SUITE(bip32_tests)

BOOST_AUTO_TEST_CASE(bip32_test1) {
    RunTest(test1);
}

BOOST_AUTO_TEST_CASE(bip32_test2) {
    RunTest(test2);
}

BOOST_AUTO_TEST_SUITE_END()
