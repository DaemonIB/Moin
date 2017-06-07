//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p10000 = uint256("0x9becec254ad78d5a5442a1bc797f42fb5677a43c802a6c6032e6596231662500");
    uint256 p150000 = uint256("0x9841585b5eeae61a3bf42fc32b998b0df66f7bf582217af8a31367b72ecd411a");
    BOOST_CHECK(Checkpoints::CheckHardened(10000, p10000));
    BOOST_CHECK(Checkpoints::CheckHardened(150000, p150000));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckHardened(10000, p150000));
    BOOST_CHECK(!Checkpoints::CheckHardened(150000, p10000));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckHardened(10000+1, p150000));
    BOOST_CHECK(Checkpoints::CheckHardened(150000+1, p10000));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 150000);
}    

BOOST_AUTO_TEST_SUITE_END()
