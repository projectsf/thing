/* to do */
  x define one command (message) MoveServoCommand
  x add command factory, and command pattern implementation
  -- add logging support (logging manager?)
  -- convert message to xml and add xml parsing
  -- command run() should look at xml payload
  -- add serialization to commands
  -- what else?
    -- add digital signature, encryption?
    -- add SSL or TLS?
    -- write server app? 
  

/* nice to have */
  -- add signal handling at top (SIGINT/SIGTERM(ctrl-c))

/* design questions */
  -- how to dynamically load components and start them (like bootstrap manager)


/* java questions */

/* what are components
  -- identity manager 
    -- collects and posts identity, capability and configuration) to management platform
  -- command processor 
    -- http web server or socket?
    -- receives commands, verifies them, decrypts them, builds concret command object from factory
    -- invokes command 


/* http web server or socket */
  -- http server will teach me more about REST (vs SOAP)
    -- GET, PUT, POST, DELETE
    -- can specify encoding scheme of message 
  -- curl can be used to test http
    -- curl -X PUT -d "something=blabla&somethingelse=blaha" http://www.example.com
  -- netcat required for socket

/* management platform web services */
  -- this should be REST (http) 
-- what are components
  -- identity manager 
    -- collects and posts identity, capability and configuration) to management platform
  -- command processor 
    -- http web server or socket?
    -- receives commands, verifies them, decrypts them, builds concret command object from factory
    -- invokes command 

-- http web server or socket */
  -- http server will teach me more about REST (vs SOAP)
    -- GET, PUT, POST, DELETE
    -- can specify encoding scheme of message 
  -- curl can be used to test http
    -- curl -X PUT -d "something=blabla&somethingelse=blaha" http://www.example.com
  -- netcat required for socket


-- management platform web services */
  -- this should be REST (http) 

java to learn
  -- logging
  -- component model (BootstrapManager->getComponent()) for java.  
