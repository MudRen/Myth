inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG
һ�����������ȱ��ֳ��˺ü����ؿ�,�����ǵ��߹�.����Ըо��õ�
���ص�Σ��.�ǳ��й���������,ϰ���Եĵ����̷�.���ͳ�,�ƺͶ�
������ì�ܵĽ�֯�š�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zlf",
  "south" : __DIR__"zoulang6",
]));

  setup();
}

void init()
{
   add_action("do_defend","defend");
   add_action("do_defend","fangshou");
   add_action("do_defend","shouhu");
   
}

int do_defend(string arg)
{
   object me,who;

   me=this_object();
   who=this_player();

   if (who->query("id")!=OBSTACLE_D->query("cated_id"))return 0;
   
   if (!arg) return notify_fail("��Ҫ˭����������?\n");

   if (arg=="none") 
	{
		write("�㳷��������ķ���\n");
		me->delete("shouhu")	;
		return 1;
	}

   write("��ָ��"+arg+"��������\n");   
   me->set("shouhu",arg);
   return 1;
}

int valid_leave (object who, string dir)
{
  object man;
  object me=this_object();
  string shouhu;

  if (dir=="south")return ::valid_leave(who,dir); 
  if (who->query("obstacle/qujing")=="ren")
    {	
        shouhu=me->query("shouhu");
	if (shouhu)
          {
    	    if (man=find_player(shouhu))
	      {
		if (environment(man)==me)
		   return notify_fail(man->query("name")+"��������,��Ҫ������Ź���ȥ\n");
	      }
          }
    } 

  return ::valid_leave(who,dir);

}

