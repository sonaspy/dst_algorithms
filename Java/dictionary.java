
package  dsa;

public interface Dictionary {
    
   public int getSize();

    
   public boolean isEmpty();

    
   public Entry find(Object key);

    
   public Iterator findAll(Object key);

    
   public Entry insert(Object key, Object value);

    
   public Entry remove(Object key);

    
   public Iterator entries();
}