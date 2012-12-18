/* to do */
  -- define message set and xsd
  -- add command factory, and command pattern implementation
    -- commands will result in file writes for now
  -- how to dynamically load components and start them (like bootstrap manager)
  -- add security 
  -- add signal handling at top (SIGINT/SIGTERM(ctrl-c))

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

-- other things
  -- command factory


-- command invocation pattern */
  -- command pattern

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
