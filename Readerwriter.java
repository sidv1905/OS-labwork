
import java.util.concurrent.Semaphore;
public class Readerwriter {
static int rc=0;
static Semaphore S=new Semaphore(1);
static Semaphore wrt=new Semaphore(1);


 public static void main(String[] args) {
        Reader r=new Reader();
        Writer w=new Writer();
        Thread t1=new Thread(r);
        Thread t2=new Thread(r);
        Thread t3=new Thread(r);
        Thread t4=new Thread(w);
        Thread t5=new Thread(w);
        Thread t6=new Thread(w);
        t1.setName("reader 1 ");
        t1.start();
        t2.setName("reader 2");
        t2.start();
        t3.setName("reader 3");
        t3.start();
        t4.setName("writer 1");
        t4.start();
        t5.setName("writer 2 ");
        t5.start();
        t6.setName("writer 3 ");
        t6.start();
    }


static public class Reader implements Runnable
{
    public void run(){
     try
     {
         S.acquire();

        rc++;
        if(rc==1)
        {
            wrt.acquire();
        }
        S.release();
        System.out.print(Thread.currentThread().getName()+"    is reader   \n ");
        Thread.sleep(1000);
         System.out.print("Read finished \n");
         rc--;
         if(rc==0)
         {
             wrt.release();
             S.release();
         }
     }
     catch (InterruptedException e)
     {
          System.out.print("Error");

     }
    
    }
}
static public class Writer implements Runnable
{
    public void run(){
     try
     {
         wrt.acquire();
        System.out.print(Thread.currentThread().getName()+"    is writer  \n ");
        Thread.sleep(1000);
        System.out.print("Write finished \n");
        wrt.release();   
     }
     catch (InterruptedException e)
     {
          System.out.print("Error");

     }
    
    }
}
}
