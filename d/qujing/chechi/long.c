// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/long.c

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥�ǳ��ٹ����Ӹ��Ǿۺϵĳ�����¥�������ϵ��н�������һ
�ԣ�¥�ڰ��������������ﳣ�����ſ����Ĺ������������ڴ���
ң���գ�����Ƶ�̸��������

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi9",
      ]));
  set("objects", ([
        __DIR__"npc/long"     : 5,
      ]));
  set("valid_startroom", 1);
  setup();
}

