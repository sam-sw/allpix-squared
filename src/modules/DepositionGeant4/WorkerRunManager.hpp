/**
 * @file
 * @brief The WorkerRunManager class, run manager for Geant4 that works on seperate thread.
 * @copyright Copyright (c) 2019 CERN and the Allpix Squared authors.
 * This software is distributed under the terms of the MIT License, copied verbatim in the file "LICENSE.md".
 * In applying this license, CERN does not waive the privileges and immunities granted to it by virtue of its status as an
 * Intergovernmental Organization or submit itself to any jurisdiction.
 */

#ifndef ALLPIX_WORKER_RUN_MANAGER_H
#define ALLPIX_WORKER_RUN_MANAGER_H

#include <G4WorkerRunManager.hh>

class RunManager;

namespace allpix {
    /**
     * @brief Run manager for Geant4 that can be used by multiple threads where each thread will have its own instance.
     *
     * This manager overrides \ref G4WorkerRunManager behaviour so it can be used on user defined threads. Therefore, there
     * is no dependency on the master run manager except only in initialization.
     * APIs inherited from \ref G4WorkerRunManager which communicate with master run manager are suppressed because they
     * are not needed anymore. This manager assumes that the client is only interested into its own results and it is
     * independent from other instances running on different threads.
     */
    class WorkerRunManager : public G4WorkerRunManager {
        friend class RunManager;
    public:
        virtual ~WorkerRunManager();
    protected:
        WorkerRunManager() = default;

        /**
         * @brief Previously used to communicate work with master manager.
         *
         * Thread loop for receiving work from master run manager. It will now do nothing.
         */
        virtual void DoWork() override {}

        /**
         * @brief Previously used to merge the partial results obtained by this manager and the master.
         *
         * Merge the run results with the master results. It will now do nothing.
         */
        virtual void MergePartialResults() override {}
    };
} // namespace allpix

#endif /* ALLPIX_WORKER_RUN_MANAGER_H */
