// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

�򶫿�ȥ��һƬ������Զ����һ����ɽ��ɽ������ŨŨ�ĺ�����
���������޵ظ�����������ŭ�������ĵ��������ϱ�һ��С�ң�
�����Ĺٴ����˳������롣
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sifang",
  "east" : __DIR__"huang",
  "west" : __DIR__"walk7",
]));
  set("hell", 1);
  set("out_doors", 1);

  setup();
}
