// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhai.c

inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

����۵�ի�����ڵ�ǰ��ի���������һ���ľի��������
�����޹����򳵳ٹ��������Ա�����ɷ磬��С��Ůǰ������
��ի���ﲻ����������ի���ϡ�

LONG);

  set("exits", ([
        "east"         : __DIR__"dianmen",
      ]));
  set("objects", ([
         __DIR__"obj/gongguo"    : 1,
         __DIR__"obj/guo"    : 2,
      ]));
  setup();
}

