// Room: /d/qujing/wudidong/firemount-wudidong3
inherit ROOM;

void create ()
{
  set ("short", "ȡ��·");
  set ("long", @LONG

���ߵ�ƽ���Ͽ��Կ���һ��С��ׯ��������·���ߵĵ����������
�ڸ��������������ˮţ���㲻�����Ҹ��˼�С�һ�ޣ��Ľ���;��
ƣ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"firemount-wudidong2",
  "southwest" : __DIR__"entrance",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
