// created by angell 1/1/2001
// room: /d/qujing/huangfeng/changjing.c

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

Ժ��һ����ʯ·�棬·���೤�������ɴ�أ�������š�����
һ���᷿���ǵ�������Ϣ�ĵط�����������������������ڣ�
ԶԶ���Ѿ����о������˹�����

LONG);

  set("exits", ([
        "west"    : __DIR__"bedroom",
        "north"   : __DIR__"jiangtang",
	"south" : __DIR__"shanmen",
      ]));

  set("outdoors",__DIR__);
  setup();
}

