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

  set("objects", ([
        __DIR__"obj/kulou"   : 1,
      ]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sroad4",
  "southeast" : __DIR__"sroad2",
]));

  setup();
}






