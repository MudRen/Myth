// Room: come to pingding  writted by smile 12/09/1998

inherit ROOM;

void create ()
{
  set ("short", "ƽ��ɽ��");
  set ("long", @LONG

    �ܿ��Ҫ����ƽ��ɽ���ˣ����˿־�İ׹Ƕ�Խ��ԽԶ��
������������������Ϣ��Ϣ�������ۿ�̫����Ҫ���£���
ĺ�е�ƽ��ɽҲ�Ժ�������·�����������������ǣ����ߣ�
���ߡ�
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yelu8",
  "east" : __DIR__"sanchakou",
]));

  setup();
}






