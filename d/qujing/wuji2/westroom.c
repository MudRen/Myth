// Room: /u/mimi/zhuziguo/westroom  snowcat moved to /d/qujing/wuji

inherit ROOM;


void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG

�˼����������ֵ��������������ҹ���ֹ������Ѱ�ȥ�𴦡���
�г������ǵ��š���������ϰ����˾��飬���ϵİ�����һ����¯
ȴ����þ�û�������ˡ�

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
  ]));
  set("sleep_room",1);

  setup();
}

void init()
{
  add_action ("do_find","�Ĵ�����");
  add_action ("do_find","zhaozhao");

}

int do_find()
  {
  object jade;
  object me=this_object();
  object who=this_player();
  if (me->query("leave_gui")!=1) return 0;
  if (who->query("obstacle/qujing")!="ren")return 0;
  if (who->is_busy()) 
 	return notify_fail("��������æ���ء�\n");
  who->start_busy(3);
  if (random(5)) return notify_fail("���Ĵ�����,����û���ҵ�ʲô����!\n"); 

  message_vision ("$N��ǰһ��,��,��һ������,��Ȼ�ҵ��ˡ�\n",who);
  jade = new(__DIR__"obj/jade.c");
  jade->move(who);
  set("leave_gui",0);
  return 1;
  }

int valid_leave (object who, string dir)
{
  if (dir == "east")
  {
 
    if (who->query("id")=="qujing ren")
    {
   if (who->query_temp("have_dream")!=0)
      {
      message_vision("$N����˵��:����ֻ�»�������,����������������\n",who);        return 0;     	
      }
    }
  }
  return ::valid_leave(who, dir);
}


