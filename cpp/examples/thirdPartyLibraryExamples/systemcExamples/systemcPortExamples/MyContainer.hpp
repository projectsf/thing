

/**
 * MyContainer class prints to std out during copies and assigns
 *
 * @class MyContainer
 */
class MyContainer
{
public:

  /**
   * Non-Empty constructor
   */
  MyContainer(int value)
    : m_value(value)
  {
    std::cout << "Calling non-empty constructor" << '\n';
  }

  /**
   * Empty constructor
   */
  MyContainer()
    : m_value(9)
  {
    std::cout << "Calling empty constructor" << '\n';
  }

  /**
   * Getter for value
   */
  void setValue(int value) 
  {
    m_value = value;
  }

  /**
   * Getter for value
   */
  int getValue() const
  {
    return m_value;
  }

  /**
   * Copy constructor prints to std out when called
   */
  MyContainer(const MyContainer& rhs)
  {
    std::cout << "Calling copy constructor" << '\n';
    m_value = rhs.getValue();
  }

  /**
   * Assignment operator prints to screen when called
   */
  const MyContainer& operator=(const MyContainer& rhs)
  {
    std::cout << "Calling assignment operator" << '\n';
    m_value = rhs.getValue();
    return rhs;
  }

  /**
   * Prints out call to destuctor
   */
  ~MyContainer()
  {
    std::cout << "Calling destructor" << '\n';
  }

private:
  int m_value;
    
};
