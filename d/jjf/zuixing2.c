// Room: /d/jjf/zuixing2
inherit ROOM;
 
void create ()
{
  set ("short", "����¥��¥");
  set ("long", @LONG

�ϵ�¥�ݣ�ӭ����һ����ʯ���磬�ϻ��϶��µĹ��¡�ת�����磬
ֻ����������һ�����Ͽ������֣��Ա���Ů���������衣һ�ߣ�����
����Сͯ�����ź��š��е����ϲˣ��е��ڴ��ȡ�
LONG);
  set("objects", ([ /* sizeof() == 4 */
    __DIR__"npc/liyuanji.c": 1,
    __DIR__"npc/lijiancheng.c": 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zuixing",
]));
  set("light_up", 1);
 
  setup();
}
void init()
{
  add_action("do_kan", "��");
  add_action("do_kan", "chop");
  add_action("do_kan", "kan3"); 
} 
int do_kan(string arg)
{
  object me=this_player(), here=this_object(), ob;
  int kar=me->query_kar();
 
  if( (!arg || arg != "����") && (arg != "zhuzi" && arg!="pillar"))
    return notify_fail("��Ҫ���������֣�\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe" )
    return notify_fail("û��˳�ֵļһ���ô��ö���\n");
 
 if(objectp(present("li jiancheng", environment(me))) || objectp(present("li yua
nji", environment(me))))
    return notify_fail("��������ڴˣ����������˵�������\n");
  
  here->add("pending/breakdown", 1);
  if (here->query("already_breakdown"))
    return notify_fail("���Ӷ����ˣ�����ʲô����Ҫ���Ŀ���¥ȥ�ɣ�\n");
  message_vision("$N�����˾���һ�������¥�����ӣ�ֻ����ƬľƬ��ɢ�ɿ���\n", me);
  if (here->query("pending/breakdown") > (int)(40 - kar)/5 )
    {
      message_vision("ֻ��һ�����죬���Ӵ����۶ϣ�" + here->query("short") + "����������\n", me);
      message_vision("$N��Ȼ��û�ͷ����������Ȼû�����ˣ��������������ǸϽ���¥ȥ�ɣ�\n", me);
      here->set("long", @LONG

����������һ�仪���ޱȵķ��䣬������ֻʣһƬ���档������ľͷ
���浽�����ǾƱ�������Ƭ��ԭ����������̵���Ů��СͯҲ���
��֪ȥ���ˡ�
LONG);
      here->set("already_breakdown", 1);
      here->set("outdoors", 1);
      me->add_temp("mark/jjf����¥��¥broken", 1);
      me->add("mark/jjf��κ������", 1);
    }
  me->receive_damage("kee", (int)me->query("max_kee")/4);
  return 1;
}
