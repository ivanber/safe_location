#include <fstream>
#include <iostream>
#include "miner_maxer.h"
#include "my_timer.h"
#include "ranker.h"
#include "test_reader.h"
#include <thread>
#include "worker.h"
//------------------------------------------------------------------------------
static int const THREADS_NUM = std::thread::hardware_concurrency();
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  if (argc == 3) {
    TestReader::Tests tests;

    if ( TestReader::read(argv[1], tests) ) {
      std::ofstream ofl(argv[2], std::ios_base::out | std::ios_base::trunc);

      if (ofl) {
        RankerCfg rankerCfg;
        rankerCfg.setBegin(0);
        rankerCfg.setEnd(1000);
        rankerCfg.setCount(THREADS_NUM);
        auto const ranks = Ranker::doRank(rankerCfg);

        std::cout << "Threads count = " << THREADS_NUM << std::endl;

        MyTimer allTestsTimer;

        for (size_t i = 0, n = tests.size(); i < n; ++i) {
          MyTimer testTimer;

          auto const test = tests[i];

          std::cout << "Test#" << i << " bombs : [ ";
          for (auto const &bomb : test) {
            std::cout << "(x : " << bomb.x()
              << ", y : " << bomb.y()
              << ", z : " << bomb.z() << ") ";
          }
          std::cout << "]" << std::endl;

          std::vector< WorkerPtr > workers;
          for (auto const rank : ranks) {
            WorkerCfg workerCfg;
            workerCfg.setSideSize(1000);
            workerCfg.setXBegin(rank.first);
            workerCfg.setXEnd(rank.second);
            workerCfg.setTest(test);

            auto worker = std::make_shared< Worker >(workerCfg);
            workers.push_back(worker);
            auto thread = std::thread( &Worker::execute, worker.get() );
            thread.detach();
          }

          Maxer< int > maxDistanceSquared(-1);
          for (auto const &worker : workers) {
            auto const safeDistanceSquared = worker->safeDistanceSquared();
            maxDistanceSquared.setValue(safeDistanceSquared);
          }

          // write to file
          ofl << maxDistanceSquared.value() << std::endl;

          std::cout << "Safe distance squared = " << maxDistanceSquared.value()
            << std::endl;
          std::cout << "Test#" << i << " duration " << testTimer.elapsedMs()
            << " ms" << std::endl;
          std::cout << "--------" << std::endl;
        }

        std::cout << "All tests duration " << allTestsTimer.elapsedMs()
          << " ms" << std::endl;
      }
    } else {
      std::cerr << "Fail open output file " << argv[2] << std::endl;
    }
  } else {
    std::cout << "Use " << argv[0] << " <input-file> <output-file>"
      << std::endl;
  }
}
//------------------------------------------------------------------------------
