// rewritten by snowcat on 4/11/1997
// Room: dongnei

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һƬ��ڣ���ʲôҲ�����壬�ƺ�����������۾��ںڰ��ж�
���㡣�㻷�����ܣ�ģģ�����ֱ��һ��һ����Ӱ�ӡ�

LONG);

  set("exits", ([
        "out" : __DIR__"shimen",
      ]));
  set("objects", ([
    __DIR__"npc/xiaoyao" : 3,
  ]));

  setup();
}

void init()
{
  add_action("do_koujian", "koujian");
}

int do_koujian (string arg)
{
  object me = this_player();
  object princess = present("tieshan gongzhu",environment(me));

  if (arg != "princess")
  {
    message_vision("ֻ��$N������ȥ����\n",me);
    tell_object(me,"����ߵ��˭��\n");
    return 1;
  }  

  message_vision("ֻ��$N������ȥ������"+
                 RANK_D->query_self(me)+
                 "ߵ��������\n",me);

  if (princess)
    message_vision("$N����һ�ѽ�$nС���Ƶ������������ز��ء�\n",princess,me);
  else
  {
    message_vision("��Ѩ�������ط���һЩ��ɫ����\n",me);
    call_out("princess_appear",10+random(10),me);
  }
  return 1;
}

void princess_appear(object me)
{
  object princess;

  if (environment(me) != this_object())
    return;

  if (present("tieshan gongzhu",environment(me)))
    return;

  princess = new (__DIR__"npc/princess");
  princess->move(environment(me));
  message_vision("һ���ɫ�������һ����������$N��\n",princess);
}
