inherit F_CLEAN_UP;
 
int main(object me)
{
	object ob,area;
       mixed dir,file;
       string *names;
       string line="";
       int i;

line += sprintf("%6s %9s %10s %9s %10s\n","����","������","�˿�","˰��","�ܿ�����");
line += "-------------------------------------------------------------\n";
 
      dir=get_dir("/data/city/");
       if(!dir) return notify_fail("Ŀǰ��û�г��С�\n");
 	
	for(i=0;i<sizeof(dir);i++)
      if( sscanf(dir[i], "%s.o", file) ) {
      area=new("/obj/area1.c");
      area->create(file);
      if(area->query("no_use"))
   {
      destruct(area);

      continue;
    } 
     if(area->query("owner"))  
      {
  line += sprintf("%6s%10s%12d %6d %10d\n",area->query("owner"),area->query("short"),area->query("people"), 
area->query("tax"),area->query("farm")+area->query("trade")+area->query("defendance")); 
     destruct(area);
     }
     }     
write(line);
 return 1;
}
int help(object me)
{
	write(@HELP
�쿴��������
HELP
    );
    return 1;
}
