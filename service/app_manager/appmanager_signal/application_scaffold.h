/* @author T001285
 * @for 
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef APPLICATION_SCAFFOLD_H_
#define APPLICATION_SCAFFOLD_H_

#include <atomic>
#include <thread>
#include <csignal>
#include <iostream>

namespace HHT {
  
std::atomic<bool> shouldSuspend(false); 
std::atomic<bool> shouldStop(false);
/*!
 * \brief           Scaffold for an Adaptive Application
 * \tparam          Application
 */
template <typename Application>
class ApplicationScaffold {
public:
 /*!
 * \brief           Wait for signals
 * \param[in]      app
 */
    static void WaitForSignals(Application& app)   
    {
        signal(SIGUSR1, [](int signal) {
           shouldSuspend = true;
        });
        signal(SIGUSR2, [](int signal) {
            shouldStop = true;
        });
        std::this_thread::sleep_for(std::chrono::seconds(23));
        if (shouldSuspend.load()) {
             app.DoSuspend();         
        }
        if (shouldStop.load()) {
             app.DoShutdown();            
        }
        return;
    } //end of funtion
/*!
 * \brief           Main method  
 * \return          Exit code of process, 0 if application begin successfully initialized
 * \pre             
 */
    static int Main() 
    {
        // Create the application object.
        Application app{};
        // start listener thread
        std::thread listener(WaitForSignals,std::ref(app));
        // Execute the Application
        Execute(app);
        listener.join();
        return 0;
    }
/* brief          Starts life-cycle of given application  
 *                  The application to be started
 */
    static int Execute(Application& app) 
    {
        // Execute the application lifecycle
        app.DoInit();
        // run the application
        app.Run();
        //app.reportevent();
        app.DoShutdown();
        return 0;
    }
    };
}  // namespace HHT

#endif 
