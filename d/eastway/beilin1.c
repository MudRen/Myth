// create by snowcat.c 4/20/1997
// room: /d/eastway/beilin1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���߽�����֮�У����������˾��������ı�����������֮�������䣬
����Ȫ��ŷ��ѯ������������ı��̡�Ҳ��ʯ����ʯ̨Т�������ؾ�
�������й����ȵȡ�
LONG);

  set("exits", ([
        "north" : __DIR__"beilin2",
        "south" : __DIR__"jinshi",
      ]));
  set("objects", ([ /* sizeof() == 1 */
       __DIR__"obj/shibei" : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}






