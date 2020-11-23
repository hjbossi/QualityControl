// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file    testAggregatorRunner.cxx
/// \author  Barthelemy von Haller
///

#include "QualityControl/AggregatorRunnerFactory.h"
#include "QualityControl/AggregatorRunner.h"

#define BOOST_TEST_MODULE CheckRunner test
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

using namespace o2::quality_control::checker;
using namespace std;
using namespace o2::framework;
using namespace o2::header;

BOOST_AUTO_TEST_CASE(test_check_runner_static)
{
  BOOST_CHECK(AggregatorRunner::createAggregatorRunnerDataDescription("qwertyuiop") == DataDescription("qwertyuiop"));
  BOOST_CHECK(AggregatorRunner::createAggregatorRunnerDataDescription("012345678901234567890") == DataDescription("012345678901"));
  BOOST_CHECK_THROW(AggregatorRunner::createAggregatorRunnerDataDescription(""), AliceO2::Common::FatalException);
}