// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ·");
  set ("long", @LONG

    ������ͷ����,ɽ·������ƽ��ż�ž����������ж��¶ˡ�
    ����·�����ǰ׹ǣ�Զ���Ѽ����̣�����Խ��Խ�Ļţ�
ֻ�����߳���Ƭ�ط���
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "east"   : __DIR__"sroad3",
  "westup" : __DIR__"sroad5",
]));

  setup();
}






