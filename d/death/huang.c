inherit ROOM;

void create ()
{
  set ("short", "�Ľ���Ұ");
  set ("long", @LONG

��Χһ��ʲôҲ�������ˣ������ɵ�һƬ��ȴ������һЩ����
�ҵĽŲ��������������Լ����������·��Ҳ��֪��ͨ��ʲô
�ط�������һ����ɽ��ɽ������������⡣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"huangwai",
  "west" : __DIR__"roomout",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/niutou" : 1,
  __DIR__"npc/mamian" : 1,
]));

  setup();
}
