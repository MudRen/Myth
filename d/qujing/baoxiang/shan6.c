// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan6.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ�ϻ���������ʯ��㣬�β��س���һЩ���ֹ�ľ��·����
ʯ��Χ�Ƶ�������ɽ���У��ػ����ۡ��Ĵ��紵�ݶ����չȻ�����
���˻�Ȼ��֪������

LONG);

  set("exits", ([
        "northwest"  : __DIR__"shan4",
        "southdown"  : __DIR__"shanwan3",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

