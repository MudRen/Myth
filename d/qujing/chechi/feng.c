// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/feng.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����Ｗ����С�������̣������ϻ�����������ɷչ�����ɡ�
����һ�Ż������Σ������ϻ��輸��һЩ����С���������Ƿ���
�ڴ�ߴߴ������Ʒ����ʳ��

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi10",
      ]));
  set("objects", ([
        __DIR__"npc/feng"     : 5,
     ]));
  set("valid_startroom", 1);
  setup();
}

