/*  thing::core to do */
  x define one command (message) MoveServoCommand
  x add command factory, and command pattern implementation
  x add package names
  x add component manager 
    x read configuration from file
    x add getComponent functionality
  -- add logging support 
  -- code review / beautify
    -- do i need getComponent()?
    -- xml parsing cleanup
    -- add exceptions
    -- package names? replace common with core
  -- add serialization to commands (to/from xml)
  -- add identity, capability, configuration reporting
    -- components are queried -- when?
  -- add security 
    -- generate key pair and add to secure key store
    -- listening socket is TLS
  -- add componentupgrade command
    -- <Commmand>ComponentUpgrade</Command><ComponentName>ComponentName</ComponentName><JarFile>binary</JarFile><AlgorithmDetails>False</IsSigned><IsEncrypted>False</IsEncrypted>
    -- use URL class loader
    -- needs to support class reload

/* thing nice to haves */
  -- signal handling at top level
  -- add xml validation
  -- certificate is signed on button press

/* thing manager to do */
  -- get ec2 account
  -- research putting app on cloud
  -- implement

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
