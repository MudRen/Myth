// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c

inherit ROOM;

void create ()
{
  set ("short", "����ٸ��");
  set ("long", @LONG

������һ���޴�ı���ٸ���У������������ǧ�������
�������ı���ٸ���гɼ�ʮ·�ݶӣ��·����ڴ�����˷�
��Х�������㲻���������ΰ�ĳ��澪����

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}






