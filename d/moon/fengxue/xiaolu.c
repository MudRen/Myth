//edit by xuanzi 2000/9/12

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

��������һ�����ε�С·��ʯ���ϳ������Ӳݣ��������Ǹ�������������������
�������ڹ����Ե�ʣ��ܶ�С��С�޶������ﰲ�˼ҡ���С·�ľ�ͷ����ԼԼ����
һ��¥��������˿˿�Ļ���Ӹ���������

LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"lake-side",
  "northup" : __DIR__"wytdamen",
]));

  setup();
  replace_program(ROOM);
}

