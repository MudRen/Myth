// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

��������һ�ų���ľ�����������һЩ�����չޣ�ר������֮
�á�һЩ������ү��˴˴���һ��ҡ�Ŷ�ë��һ�����죬ͬʱ�۶�
�󰡣

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian2",
  ]));
  set("objects", ([ 
    __DIR__"npc/xishuai" : 2,
  ]));
  setup();
}

void init ()
{
  object xishuai1 = present("xishuai 1",this_object());
  object xishuai2 = present("xishuai 2",this_object());

  if (! xishuai1 || ! xishuai2)
    return;
  xishuai1->kill_ob(xishuai2);
  xishuai2->kill_ob(xishuai1);
}
