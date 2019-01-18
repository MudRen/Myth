// created 6-8-97 pickle
// Room: /d/jjf/zuixing.c
 
inherit CROOM;
 
void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

̫����ɺ�������Ԫ���Ը�����ּ�������ʮ�ֲ�������Ϊ���Ƕ�
������ƫ�������Ƕ��������֮�ʣ���������������һ�����仪��
��ΰ�Ĳ�¥����������¥����Ϊ����������ǰ���ۿ�������������ϧ
����ʳ��Ǯ�ơ�
LONG);

  set("no_fight", 1);
  set("broken", 0);
//  set("light_up", 1)
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinbing-jian" : 1,
  __DIR__"npc/qinbing-qi" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/city/xuanwu-n0",
  "up" : __DIR__"zuixing2",
]));

  set("outdoors", 0);
  setup();
}
int valid_leave(object me, string dir)
{
  if(me->query("env/invisibility")) return ::valid_leave(me, dir);
  if(dir == "up" && objectp(present("qin bing", environment(me))))
    {
       if (member_array("qin bing",me->parse_command_id_list())==-1
          && member_array("qin bing",me->parse_command_id_list())==-1 )
         return notify_fail("�ױ��ȵ��������˵Ȳ����Ҵ���\n");
    }
  return ::valid_leave(me, dir);
}

void init()
{
  add_action("do_kan", "kan3");
  add_action("do_kan", "��");
  add_action("do_kan", "chop");
}
int do_kan(string arg)
{
  object me=this_player(), here=this_object(), ob, zhuzi;
  int kar=me->query_kar();
 
  if( (!arg || arg != "����") && (arg != "zhuzi" && arg!="pillar"))
    return notify_fail("��Ҫ���������֣�\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe" )
    return notify_fail("û˳�ֵļһ���ô��ö���\n");
 if(objectp(present("qin bing", environment(me))))
    return notify_fail("������Ҫ���¥���ȵð��ױ������ˣ�\n");
  if (here->query("broken"))
    return notify_fail("���Ӷ����ˣ�����ʲô����Ҫ���Ŀ��ȥ�ɣ�\n");
  if(!me->query_temp("mark/jjf����¥��¥broken"))
    return notify_fail("��û�Ҷ�¥�أ�������һ¥�����⣿\n");
  message_vision("$N�����˾���һ�������¥�����ӣ�ֻ����ƬľƬ��ɢ�ɿ���\n", me);
  here->add("pending/breakdown", 1);
  if (here->query("pending/breakdown") >= (int)(40 - kar)/5 )
    {
      message_vision("ֻ��һ�����죬֧�ŷ��ӵ����Ӵ����۶ϣ���������¥����������\n", me);
      message_vision("$N��Ȼ��û�ͷ����������Ȼû�����ˣ��������������ǸϽ���ȥ�ɣ�\n", me);
      here->set("long", @LONG

����������һ���������ɵĲ�¥������֪Ϊ�α��˲���ˣ�ֻʣһƬ
���档������ľͷ���浽�����ǾƱ�������Ƭ����ر����ϵ�����
�����űߡ�
LONG);
      me->delete_temp("mark/jjf����¥��¥broken");
      here->set("broken", 1);
      here->set("outdoors", 1);
      here->set("pending/breakdown", 0);
      zhuzi=new(__DIR__"obj/zhuzi");
      zhuzi->move(here);
      call_out("create",3600);
      here->set("exits", ([ /* sizeof() == 1 */
         "west" : "/d/city/xuanwu-n0",
]));

    }
  me->receive_damage("kee", (int)me->query("max_kee")/4);
  return 1;
}
