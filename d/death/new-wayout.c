// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������ɵ�һƬ����Χһ��ʲôҲ�������ˣ�ȴ������һЩ
���ҴҵĽŲ��������������Լ����������·��Ҳ��֪��ͨ��ʲô
�ط�������һ����ɽ��ɽ������������⡣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"huangwai",
  "west" : __DIR__"new-walk3",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shentu" : 1,
  __DIR__"npc/yulei" : 1,
]));




  set("hell", 1);

  setup();
}

