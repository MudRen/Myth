// created by angell 1/1/2001
// room: /d/qujing/huangfeng/ting.c

inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

�������ƿ�������ʮ��С�����ϴ������Ĳ�֪æЩʲô��
����һ���໨ʯ�������ϰ�����������ζ������������
һ���ڣ����߻谵��������ͨ��ʲô���ڡ�

LONG);

  set("exits", ([
        "west" : __DIR__"dong3",
        "northeast" : __DIR__"yuandoor",
	"northwest" : __DIR__"dong4",
      ]));
  set("objects",([
          __DIR__"npc/huangfengguai":1,
	__DIR__"npc/yao":3,
                 ]));     
  setup();
}

int valid_leave (object me, string dir)
{
   me->delete_temp("obstacle/has_here");
   return 1;
}
