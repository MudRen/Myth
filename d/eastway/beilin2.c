// create by snowcat.c 4/20/1997
// room: /d/eastway/beilin2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���߽�����֮�У����������˾��������ı�����������֮�������䣬
����Ȫ��ŷ��ѯ������������ı��̡�Ҳ��ʯ����ʯ̨Т�������ؾ�
�������й����ȵȡ�����Щʯ�̣�ʯ��
LONG);

  set("exits", ([
        "south" : __DIR__"beilin1",
      ]));
  set("objects", ([ /* sizeof() == 1 */
       __DIR__"obj/shigui" : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}






