// Room: /d/qujing/wudidong/houdong
inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

������������ǰһ����ԭ���󶴱�ǰ����Ҫ��öࡣ��Բ�����ﶼ
�������滨��ݡ�����ӭ�ͣ������������Ĵ������ػ��㡣����
ǰ�������ﴦ��͸�����죬�������Ϊ�������ɾ��ˡ�����һ����
�����������¥�����������и�ʯ��������ȴ�ǽ����ġ�
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "dong" : "���ſ���һ���ִ��������������������ûԿ���ǽ���ȥ�ˡ�
",
]));
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"square2",
  "north" : __DIR__"tang-gate",
  "east" : __DIR__"bedroom-gate",
]));
  set("light_up", 1);
  set("no_clean_up", 1);
  setup();
}
void init()
{
  add_action("unlock", "unlock");
  add_action("unlock", "kai");
}
int unlock()
{
  object me=this_player(), here=this_object(), key;
  int mykar=me->query_kar();
  int mystr=me->query("str")+me->query_skill("unarmed",1)/10-2;
  int factor;

  key=present("tie yaoshi", me);
  if(!key)
    return notify_fail("ûԿ����ô������\n");
  if(here->query("lockbroken"))
    return notify_fail("�������ж�����Կ�ײ岻��ȥ��\n");
  if(here->query("locked_from_inside"))
    return notify_fail("����û����������������������������˴����淴��ס�ˡ�\n");
  if(mystr<20)
    return notify_fail("���þ��˳��̵�����������š����Կ�ס�\n");
  me->add_temp("mark/wudidong_times", 1);
  if(random(31-mykar)>mykar &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N��Կ�ײ������ף���Կ�ױ���ס�ˡ�\n", me);
      return 1;
    }
  factor=random(mykar);
  if(factor<9 &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N����Կ�ײ���������һš��ֻ��ž��һ�������Կ�׶��������ˡ�\n", me);
      return 1;
    }
  if(key->query("name_recognized")!="real key" &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N��Կ�ײ������ף���˵ʲôҲš������$Nһʹ����ֻ��ž��һ����Կ�׶��ˡ�\n", me);
      return 1;
    }
  destruct(key);
  call_out("lock_from_inside", 1);
  me->set_temp("mark/wudidong_times", 0);
  message_vision("$N��Կ�ײ���������š�˰��죬���ڰ������ˡ�\n", me);
  message_vision("$N���������������ţ����˽�ȥ��\n", me);
  if (me->query_temp("mark/wudidong_yushu_gave_me_key"))
    {
      me->set_temp("mark/wudidong_opened_door", 1);
      me->delete_temp("mark/wudidong_yushu_gave_me_key");
    }
  me->move(__DIR__"lock");
  message("vision", "ֻ���ص�һ���������ֱ������ˡ�\n", this_object());
  message_vision("$N�߽�����˳�ֹ������ţ���������\n", me);
  return 1;
}
void break_lock()
{
  this_object()->add("lockbroken", 1);
  call_out("unstuff_lock", 600);
  return;
}
void lock_from_inside()
{
  this_object()->add("locked_from_inside", 1);
  call_out("unstuff_lock", 600);
  return;
}
void unstuff_lock()
{
  this_object()->delete("lockbroken");
  this_object()->delete("locked_from_inside");
  return;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
