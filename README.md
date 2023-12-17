# Golf
I am trying to develop a CLI app that will keep track of my golf progress.

Eventually, there will be a hardware component, but for the moment it is pure software.

Route:

App (executable) / App.cpp
    - main()
        - GolfDataFactory() Constructor
            - initialize()
            - process()
                - Round() Constructor
                    - popAllOpts()
                - Round::start()
                    - playHole()
                        - Hole() Constructor
                        - Hole::play()
                            - Shot() Constructor
                            - Shot::hit()
                