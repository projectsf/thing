package thing.common;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.File;
import java.util.logging.*;


public class ComponentManager {
	private static HashMap<String, Object> components = new HashMap<String, Object>();
	private ArrayList<String> componentNames = new ArrayList<String>();
    private static final Logger log = Logger.getLogger(ComponentManager.class.getName());

	public void start()
	{

		log.info("Starting");

		//load all commands in here for now
		try {
			Class.forName("thing.common.MoveServoCommand");
		}
		catch (ClassNotFoundException e) {
			log.warning("MoveServoCommand.class not found");
		}             

		//read in component list from file
		readConfiguration();

		for (String entry : componentNames)
		{
			try {
				Class<?> componentClass = Class.forName(entry);
				components.put(entry.trim(), componentClass.newInstance());
			}
			catch (ClassNotFoundException e) {
				log.warning(entry + " not found");
			}
			catch (InstantiationException e) {
				log.warning(entry + " can't be instantiated");
			}
			catch (IllegalAccessException e) {
				log.warning(entry + " can't be accesses");
			}
		}             

		//start all components in container
		for (Map.Entry<String, Object> entry : components.entrySet())
		{
			log.info("Starting: " + entry.getKey());
			Component component = (Component)entry.getValue();
			component.start();
		}
	}

	public void upgrade(String componentName)
	{
	}

	static Component getComponent(String componentName)
	{
		return  (Component)components.get(componentName);
	}

	private void readConfiguration()
	{
		try {
			File fXmlFile = new File("./configuration/Thing.xml");
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			doc.getDocumentElement().normalize();

			NodeList nList = doc.getElementsByTagName("Component");
 
			for (int temp = 0; temp < nList.getLength(); temp++) {
 
				Node nNode = nList.item(temp);
				if (nNode.getNodeType() == Node.ELEMENT_NODE) {
					Element eElement = (Element) nNode;
					componentNames.add(getTagValue("Classname", eElement));
				}
			}
		}
		catch (Exception e) {
			log.severe(e.getMessage());
		}
	}


	private String getTagValue(String sTag, Element eElement) {
		NodeList nlList = eElement.getElementsByTagName(sTag).item(0).getChildNodes();
		Node nValue = (Node) nlList.item(0);
		return nValue.getNodeValue();
	}

}
