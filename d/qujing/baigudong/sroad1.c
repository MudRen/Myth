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
  "west" : __DIR__"sroad2",
   "east"  : "/d/qujing/huangfeng/huangfeng8",
]));

  setup();
}






